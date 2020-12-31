#pragma once

#include <DragonWrath/Levels/TimedScroll.hpp>
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

      DragonWrath::Levels::TimedScroll *create_timed_scroll_level_with_10_random_enemies();
      DragonWrath::Levels::TimedScroll *create_timed_scroll_level_with_test_enemies();
      DragonWrath::Levels::Base *create_level_by_identifier(std::string identifier);

      DragonWrath::Levels::TimedScroll *create_level_1();
   };
}

