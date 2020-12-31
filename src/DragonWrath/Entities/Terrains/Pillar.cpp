

#include <DragonWrath/Entities/Terrains/Pillar.hpp>

#include <AllegroFlare/Useful.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace Terrains
{


Pillar::Pillar(AllegroFlare::ElementID *parent, float x, float y, float w, float h, ALLEGRO_BITMAP *texture)
   : DragonWrath::Entities::Terrains::Base(parent)
   , texture(texture)
{
   place.position.x = x;
   place.position.y = y;
   place.size.x = w;
   place.size.y = h;
   place.align.x = 0;
   place.align.y = 0;
}


Pillar::~Pillar()
{
}


void Pillar::draw()
{
   if (texture)
   {
      place.start_transform();
      AllegroFlare::draw_textured_rectangle(0, 0, place.size.x, place.size.y, texture);
      place.restore_transform();
   }
}


} // namespace Terrains
} // namespace Entities
} // namespace DragonWrath




