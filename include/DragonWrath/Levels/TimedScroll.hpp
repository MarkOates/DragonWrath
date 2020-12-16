#pragma once

#include <DragonWrath/Levels/Base.hpp>

namespace DragonWrath
{
   namespace Levels
   {
      class TimedScroll : public DragonWrath::Levels::Base
      {
      private:
         float timer;
         const float timer_step;

      public:
         TimedScroll();
         ~TimedScroll();

         void update() override;
         float get_timer();
      };
   }
}
