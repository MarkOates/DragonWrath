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

         int player_lives;
         int player_shield_level;
         int player_bullet_level;
         int player_speed_level;
         int player_option_level;

         int player_score;
         float level_progress_position;

         bool game_over_banner_showing;
         bool level_complete_banner_showing;
         bool level_progress_meter_showing;

         bool debug_mode;
         float debug__level_scroll_timer;

         void draw_bar(float x, float y, int value, int max_value=3, std::string label="");
         void draw_player_score();
         void draw_game_over_banner();
         void draw_level_complete_banner();
         void draw_player_lives();
         void draw_all_bars();
         void draw_level_progress_meter();

      public:
         GameplayScreenHud(AllegroFlare::Framework &framework);
         ~GameplayScreenHud();

         void draw();

         void set_player_lives(int player_lives);
         void set_player_shield_level(int player_shield_level);
         void set_player_bullet_level(int player_bullet_level);
         void set_player_speed_level(int player_speed_level);
         void set_player_option_level(int player_option_level);
         void set_player_score(int player_score);

         void set_level_progress_position(float level_progress_position);

         void activate_level_progress_meter();
         void activate_game_over_banner();
         void activate_level_complete_banner();
         void deactivate_level_progress_meter();
         void deactivate_game_over_banner();
         void deactivate_level_complete_banner();
         void deactivate_all_banners();
         bool is_progress_meter_showing();

         void debug__show_level_scroll_timer();
         void debug__set_level_scroll_timer(float time);
      };
   }
}

