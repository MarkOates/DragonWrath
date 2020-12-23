
#include <DragonWrath/EntityFactory.hpp>

#include <DragonWrath/EntityAttributeNames.hpp>
#include <DragonWrath/EntityTypeNames.hpp>
#include <DragonWrath/MovementStrategyNames.hpp>
#include <AllegroFlare/Useful.hpp>


#define BLUE_DRAGON_BITMAP_IDENTFIER "generate-blue-dragon-from-enemy.png"

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


ALLEGRO_BITMAP *EntityFactory::get_or_generate_dragon_bitmap_for_type(std::string enemy_type, float hue_rotation, std::string generated_bitmap_identifier)
{
   AllegroFlare::BitmapBin &bitmap_bin = framework.get_bitmap_bin_ref();

   ALLEGRO_BITMAP *already_existing_blue_dragon_bitmap =
      bitmap_bin.get(generated_bitmap_identifier);

   if (already_existing_blue_dragon_bitmap)
   {
      return already_existing_blue_dragon_bitmap;
   }
   else
   {
      ALLEGRO_BITMAP *original_bitmap = framework.bitmap("enemy.png");
      ALLEGRO_BITMAP *clone_of_bitmap = al_clone_bitmap(original_bitmap);
      AllegroFlare::color::change_hue(clone_of_bitmap, hue_rotation, AllegroFlare::color::blend_op::add);

      AllegroFlare::BitmapBin &bitmap_bin = framework.get_bitmap_bin_ref();
      bitmap_bin.include(generated_bitmap_identifier, clone_of_bitmap);

      return clone_of_bitmap;
   }

   return nullptr;
}


ALLEGRO_BITMAP *EntityFactory::get_dragon_enemy_bitmap(std::string enemy_type)
{
   if (enemy_type == YELLOW_DRAGON)
   {
      return framework.bitmap("enemy.png");
   }
   else if (enemy_type == BLUE_DRAGON)
   {
      return get_or_generate_dragon_bitmap_for_type(BLUE_DRAGON, 0.5, BLUE_DRAGON_BITMAP_IDENTFIER);
   }
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


DragonWrath::Entities::YellowDragon *EntityFactory::create_yellow_dragon(float x, float y, std::string movement_strategy)
{
   DragonWrath::Entities::YellowDragon *yellow_dragon =
      new DragonWrath::Entities::YellowDragon(current_level, x, y);

   ALLEGRO_BITMAP *enemy_bitmap = get_dragon_enemy_bitmap(YELLOW_DRAGON);
   yellow_dragon->bitmap.bitmap(enemy_bitmap);
   yellow_dragon->bitmap.align(0.5, 0.5);
   yellow_dragon->place.flip.x = true;
   yellow_dragon->place.size = AllegroFlare::vec2d(
         al_get_bitmap_width(enemy_bitmap),
         al_get_bitmap_height(enemy_bitmap)
      );

   yellow_dragon->set_movement_strategy(movement_strategy);

   return yellow_dragon;
}


DragonWrath::Entities::BlueDragon *EntityFactory::create_blue_dragon(float x, float y, std::string movement_strategy)
{
   DragonWrath::Entities::BlueDragon *blue_dragon =
      new DragonWrath::Entities::BlueDragon(current_level, x, y);

   ALLEGRO_BITMAP *enemy_bitmap = get_dragon_enemy_bitmap(BLUE_DRAGON);
   blue_dragon->bitmap.bitmap(enemy_bitmap);
   blue_dragon->bitmap.align(0.5, 0.5);
   blue_dragon->place.flip.x = true;
   blue_dragon->place.size = AllegroFlare::vec2d(
         al_get_bitmap_width(enemy_bitmap),
         al_get_bitmap_height(enemy_bitmap)
      );

   blue_dragon->set_movement_strategy(movement_strategy);

   return blue_dragon;
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
      result.push_back(create_yellow_dragon(x, y, SIN_WAVE_MOVE_LEFT));
   }

   return result;
}


}


