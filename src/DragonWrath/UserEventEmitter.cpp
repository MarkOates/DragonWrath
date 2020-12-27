
#include <DragonWrath/UserEventEmitter.hpp>

#include <DragonWrath/MusicAndSoundEffectTrackNames.hpp>
#include <DragonWrath/UserEventNames.hpp>
#include <sstream>

namespace DragonWrath
{


UserEventEmitter::UserEventEmitter(ALLEGRO_EVENT_SOURCE &screen_switcher_event_souce)
   : screen_switcher_event_souce(screen_switcher_event_souce)
{}


UserEventEmitter::~UserEventEmitter()
{}


void UserEventEmitter::emit_start_title_screen_event()
{
   ALLEGRO_EVENT event;
   event.user.type = SCREEN_MANAGER_SWITCH_SCREEN_EVENT;
   event.user.data1 = 1;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void UserEventEmitter::emit_start_gameplay_screen_event()
{
   ALLEGRO_EVENT event;
   event.user.type = SCREEN_MANAGER_SWITCH_SCREEN_EVENT;
   event.user.data1 = 2;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void UserEventEmitter::emit_increase_player_score(int points_to_add)
{
   ALLEGRO_EVENT event;
   event.user.type = INCREASE_PLAYER_SCORE_EVENT;
   event.user.data1 = points_to_add;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void UserEventEmitter::emit_spawn_player_bullet_event(float x, float y)
{
   ALLEGRO_EVENT event;
   event.user.type = SPAWN_PLAYER_BULLET_EVENT;
   event.user.data1 = x;
   event.user.data2 = y;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void UserEventEmitter::emit_spawn_extra_life_power_up_event(float x, float y)
{
   ALLEGRO_EVENT event;
   event.user.type = SPAWN_EXTRA_LIFE_POWER_UP_EVENT;
   event.user.data1 = x;
   event.user.data2 = y;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void UserEventEmitter::emit_spawn_shield_boost_power_up_event(float x, float y)
{
   ALLEGRO_EVENT event;
   event.user.type = SPAWN_SHIELD_BOOST_POWER_UP_EVENT;
   event.user.data1 = x;
   event.user.data2 = y;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void UserEventEmitter::emit_spawn_bullet_boost_power_up_event(float x, float y)
{
   ALLEGRO_EVENT event;
   event.user.type = SPAWN_BULLET_BOOST_POWER_UP_EVENT;
   event.user.data1 = x;
   event.user.data2 = y;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void UserEventEmitter::emit_spawn_speed_boost_power_up_event(float x, float y)
{
   ALLEGRO_EVENT event;
   event.user.type = SPAWN_SPEED_BOOST_POWER_UP_EVENT;
   event.user.data1 = x;
   event.user.data2 = y;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void UserEventEmitter::emit_spawn_option_boost_power_up_event(float x, float y)
{
   ALLEGRO_EVENT event;
   event.user.type = SPAWN_OPTION_BOOST_POWER_UP_EVENT;
   event.user.data1 = x;
   event.user.data2 = y;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void UserEventEmitter::emit_player_dragon_gets_extra_life()
{
   ALLEGRO_EVENT event;
   event.user.type = PLAYER_DRAGON_GETS_EXTRA_LIFE_EVENT;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void UserEventEmitter::emit_player_dragon_gets_shield_boost()
{
   ALLEGRO_EVENT event;
   event.user.type = PLAYER_DRAGON_GETS_SHIELD_BOOST_EVENT;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void UserEventEmitter::emit_player_dragon_gets_bullet_boost()
{
   ALLEGRO_EVENT event;
   event.user.type = PLAYER_DRAGON_GETS_BULLET_BOOST_EVENT;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void UserEventEmitter::emit_player_dragon_gets_speed_boost()
{
   ALLEGRO_EVENT event;
   event.user.type = PLAYER_DRAGON_GETS_SPEED_BOOST_EVENT;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void UserEventEmitter::emit_player_dragon_gets_option_boost()
{
   ALLEGRO_EVENT event;
   event.user.type = PLAYER_DRAGON_GETS_OPTION_BOOST_EVENT;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void UserEventEmitter::emit_play_title_screen_music_event()
{
   ALLEGRO_EVENT event;
   event.user.type = PLAY_MUSIC_TRACK;
   event.user.data1 = TITLE_SCREEN_MUSIC;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void UserEventEmitter::emit_play_level_1_music_event()
{
   ALLEGRO_EVENT event;
   event.user.type = PLAY_MUSIC_TRACK;
   event.user.data1 = LEVEL_1_MUSIC;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}


void UserEventEmitter::emit_play_player_shooting_bullet_sound_effect_event()
{
   ALLEGRO_EVENT event;
   event.user.type = PLAY_SOUND_EFFECT;
   event.user.data1 = PLAYER_SHOOT_BULLET_SOUND_EFFECT;
   al_emit_user_event(&screen_switcher_event_souce, &event, NULL);
}



} // namespace DragonWrath

