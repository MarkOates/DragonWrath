#pragma once

#include <AllegroFlare/Screen.hpp>
#include <allegro5/allegro_font.h>

namespace World
{
   namespace BasicScreens
   {
      class TitleScreen : public AllegroFlare::Screen
      {
      private:
         std::string title_text;
         ALLEGRO_FONT *title_text_font;

      public:
         TitleScreen(AllegroFlare::Display *display);
         ~TitleScreen();

         void initialize() override;
         void start() override;

         void primary_timer_func() override;
      };
   }
}


