

#include <DragonWrath/Screens/TitleScreen.hpp>

#include <allegro5/allegro_color.h>
#include <AllegroFlare/Color.hpp>
#include <cmath>
#include <math.h>


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


TitleScreen::TitleScreen(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter)
   : framework(framework)
   , user_event_emitter(user_event_emitter)
   , started_at(0)
   , time_jump(0)
   , slides()
   , menu_items()
   , menu_cursor_pos(0)
{
   slides = {
      {1, 3.5, &TitleScreen::draw_krampushack_2020},
      {5.5, 3.5, &TitleScreen::draw_game_by_mark_oates},
      {10, 3, &TitleScreen::draw_powered_by_allegro},
      {13.5, 37, &TitleScreen::draw_sunset_background},
      {14.25, 37, &TitleScreen::draw_main_title},
      {15.75, 37, &TitleScreen::draw_menu_items},
   };

   menu_items = {
      {"Start New Game", &TitleScreen::start_new_game},
      {"Exit", &TitleScreen::exit},
   };
}


TitleScreen::~TitleScreen()
{
}


void TitleScreen::draw_powered_by_allegro()
{
   ALLEGRO_FONT *text_font = framework.font("ChronoTrigger.ttf 60");
   std::string text = "made with Allegro";
   ALLEGRO_COLOR text_color = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};
   float text_x = 1920 / 2;
   float text_y = 1080 / 2 - 60;
   al_draw_text(text_font, text_color, text_x, text_y, ALLEGRO_ALIGN_CENTER, text.c_str());
}


void TitleScreen::draw_game_by_mark_oates()
{
   ALLEGRO_FONT *text_font = framework.font("ChronoTrigger.ttf 60");
   std::string text = "a game by Mark Oates";
   ALLEGRO_COLOR text_color = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};
   float text_x = 1920 / 2;
   float text_y = 1080 / 2 - 60;
   al_draw_text(text_font, text_color, text_x, text_y, ALLEGRO_ALIGN_CENTER, text.c_str());
}


void TitleScreen::draw_krampushack_2020()
{
   ALLEGRO_FONT *text_font = framework.font("ChronoTrigger.ttf 60");
   std::string text = "KrampusHack 2020";
   ALLEGRO_COLOR text_color = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};
   float text_x = 1920 / 2;
   float text_y = 1080 / 2 - 60;
   al_draw_text(text_font, text_color, text_x, text_y, ALLEGRO_ALIGN_CENTER, text.c_str());
}


void TitleScreen::draw_sunset_background()
{
   ALLEGRO_BITMAP *sunset_background = framework.bitmap("backgrounds/SkyAndCloud5.png");
   if (!sunset_background) return;

   ALLEGRO_COLOR blackout = ALLEGRO_COLOR{0.0, 0.0, 0.0, 0.0};
   ALLEGRO_COLOR dark_gray = ALLEGRO_COLOR{0.25, 0.25, 0.25, 0.25};
   ALLEGRO_COLOR light_gray = ALLEGRO_COLOR{0.75, 0.75, 0.75, 0.75};
   ALLEGRO_COLOR full_white = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};

   ALLEGRO_COLOR final_color = full_white;

   draw_offset_textured_rectangle(0, 0, 1920, 1080, 0, 0, sunset_background, final_color);
}


void TitleScreen::draw_menu_items()
{
   ALLEGRO_FONT *text_font = framework.font("ChronoTrigger.ttf 60");
   ALLEGRO_FONT *hilighted_menu_cursor_bracket_font = framework.font("ChronoTrigger.ttf 120");
   float center_x = 1920 / 2;
   float top_y = 1080 / 2 + 100;
   float text_x = 1920 / 2;
   float text_y = 1080 / 2 + 100;
   float menu_spacing_y = 70;
   //std::string text = "Press ENTER key to START";
   ALLEGRO_COLOR darker_text_color = ALLEGRO_COLOR{0.678, 0.847, 0.902, 1.0}; // a nice light blue
   ALLEGRO_COLOR hilighted_menu_item_text_color = fmod(al_get_time(), 0.2f) < 0.1 ? ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0} : darker_text_color;
   ALLEGRO_COLOR normal_menu_item_text_color = ALLEGRO_COLOR{0.5, 0.5, 0.5, 0.5};
   ALLEGRO_COLOR hilighted_menu_selector_bracket_color = al_color_name("yellow");

   int list_item_index = 0;
   for (auto &menu_item : menu_items)
   {
      bool is_selected = (list_item_index == menu_cursor_pos);
      float y = text_y + list_item_index * menu_spacing_y;
      std::string text = std::get<0>(menu_item);
      ALLEGRO_COLOR menu_item_text_color = is_selected ? hilighted_menu_item_text_color : normal_menu_item_text_color;
      
      // rectangle behind menu item

      float rectangle_padding_x = 80;
      float rectangle_padding_y = 8;
      float rectangle_width = al_get_text_width(text_font, text.c_str()) + rectangle_padding_x * 2;
      float rectangle_h_width = rectangle_width / 2;
      ALLEGRO_COLOR rectangle_color = ALLEGRO_COLOR{0.0, 0.0, 0.0, 0.25};
      al_draw_filled_rectangle(
            center_x - rectangle_h_width,
            y - rectangle_padding_y,
            center_x + rectangle_h_width,
            y + rectangle_padding_y + al_get_font_line_height(text_font),
            rectangle_color
         );

      if (is_selected)
      {
         // selection bracket
         al_draw_text(
            hilighted_menu_cursor_bracket_font,
            hilighted_menu_selector_bracket_color,
            text_x,
            y - 15,
            ALLEGRO_ALIGN_CENTER,
            "[                    ]"
         );
      }

      al_draw_text(
         text_font,
         menu_item_text_color,
         text_x,
         y,
         ALLEGRO_ALIGN_CENTER,
         text.c_str()
      );

      list_item_index++;
   }
}


void TitleScreen::draw_main_title()
{
   ALLEGRO_FONT *title_text_font = framework.font("ChronoTrigger.ttf 300");
   ALLEGRO_FONT *subtitle_text_font = framework.font("ChronoTrigger.ttf 60");

   std::string title_text = "DRAGONWRATH";
   //std::string subtitle_text = "Press ENTER key to START";

   ALLEGRO_COLOR title_text_color = al_color_name("yellow");
   ALLEGRO_COLOR title_text_dropshadow_color = AllegroFlare::color::color(al_color_name("yellow"), 0.2);
   //ALLEGRO_COLOR subtitle_darker_text_color = ALLEGRO_COLOR{0.678, 0.847, 0.902, 1.0}; // a nice light blue
   //ALLEGRO_COLOR subtitle_text_color = fmod(al_get_time(), 0.5f) < 0.25 ? ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0} : subtitle_darker_text_color;

   float title_text_x = 1920 / 2;
   float title_text_y = 1080 / 2 - 180;
   float title_text_dropshadow_y_offset = 20;

   //float subtitle_text_x = 1920 / 2;
   //float subtitle_text_y = 1080 / 2 + 100;

   al_draw_text(
      title_text_font,
      title_text_dropshadow_color,
      title_text_x,
      title_text_y+title_text_dropshadow_y_offset,
      ALLEGRO_ALIGN_CENTER,
      title_text.c_str()
   );
   al_draw_text(
      title_text_font,
      title_text_color,
      title_text_x,
      title_text_y,
      ALLEGRO_ALIGN_CENTER,
      title_text.c_str()
   );
   //al_draw_text(
      //subtitle_text_font,
      //subtitle_text_color,
      //subtitle_text_x,
      //subtitle_text_y,
      //ALLEGRO_ALIGN_CENTER,
      //subtitle_text.c_str()
   //);
}


void TitleScreen::start()
{
   started_at = al_get_time();
   time_jump = 0;
   user_event_emitter.emit_stop_all_music_and_sound_effects_event();
   user_event_emitter.emit_play_title_screen_music_event();
}


void TitleScreen::start_new_game()
{
   user_event_emitter.emit_start_gameplay_screen_event();
}


void TitleScreen::exit()
{
   framework.shutdown_program = true;
}


void TitleScreen::move_cursor_up()
{
   menu_cursor_pos--;
   if (menu_cursor_pos < 0) menu_cursor_pos += menu_items.size();
}


void TitleScreen::move_cursor_down()
{
   menu_cursor_pos++;
   if (menu_cursor_pos >= num_menu_items()) menu_cursor_pos -= num_menu_items();
}


void TitleScreen::activate_current_menu_selection()
{
   if (menu_items.empty()) return;
   std::tuple<std::string, void (DragonWrath::Screens::TitleScreen::*)()> menu_item = menu_items[menu_cursor_pos];

   void (DragonWrath::Screens::TitleScreen::*menu_function)() = std::get<1>(menu_item);
   if (menu_function) (this->*menu_function)();
}


int TitleScreen::num_menu_items()
{
   return menu_items.size();
}


bool TitleScreen::is_menu_active()
{
   return (time_since_start() > 15.75);
}


float TitleScreen::time_since_start()
{
   return al_get_time() - started_at + time_jump;
}


void TitleScreen::primary_timer_func()
{
   al_clear_to_color(AllegroFlare::color::black);

   float current_time_counter = time_since_start();
   for (auto &slide : slides)
   {
      float slide_start_time = std::get<0>(slide);
      float slide_duration = std::get<1>(slide);
      float slide_end_time = slide_start_time + slide_duration;
      if (current_time_counter > slide_start_time && current_time_counter < slide_end_time)
      {
         void (DragonWrath::Screens::TitleScreen::*render_method)() = std::get<2>(slide);
         if (render_method) (this->*render_method)();
      }
   }

   if (time_since_start() > 52) start();
}


void TitleScreen::key_char_func(ALLEGRO_EVENT *ev)
{
   if (is_menu_active())
   {
      switch(ev->keyboard.keycode)
      {
      case ALLEGRO_KEY_UP:
         move_cursor_up();
         break;
      case ALLEGRO_KEY_DOWN:
         move_cursor_down();
         break;
      }
   }
}


void TitleScreen::key_down_func(ALLEGRO_EVENT *ev)
{
   if (ev->keyboard.keycode == ALLEGRO_KEY_ESCAPE) framework.shutdown_program = true;

   if (time_since_start() < 14.0f)
   {
      // skip past the credits
      time_jump = (14.0f - time_since_start());
   }

   if (is_menu_active() && ev->keyboard.keycode == ALLEGRO_KEY_ENTER)
   {
      activate_current_menu_selection();
   }
}


} // Screens
} // DragonWrath


