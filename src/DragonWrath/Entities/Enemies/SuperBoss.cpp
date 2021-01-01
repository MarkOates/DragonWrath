
#include <DragonWrath/Entities/Enemies/SuperBoss.hpp>

#include <DragonWrath/LevelTypeNames.hpp>
#include <DragonWrath/EntityTypeNames.hpp>
#include <DragonWrath/EntityFactory.hpp>
#include <allegro5/allegro.h>
#include <DragonWrath/Entities/MovementStrategies/SinWaveAlongRightScreenEdge.hpp>
#include <DragonWrath/Entities/MovementStrategies/StayStill.hpp>
#include <DragonWrath/Entities/MovementStrategies/TrackPlayerDragonThenFreeze.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace Enemies
{


SuperBoss::SuperBoss(AllegroFlare::ElementID *parent)
   : DragonWrath::Entities::Enemies::Base(parent, "SuperBoss", 1920/5*4, 1080/2, 100, 10000)
   , current_movement_strategy(nullptr)
   , started_at(al_get_time())
   , initialized(false)
   , timer(0)
   , movement_strategy_playlist_items({})
{}


void SuperBoss::initialize()
{
   if (initialized) return;

   movement_strategy_playlist_items = std::vector<std::tuple<float, float, DragonWrath::Entities::MovementStrategies::Base*>>({
         //{ 0, 5, new MovementStrategies::StayStill(this) },
         //{ 5, 1.5, new MovementStrategies::TrackPlayerDragonThenFreeze(this) },
         //{ 6.5, 3, new MovementStrategies::StayStill(this) },
         //{ 9.5, 10, new MovementStrategies::SinWaveAlongRightScreenEdge(this) },
      });

   initialized = true;
}


float SuperBoss::time_since_start()
{
   return al_get_time() - started_at;
}



void SuperBoss::update()
{
   timer += 1.0f / 60.0f;
   
   // check to see if movement strategy playlist has a new strategy
   //float current_time_counter = time_since_start();
   //for (auto &movement_strategy_playlist_item : movement_strategy_playlist_items)
   //{
      //float movement_strategy_playlist_item_start_time = std::get<0>(movement_strategy_playlist_item);
      //float movement_strategy_playlist_item_duration = std::get<1>(movement_strategy_playlist_item);
      //float movement_strategy_playlist_item_end_time = movement_strategy_playlist_item_start_time + movement_strategy_playlist_item_duration;

      //if (current_time_counter > movement_strategy_playlist_item_start_time && current_time_counter < movement_strategy_playlist_item_end_time)
      //{
         //DragonWrath::Entities::MovementStrategies::Base *movement_strategy = std::get<2>(movement_strategy_playlist_item);
         //if (movement_strategy) current_movement_strategy = movement_strategy;
      //}
   //}

   //if (current_movement_strategy)
   //{
      //current_movement_strategy->update();
   //}
}


SuperBoss::~SuperBoss()
{}


} // namespace Enemies
} // namespace Entities
} // namespace DragonWrath


