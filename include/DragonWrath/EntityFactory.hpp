#pragma once

#include <DragonWrath/Levels/Base.hpp>
#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/Entities/Base.hpp>
#include <DragonWrath/Entities/PlayerBullet.hpp>

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
   };
}

