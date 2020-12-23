#pragma once

#include <DragonWrath/Levels/Base.hpp>
#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/Entities/Base.hpp>
#include <DragonWrath/Entities/PlayerBullet.hpp>
#include <DragonWrath/Entities/PlayerDragon.hpp>
#include <DragonWrath/Entities/YellowDragon.hpp>
#include <DragonWrath/Entities/BlueDragon.hpp>
#include <DragonWrath/Entities/GreenDragon.hpp>

namespace DragonWrath
{
   class EntityFactory
   {
   private:
      AllegroFlare::Framework &framework;
      DragonWrath::Levels::Base *current_level;

      ALLEGRO_BITMAP *get_or_generate_dragon_bitmap_for_type(std::string enemy_type, float hue_rotation, std::string generated_bitmap_identifier);
      ALLEGRO_BITMAP *get_dragon_enemy_bitmap(std::string enemy_type);

   public:
      EntityFactory(AllegroFlare::Framework &framework, DragonWrath::Levels::Base *current_level);

      ~EntityFactory();

      DragonWrath::Entities::GreenDragon *create_green_dragon(float x, float y, std::string movement_strategy);
      DragonWrath::Entities::YellowDragon *create_yellow_dragon(float x, float y, std::string movement_strategy);
      DragonWrath::Entities::BlueDragon *create_blue_dragon(float x, float y, std::string movement_strategy);
      DragonWrath::Entities::PlayerBullet *create_player_bullet(float x, float y);
      DragonWrath::Entities::PlayerDragon *create_player_dragon(float x, float y);

      std::vector<DragonWrath::Entities::Base *> create_10_random_enemies();
   };
}

