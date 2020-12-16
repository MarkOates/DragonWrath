#pragma once

#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/FontBin.hpp>

namespace DragonWrath
{
   class GameplayScreenHud
   {
   private:
      AllegroFlare::BitmapBin &bitmap_bin;
      AllegroFlare::FontBin &font_bin;

   public:
      GameplayScreenHud(AllegroFlare::Framework &framework);
      ~GameplayScreenHud();

      void draw();
   };
}

