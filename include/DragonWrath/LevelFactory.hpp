#pragma once

#include <DragonWrath/Levels/TimedScroll.hpp>

namespace DragonWrath
{
   class LevelFactory
   {
   public:
      LevelFactory();
      ~LevelFactory();

      DragonWrath::Levels::TimedScroll *create_timed_scroll_level();
   };
}

