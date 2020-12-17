
#include <DragonWrath/LevelFactory.hpp>
#include <DragonWrath/EntityFactory.hpp>
#include <DragonWrath/MovementStrategyNames.hpp>

namespace DragonWrath
{


LevelFactory::LevelFactory(AllegroFlare::Framework &framework)
   : framework(framework)
{
}


LevelFactory::~LevelFactory()
{
}


DragonWrath::Levels::TimedScroll *LevelFactory::create_timed_scroll_level_with_10_random_enemies()
{
   DragonWrath::Levels::TimedScroll *timed_scroll_level = new DragonWrath::Levels::TimedScroll(framework);
   DragonWrath::EntityFactory entity_factory(framework, timed_scroll_level);

   // create player dragon
   entity_factory.create_player_dragon(480, 1080/2);

   // create random enemies
   entity_factory.create_10_random_enemies();

   return timed_scroll_level;
}


DragonWrath::Levels::TimedScroll *LevelFactory::create_timed_scroll_level_with_test_enemies()
{
   // enemies to create
  // EnemyToSpawn(float spawn_time, std::string enemy_type, float spawn_x, float spawn_y, std::string movement_strategy);
   std::vector<EnemyToSpawn> enemies_to_spawn = {
      { 1, "doesnt-matter-right-now", 1920*0.75 - 300, 1080/2 - 100, MOVE_LEFT},
      { 2, "doesnt-matter-right-now", 1920*0.75 - 150, 1080/2 - 50,  MOVE_RIGHT},
      { 3, "doesnt-matter-right-now", 1920*0.75 + 0,   1080/2 + 0,   SIN_WAVE_MOVE_LEFT},
      { 4, "doesnt-matter-right-now", 1920*0.75 + 150, 1080/2 + 50,  MOVE_RIGHT},
      { 5, "doesnt-matter-right-now", 1920*0.75 + 300, 1080/2 + 100, MOVE_LEFT},
   };

   DragonWrath::Levels::TimedScroll *timed_scroll_level =
      new DragonWrath::Levels::TimedScroll(framework, enemies_to_spawn);
   DragonWrath::EntityFactory entity_factory(framework, timed_scroll_level);

   // create player dragon
   entity_factory.create_player_dragon(480, 1080/2);

   return timed_scroll_level;
}


}


