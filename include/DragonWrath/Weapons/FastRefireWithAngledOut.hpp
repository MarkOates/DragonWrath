#pragma once


#include <DragonWrath/Weapons/Base.hpp>
#include <DragonWrath/UserEventEmitter.hpp>
#include <DragonWrath/Entities/PlayerDragon.hpp>


namespace DragonWrath
{
   namespace Weapons
   {
      class FastRefireWithAngledOut : public DragonWrath::Weapons::Base
      {
      private:
         DragonWrath::Entities::PlayerDragon *player_dragon;
         bool activated;
         float bullet_refire_counter;
         float bullet_refire_counter_length;
         float angled_bullet_refire_counter;
         float angled_bullet_refire_counter_length;

         bool is_activated();

      public:
         FastRefireWithAngledOut(
               DragonWrath::Entities::PlayerDragon *player_dragon,
               DragonWrath::UserEventEmitter &user_event_emitter
            );
         ~FastRefireWithAngledOut();

         void activate() override;
         void deactivate() override;
         void update() override;
      };
   }
}





