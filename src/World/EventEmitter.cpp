
#include <World/EventEmitter.hpp>

//#include <World/MusicAndSoundEffectTrackNames.hpp>
#include <World/EventNames.hpp>
#include <World/ScreenNames.hpp>
#include <sstream>

namespace World
{


ALLEGRO_EVENT EventEmitter::build_emit_play_sound_effect_by_identifier(std::string identifier)
{
   ALLEGRO_EVENT event;
   event.user.type = PLAY_SOUND_EFFECT;
   event.user.data1 = (intptr_t)(void *)(new std::string(identifier));
   return event;
}


ALLEGRO_EVENT EventEmitter::build_emit_play_music_track_by_identifier(std::string identifier)
{
   ALLEGRO_EVENT event;
   event.user.type = PLAY_MUSIC_TRACK;
   event.user.data1 = (intptr_t)(void *)(new std::string(identifier));
   return event;
}


ALLEGRO_EVENT EventEmitter::build_emit_start_screen_by_identifier(std::string identifier)
{
   ALLEGRO_EVENT event;
   event.user.type = SCREEN_MANAGER_SWITCH_SCREEN_EVENT;
   event.user.data1 = (intptr_t)(void *)(new std::string(identifier));
   return event;
}


void EventEmitter::emit(ALLEGRO_EVENT event)
{
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


EventEmitter::EventEmitter(ALLEGRO_EVENT_SOURCE &screen_switcher_event_souce)
   : screen_switcher_event_souce(screen_switcher_event_souce)
{}


EventEmitter::~EventEmitter()
{}


void EventEmitter::emit_start_title_screen_event()
{
   ALLEGRO_EVENT event = build_emit_start_screen_by_identifier(SCREEN_TITLE_SCREEN);
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void EventEmitter::emit_start_gameplay_screen_event()
{
   ALLEGRO_EVENT event = build_emit_start_screen_by_identifier(SCREEN_GAMEPLAY_SCREEN);
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void EventEmitter::emit_start_game_over_screen_event()
{
   ALLEGRO_EVENT event = build_emit_start_screen_by_identifier(SCREEN_GAME_OVER_SCREEN);
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void EventEmitter::emit_start_game_won_screen_event()
{
   ALLEGRO_EVENT event = build_emit_start_screen_by_identifier(SCREEN_GAME_WON_SCREEN);
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void EventEmitter::emit_game_over_event()
{
   ALLEGRO_EVENT event;
   event.user.type = GAME_OVER_EVENT;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void EventEmitter::emit_game_won_event()
{
   ALLEGRO_EVENT event;
   event.user.type = GAME_WON_EVENT;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void EventEmitter::emit_stop_all_music_and_sound_effects_event()
{
   ALLEGRO_EVENT event;
   event.user.type = STOP_ALL_MUSIC_AND_SOUND_EFFECTS_EVENT;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void EventEmitter::emit_start_screen_by_identifier(std::string identifier)
{
   ALLEGRO_EVENT event = build_emit_start_screen_by_identifier(identifier);
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void EventEmitter::emit_play_sound_effect_by_identifier(std::string identifier)
{
   ALLEGRO_EVENT event = build_emit_play_sound_effect_by_identifier(identifier);
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void EventEmitter::emit_play_music_track_by_identifier(std::string identifier)
{
   ALLEGRO_EVENT event = build_emit_play_music_track_by_identifier(identifier);
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


} // namespace World


