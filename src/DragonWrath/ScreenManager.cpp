

#include <DragonWrath/ScreenManager.hpp>

#include <DragonWrath/Screens/GameplayScreen.hpp>
#include <DragonWrath/Screens/TitleScreen.hpp>
#include <DragonWrath/UserEventNames.hpp>



namespace DragonWrath
{


ScreenManager::ScreenManager(AllegroFlare::Framework &framework, AllegroFlare::Screens &screens)
   : AllegroFlare::Screen()
   , framework(framework)
   , screens(screens)
   , current_screen(nullptr)
   , screen_switcher_event_souce()
   , user_event_emitter(screen_switcher_event_souce)
   , audio_controller(
         framework.get_sample_bin_ref(),
         std::vector<AudioRepositoryElement>{
            { TITLE_SCREEN_MUSIC, "01 sawsquarenoise - Tittle Screen.ogg", true },
            { LEVEL_1_MUSIC, "02 sawsquarenoise - Stage 1.ogg", true },
            { GAME_OVER_SCREEN_MUSIC, "05 sawsquarenoise - Boss Splash.ogg", false },
         },
         std::vector<AudioRepositoryElement>{
            { PLAYER_SHOOT_BULLET_SOUND_EFFECT, "sfx_wpn_laser8.wav", false },
            { ENEMY_TAKES_HIT_SOUND_EFFECT, "sfx_wpn_punch3.wav", false },
            { ENEMY_EXPLOSION_SOUND_EFFECT, "sfx_wpn_punch4.wav", false },
            { BULLET_DEFLECTED_SOUND_EFFECT, "sfx_wpn_noammo1.wav", false },
         }
      )
{
}



ScreenManager::~ScreenManager()
{
}


void ScreenManager::initialize()
{
   al_init_user_event_source(&screen_switcher_event_souce);
   al_register_event_source(framework.event_queue, &screen_switcher_event_souce);
   audio_controller.initialize();
}


void ScreenManager::load_initial_screen()
{
   user_event_emitter.emit_start_title_screen_event();
}


void ScreenManager::key_down_func(ALLEGRO_EVENT *ev)
{
   switch(ev->keyboard.keycode)
   {
   case ALLEGRO_KEY_1:
      {
         user_event_emitter.emit_start_title_screen_event();
      }
      break;
   case ALLEGRO_KEY_2:
      {
         user_event_emitter.emit_start_gameplay_screen_event();
      }
      break;
   }
}


void ScreenManager::user_event_func(ALLEGRO_EVENT *ev)
{
   switch(ev->type)
   {
   case PLAY_MUSIC_TRACK:
      {
         int track_id = ev->user.data1;
         audio_controller.play_music_track_by_id(track_id);
      }
      break;
   case PLAY_SOUND_EFFECT:
      {
         int sound_effect_id = ev->user.data1;
         audio_controller.play_sound_effect_by_id(sound_effect_id);
      }
      break;
   case STOP_ALL_MUSIC_AND_SOUND_EFFECTS_EVENT:
      {
         audio_controller.stop_all();
      }
      break;
   case SCREEN_MANAGER_SWITCH_SCREEN_EVENT:
      {
         int index_of_level_to_start = ev->user.data1;

         DragonWrath::Screens::Base *newly_created_screen = nullptr;

         switch(index_of_level_to_start)
         {
         case 1:
            {
               DragonWrath::Screens::TitleScreen *title_screen =
                  new DragonWrath::Screens::TitleScreen(framework, user_event_emitter);
               newly_created_screen = title_screen;
            }
            break;
         case 2:
            {
               DragonWrath::Screens::GameplayScreen *gameplay_screen =
                  new DragonWrath::Screens::GameplayScreen(framework, user_event_emitter);
               gameplay_screen->initialize();
               newly_created_screen = gameplay_screen;
            }
            break;
         default:
            {
               std::stringstream error_message;
               error_message << "ScreenManager::user_event_func(): error: undefined index_of_level_to_start \""
                  << index_of_level_to_start
                  << "\""
                  << std::endl;
               throw std::runtime_error(error_message.str());
            }
            break;
         }

         if (newly_created_screen)
         {
            if (current_screen)
            {
               screens.remove(current_screen);
               delete current_screen;
            }
            current_screen = newly_created_screen;
            screens.add(newly_created_screen);
            current_screen->start();
         }
      }
      break;
   default:
      break;
   }
}


} // DragonWrath


