


#include <DragonWrath/Weapons/TwinFastRefire.hpp>



namespace DragonWrath
{
namespace Weapons
{


TwinFastRefire::TwinFastRefire(
      DragonWrath::Entities::PlayerDragon *player_dragon,
      DragonWrath::UserEventEmitter &user_event_emitter
   )
   : DragonWrath::Weapons::Base(user_event_emitter)
   , player_dragon(player_dragon)
   , activated(false)
   , bullet_refire_counter(0.0)
   , bullet_refire_counter_length(1.0 / 8.0)
{
}



TwinFastRefire::~TwinFastRefire()
{
}



void TwinFastRefire::activate()
{
   if (is_activated())
   {
      // don't do anything
   }
   else
   {
      bullet_refire_counter = 0.0f;
      this->activated = true;
   }
}


void TwinFastRefire::deactivate()
{
   this->activated = false;
}


void TwinFastRefire::update()
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
            float bullet_distance = 30;
            float bullet_h_distance = bullet_distance/2;
            user_event_emitter.emit_spawn_player_bullet_event(
                  emit_bullet_from_x,
                  emit_bullet_from_y - bullet_h_distance
               );
            user_event_emitter.emit_spawn_player_bullet_event(
                  emit_bullet_from_x,
                  emit_bullet_from_y + bullet_h_distance
               );
         }
      }
   }
}


bool TwinFastRefire::is_activated()
{
   return activated;
}


} // namespace Weapons
} // namespace DragonWrath



