
#include <DragonWrath/LevelFactory.hpp>
#include <DragonWrath/EntityFactory.hpp>
#include <DragonWrath/EntityTypeNames.hpp>
#include <DragonWrath/MovementStrategyNames.hpp>
#include <DragonWrath/Weapons/BasicRefire.hpp>

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


std::vector<EnemyToSpawn> LevelFactory::build_5_dragon_wave(std::string dragon_type, int num_dragons, float frequency, float y, std::string movement_strategy)
{
   std::vector<EnemyToSpawn> result = {};

   for (int i=0; i<num_dragons; i++) {
      result.push_back({ frequency * i, dragon_type, 1920-5, y, movement_strategy });
   };
   return result;
}


std::vector<EnemyToSpawn> LevelFactory::offset_spawn_time(std::vector<EnemyToSpawn> original, float time_offset)
{
   for (auto &enemy : original) enemy.spawn_time += time_offset;
   return original;
}


std::vector<EnemyToSpawn> LevelFactory::append(std::vector<EnemyToSpawn> a, std::vector<EnemyToSpawn> b)
{
   a.insert(a.end(), b.begin(), b.end());
   return a;
}


DragonWrath::Levels::TimedScroll *LevelFactory::create_level_1()
{
   // enemies to create
  // EnemyToSpawn(float spawn_time, std::string enemy_type, float spawn_x, float spawn_y, std::string movement_strategy);
   float screen_h = 1080;
   float upper_y = screen_h/4;
   float middle_y = screen_h/2;
   float lower_y = screen_h/4*3;

   std::vector<EnemyToSpawn> result_enemies_list = {};
   float delay_for_first_wave_start = 2.0;
   float wave_start = delay_for_first_wave_start;

   result_enemies_list = append(result_enemies_list, offset_spawn_time(build_5_dragon_wave(YELLOW_DRAGON, 5, 0.4, upper_y, MOVE_LEFT), wave_start + 0.0));
   result_enemies_list = append(result_enemies_list, offset_spawn_time(build_5_dragon_wave(YELLOW_DRAGON, 5, 0.4, lower_y, MOVE_LEFT), wave_start + 3.0));
   result_enemies_list = append(result_enemies_list, offset_spawn_time(build_5_dragon_wave(YELLOW_DRAGON, 5, 0.4, middle_y, MOVE_LEFT), wave_start + 5.0));
   wave_start += 7.0;

   result_enemies_list = append(result_enemies_list, offset_spawn_time(build_5_dragon_wave(BLUE_DRAGON, 3, 0.4, middle_y, SIN_WAVE_MOVE_LEFT), wave_start + 0.0));
   wave_start += 7.0;

   result_enemies_list = append(result_enemies_list, offset_spawn_time(build_5_dragon_wave(PURPLE_DRAGON, 1, 0.4, upper_y, SIN_WAVE_MOVE_LEFT), wave_start + 0.0));
   result_enemies_list = append(result_enemies_list, offset_spawn_time(build_5_dragon_wave(PURPLE_DRAGON, 1, 0.4, middle_y, SIN_WAVE_MOVE_LEFT), wave_start + 1.0));
   result_enemies_list = append(result_enemies_list, offset_spawn_time(build_5_dragon_wave(PURPLE_DRAGON, 1, 0.4, lower_y, SIN_WAVE_MOVE_LEFT), wave_start + 2.0));
   wave_start += 7.0;

   result_enemies_list = append(result_enemies_list, offset_spawn_time(build_5_dragon_wave(BLUE_DRAGON, 3, 0.4, upper_y, SIN_WAVE_MOVE_LEFT), wave_start + 0.0));
   result_enemies_list = append(result_enemies_list, offset_spawn_time(build_5_dragon_wave(BLUE_DRAGON, 3, 0.4, lower_y, SIN_WAVE_MOVE_LEFT), wave_start + 0.0));
   wave_start += 7.0;

   DragonWrath::Levels::TimedScroll *timed_scroll_level =
      new DragonWrath::Levels::TimedScroll(framework, user_event_emitter, 60 * 3, result_enemies_list);
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


DragonWrath::Levels::TimedScroll *LevelFactory::create_timed_scroll_level_with_test_enemies()
{
   std::vector<EnemyToSpawn> enemies_to_spawn = {
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


