#include <DragonWrath/GameplayScreenHud.hpp>


namespace DragonWrath
{


GameplayScreenHud::GameplayScreenHud(AllegroFlare::Framework &framework)
   : bitmap_bin(framework.get_bitmap_bin_ref())
   , font_bin(framework.get_font_bin_ref())
{
}


GameplayScreenHud::~GameplayScreenHud()
{
}


}


