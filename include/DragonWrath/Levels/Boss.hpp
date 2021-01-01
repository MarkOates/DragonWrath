#pragma once

#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/Levels/Base.hpp>
#include <DragonWrath/Entities/Base.hpp>
#include <DragonWrath/Entities/Enemies/SuperBoss.hpp>


namespace DragonWrath
{
   namespace Levels
   {
      class Boss : public DragonWrath::Levels::Base
      {
      private:
         AllegroFlare::Framework &framework;
         bool completed;
         float started_at;

         void spawn_super_boss();
         DragonWrath::Entities::Enemies::SuperBoss *get_super_boss();

      public:
         Boss(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter);
         ~Boss();

         void start();

         void update_level_specific_behavior() override;

         bool is_completed() override;
         void activate_completed();
         void deactivate_completed();
      };
   }
}
