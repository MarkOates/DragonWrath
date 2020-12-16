

#include <DragonWrath/Entities/PlayerDragon.hpp>
#include <DragonWrath/EntityTypeNames.hpp>


namespace DragonWrath
{
namespace Entities
{


PlayerDragon::PlayerDragon(ElementID *parent, float x, float y)
   : DragonWrath::Entities::Base(parent, PLAYER_DRAGON, x, y)
   , max_health(10)
   , health(max_health)
{
}


PlayerDragon::~PlayerDragon()
{
}


} // namespace Entities
} // namespace DragonWrath


