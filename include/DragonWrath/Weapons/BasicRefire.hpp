#pragma once


#include <DragonWrath/Weapons/Base.hpp>
#include <DragonWrath/UserEventEmitter.hpp>
#include <DragonWrath/Entities/PlayerDragon.hpp>


namespace DragonWrath
{
   namespace Weapons
   {
      class BasicRefire : public DragonWrath::Weapons::Base
      {
      private:
         DragonWrath::Entities::PlayerDragon *player_dragon;
         bool activated;
         float bullet_refire_counter;
         float bullet_refire_counter_length;

         bool is_activated();

      public:
         BasicRefire(
               DragonWrath::Entities::PlayerDragon *player_dragon,
               DragonWrath::UserEventEmitter &user_event_emitter
            );
         ~BasicRefire();

         void activate() override;
         void deactivate() override;
         void update() override;
      };
   }
}





