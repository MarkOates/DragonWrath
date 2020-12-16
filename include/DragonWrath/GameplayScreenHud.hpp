#pragma once

#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/FontBin.hpp>

namespace DragonWrath
{
   class GameplayScreenHud
   {
   private:
      AllegroFlare::BitmapBin &bitmap_bin;
      AllegroFlare::FontBin &font_bin;

      int player_health;
      int player_max_health;

   public:
      GameplayScreenHud(AllegroFlare::Framework &framework);
      ~GameplayScreenHud();

      void draw_health_bar();

      void draw();

      void set_player_health(int player_health);
      void set_player_max_health(int player_max_health);
   };
}

