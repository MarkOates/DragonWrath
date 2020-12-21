
#include <DragonWrath/UserEventEmitter.hpp>

#include <DragonWrath/UserEventNames.hpp>
#include <sstream>

namespace DragonWrath
{


UserEventEmitter::UserEventEmitter(ALLEGRO_EVENT_SOURCE *screen_switcher_event_souce)
   : screen_switcher_event_souce(screen_switcher_event_souce)
{}


UserEventEmitter::~UserEventEmitter()
{}


void UserEventEmitter::validate_screen_switcher_event_souce_is_present(std::string method_name)
{
   if (!screen_switcher_event_souce)
   {
      std::stringstream error_message;
      error_message
         << "UserEventEmitter::"
         << method_name
         << "error: screen_switcher_event_souce cannot be nullptr.\""
         << std::endl;
      throw std::runtime_error(error_message.str());
   }
}


void UserEventEmitter::emit_start_title_screen_event()
{
   validate_screen_switcher_event_souce_is_present("emit_start_title_screen_event");

   ALLEGRO_EVENT event;
   event.user.type = SCREEN_MANAGER_SWITCH_SCREEN_EVENT;
   event.user.data1 = 1;
   al_emit_user_event(screen_switcher_event_souce, &event, NULL);
}


void UserEventEmitter::emit_start_gameplay_screen_event()
{
   validate_screen_switcher_event_souce_is_present("emit_start_gameplay_screen_event");

   ALLEGRO_EVENT event;
   event.user.type = SCREEN_MANAGER_SWITCH_SCREEN_EVENT;
   event.user.data1 = 2;
   al_emit_user_event(screen_switcher_event_souce, &event, NULL);
}


} // namespace DragonWrath

