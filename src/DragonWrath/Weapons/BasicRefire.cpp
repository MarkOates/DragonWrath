


#include <DragonWrath/Weapons/BasicRefire.hpp>



namespace DragonWrath
{
namespace Weapons
{


BasicRefire::BasicRefire(
      DragonWrath::Entities::PlayerDragon *player_dragon,
      DragonWrath::UserEventEmitter &user_event_emitter
   )
   : DragonWrath::Weapons::Base(user_event_emitter)
   , player_dragon(player_dragon)
   , activated(false)
   , bullet_refire_counter(0.0)
   , bullet_refire_counter_length(1.0 / 2.0)
{
}



BasicRefire::~BasicRefire()
{
}



void BasicRefire::activate()
{
   if (is_activated())
   {
      // don't do anything
   }
   else
   {
      this->activated = true;
      bullet_refire_counter = 0.0f;
   }
}


void BasicRefire::deactivate()
{
   this->activated = false;
}


void BasicRefire::update()
{
   if (is_activated())
   {
      bullet_refire_counter -= (1.0/60.0);
      if (bullet_refire_counter <= 0.0f)
      {
         bullet_refire_counter += bullet_refire_counter_length;

         if (player_dragon)
         {
            // bullet is fired
            float emit_bullet_from_x = player_dragon->place.position.x;
            float emit_bullet_from_y = player_dragon->place.position.y;
            user_event_emitter.emit_spawn_player_bullet_event(emit_bullet_from_x, emit_bullet_from_y);
            user_event_emitter.emit_play_player_shooting_bullet_sound_effect_event();
         }
      }
   }
}


bool BasicRefire::is_activated()
{
   return activated;
}



} // namespace Weapons
} // namespace DragonWrath



