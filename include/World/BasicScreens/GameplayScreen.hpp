#pragma once

#include <AllegroFlare/Screen.hpp>

namespace World
{
   namespace BasicScreens
   {
      class GameplayScreen : public AllegroFlare::Screen
      {
      public:
         GameplayScreen(AllegroFlare::Display *display);
         ~GameplayScreen();
      };
   }
}


