
#include <DragonWrath/EntityFactory.hpp>

#include <DragonWrath/EntityAttributeNames.hpp>
#include <DragonWrath/EntityTypeNames.hpp>
#include <DragonWrath/MovementStrategyNames.hpp>
#include <AllegroFlare/Useful.hpp>
#include <allegro_flare/image_processing.h>

#define YELLOW_DRAGON_BITMAP_IDENTFIER "generated-yellow-dragon-from-enemy.png"
#define BLUE_DRAGON_BITMAP_IDENTFIER "generated-blue-dragon-from-enemy.png"
#define GREEN_DRAGON_BITMAP_IDENTFIER "generated-green-dragon-from-enemy.png"
#define RED_DRAGON_BITMAP_IDENTFIER "generated-red-dragon-from-enemy.png"
#define PURPLE_DRAGON_BITMAP_IDENTFIER "generated-purple-dragon-from-enemy.png"

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


ALLEGRO_BITMAP *EntityFactory::get_or_generate_modified_bitmap(
      std::string generated_bitmap_identifier,
      ALLEGRO_BITMAP *source_bitmap,
      float hue_rotation
   )
{
   AllegroFlare::BitmapBin &bitmap_bin = framework.get_bitmap_bin_ref();

   ALLEGRO_BITMAP *already_existing_bitmap =
      bitmap_bin.get(generated_bitmap_identifier);

   if (already_existing_bitmap)
   {
      return already_existing_bitmap;
   }
   else
   {
      ALLEGRO_BITMAP *original_bitmap = source_bitmap;
      ALLEGRO_BITMAP *clone_of_bitmap = al_clone_bitmap(original_bitmap);

      // change hue
      AllegroFlare::color::change_hue(clone_of_bitmap, hue_rotation, AllegroFlare::color::blend_op::add);

      // change scale
      ALLEGRO_BITMAP *scaled_bitmap = allegro_flare::create_pixel_perfect_scaled_render(clone_of_bitmap, 4); 
      al_destroy_bitmap(clone_of_bitmap);

      // add the image to the bin
      AllegroFlare::BitmapBin &bitmap_bin = framework.get_bitmap_bin_ref();
      bitmap_bin.include(generated_bitmap_identifier, scaled_bitmap);

      // save the bitmap to the Desktop (for visual reference)
      std::stringstream filename;
      filename << "/Users/markoates/Desktop/" << generated_bitmap_identifier;
      al_save_bitmap(filename.str().c_str(), scaled_bitmap);

      // return the final result
      return scaled_bitmap;
   }

   return nullptr;
}


ALLEGRO_BITMAP *EntityFactory::get_dragon_enemy_bitmap(std::string enemy_type)
{
   ALLEGRO_BITMAP *source_bitmap = framework.bitmap("enemies/dragons/attack_loop_1.png");

   if (enemy_type == YELLOW_DRAGON)
   {
      return get_or_generate_modified_bitmap(YELLOW_DRAGON_BITMAP_IDENTFIER, source_bitmap, 0.0);
   }
   else if (enemy_type == BLUE_DRAGON)
   {
      return get_or_generate_modified_bitmap(BLUE_DRAGON_BITMAP_IDENTFIER, source_bitmap, 0.5);
   }
   else if (enemy_type == GREEN_DRAGON)
   {
      return get_or_generate_modified_bitmap(GREEN_DRAGON_BITMAP_IDENTFIER, source_bitmap, 0.25);
   }
   else if (enemy_type == RED_DRAGON)
   {
      return get_or_generate_modified_bitmap(RED_DRAGON_BITMAP_IDENTFIER, source_bitmap, 0.95);
   }
   else if (enemy_type == PURPLE_DRAGON)
   {
      return get_or_generate_modified_bitmap(PURPLE_DRAGON_BITMAP_IDENTFIER, source_bitmap, 0.75);
   }
   else
   {
      std::stringstream error_message;
      error_message << "EntityFactory::get_dragon_enemy_bitmap(): "
         << "error: unrecognized enemy_type \""
         << enemy_type
         << "\""
         << std::endl;
      throw std::runtime_error(error_message.str());
   }
}


AllegroFlare::vec2d EntityFactory::default_enemy_dragon_size()
{
   return AllegroFlare::vec2d(96, 96);
}


DragonWrath::Entities::PlayerBullet *EntityFactory::create_player_bullet(float x, float y)
{
   DragonWrath::Entities::PlayerBullet *player_bullet =
      new DragonWrath::Entities::PlayerBullet(current_level, x, y);

   ALLEGRO_BITMAP *bullet_bitmap = get_or_generate_modified_bitmap(
            "player-bullet",
            framework.bitmap("player_bullets/fire_bolt_small_3_1.png"),
            0.0
         );
   player_bullet->velocity.position.x = 20;
   player_bullet->bitmap.bitmap(bullet_bitmap);
   player_bullet->bitmap.align(0.5, 0.5);
   player_bullet->place.size = AllegroFlare::vec2d(48, 48);

   return player_bullet;
}


DragonWrath::Entities::Enemies::GreenDragon *EntityFactory::create_green_dragon(float x, float y, std::string movement_strategy)
{
   DragonWrath::Entities::Enemies::GreenDragon *green_dragon =
      new DragonWrath::Entities::Enemies::GreenDragon(current_level, x, y);

   ALLEGRO_BITMAP *enemy_bitmap = get_dragon_enemy_bitmap(GREEN_DRAGON);
   green_dragon->bitmap.bitmap(enemy_bitmap);
   green_dragon->bitmap.align(0.5, 0.5);
   green_dragon->place.flip.x = true;
   green_dragon->place.size = default_enemy_dragon_size();
   green_dragon->set_movement_strategy(movement_strategy);

   return green_dragon;
}


DragonWrath::Entities::Enemies::YellowDragon *EntityFactory::create_yellow_dragon(float x, float y, std::string movement_strategy)
{
   DragonWrath::Entities::Enemies::YellowDragon *yellow_dragon =
      new DragonWrath::Entities::Enemies::YellowDragon(current_level, x, y);

   ALLEGRO_BITMAP *enemy_bitmap = get_dragon_enemy_bitmap(YELLOW_DRAGON);
   yellow_dragon->bitmap.bitmap(enemy_bitmap);
   yellow_dragon->bitmap.align(0.5, 0.5);
   yellow_dragon->place.flip.x = true;
   yellow_dragon->place.size = default_enemy_dragon_size();
   yellow_dragon->set_movement_strategy(movement_strategy);

   return yellow_dragon;
}


DragonWrath::Entities::Enemies::BlueDragon *EntityFactory::create_blue_dragon(float x, float y, std::string movement_strategy)
{
   DragonWrath::Entities::Enemies::BlueDragon *blue_dragon =
      new DragonWrath::Entities::Enemies::BlueDragon(current_level, x, y);

   ALLEGRO_BITMAP *enemy_bitmap = get_dragon_enemy_bitmap(BLUE_DRAGON);
   blue_dragon->bitmap.bitmap(enemy_bitmap);
   blue_dragon->bitmap.align(0.5, 0.5);
   blue_dragon->place.flip.x = true;
   blue_dragon->place.size = default_enemy_dragon_size();
   blue_dragon->set_movement_strategy(movement_strategy);

   return blue_dragon;
}


DragonWrath::Entities::Enemies::RedDragon *EntityFactory::create_red_dragon(float x, float y, std::string movement_strategy)
{
   DragonWrath::Entities::Enemies::RedDragon *red_dragon =
      new DragonWrath::Entities::Enemies::RedDragon(current_level, x, y);

   ALLEGRO_BITMAP *enemy_bitmap = get_dragon_enemy_bitmap(RED_DRAGON);
   red_dragon->bitmap.bitmap(enemy_bitmap);
   red_dragon->bitmap.align(0.5, 0.5);
   red_dragon->place.flip.x = true;
   red_dragon->place.size = default_enemy_dragon_size();

   red_dragon->set_movement_strategy(movement_strategy);

   return red_dragon;
}


DragonWrath::Entities::Enemies::PurpleDragon *EntityFactory::create_purple_dragon(float x, float y)
{
   DragonWrath::Entities::Enemies::PurpleDragon *purple_dragon =
      new DragonWrath::Entities::Enemies::PurpleDragon(current_level, x, y);

   ALLEGRO_BITMAP *enemy_bitmap = get_dragon_enemy_bitmap(PURPLE_DRAGON);
   purple_dragon->bitmap.bitmap(enemy_bitmap);
   purple_dragon->bitmap.align(0.5, 0.5);
   purple_dragon->place.flip.x = true;
   purple_dragon->place.size = default_enemy_dragon_size();


   return purple_dragon;
}


DragonWrath::Entities::PlayerDragon *EntityFactory::create_player_dragon(float x, float y)
{
   DragonWrath::Entities::PlayerDragon *player_dragon = new DragonWrath::Entities::PlayerDragon(
      current_level, x, x
   );

   ALLEGRO_BITMAP *source_bitmap = framework.bitmap("player_dragon/flying_1.png");
   ALLEGRO_BITMAP *player_dragon_bitmap = get_or_generate_modified_bitmap("player-dragon", source_bitmap, 0.0);
   player_dragon->bitmap.bitmap(player_dragon_bitmap);
   player_dragon->bitmap.align(0.5, 0.5);
   player_dragon->set(ALWAYS_ON_TOP);
   player_dragon->place.size = AllegroFlare::vec2d(96, 96);

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


