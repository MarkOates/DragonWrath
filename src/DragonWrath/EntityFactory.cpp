
#include <DragonWrath/EntityFactory.hpp>

#include <DragonWrath/EntityAttributeNames.hpp>
#include <DragonWrath/EntityTypeNames.hpp>
#include <DragonWrath/MovementStrategyNames.hpp>
#include <DragonWrath/SceneCollectionHelper.hpp>
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

   if (movement_strategy == TOWARDS_PLAYER_DRAGON_BUT_MAINTAIN_TRAJECTORY)
   {
      DragonWrath::SceneCollectionHelper scene_collection_helper(current_level);
      DragonWrath::Entities::PlayerDragon *player_dragon = scene_collection_helper.get_player_dragon();
      float speed = 8;

      if (player_dragon)
      {
         AllegroFlare::vec2d direction_vector =
            (player_dragon->place.position - red_dragon->place.position).normalized();
         red_dragon->velocity.position = direction_vector * speed;
      }
      else
      {
         red_dragon->velocity.x = -speed;
         red_dragon->velocity.y = 0;
      }
   }

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
   purple_dragon->initialize_movement_strategy();

   return purple_dragon;
}


DragonWrath::Entities::PlayerDragon *EntityFactory::create_player_dragon(float x, float y)
{
   DragonWrath::Entities::PlayerDragon *player_dragon = new DragonWrath::Entities::PlayerDragon(
      current_level, x, y
   );

   ALLEGRO_BITMAP *source_bitmap = framework.bitmap("player_dragon/flying_1.png");
   ALLEGRO_BITMAP *player_dragon_bitmap = get_or_generate_modified_bitmap("player-dragon", source_bitmap, 0.0);
   player_dragon->bitmap.bitmap(player_dragon_bitmap);
   player_dragon->bitmap.align(0.5, 0.5);
   player_dragon->set(ALWAYS_ON_TOP);
   player_dragon->place.size = AllegroFlare::vec2d(96, 96);

   return player_dragon;
}


DragonWrath::Entities::PowerUps::ExtraLife *EntityFactory::create_extra_life(float x, float y)
{
   DragonWrath::Entities::PowerUps::ExtraLife *entity =
      new DragonWrath::Entities::PowerUps::ExtraLife(current_level, x, y);

   ALLEGRO_BITMAP *source_bitmap = framework.bitmap("power_ups/extra_life.png");
   ALLEGRO_BITMAP *bitmap = get_or_generate_modified_bitmap("extra-life", source_bitmap, 0.0);
   entity->bitmap.bitmap(bitmap);
   entity->bitmap.align(0.5, 0.5);
   entity->set(ALWAYS_ON_TOP);
   entity->place.size = AllegroFlare::vec2d(96, 96);

   return entity;
}


DragonWrath::Entities::PowerUps::ShieldBoost *EntityFactory::create_shield_boost(float x, float y)
{
   DragonWrath::Entities::PowerUps::ShieldBoost *entity =
      new DragonWrath::Entities::PowerUps::ShieldBoost(current_level, x, y);

   ALLEGRO_BITMAP *source_bitmap = framework.bitmap("power_ups/shield_boost.png");
   ALLEGRO_BITMAP *bitmap = get_or_generate_modified_bitmap("shield-boost", source_bitmap, 0.0);
   entity->bitmap.bitmap(bitmap);
   entity->bitmap.align(0.5, 0.5);
   entity->set(ALWAYS_ON_TOP);
   entity->place.size = AllegroFlare::vec2d(96, 96);

   return entity;
}


DragonWrath::Entities::PowerUps::BulletBoost *EntityFactory::create_bullet_boost(float x, float y)
{
   DragonWrath::Entities::PowerUps::BulletBoost *entity =
      new DragonWrath::Entities::PowerUps::BulletBoost(current_level, x, y);

   ALLEGRO_BITMAP *source_bitmap = framework.bitmap("power_ups/bullet_boost.png");
   ALLEGRO_BITMAP *bitmap = get_or_generate_modified_bitmap("bullet-boost", source_bitmap, 0.0);
   entity->bitmap.bitmap(bitmap);
   entity->bitmap.align(0.5, 0.5);
   entity->set(ALWAYS_ON_TOP);
   entity->place.size = AllegroFlare::vec2d(96, 96);

   return entity;
}


DragonWrath::Entities::PowerUps::SpeedBoost *EntityFactory::create_speed_boost(float x, float y)
{
   DragonWrath::Entities::PowerUps::SpeedBoost *entity =
      new DragonWrath::Entities::PowerUps::SpeedBoost(current_level, x, y);

   ALLEGRO_BITMAP *source_bitmap = framework.bitmap("power_ups/speed_boost.png");
   ALLEGRO_BITMAP *bitmap = get_or_generate_modified_bitmap("speed-boost", source_bitmap, 0.0);
   entity->bitmap.bitmap(bitmap);
   entity->bitmap.align(0.5, 0.5);
   entity->set(ALWAYS_ON_TOP);
   entity->place.size = AllegroFlare::vec2d(96, 96);

   return entity;
}


DragonWrath::Entities::PowerUps::OptionBoost *EntityFactory::create_option_boost(float x, float y)
{
   DragonWrath::Entities::PowerUps::OptionBoost *entity =
      new DragonWrath::Entities::PowerUps::OptionBoost(current_level, x, y);

   ALLEGRO_BITMAP *source_bitmap = framework.bitmap("power_ups/option_boost.png");
   ALLEGRO_BITMAP *bitmap = get_or_generate_modified_bitmap("option-boost", source_bitmap, 0.0);
   entity->bitmap.bitmap(bitmap);
   entity->bitmap.align(0.5, 0.5);
   entity->set(ALWAYS_ON_TOP);
   entity->place.size = AllegroFlare::vec2d(96, 96);

   return entity;
}


DragonWrath::Entities::Backgrounds::Base *EntityFactory::create_background()
{
   //ALLEGRO_BITMAP *source_bitmap = framework.bitmap("backgrounds/Sky3.png");
   AllegroFlare::BitmapBin &bitmap_bin = framework.get_bitmap_bin_ref();
   DragonWrath::Entities::Backgrounds::Base *background =
      new DragonWrath::Entities::Backgrounds::Base(current_level, bitmap_bin);

   //ALLEGRO_BITMAP *source_bitmap = framework.bitmap("backgrounds/Cloud2.png");
   //ALLEGRO_BITMAP *bitmap = get_or_generate_modified_bitmap("sky-and-cloud3", source_bitmap, 0.0);
   //background->bitmap.bitmap(bitmap);
   //background->bitmap.align(0, 0);
   //background->bitmap.scale_to_fit(1920, 1080);

   return background;
}


DragonWrath::Entities::Terrains::Pillar *EntityFactory::create_pillar()
{
   AllegroFlare::BitmapBin &bitmap_bin = framework.get_bitmap_bin_ref();
   ALLEGRO_BITMAP *source_bitmap = framework.bitmap("terrains/simple_rock.png");
   ALLEGRO_BITMAP *bitmap = get_or_generate_modified_bitmap("pillar-texture", source_bitmap, 0.0);

   float scale = (4 * 16);

   DragonWrath::Entities::Terrains::Pillar *pillar = new DragonWrath::Entities::Terrains::Pillar(
            current_level,
            10 * scale,
            scale * 3,
            scale * 1,
            scale * 6,
            bitmap
         );

   return pillar;
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


