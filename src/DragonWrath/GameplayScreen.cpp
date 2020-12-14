#include <DragonWrath/GameplayScreen.hpp>

#include <DragonWrath/Entities/Base.hpp>
#include <AllegroFlare/Useful.hpp>

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
   load_level();
}

void DragonWrath::GameplayScreen::load_level()
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

   player_dragon->bitmap.bitmap(framework.bitmap("dragon.png"));

   for (int i=0; i<10; i++)
   {
      float x = AllegroFlare::random_float(0, 1920);
      float y = AllegroFlare::random_float(0, 1080);

      DragonWrath::Entities::Base *entity = new DragonWrath::Entities::Base(
            current_level, "enemy", x, y
         );
      entity->bitmap.bitmap(framework.bitmap("dragon.png"));
      entity->place.scale = AllegroFlare::vec2d(0.5, 0.5);
      entity->place.flip.x = true;
   }

   std::cout << current_level->num_descendants() << std::endl;
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

