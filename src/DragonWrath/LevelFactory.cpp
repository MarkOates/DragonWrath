
#include <DragonWrath/LevelFactory.hpp>
#include <DragonWrath/EntityFactory.hpp>
#include <DragonWrath/EntityTypeNames.hpp>
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
   DragonWrath::Levels::TimedScroll *timed_scroll_level = new DragonWrath::Levels::TimedScroll(framework, 10);
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
      { 0, YELLOW_DRAGON, 1920*0.75 - 300, 1080/2 - 100, MOVE_LEFT},
      { 0.5, YELLOW_DRAGON, 1920*0.75 - 150, 1080/2 - 50,  MOVE_LEFT},
      { 1, YELLOW_DRAGON, 1920*0.75 + 0,   1080/2 + 0,   MOVE_LEFT},
      { 1.5, YELLOW_DRAGON, 1920*0.75 + 150, 1080/2 + 50,  MOVE_LEFT},
      { 2, YELLOW_DRAGON, 1920*0.75 + 300, 1080/2 + 100, MOVE_LEFT},
      { 2.5, YELLOW_DRAGON, 1920*0.75 - 300, 1080/2 - 100, MOVE_LEFT},
      { 3, YELLOW_DRAGON, 1920*0.75 - 150, 1080/2 - 50,  MOVE_LEFT},
      { 3.5, YELLOW_DRAGON, 1920*0.75 + 0,   1080/2 + 0,   MOVE_LEFT},
      { 4, YELLOW_DRAGON, 1920*0.75 + 150, 1080/2 + 50,  MOVE_LEFT},
      { 4.5, YELLOW_DRAGON, 1920*0.75 + 300, 1080/2 + 100, MOVE_LEFT},
   };

   DragonWrath::Levels::TimedScroll *timed_scroll_level =
      new DragonWrath::Levels::TimedScroll(framework, 10, enemies_to_spawn);
   DragonWrath::EntityFactory entity_factory(framework, timed_scroll_level);

   // create player dragon
   entity_factory.create_player_dragon(480, 1080/2);

   return timed_scroll_level;
}


DragonWrath::Levels::Base *LevelFactory::create_level_by_identifier(std::string identifier)
{
   DragonWrath::Levels::Base *result = nullptr;

   if (identifier == "level_1")
   {
      result = create_timed_scroll_level_with_test_enemies();
   }
   else if (identifier == "level_2")
   {
      result = create_timed_scroll_level_with_10_random_enemies();
   }
   else
   {
      std::stringstream error_message;
      error_message << "DragonWrath::Levels::Base::create_level_by_identifier(): "
         << "error: undefined identifier \""
         << identifier
         << "\""
         << std::endl;
      throw std::runtime_error(error_message.str());
   }

   return result;
}


} // namespace DragonWrath


