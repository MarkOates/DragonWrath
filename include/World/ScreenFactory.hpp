#pragma once


#include <AllegroFlare/Screen.hpp>

#include <map>


namespace World
{
   class ScreenFactory
   {
   private:
      std::map<std::string, void (World::ScreenFactory::*)()> screen_elements;

   public:
      ScreenFactory(std::map<std::string, void (World::ScreenFactory::*)()> screen_elements={});
      virtual ~ScreenFactory();

      virtual AllegroFlare::Screen *create_title_screen();
      virtual AllegroFlare::Screen *create_gameplay_screen();
      virtual AllegroFlare::Screen *create_game_over_screen();
      virtual AllegroFlare::Screen *create_game_won_screen();

      virtual AllegroFlare::Screen *create_from_identifier(std::string identifier);
   };
};


