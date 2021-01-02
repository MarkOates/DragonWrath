#pragma once

#include <AllegroFlare/Screen.hpp>

namespace World
{
   namespace BasicScreens
   {
      class GameOverScreen : public AllegroFlare::Screen
      {
      public:
         GameOverScreen(AllegroFlare::Display *display);
         ~GameOverScreen();

         void primary_timer_func() override;
      };
   }
}

