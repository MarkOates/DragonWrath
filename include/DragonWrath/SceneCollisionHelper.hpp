#pragma once


#include <DragonWrath/Levels/Base.hpp>
#include <DragonWrath/SceneCollectionHelper.hpp>
#include <DragonWrath/UserEventEmitter.hpp>


namespace DragonWrath
{
   class SceneCollisionHelper
   {
   private:
      DragonWrath::Levels::Base *scene;
      SceneCollectionHelper collections;
      DragonWrath::UserEventEmitter &user_event_emitter;

      void update_entities_position_by_velocity();
      void update_entities();
      void update_collisions_on_enemies();
      void update_collisions_on_player_dragon();
      void destroy_entities_that_are_off_screen();
      //void limit_sprites_to_world_bounds();
      //void check_damage_zones_on_enemies();
      //void check_damage_zones_on_krampus();
      //void check_krampus_on_door();
      //void check_krampus_on_items();

   public:
      SceneCollisionHelper(DragonWrath::Levels::Base *scene, DragonWrath::UserEventEmitter &user_event_emitter);

      void resolve_collisions();
   };
}


