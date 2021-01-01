#pragma once

#include <DragonWrath/Levels/TimedScroll.hpp>
#include <DragonWrath/Levels/Base.hpp>
#include <DragonWrath/Levels/Boss.hpp>
#include <DragonWrath/Entities/Backgrounds/Base.hpp>
#include <DragonWrath/Entities/Backgrounds/Boss.hpp>
#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/UserEventEmitter.hpp>

namespace DragonWrath
{
   class LevelFactory
   {
   private:
      AllegroFlare::Framework &framework;
      DragonWrath::UserEventEmitter &user_event_emitter;

   public:
      LevelFactory(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter);
      ~LevelFactory();

      // master entry point
      DragonWrath::Levels::Base *create_level_by_identifier(std::string identifier);

      // create some test levels
      DragonWrath::Levels::TimedScroll *create_timed_scroll_level_with_10_random_enemies();
      DragonWrath::Levels::TimedScroll *create_timed_scroll_level_with_test_enemies();

      // actual gameplay levels
      DragonWrath::Levels::TimedScroll *create_level_1();
      DragonWrath::Levels::Boss *create_boss_level();
   };
}

