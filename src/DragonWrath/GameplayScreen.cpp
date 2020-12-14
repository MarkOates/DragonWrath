#include <DragonWrath/GameplayScreen.hpp>
#include <DragonWrath/Entities/Base.hpp>

DragonWrath::GameplayScreen::GameplayScreen(AllegroFlare::Framework &framework)
   : framework(framework)
   , AllegroFlare::Screen()
   , current_level(nullptr)
{
}

DragonWrath::GameplayScreen::~GameplayScreen()
{
}

void DragonWrath::GameplayScreen::initialize()
{
   if (current_level)
   {
      std::string error_message = "DragonWrath::GameplayScreen::initialize: A level already exists";
      throw std::runtime_error(error_message);
   }

   current_level = new DragonWrath::Levels::Base(100);
   DragonWrath::Entities::Base *player_dragon = new DragonWrath::Entities::Base(
      current_level,
      "player_dragon",
      300,
      300
   );
   ALLEGRO_BITMAP *dragon_bitmap = framework.bitmap("dragon.png");
   player_dragon->bitmap.bitmap(dragon_bitmap);
}

void DragonWrath::GameplayScreen::primary_timer_func()
{
   if (current_level) current_level->draw_all();
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

