
#include <DragonWrath/EntityFactory.hpp>

namespace DragonWrath
{

EntityFactory::EntityFactory(DragonWrath::Levels::Base *current_level)
   : current_level(current_level)
{
}

EntityFactory::~EntityFactory()
{
}

DragonWrath::Entities::PlayerBullet *EntityFactory::create_player_bullet(float x, float y)
{
   DragonWrath::Entities::PlayerBullet *player_bullet =
      new DragonWrath::Entities::PlayerBullet(current_level, x, y);

   return player_bullet;
}

}


