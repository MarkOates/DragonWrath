#include <DragonWrath/GameplayScreen.hpp>

DragonWrath::GameplayScreen::GameplayScreen(AllegroFlare::Framework &framework)
   : framework(framework)
   , AllegroFlare::Screen()
{
}

DragonWrath::GameplayScreen::~GameplayScreen()
{
}

void DragonWrath::GameplayScreen::primary_timer_func()
{
   ALLEGRO_BITMAP *dragon_bitmap = framework.bitmap("dragon.png");
   al_draw_bitmap(dragon_bitmap, 100, 100, 0);
}

