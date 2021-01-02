#pragma once


#include <AllegroFlare/Screen.hpp>


namespace World
{
   class ScreenFactory
   {
   public:
      ScreenFactory();
      virtual ~ScreenFactory();

      virtual AllegroFlare::Screen *create_title_screen();
      virtual AllegroFlare::Screen *create_gameplay_screen();
      virtual AllegroFlare::Screen *create_game_over_screen();
      virtual AllegroFlare::Screen *create_game_won_screen();
   };
};


