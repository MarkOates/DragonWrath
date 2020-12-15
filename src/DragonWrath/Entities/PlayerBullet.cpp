

#include <DragonWrath/Entities/PlayerBullet.hpp>


namespace DragonWrath
{
namespace Entities
{


PlayerBullet::PlayerBullet(ElementID *parent, float x, float y)
   : DragonWrath::Entities::Base(parent, "player_bullet", x, y)
{
}


PlayerBullet::~PlayerBullet()
{
}


} // namespace Entities
} // namespace DragonWrath

