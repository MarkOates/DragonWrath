

#include <DragonWrath/Entities/Enemies/PurpleDragon.hpp>

#include <DragonWrath/MovementStrategyNames.hpp>
#include <DragonWrath/Entities/MovementStrategies/TrackPlayerDragon.hpp>
#include <sstream>
#include <math.h>


namespace DragonWrath
{
namespace Entities
{
namespace Enemies
{


PurpleDragon::PurpleDragon(ElementID *parent, float x, float y)
   : DragonWrath::Entities::Enemies::Base(parent, "basic_enemy", x, y, 3, 800)
   , movement_strategy(new DragonWrath::Entities::MovementStrategies::TrackPlayerDragon(this, 2))
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


