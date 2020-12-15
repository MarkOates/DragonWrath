
#include <DragonWrath/EntityFactory.hpp>

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

   player_bullet->velocity.position.x = 10;
   player_bullet->bitmap.bitmap(framework.bitmap("fireball.png"));
   player_bullet->place.size = AllegroFlare::vec2d(100, 100);

   return player_bullet;
}

DragonWrath::Entities::Base *EntityFactory::create_enemy(float x, float y)
{
   DragonWrath::Entities::Base *enemy = new DragonWrath::Entities::Base(
         current_level, "enemy", x, y
      );

   ALLEGRO_BITMAP *enemy_bitmap = framework.bitmap("enemy.png");
   enemy->bitmap.bitmap(enemy_bitmap);
   enemy->place.flip.x = true;
   enemy->place.size = AllegroFlare::vec2d(
         al_get_bitmap_width(enemy_bitmap),
         al_get_bitmap_height(enemy_bitmap)
      );

   return enemy;
}

}


