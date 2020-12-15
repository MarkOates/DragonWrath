#pragma once


#include <DragonWrath/Levels/Base.hpp>
#include <DragonWrath/SceneCollectionHelper.hpp>


namespace DragonWrath
{
   class SceneCollisionHelper
   {
   private:
      DragonWrath::Levels::Base *scene;
      SceneCollectionHelper collections;

      void update_entities();
      //void limit_sprites_to_world_bounds();
      //void check_damage_zones_on_enemies();
      //void check_damage_zones_on_krampus();
      //void check_krampus_on_door();
      //void check_krampus_on_items();

   public:
      SceneCollisionHelper(DragonWrath::Levels::Base *scene);

      void resolve_collisions();
   };
}


