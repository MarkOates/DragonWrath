
#include <DragonWrath/EntityFactory.hpp>

#include <DragonWrath/EntityAttributeNames.hpp>
#include <DragonWrath/EntityTypeNames.hpp>
#include <DragonWrath/MovementStrategyNames.hpp>
#include <AllegroFlare/Useful.hpp>

namespace DragonWrath
{

EntityFactory::EntityFactory(
      AllegroFlare::Framework &framework,
      DragonWrath::Levels::Base *current_level
   )
   : framework(framework)
   , current_level(current_level)
{
}

EntityFactory::~EntityFactory()
{
}

DragonWrath::Entities::PlayerBullet *EntityFactory::create_player_bullet(float x, float y)
{
   DragonWrath::Entities::PlayerBullet *player_bullet =
      new DragonWrath::Entities::PlayerBullet(current_level, x, y);

   ALLEGRO_BITMAP *bullet_bitmap = framework.bitmap("fireball.png");
   player_bullet->velocity.position.x = 10;
   player_bullet->bitmap.bitmap(bullet_bitmap);
   player_bullet->bitmap.align(0.5, 0.5);
   player_bullet->place.size = AllegroFlare::vec2d(
         al_get_bitmap_width(bullet_bitmap),
         al_get_bitmap_height(bullet_bitmap)
      );

   return player_bullet;
}

DragonWrath::Entities::BasicEnemy *EntityFactory::create_enemy(std::string enemy_type, float x, float y, std::string movement_strategy)
{
   DragonWrath::Entities::BasicEnemy *enemy = new DragonWrath::Entities::BasicEnemy(current_level, x, y);

   ALLEGRO_BITMAP *enemy_bitmap = framework.bitmap("enemy.png");
   enemy->bitmap.bitmap(enemy_bitmap);
   enemy->bitmap.align(0.5, 0.5);
   enemy->place.flip.x = true;
   enemy->place.size = AllegroFlare::vec2d(
         al_get_bitmap_width(enemy_bitmap),
         al_get_bitmap_height(enemy_bitmap)
      );

   enemy->set_movement_strategy(movement_strategy);

   return enemy;
}

DragonWrath::Entities::PlayerDragon *EntityFactory::create_player_dragon(float x, float y)
{
   DragonWrath::Entities::PlayerDragon *player_dragon = new DragonWrath::Entities::PlayerDragon(
      current_level, x, x
   );

   ALLEGRO_BITMAP *player_dragon_bitmap = framework.bitmap("dragon.png");
   player_dragon->bitmap.bitmap(player_dragon_bitmap);
   player_dragon->bitmap.align(0.5, 0.5);
   player_dragon->set(ALWAYS_ON_TOP);
   player_dragon->place.size = AllegroFlare::vec2d(
         al_get_bitmap_width(player_dragon_bitmap),
         al_get_bitmap_height(player_dragon_bitmap)
      );

   return player_dragon;
}


std::vector<DragonWrath::Entities::Base *> EntityFactory::create_10_random_enemies()
{
   std::vector<DragonWrath::Entities::Base *> result;

   for (int i=0; i<10; i++)
   {
      float x = AllegroFlare::random_float(1920/2, 1920);
      float y = AllegroFlare::random_float(0, 1080);
      result.push_back(create_enemy(YELLOW_DRAGON, x, y, SIN_WAVE_MOVE_LEFT));
   }

   return result;
}


}


