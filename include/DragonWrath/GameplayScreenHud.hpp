#pragma once

#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/FontBin.hpp>

namespace DragonWrath
{
   class GameplayScreenHud
   {
   public:
      AllegroFlare::BitmapBin &bitmap_bin;
      AllegroFlare::FontBin &font_bin;

   private:
      GameplayScreenHud(AllegroFlare::Framework &framework);
      ~GameplayScreenHud();
   };
}

