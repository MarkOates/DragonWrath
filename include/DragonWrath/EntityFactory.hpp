#pragma once

#include <DragonWrath/Levels/Base.hpp>
#include <DragonWrath/Entities/Base.hpp>
#include <DragonWrath/Entities/PlayerBullet.hpp>

namespace DragonWrath
{
   class EntityFactory
   {
   private:
      DragonWrath::Levels::Base *current_level;

   public:
      EntityFactory(DragonWrath::Levels::Base *current_level);

      ~EntityFactory();

      DragonWrath::Entities::PlayerBullet *create_player_bullet(float x, float y);
   };
}

