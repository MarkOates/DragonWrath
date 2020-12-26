#pragma once

#include <DragonWrath/Levels/TimedScroll.hpp>
#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/UserEventEmitter.hpp>

namespace DragonWrath
{
   class LevelFactory
   {
   private:
      AllegroFlare::Framework &framework;
      DragonWrath::UserEventEmitter &user_event_emitter;

      std::vector<EnemyToSpawn> build_5_dragon_wave(std::string dragon_type, int num_dragons, float frequency, float y, std::string movement_strategy);
      std::vector<EnemyToSpawn> offset_spawn_time(std::vector<EnemyToSpawn> original, float time_offset);
      std::vector<EnemyToSpawn> append(std::vector<EnemyToSpawn> a, std::vector<EnemyToSpawn> b);

   public:
      LevelFactory(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter);
      ~LevelFactory();

      DragonWrath::Levels::TimedScroll *create_timed_scroll_level_with_10_random_enemies();
      DragonWrath::Levels::TimedScroll *create_timed_scroll_level_with_test_enemies();
      DragonWrath::Levels::Base *create_level_by_identifier(std::string identifier);

      DragonWrath::Levels::TimedScroll *create_level_1();
   };
}

