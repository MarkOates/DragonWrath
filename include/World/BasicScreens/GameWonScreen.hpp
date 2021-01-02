#pragma once

#include <AllegroFlare/Screen.hpp>

namespace World
{
   namespace BasicScreens
   {
      class GameWonScreen : public AllegroFlare::Screen
      {
      public:
         GameWonScreen(AllegroFlare::Display *display);
         ~GameWonScreen();

         void primary_timer_func() override;
      };
   }
}


