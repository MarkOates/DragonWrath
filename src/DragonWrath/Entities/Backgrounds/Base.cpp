


#include <DragonWrath/Entities/Backgrounds/Base.hpp>

#include <AllegroFlare/Useful.hpp>
#include <allegro_flare/blender.h>
#include <DragonWrath/Levels/TimedScroll.hpp>
#include <DragonWrath/LevelTypeNames.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace Backgrounds
{


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


Base::Base(
      AllegroFlare::ElementID *parent,
      AllegroFlare::BitmapBin &bitmap_bin, 
      std::vector<DragonWrath::Entities::Backgrounds::Base::BackgroundLayer> background_layers,
      std::vector<DragonWrath::Entities::Backgrounds::Base::ForegroundLayer> foreground_layers
   )
   : DragonWrath::Entities::Base(parent, "background", 0, 0)
   , bitmap_bin(bitmap_bin)
   , offset_x(0)
   , offset_y(0)
   , background_layers(background_layers)
   , foreground_layers(foreground_layers)
{
}


Base::~Base()
{
}


void Base::update()
{
   if (get_parent() && get_parent()->exists("type", TIMED_SCROLL))
   {
      DragonWrath::Levels::TimedScroll *timed_scroll_level = 
         static_cast<DragonWrath::Levels::TimedScroll*>(get_parent());
      offset_x = timed_scroll_level->get_timer();
   }
}


void Base::draw()
{
   for (auto &background_layer : background_layers)
   {
      if (background_layer.bitmap)
      {
         draw_offset_textured_rectangle(
               0,
               0,
               1920,
               1080,
               offset_x * background_layer.offset_scale + background_layer.offset_x,
               offset_y * background_layer.offset_scale + background_layer.offset_y,
               background_layer.bitmap
            );
      }
   }


   //ALLEGRO_BITMAP *back_texture = bitmap_bin.auto_get("backgrounds/Sky3.png");

   //offset_y = -116;

   //float this_layer_offset_scale = 20.0f;
   //ALLEGRO_BITMAP *texture = bitmap_bin.auto_get("backgrounds/Cloud3a.png");
   //draw_offset_textured_rectangle(0, 0, 1920, 1080, offset_x * this_layer_offset_scale, offset_y, texture);
}


void Base::draw_foregrounds()
{
   for (auto &foreground_layer : foreground_layers)
   {
      if (foreground_layer.bitmap)
      {
         draw_offset_textured_rectangle(
               0,
               0,
               1920,
               1080,
               offset_x * foreground_layer.offset_scale + foreground_layer.offset_x,
               offset_y * foreground_layer.offset_scale + foreground_layer.offset_y,
               foreground_layer.bitmap,
               ALLEGRO_COLOR{0.75f, 0.75f, 0.75f, 0.75f}
            );
      }
   }

   ////set_blender(allegro_flare::BLENDER_MULTIPLY);
   //offset_y = -(190 + 190) * 2.0;

   //float this_layer_offset_scale = 40.0f;
   //ALLEGRO_BITMAP *texture = bitmap_bin.auto_get("backgrounds/Cloud2.png");
   //draw_offset_textured_rectangle(0, 0, 1920, 1080, offset_x * this_layer_offset_scale, offset_y * 2.0, texture, ALLEGRO_COLOR{0.75f,0.75f,0.75f,0.75f});
   ////set_blender(allegro_flare::BLENDER_ADDITIVE);
}


} // Backgrounds
} // Entities
} // DragonWrath

