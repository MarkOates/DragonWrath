
#include <DragonWrath/Screens/GameplayScreenHud.hpp>

#include <sstream>
#include <iomanip>

namespace DragonWrath
{
namespace Screens
{


GameplayScreenHud::GameplayScreenHud(AllegroFlare::Framework &framework)
   : bitmap_bin(framework.get_bitmap_bin_ref())
   , font_bin(framework.get_font_bin_ref())
   , player_lives(0)
   , player_shield_level(0)
   , player_bullet_level(0)
   , player_speed_level(0)
   , player_options_level(0)
   , player_score(0)
   , game_over_banner_showing(false)
   , level_complete_banner_showing(false)
   , debug_mode(true)
   , level_scroll_timer(0)
{
}


GameplayScreenHud::~GameplayScreenHud()
{
}


void GameplayScreenHud::draw_bar(float x, float y, int value, int max_value, std::string label)
{
   //float x = 130;
   //float y = 60;
   float bar_max_width = 210;
   float bar_height = 30;

   float percentage = (float)value / max_value;

   ALLEGRO_COLOR backfill_color = ALLEGRO_COLOR{0.25, 0.25, 0.25, 1.0};
   ALLEGRO_COLOR fill_color = ALLEGRO_COLOR{1.0, 0.0, 0.0, 1.0};
   ALLEGRO_COLOR border_color = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};

   // backfill
   al_draw_filled_rectangle(x, y, x+bar_max_width, y+bar_height, backfill_color);
   // active health
   al_draw_filled_rectangle(x, y, x+bar_max_width*percentage, y+bar_height, fill_color);
   // frame
   al_draw_rectangle(x, y, x+bar_max_width, y+bar_height, border_color, 4.0f);

   // draw text
   ALLEGRO_FONT *font = font_bin.auto_get("ChronoTrigger.ttf 48");
   al_draw_text(font, ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0}, x, y-45, 0, label.c_str());
}


void GameplayScreenHud::draw_player_score()
{
   float x = 1920 - 320;
   float y = 30;

   ALLEGRO_COLOR text_color = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};
   ALLEGRO_FONT *font = font_bin.auto_get("ChronoTrigger.ttf 72");
   std::stringstream player_score_text;
   player_score_text << std::setw(6) << std::setfill('0') << player_score;

   al_draw_text(font, text_color, x, y, 0, player_score_text.str().c_str());
}


void GameplayScreenHud::draw_game_over_banner()
{
   ALLEGRO_FONT *title_text_font = font_bin.auto_get("ChronoTrigger.ttf 200");
   ALLEGRO_FONT *subtitle_text_font = font_bin.auto_get("ChronoTrigger.ttf 60");

   std::string title_text = "GAME OVER";
   std::string subtitle_text = "Press ESC key to quit";

   ALLEGRO_COLOR text_color = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};

   float title_text_x = 1920 / 2;
   float title_text_y = 1080 / 2 - 150;

   float subtitle_text_x = 1920 / 2;
   float subtitle_text_y = 1080 / 2 + 100;

   al_draw_text(
      title_text_font,
      text_color,
      title_text_x,
      title_text_y,
      ALLEGRO_ALIGN_CENTER,
      title_text.c_str()
   );
   al_draw_text(
      subtitle_text_font,
      text_color,
      subtitle_text_x,
      subtitle_text_y,
      ALLEGRO_ALIGN_CENTER,
      subtitle_text.c_str()
   );
}


void GameplayScreenHud::draw_level_complete_banner()
{
   ALLEGRO_FONT *title_text_font = font_bin.auto_get("ChronoTrigger.ttf 100");
   ALLEGRO_FONT *subtitle_text_font = font_bin.auto_get("ChronoTrigger.ttf 60");

   std::string title_text = "--  L E V E L  C O M P L E T E  --";
   std::string subtitle_text = "";

   ALLEGRO_COLOR text_color = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};

   float title_text_x = 1920 / 2;
   float title_text_y = 1080 / 2 - 20;

   float subtitle_text_x = 1920 / 2;
   float subtitle_text_y = 1080 / 2 + 100;

   al_draw_text(
      title_text_font,
      text_color,
      title_text_x,
      title_text_y,
      ALLEGRO_ALIGN_CENTER,
      title_text.c_str()
   );
   al_draw_text(
      subtitle_text_font,
      text_color,
      subtitle_text_x,
      subtitle_text_y,
      ALLEGRO_ALIGN_CENTER,
      subtitle_text.c_str()
   );
}


void GameplayScreenHud::draw_player_lives()
{
   float x = 120;
   float y = 30;

   ALLEGRO_COLOR text_color = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};
   ALLEGRO_FONT *font = font_bin.auto_get("ChronoTrigger.ttf 72");
   std::stringstream player_lives_text;
   player_lives_text << "LIVES: " << player_lives;

   al_draw_text(font, text_color, x, y, 0, player_lives_text.str().c_str());
}


void GameplayScreenHud::draw_all_bars()
{
   float start_x = 420;
   float y = 60;

   float cursor_x = start_x;
   float bar_distance_x = 280;

   draw_bar(cursor_x, y, player_shield_level, 3, "SHIELD");
   cursor_x += bar_distance_x;
   draw_bar(cursor_x, y, player_bullet_level, 3, "FIREPOWER");
   cursor_x += bar_distance_x;
   draw_bar(cursor_x, y, player_speed_level, 3, "SPEED");
   cursor_x += bar_distance_x;
   draw_bar(cursor_x, y, player_options_level, 3, "OPTION");
}


void GameplayScreenHud::draw()
{
   draw_player_lives();
   draw_all_bars();

   if (game_over_banner_showing) draw_game_over_banner();
   if (level_complete_banner_showing) draw_level_complete_banner();

   draw_player_score();

   if (debug_mode) debug__show_level_scroll_timer();
}


void GameplayScreenHud::set_player_lives(int player_lives)
{
   this->player_lives = player_lives;
}


void GameplayScreenHud::set_player_shield_level(int player_shield_level)
{
   this->player_shield_level = player_shield_level;
}


void GameplayScreenHud::set_player_bullet_level(int player_bullet_level)
{
   this->player_bullet_level = player_bullet_level;
}


void GameplayScreenHud::set_player_speed_level(int player_speed_level)
{
   this->player_speed_level = player_speed_level;
}


void GameplayScreenHud::set_player_options_level(int player_options_level)
{
   this->player_options_level = player_options_level;
}


void GameplayScreenHud::set_player_score(int player_score)
{
   this->player_score = player_score;
}


void GameplayScreenHud::activate_game_over_banner()
{
   this->game_over_banner_showing = true;
}


void GameplayScreenHud::activate_level_complete_banner()
{
   this->level_complete_banner_showing = true;
}


void GameplayScreenHud::deactivate_game_over_banner()
{
   this->game_over_banner_showing = false;
}


void GameplayScreenHud::deactivate_level_complete_banner()
{
   this->level_complete_banner_showing = false;
}


void GameplayScreenHud::deactivate_all_banners()
{
   deactivate_game_over_banner();
   deactivate_level_complete_banner();
}


void GameplayScreenHud::debug__show_level_scroll_timer()
{
   ALLEGRO_FONT *font = font_bin.auto_get("ChronoTrigger.ttf 32");
   std::stringstream level_scroll_timer_text;
   level_scroll_timer_text << (int)level_scroll_timer;

   al_draw_text(
      font,
      ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0},
      1920/2,
      1080-50,
      ALLEGRO_ALIGN_CENTER,
      level_scroll_timer_text.str().c_str()
   );
}


void GameplayScreenHud::debug__set_level_scroll_timer(float time)
{
   this->level_scroll_timer = time;
}


} // Screens
} // GameplayScreenHud


