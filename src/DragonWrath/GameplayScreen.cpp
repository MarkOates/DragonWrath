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

void DragonWrath::GameplayScreen::key_down_func(ALLEGRO_EVENT *ev)
{
   switch(ev->keyboard.keycode)
   {
   case ALLEGRO_KEY_ESCAPE:
      framework.shutdown_program = true;
      break;
   default:
      break;
   }
}

