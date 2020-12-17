#include <DragonWrath/GameplayScreen.hpp>

#include <DragonWrath/Entities/Base.hpp>
#include <DragonWrath/SceneCollectionHelper.hpp>
#include <DragonWrath/EntityAttributeNames.hpp>
#include <DragonWrath/LevelTypeNames.hpp>
#include <DragonWrath/EntityFactory.hpp>
#include <DragonWrath/LevelFactory.hpp>
#include <AllegroFlare/Useful.hpp>
#include <DragonWrath/Levels/TimedScroll.hpp>

DragonWrath::GameplayScreen::GameplayScreen(AllegroFlare::Framework &framework)
   : AllegroFlare::Screen()
   , framework(framework)
   , current_level(nullptr)
   , hud(framework)
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

   DragonWrath::LevelFactory level_factory(framework);
   current_level = level_factory.create_timed_scroll_level_with_test_enemies();
   //current_level = level_factory.create_timed_scroll_level_with_10_random_enemies();
}

void DragonWrath::GameplayScreen::primary_timer_func()
{
   al_clear_to_color(AllegroFlare::color::black);

   if (current_level)
   {
      DragonWrath::SceneCollectionHelper collection_helper(current_level);
      DragonWrath::Entities::PlayerDragon *player_dragon = collection_helper.get_player_dragon();

      current_level->update();

      // update
      current_level->update_all();

      if (player_dragon && player_dragon->is_dead())
      {
         hud.active_game_over_banner_showing();
      }

      // update the hud
      if (current_level && current_level->is_type(TIMED_SCROLL))
      {
         DragonWrath::Levels::TimedScroll *timed_scroll_level =
            static_cast<DragonWrath::Levels::TimedScroll *>(current_level);
         float level_scroll_timer = timed_scroll_level->get_timer();
         hud.debug__set_level_scroll_timer(level_scroll_timer);
      }
      if (player_dragon)
      {
         hud.set_player_health(player_dragon->get_health());
         hud.set_player_max_health(player_dragon->get_max_health());
      }

      // draw
      current_level->draw_all();
      hud.draw();

      // cleanup
      current_level->cleanup_all();
   }

}

void DragonWrath::GameplayScreen::key_down_func(ALLEGRO_EVENT *ev)
{
   DragonWrath::SceneCollectionHelper scene_collection_helper(current_level);
   Entities::Base *player_dragon = scene_collection_helper.get_player_dragon();

   DragonWrath::EntityFactory entity_factory(framework, current_level);

   switch(ev->keyboard.keycode)
   {
   case ALLEGRO_KEY_UP:
      if (player_dragon) player_dragon->velocity.y = -8;
      break;
   case ALLEGRO_KEY_DOWN:
      if (player_dragon) player_dragon->velocity.y = 8;
      break;
   case ALLEGRO_KEY_LEFT:
      if (player_dragon) player_dragon->velocity.x = -8;
      break;
   case ALLEGRO_KEY_RIGHT:
      if (player_dragon) player_dragon->velocity.x = 8;
      break;
   case ALLEGRO_KEY_SPACE:
      {
         if (player_dragon)
         {
            float bullet_spawn_x = player_dragon->place.position.x;
            float bullet_spawn_y = player_dragon->place.position.y;
            entity_factory.create_player_bullet(bullet_spawn_x, bullet_spawn_y);
         }
      }
      break;
   case ALLEGRO_KEY_ESCAPE:
      framework.shutdown_program = true;
      break;
   default:
      break;
   }
}

void DragonWrath::GameplayScreen::key_up_func(ALLEGRO_EVENT *ev)
{
   DragonWrath::SceneCollectionHelper scene_collection_helper(current_level);
   Entities::Base *player_dragon = scene_collection_helper.get_player_dragon();

   switch(ev->keyboard.keycode)
   {
   case ALLEGRO_KEY_UP:
      if (player_dragon) player_dragon->velocity.y = 0;
      break;
   case ALLEGRO_KEY_DOWN:
      if (player_dragon) player_dragon->velocity.y = 0;
      break;
   case ALLEGRO_KEY_LEFT:
      if (player_dragon) player_dragon->velocity.x = 0;
      break;
   case ALLEGRO_KEY_RIGHT:
      if (player_dragon) player_dragon->velocity.x = 0;
      break;
   default:
      break;
   }
}


