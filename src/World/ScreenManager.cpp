

#include <World/ScreenManager.hpp>

//#include <World/Screens/GameplayScreen.hpp>
//#include <World/Screens/TitleScreen.hpp>
//#include <World/Screens/GameOverScreen.hpp>
//#include <World/Screens/GameWonScreen.hpp>
#include <World/EventNames.hpp>
#include <World/ScreenNames.hpp>



namespace World
{


ScreenManager::ScreenManager(
         AllegroFlare::Framework &framework,
         AllegroFlare::Screens &screens,
         std::map<std::string, AudioRepositoryElement> music_track_elements,
         std::map<std::string, AudioRepositoryElement> sound_effect_elements,
         World::ScreenFactory *screen_factory,
         std::string initial_screen_identifier
      )
   : AllegroFlare::Screen()
   , framework(framework)
   , screens(screens)
   , current_screen(nullptr)
   , event_emitter_souce()
   , event_emitter(event_emitter_souce)
   , audio_controller(framework.get_sample_bin_ref(), music_track_elements, sound_effect_elements)
   , screen_factory(screen_factory)
   , initial_screen_identifier(initial_screen_identifier)
{
}



ScreenManager::~ScreenManager()
{
}


void ScreenManager::initialize()
{
   al_init_user_event_source(&event_emitter_souce);
   al_register_event_source(framework.event_queue, &event_emitter_souce);

   audio_controller.initialize();
}


void ScreenManager::start()
{
   event_emitter.emit_start_screen_by_identifier(initial_screen_identifier);
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
         event_emitter.emit_start_game_over_screen_event();
      }
      break;
   case GAME_WON_EVENT:
      {
         event_emitter.emit_start_game_won_screen_event();
      }
      break;
   case SCREEN_MANAGER_SWITCH_SCREEN_EVENT:
      {
         AllegroFlare::Screen *newly_created_screen = nullptr;

         std::string *screen_identifier = (std::string *)(ev->user.data1);
         if (!screen_identifier)
         {
            std::stringstream error_message;
            error_message
               << "World::ScreenManager::user_event_func(): SCREEN_MANAGER_SWITCH_SCREEN_EVENT error: "
               << "screen_identifier is missing; expecting (string*) type but is nullptr\"";
            throw std::runtime_error(error_message.str());
         }
         else
         {
            AllegroFlare::Screen *title_screen = screen_factory->create_from_identifier(*screen_identifier);
            newly_created_screen = title_screen;
            delete screen_identifier;
            ev->user.data1 = 0;
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
            current_screen->initialize();
            current_screen->start();
         }
      }
      break;
   default:
      break;
   }
}


} // DragonWrath



