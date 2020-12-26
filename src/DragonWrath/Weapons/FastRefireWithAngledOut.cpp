


#include <DragonWrath/Weapons/FastRefireWithAngledOut.hpp>



namespace DragonWrath
{
namespace Weapons
{


FastRefireWithAngledOut::FastRefireWithAngledOut(
      DragonWrath::Entities::PlayerDragon *player_dragon,
      DragonWrath::UserEventEmitter &user_event_emitter
   )
   : DragonWrath::Weapons::Base(user_event_emitter)
   , player_dragon(player_dragon)
   , bullet_refire_counter(0.0)
   , bullet_refire_counter_length(1.0 / 6.0)
   , angled_bullet_refire_counter(0.0)
   , angled_bullet_refire_counter_length(1.0 / 2.0)
{
}



FastRefireWithAngledOut::~FastRefireWithAngledOut()
{
}



void FastRefireWithAngledOut::activate()
{
   if (is_activated())
   {
      // don't do anything
   }
   else
   {
      bullet_refire_counter = 0.0f;
      angled_bullet_refire_counter = 0.0f;
      this->activated = true;
   }
}


void FastRefireWithAngledOut::deactivate()
{
   this->activated = false;
}


void FastRefireWithAngledOut::update()
{
   if (is_activated())
   {
      // bullet_refire_counter
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
         }
      }

      // angled_bullet_refire_counter
      angled_bullet_refire_counter -= (1.0/60.0);
      if (angled_bullet_refire_counter <= 0.0f)
      {
         angled_bullet_refire_counter += angled_bullet_refire_counter_length;

         if (player_dragon)
         {
            // bullet is fired
            float emit_bullet_from_x = player_dragon->place.position.x;
            float emit_bullet_from_y = player_dragon->place.position.y;
            user_event_emitter.emit_spawn_player_bullet_event(emit_bullet_from_x, emit_bullet_from_y - 32);
            user_event_emitter.emit_spawn_player_bullet_event(emit_bullet_from_x, emit_bullet_from_y + 32);
         }
      }
   }
}


bool FastRefireWithAngledOut::is_activated()
{
   return activated;
}


} // namespace Weapons
} // namespace DragonWrath



