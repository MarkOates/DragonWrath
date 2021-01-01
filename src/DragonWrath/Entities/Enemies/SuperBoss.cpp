
#include <DragonWrath/Entities/Enemies/SuperBoss.hpp>

#include <DragonWrath/LevelTypeNames.hpp>
#include <DragonWrath/EntityTypeNames.hpp>
#include <DragonWrath/EntityFactory.hpp>
#include <allegro5/allegro.h>


namespace DragonWrath
{
namespace Entities
{
namespace Enemies
{


SuperBoss::SuperBoss(AllegroFlare::ElementID *parent)
   : DragonWrath::Entities::Enemies::Base(parent, "SuperBoss", 1920/5*4, 1080/2, 3, 10000)
{}


SuperBoss::~SuperBoss()
{}


} // namespace Enemies
} // namespace Entities
} // namespace DragonWrath


