#pragma once


#include <allegro_flare/bitmap_object.h>
#include <allegro_flare/placement2d.h>
#include <AllegroFlare/ElementID.hpp>


namespace Entity
{
   class Base : public AllegroFlare::ElementID
   {
   public:
      allegro_flare::placement2d place;
      allegro_flare::placement2d velocity;
      allegro_flare::BitmapObject bitmap;

      Base(AllegroFlare::ElementID *parent, std::string type, float x, float y);
      virtual ~Base();

      virtual void update();
      virtual void draw();

      void flag_for_deletion();
      bool collides(const Base &other);
   };
}



