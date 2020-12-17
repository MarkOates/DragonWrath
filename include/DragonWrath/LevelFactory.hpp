#pragma once

#include <DragonWrath/Levels/TimedScroll.hpp>
#include <AllegroFlare/Framework.hpp>

namespace DragonWrath
{
   class LevelFactory
   {
   private:
      AllegroFlare::Framework &framework;

   public:
      LevelFactory(AllegroFlare::Framework &framework);
      ~LevelFactory();

      DragonWrath::Levels::TimedScroll *create_timed_scroll_level_with_10_random_enemies();
      DragonWrath::Levels::TimedScroll *create_timed_scroll_level_with_test_enemies();
   };
}

