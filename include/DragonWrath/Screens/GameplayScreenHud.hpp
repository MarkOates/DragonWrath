#pragma once

#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/FontBin.hpp>

namespace DragonWrath
{
   namespace Screens
   {
      class GameplayScreenHud
      {
      private:
         AllegroFlare::BitmapBin &bitmap_bin;
         AllegroFlare::FontBin &font_bin;

         int player_health;
         int player_max_health;

         bool game_over_banner_showing;
         bool level_complete_banner_showing;

         bool debug_mode;
         float level_scroll_timer;

      public:
         GameplayScreenHud(AllegroFlare::Framework &framework);
         ~GameplayScreenHud();

         void draw_health_bar();
         void draw_game_over_banner();
         void draw_level_complete_banner();

         void draw();

         void set_player_health(int player_health);
         void set_player_max_health(int player_max_health);
         void activate_game_over_banner();
         void activate_level_complete_banner();
         void deactivate_game_over_banner();
         void deactivate_level_complete_banner();
         void deactivate_all_banners();

         void debug__show_level_scroll_timer();
         void debug__set_level_scroll_timer(float time);
      };
   }
}

