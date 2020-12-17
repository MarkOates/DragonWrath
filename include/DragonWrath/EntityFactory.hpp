#pragma once

#include <DragonWrath/Levels/Base.hpp>
#include <AllegroFlare/Framework.hpp>
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

   public:
      EntityFactory(AllegroFlare::Framework &framework, DragonWrath::Levels::Base *current_level);

      ~EntityFactory();

      DragonWrath::Entities::PlayerBullet *create_player_bullet(float x, float y);
      DragonWrath::Entities::Base *create_enemy(float x, float y);
      DragonWrath::Entities::PlayerDragon *create_player_dragon(float x, float y);

      std::vector<DragonWrath::Entities::Base *> create_10_random_enemies();
   };
}

