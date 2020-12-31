
#include <DragonWrath/LevelFactory.hpp>
#include <DragonWrath/EntityFactory.hpp>
#include <DragonWrath/EntityTypeNames.hpp>
#include <DragonWrath/MovementStrategyNames.hpp>
#include <DragonWrath/Weapons/BasicRefire.hpp>
#include <DragonWrath/JsonLevelLoader.hpp>
#include <string>
#include <fstream>
#include <streambuf>


namespace DragonWrath
{



LevelFactory::LevelFactory(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter)
   : framework(framework)
   , user_event_emitter(user_event_emitter)
{
}


LevelFactory::~LevelFactory()
{
}


DragonWrath::Levels::TimedScroll *LevelFactory::create_timed_scroll_level_with_10_random_enemies()
{
   DragonWrath::Levels::TimedScroll *timed_scroll_level =
      new DragonWrath::Levels::TimedScroll(framework, user_event_emitter, 10);
   DragonWrath::EntityFactory entity_factory(framework, timed_scroll_level);

   // create player dragon
   DragonWrath::Entities::PlayerDragon *created_player_dragon = entity_factory.create_player_dragon(480, 1080/2);
   DragonWrath::Weapons::Base *weapon_to_equip = new DragonWrath::Weapons::BasicRefire(
         created_player_dragon,
         user_event_emitter
      );
   created_player_dragon->equip_weapon(weapon_to_equip);

   // create random enemies
   entity_factory.create_10_random_enemies();

   return timed_scroll_level;
}


static std::string load_file_contents(std::string filename)
{
   // WARNING! this helper function does not raise an exception if the file does not exist
   // TODO raise error when file is not present

   std::ifstream t(filename);
   std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
   return str;
}


DragonWrath::Levels::TimedScroll *LevelFactory::create_level_1()
{
   // load the level source json from file
   std::string level_source_json = load_file_contents("data/levels/level_1.generated.json");

   // load the level from json
   DragonWrath::JsonLevelLoader json_level_loader;
   DragonWrath::Levels::TimedScroll *timed_scroll_level =
      json_level_loader.create_timed_scroll_from_source(level_source_json, framework, user_event_emitter);
   DragonWrath::EntityFactory entity_factory(framework, timed_scroll_level);

   // create player dragon
   DragonWrath::Entities::PlayerDragon *created_player_dragon = entity_factory.create_player_dragon(480, 1080/2);

   // create and equip the weapon on the dragon
   DragonWrath::Weapons::Base *weapon_to_equip = new DragonWrath::Weapons::BasicRefire(created_player_dragon, user_event_emitter);
   created_player_dragon->equip_weapon(weapon_to_equip);

   // create a basic background
   DragonWrath::Entities::Backgrounds::Base *background = entity_factory.create_background();

   return timed_scroll_level;

}


DragonWrath::Levels::TimedScroll *LevelFactory::create_level_2()
{
   // load the level source json from file
   std::string level_source_json = load_file_contents("data/levels/level_2.generated.json");

   // load the level from json
   DragonWrath::JsonLevelLoader json_level_loader;
   DragonWrath::Levels::TimedScroll *timed_scroll_level =
      json_level_loader.create_timed_scroll_from_source(level_source_json, framework, user_event_emitter);
   DragonWrath::EntityFactory entity_factory(framework, timed_scroll_level);

   // create player dragon
   DragonWrath::Entities::PlayerDragon *created_player_dragon = entity_factory.create_player_dragon(480, 1080/2);

   // create and equip the weapon on the dragon
   DragonWrath::Weapons::Base *weapon_to_equip = new DragonWrath::Weapons::BasicRefire(created_player_dragon, user_event_emitter);
   created_player_dragon->equip_weapon(weapon_to_equip);

   // create a basic background
   DragonWrath::Entities::Backgrounds::Base *background = entity_factory.create_background();

   return timed_scroll_level;

}


DragonWrath::Levels::TimedScroll *LevelFactory::create_timed_scroll_level_with_test_enemies()
{
   std::vector<DragonWrath::Levels::TimedScroll::EnemyToSpawn> enemies_to_spawn = {
      { 0, PURPLE_DRAGON, 1920*0.95, 1080/2 - 100, MOVE_LEFT},
      { 1, GREEN_DRAGON, 1920*0.95, 1080/2 - 50,  MOVE_LEFT},
      { 2, PURPLE_DRAGON, 1920*0.95,   1080/2 + 0,   MOVE_LEFT},
      { 3, RED_DRAGON, 1920*0.95, 1080/2 + 50,  MOVE_LEFT},
      { 4, YELLOW_DRAGON, 1920*0.95, 1080/2 + 100, MOVE_LEFT},
   };

   DragonWrath::Levels::TimedScroll *timed_scroll_level =
      new DragonWrath::Levels::TimedScroll(framework, user_event_emitter, 10, enemies_to_spawn);
   DragonWrath::EntityFactory entity_factory(framework, timed_scroll_level);

   // create player dragon
   DragonWrath::Entities::PlayerDragon *created_player_dragon = entity_factory.create_player_dragon(480, 1080/2);
   DragonWrath::Weapons::Base *weapon_to_equip = new DragonWrath::Weapons::BasicRefire(
         created_player_dragon,
         user_event_emitter
      );
   created_player_dragon->equip_weapon(weapon_to_equip);

   return timed_scroll_level;
}


DragonWrath::Levels::Base *LevelFactory::create_level_by_identifier(std::string identifier)
{
   DragonWrath::Levels::Base *result = nullptr;

   if (identifier == "level_1")
   {
      result = create_level_1();
   }
   else if (identifier == "level_2")
   {
      result = create_level_2();
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


