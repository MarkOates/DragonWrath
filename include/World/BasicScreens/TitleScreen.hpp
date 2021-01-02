#pragma once

#include <AllegroFlare/Screen.hpp>

namespace World
{
   namespace BasicScreens
   {
      class TitleScreen : public AllegroFlare::Screen
      {
      public:
         TitleScreen(AllegroFlare::Display *display);
         ~TitleScreen();
      };
   }
}


