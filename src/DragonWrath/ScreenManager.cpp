

#include <DragonWrath/ScreenManager.hpp>

#include <DragonWrath/Screens/GameplayScreen.hpp>
#include <DragonWrath/Screens/TitleScreen.hpp>
#include <DragonWrath/Screens/GameOverScreen.hpp>
#include <DragonWrath/Screens/GameWonScreen.hpp>
#include <DragonWrath/UserEventNames.hpp>
#include <DragonWrath/ScreenNames.hpp>



namespace DragonWrath
{


ScreenManager::ScreenManager(
         AllegroFlare::Framework &framework,
         AllegroFlare::Screens &screens,
         std::map<std::string, AudioRepositoryElement> music_track_elements,
         std::map<std::string, AudioRepositoryElement> sound_effect_elements
      )
   : AllegroFlare::Screen()
   , framework(framework)
   , screens(screens)
   , current_screen(nullptr)
   , user_event_emitter_souce()
   , user_event_emitter(user_event_emitter_souce)
   , audio_controller(framework.get_sample_bin_ref(), music_track_elements, sound_effect_elements)
{
}



ScreenManager::~ScreenManager()
{
}


void ScreenManager::initialize()
{
   al_init_user_event_source(&user_event_emitter_souce);
   al_register_event_source(framework.event_queue, &user_event_emitter_souce);

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
   case ALLEGRO_KEY_3:
      {
         user_event_emitter.emit_start_game_over_screen_event();
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
         std::string *music_track_identifier = (std::string *)(ev->user.data1);
         if (!music_track_identifier)
         {
            std::stringstream error_message;
            error_message
               << "ScreenManager::user_event_func(): PLAY_MUSIC_TRACK error: "
               << "music_track_identifier is missing; expecting (string*) type but is nullptr\"";
            throw std::runtime_error(error_message.str());
         }
         else
         {
            audio_controller.play_music_track_by_identifier(*music_track_identifier);
            delete music_track_identifier;
            ev->user.data1 = 0;
         }
      }
      break;
   case PLAY_SOUND_EFFECT:
      {
         std::string *sound_effect_identifier = (std::string *)(ev->user.data1);
         if (!sound_effect_identifier)
         {
            std::stringstream error_message;
            error_message
               << "ScreenManager::user_event_func(): PLAY_SOUND_EFFECT error: "
               << "sound_effect_identifier is missing; expecting (string*) type but is nullptr\"";
            throw std::runtime_error(error_message.str());
         }
         else
         {
            audio_controller.play_sound_effect_by_identifier(*sound_effect_identifier);
            delete sound_effect_identifier;
            ev->user.data1 = 0;
         }
      }
      break;
   case STOP_ALL_MUSIC_AND_SOUND_EFFECTS_EVENT:
      {
         audio_controller.stop_all();
      }
      break;
   case GAME_OVER_EVENT:
      {
         user_event_emitter.emit_start_game_over_screen_event();
      }
      break;
   case GAME_WON_EVENT:
      {
         user_event_emitter.emit_start_game_won_screen_event();
      }
      break;
   case SCREEN_MANAGER_SWITCH_SCREEN_EVENT:
      {
         int index_of_level_to_start = ev->user.data1;

         DragonWrath::Screens::Base *newly_created_screen = nullptr;

         switch(index_of_level_to_start)
         {
         case SCREEN_TITLE_SCREEN:
            {
               DragonWrath::Screens::TitleScreen *title_screen =
                  new DragonWrath::Screens::TitleScreen(framework, user_event_emitter);
               newly_created_screen->initialize();
               newly_created_screen = title_screen;
            }
            break;
         case SCREEN_GAMEPLAY_SCREEN:
            {
               DragonWrath::Screens::GameplayScreen *gameplay_screen =
                  new DragonWrath::Screens::GameplayScreen(framework, user_event_emitter);
               gameplay_screen->initialize();
               newly_created_screen = gameplay_screen;
            }
            break;
         case SCREEN_GAME_OVER_SCREEN:
            {
               DragonWrath::Screens::GameOverScreen *game_over_screen =
                  new DragonWrath::Screens::GameOverScreen(framework, user_event_emitter);
               game_over_screen->initialize();
               newly_created_screen = game_over_screen;
            }
            break;
         case SCREEN_GAME_WON_SCREEN:
            {
               DragonWrath::Screens::GameWonScreen *game_won_screen =
                  new DragonWrath::Screens::GameWonScreen(framework, user_event_emitter);
               game_won_screen->initialize();
               newly_created_screen = game_won_screen;
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


