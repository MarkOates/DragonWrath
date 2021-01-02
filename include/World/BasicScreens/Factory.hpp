#pragma once


#include <World/ScreenFactory.hpp>


namespace World
{
   namespace BasicScreens
   {
      class Factory : public World::ScreenFactory
      {
      private:
         AllegroFlare::Display *display;

         AllegroFlare::Screen *create_title_screen();
         AllegroFlare::Screen *create_gameplay_screen();
         AllegroFlare::Screen *create_game_over_screen();
         AllegroFlare::Screen *create_game_won_screen();

      public:
         Factory(AllegroFlare::Display *display);
         virtual ~Factory();

         virtual AllegroFlare::Screen *create_from_identifier(std::string identifier) override;
      };
   }
}


