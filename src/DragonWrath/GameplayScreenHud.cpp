#include <DragonWrath/GameplayScreenHud.hpp>

#include <sstream>


namespace DragonWrath
{


GameplayScreenHud::GameplayScreenHud(AllegroFlare::Framework &framework)
   : bitmap_bin(framework.get_bitmap_bin_ref())
   , font_bin(framework.get_font_bin_ref())
   , player_health(0)
   , player_max_health(10)
   , game_over_banner_showing(false)
{
}


GameplayScreenHud::~GameplayScreenHud()
{
}


void GameplayScreenHud::draw_health_bar()
{
   float x = 60;
   float y = 20;

   float health_bar_max_width = 480;
   float health_bar_height = 40;

   float health_percentage = (float)player_health / player_max_health;

   ALLEGRO_COLOR backfill_color = ALLEGRO_COLOR{0.25, 0.25, 0.25, 1.0};
   ALLEGRO_COLOR fill_color = ALLEGRO_COLOR{1.0, 0.0, 0.0, 1.0};
   ALLEGRO_COLOR border_color = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};

   ALLEGRO_FONT *font = font_bin.auto_get("ChronoTrigger.ttf 32");
   std::stringstream health_text;
   health_text << player_health << "/" << player_max_health;

   al_draw_text(font, ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0}, 10, 10, 0, health_text.str().c_str());

   // backfill
   al_draw_filled_rectangle(x, y, x+health_bar_max_width, y+health_bar_height, backfill_color);
   // active health
   al_draw_filled_rectangle(x, y, x+health_bar_max_width*health_percentage, y+health_bar_height, fill_color);
   // frame
   al_draw_rectangle(x, y, x+health_bar_max_width, y+health_bar_height, border_color, 4.0f);
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


void GameplayScreenHud::draw()
{
   draw_health_bar();
   if (game_over_banner_showing) draw_game_over_banner();
}


void GameplayScreenHud::set_player_health(int player_health)
{
   this->player_health = player_health;
}


void GameplayScreenHud::set_player_max_health(int player_max_health)
{
   this->player_max_health = player_max_health;
}


void GameplayScreenHud::active_game_over_banner_showing()
{
   this->game_over_banner_showing = true;
}


}


