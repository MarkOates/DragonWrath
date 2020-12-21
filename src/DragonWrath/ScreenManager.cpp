

#include <DragonWrath/ScreenManager.hpp>

#include <DragonWrath/Screens/GameplayScreen.hpp>
#include <DragonWrath/Screens/TitleScreen.hpp>


#define SCREEN_MANAGER_SWITCH_SCREEN_EVENT ALLEGRO_GET_EVENT_TYPE('L','v','l','S')


namespace DragonWrath
{


ScreenManager::ScreenManager(AllegroFlare::Framework &framework, AllegroFlare::Screens &screens)
   : AllegroFlare::Screen()
   , framework(framework)
   , screens(screens)
   , current_screen(nullptr)
   , screen_switcher_event_souce()
{
}


ScreenManager::~ScreenManager()
{
}


void ScreenManager::initialize()
{
   al_init_user_event_source(&screen_switcher_event_souce);
   al_register_event_source(framework.event_queue, &screen_switcher_event_souce);
}


void ScreenManager::load_initial_screen()
{
   ALLEGRO_EVENT event;
   event.user.type = SCREEN_MANAGER_SWITCH_SCREEN_EVENT;
   event.user.data1 = 1;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void ScreenManager::key_down_func(ALLEGRO_EVENT *ev)
{
   switch(ev->keyboard.keycode)
   {
   case ALLEGRO_KEY_1:
      {
         ALLEGRO_EVENT event;
         event.user.type = SCREEN_MANAGER_SWITCH_SCREEN_EVENT;
         event.user.data1 = 1;
         al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
      }
      break;
   case ALLEGRO_KEY_2:
      {
         ALLEGRO_EVENT event;
         event.user.type = SCREEN_MANAGER_SWITCH_SCREEN_EVENT;
         event.user.data1 = 2;
         al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
      }
      break;
   }
}


void ScreenManager::user_event_func(ALLEGRO_EVENT *ev)
{
   if (ev->type != SCREEN_MANAGER_SWITCH_SCREEN_EVENT) return;

   int index_of_level_to_start = ev->user.data1;
   std::cout << "index_of_level_to_start: " << index_of_level_to_start << std::endl;

   DragonWrath::Screens::Base *newly_created_screen = nullptr;

   switch(index_of_level_to_start)
   {
   case 1:
      {
         std::cout << "  creating TitleScreen" << std::endl;
         DragonWrath::Screens::TitleScreen *title_screen = new DragonWrath::Screens::TitleScreen(framework);
         newly_created_screen = title_screen;
      }
      break;
   case 2:
      {
         std::cout << "  creating GameplayScreen" << std::endl;
         DragonWrath::Screens::GameplayScreen *gameplay_screen =
            new DragonWrath::Screens::GameplayScreen(framework);
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
   }
}


} // DragonWrath


