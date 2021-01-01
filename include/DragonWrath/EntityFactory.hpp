#pragma once

#include <DragonWrath/Levels/Base.hpp>
#include <DragonWrath/Levels/Boss.hpp>
#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/Entities/Enemies/YellowDragon.hpp>
#include <DragonWrath/Entities/Enemies/BlueDragon.hpp>
#include <DragonWrath/Entities/Enemies/GreenDragon.hpp>
#include <DragonWrath/Entities/Enemies/RedDragon.hpp>
#include <DragonWrath/Entities/Enemies/PurpleDragon.hpp>
#include <DragonWrath/Entities/Base.hpp>
#include <DragonWrath/Entities/PlayerBullet.hpp>
#include <DragonWrath/Entities/PlayerDragon.hpp>
#include <DragonWrath/Entities/PowerUps/ExtraLife.hpp>
#include <DragonWrath/Entities/PowerUps/ShieldBoost.hpp>
#include <DragonWrath/Entities/PowerUps/BulletBoost.hpp>
#include <DragonWrath/Entities/PowerUps/SpeedBoost.hpp>
#include <DragonWrath/Entities/PowerUps/OptionBoost.hpp>
#include <DragonWrath/Entities/Backgrounds/Base.hpp>
#include <DragonWrath/Entities/Backgrounds/Boss.hpp>
#include <DragonWrath/Entities/Terrains/Pillar.hpp>
#include <DragonWrath/Entities/MotionFX/SequentialFrameAnimation.hpp>

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

      // enemy dragons

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

      // player

      DragonWrath::Entities::PlayerBullet *create_player_bullet(float x, float y);
      DragonWrath::Entities::PlayerDragon *create_player_dragon(float x, float y);

      // motion fx

      DragonWrath::Entities::MotionFX::SequentialFrameAnimation *create_slash_poof(float x, float y);

      // power ups

      DragonWrath::Entities::PowerUps::ExtraLife *create_extra_life(float x, float y);
      DragonWrath::Entities::PowerUps::ShieldBoost *create_shield_boost(float x, float y);
      DragonWrath::Entities::PowerUps::BulletBoost *create_bullet_boost(float x, float y);
      DragonWrath::Entities::PowerUps::SpeedBoost *create_speed_boost(float x, float y);
      DragonWrath::Entities::PowerUps::OptionBoost *create_option_boost(float x, float y);

      // background

      DragonWrath::Entities::Backgrounds::Base *create_basic_background();
      DragonWrath::Entities::Backgrounds::Boss *create_boss_background();

      // terrains

      DragonWrath::Entities::Terrains::Pillar *create_pillar();

      // composite

      std::vector<DragonWrath::Entities::Base *> create_10_random_enemies();
   };
}

