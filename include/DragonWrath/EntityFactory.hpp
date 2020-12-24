#pragma once

#include <DragonWrath/Levels/Base.hpp>
#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/Entities/Enemies/YellowDragon.hpp>
#include <DragonWrath/Entities/Enemies/BlueDragon.hpp>
#include <DragonWrath/Entities/Enemies/GreenDragon.hpp>
#include <DragonWrath/Entities/Enemies/RedDragon.hpp>
#include <DragonWrath/Entities/Enemies/PurpleDragon.hpp>
#include <DragonWrath/Entities/PowerUps/SpeedBoost.hpp>
#include <DragonWrath/Entities/Base.hpp>
#include <DragonWrath/Entities/PlayerBullet.hpp>
#include <DragonWrath/Entities/PlayerDragon.hpp>

namespace DragonWrath
{
   class EntityFactory
   {
   private:
      AllegroFlare::Framework &framework;
      DragonWrath::Levels::Base *current_level;

      ALLEGRO_BITMAP *get_or_generate_modified_bitmap(
            std::string generated_bitmap_identifier,
            ALLEGRO_BITMAP *source_bitmap,
            float hue_rotation
         );
      ALLEGRO_BITMAP *get_dragon_enemy_bitmap(std::string enemy_type);
      AllegroFlare::vec2d default_enemy_dragon_size();

   public:
      EntityFactory(AllegroFlare::Framework &framework, DragonWrath::Levels::Base *current_level);

      ~EntityFactory();

      DragonWrath::Entities::Enemies::GreenDragon *create_green_dragon(
            float x,
            float y,
            std::string movement_strategy
         );
      DragonWrath::Entities::Enemies::YellowDragon *create_yellow_dragon(
            float x,
            float y,
            std::string movement_strategy
         );
      DragonWrath::Entities::Enemies::BlueDragon *create_blue_dragon(
            float x,
            float y,
            std::string movement_strategy
         );
      DragonWrath::Entities::Enemies::RedDragon *create_red_dragon(
            float x,
            float y,
            std::string movement_strategy
         );
      DragonWrath::Entities::Enemies::PurpleDragon *create_purple_dragon(
            float x,
            float y
         );
      DragonWrath::Entities::PlayerBullet *create_player_bullet(float x, float y);
      DragonWrath::Entities::PlayerDragon *create_player_dragon(float x, float y);
      DragonWrath::Entities::PowerUps::SpeedBoost *create_speed_boost(float x, float y);

      std::vector<DragonWrath::Entities::Base *> create_10_random_enemies();
   };
}

