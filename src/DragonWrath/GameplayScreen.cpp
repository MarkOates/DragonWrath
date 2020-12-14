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
   sleep(2);
   framework.shutdown_program = true;
}

