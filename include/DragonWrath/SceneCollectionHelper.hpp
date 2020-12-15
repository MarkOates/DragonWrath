#pragma once


#include <DragonWrath/Entities/Base.hpp>
//#include <dungeon/models/entities/item_entity.hpp>
//#include <dungeon/models/entities/krampus_entity.hpp>
#include <DragonWrath/Entities/PlayerBullet.hpp>
#include <DragonWrath/Levels/Base.hpp>


namespace Enemy { class Base; }
//class DamageZoneEntity;
//class DoorEntity;
//class KidEntity;
//class KnightEntity;


namespace DragonWrath
{
   class SceneCollectionHelper
   {
   private:
      DragonWrath::Levels::Base *scene;

   public:
      SceneCollectionHelper(DragonWrath::Levels::Base *scene);

      std::vector<Entities::Base *> get_all_entities();
      std::vector<Entities::Base *> get_all_entities_y_sorted();
      //std::vector<KidEntity *> get_kids();
      //std::vector<KnightEntity *> get_knights();
      //std::vector<Enemy::Base *> get_enemies();
      //std::vector<DamageZoneEntity *> get_all_damage_zones();
      //std::vector<DamageZoneEntity *> get_all_damage_zones_that_damage_krampus();
      //std::vector<DamageZoneEntity *> get_all_damage_zones_that_damage_enemies();
      std::vector<Entities::Base *> get_entities_bound_in_world();
      std::vector<Entities::Base *> get_all_flagged_for_deletion();
      std::vector<Entities::Base *> get_all_enemies();
      std::vector<Entities::PlayerBullet *> get_all_player_bullets();
      //std::vector<Enemy::Base *> get_enemies_flagged_for_deletion();
      //std::vector<KidEntity *> get_kids_flagged_for_deletion();
      //std::vector<DoorEntity *> get_doors();
      //std::vector<ItemEntity *> get_items();
      Entities::Base *get_player_dragon();
      //DoorEntity *get_door(char door_name);
   };
}


