

#include <DragonWrath/Entities/Enemies/PurpleDragon.hpp>

#include <DragonWrath/MovementStrategyNames.hpp>
#include <DragonWrath/Entities/MovementStrategies/MoveAlongPath.hpp>
#include <sstream>
#include <math.h>


namespace DragonWrath
{
namespace Entities
{
namespace Enemies
{


PurpleDragon::PurpleDragon(ElementID *parent, float x, float y)
   : DragonWrath::Entities::Base(parent, "basic_enemy", x, y)
   , movement_strategy(new DragonWrath::Entities::MovementStrategies::MoveAlongPath(this, 10))
{
}


PurpleDragon::~PurpleDragon()
{
   delete movement_strategy;
}


void PurpleDragon::update()
{
   if (movement_strategy) movement_strategy->update();
}


} // namespace Enemies
} // namespace Entities
} // namespace DragonWrath


