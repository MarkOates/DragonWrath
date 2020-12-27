


#include <DragonWrath/Entities/Backgrounds/Base.hpp>

#include <AllegroFlare/Useful.hpp>


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


Base::Base(AllegroFlare::ElementID *parent, AllegroFlare::BitmapBin &bitmap_bin)
   : DragonWrath::Entities::Base(parent, "background", 0, 0)
   , bitmap_bin(bitmap_bin)
   , offset_x(0)
   , offset_y(0)
{
}


Base::~Base()
{
}


void Base::draw()
{
   ALLEGRO_BITMAP *back_texture = bitmap_bin.auto_get("backgrounds/Sky3.png");
   draw_offset_textured_rectangle(0, 0, 1920, 1080, 0, 0, back_texture);

   offset_x += 1.0f;
   offset_y = -110;
   ALLEGRO_BITMAP *texture = bitmap_bin.auto_get("backgrounds/Cloud3a.png");
   draw_offset_textured_rectangle(0, 0, 1920, 1080, offset_x, offset_y, texture);
}


} // Backgrounds
} // Entities
} // DragonWrath

