

#include <DragonWrath/Screens/GameWonScreen.hpp>

#include <allegro5/allegro_color.h>
#include <AllegroFlare/Color.hpp>


static ALLEGRO_VERTEX build_vertex(float x, float y, float z, ALLEGRO_COLOR col, float u, float v)
{
   ALLEGRO_VERTEX vertex;
   vertex.x = x, vertex.y = y, vertex.z = z, vertex.color = col, vertex.u = u, vertex.v = v;
   return vertex;
}


static void draw_offset_textured_rectangle(float x1, float y1, float x2, float y2, float offset_x, float offset_y, ALLEGRO_BITMAP *texture, const ALLEGRO_COLOR &color=ALLEGRO_COLOR{1.0f,1.0f,1.0f,1.0f})
{
   ALLEGRO_VERTEX v[4];

   float bitmap_w = al_get_bitmap_width(texture);
   float bitmap_h = al_get_bitmap_height(texture);

   float scale_x = 1920.0f / bitmap_w;
   float scale_y = 1080.0f / bitmap_h;

   offset_x /= scale_x;
   offset_y /= scale_y;

   v[0] = build_vertex(x1, y1, 0, color, offset_x, offset_y);
   v[1] = build_vertex(x2, y1, 0, color, bitmap_w + offset_x, offset_y);
   v[2] = build_vertex(x2, y2, 0, color, bitmap_w + offset_x, bitmap_h + offset_y);
   v[3] = build_vertex(x1, y2, 0, color, offset_x, bitmap_h + offset_y);

   al_draw_prim(v, NULL, texture, 0, 4, ALLEGRO_PRIM_TRIANGLE_FAN);
}


namespace DragonWrath
{
namespace Screens
{


GameWonScreen::GameWonScreen(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter)
   : framework(framework)
   , user_event_emitter(user_event_emitter)
   , duration_to_allow_exit(10.0f)
   , timer_to_allow_exit(duration_to_allow_exit)
   , exitable(false)
{
}


GameWonScreen::~GameWonScreen()
{
}


bool GameWonScreen::is_exitable()
{
   return exitable;
}


void GameWonScreen::activate_exitable()
{
   exitable = true;
}


void GameWonScreen::deactivate_exitable()
{
   exitable = false;
}


void GameWonScreen::update_timer_to_allow_exit()
{
   if (is_exitable()) return;

   timer_to_allow_exit -= (1.0 / 60.0f);
   if (timer_to_allow_exit <= 0.0f) activate_exitable();
}


void GameWonScreen::draw_you_have_won_banner()
{
   ALLEGRO_FONT *title_text_font = framework.font("ChronoTrigger.ttf 100");
   ALLEGRO_FONT *subtitle_text_font = framework.font("ChronoTrigger.ttf 100");

   std::string title_text = "--  CONGRATULATIONS  --";
   std::string subtitle_text = "You have won the game";

   ALLEGRO_COLOR title_text_color = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};
   ALLEGRO_COLOR subtitle_text_color = al_color_name("yellow"); // a nice light blue
   //ALLEGRO_COLOR subtitle_text_color = ALLEGRO_COLOR{0.678, 0.847, 0.902, 1.0}; // a nice light blue
   ALLEGRO_COLOR subtitle_text_dropshadow_color = al_color_html("5234a4"); // a deep purple
   //ALLEGRO_COLOR subtitle_text_dropshadow_color = al_color_html("ffffff"); // a deep purple

   float title_text_x = 1920 / 2;
   float title_text_y = 1080 / 2 - 150;

   float subtitle_text_x = 1920 / 2;
   float subtitle_text_y = 1080 / 2;
   float subtitle_text_dropshadow_y_offset = 8;

   al_draw_text(
      title_text_font,
      title_text_color,
      title_text_x,
      title_text_y,
      ALLEGRO_ALIGN_CENTER,
      title_text.c_str()
   );
   al_draw_text(
      subtitle_text_font,
      subtitle_text_dropshadow_color,
      subtitle_text_x,
      subtitle_text_y + subtitle_text_dropshadow_y_offset,
      ALLEGRO_ALIGN_CENTER,
      subtitle_text.c_str()
   );
   al_draw_text(
      subtitle_text_font,
      subtitle_text_color,
      subtitle_text_x,
      subtitle_text_y,
      ALLEGRO_ALIGN_CENTER,
      subtitle_text.c_str()
   );
}


void GameWonScreen::draw_sunset_background()
{
   ALLEGRO_BITMAP *sunset_background = framework.bitmap("backgrounds/SkyAndCloud4.png");
   if (!sunset_background) return;

   draw_offset_textured_rectangle(0, 0, 1920, 1080, 0, 0, sunset_background);
}


void GameWonScreen::draw_press_any_key_to_return_to_the_title_screen()
{
   //ALLEGRO_FONT *title_text_font = framework.font("ChronoTrigger.ttf 100");
   ALLEGRO_FONT *subtitle_text_font = framework.font("ChronoTrigger.ttf 60");

   //std::string title_text = "--  CONGRATULATIONS  --";
   std::string subtitle_text = "Press ANY KEY to return to the TITLE SCREEN";

   ALLEGRO_COLOR text_color = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};

   //float title_text_x = 1920 / 2;
   //float title_text_y = 1080 / 2 - 150;

   float subtitle_text_x = 1920 / 2;
   float subtitle_text_y = 1080 / 2 + 100 + 60;

   //al_draw_text(
      //title_text_font,
      //text_color,
      //title_text_x,
      //title_text_y,
      //ALLEGRO_ALIGN_CENTER,
      //title_text.c_str()
   //);
   al_draw_text(
      subtitle_text_font,
      text_color,
      subtitle_text_x,
      subtitle_text_y,
      ALLEGRO_ALIGN_CENTER,
      subtitle_text.c_str()
   );
}


void GameWonScreen::start()
{
   user_event_emitter.emit_stop_all_music_and_sound_effects_event();
   user_event_emitter.emit_play_game_won_music();
}


void GameWonScreen::primary_timer_func()
{
   update_timer_to_allow_exit();

   al_clear_to_color(AllegroFlare::color::black);

   draw_sunset_background();
   draw_you_have_won_banner();
   if (is_exitable()) draw_press_any_key_to_return_to_the_title_screen();
}


void GameWonScreen::key_down_func(ALLEGRO_EVENT *ev)
{
   if (is_exitable()) user_event_emitter.emit_start_title_screen_event();
}


} // Screens
} // DragonWrath


