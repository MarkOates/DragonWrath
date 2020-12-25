


#include <DragonWrath/SceneCollisionHelper.hpp>

//#include <dungeon/emitters/user_event_emitter.hpp>
//#include <dungeon/models/entities/enemy/kid_entity.hpp>
//#include <dungeon/models/entities/damage_zone_entity.hpp>
#include <DragonWrath/Entities/Base.hpp>
#include <DragonWrath/Entities/PlayerDragon.hpp>
//#include <dungeon/models/entities/door_entity.hpp>
//#include <dungeon/models/entities/krampus_entity.hpp>
#include <DragonWrath/SceneCollectionHelper.hpp>
//#include <dungeon/user_events.hpp>


namespace DragonWrath
{



SceneCollisionHelper::SceneCollisionHelper(
      DragonWrath::Levels::Base *scene,
      DragonWrath::UserEventEmitter &user_event_emitter
   )
   : scene(scene)
   , collections(scene)
   , user_event_emitter(user_event_emitter)
{}



void SceneCollisionHelper::update_entities_position_by_velocity()
{
   for (auto &entity : collections.get_all_entities())
      entity->place.position += entity->velocity.position;
}



void SceneCollisionHelper::update_entities()
{
   for (auto &entity : collections.get_all_entities())
   {
      entity->update();
   }
}



void SceneCollisionHelper::update_player_bullet_collisions_on_enemies()
{
   // start with player bullets
   std::vector<Entities::PlayerBullet *> bullets = collections.get_all_player_bullets();
   std::vector<Entities::Enemies::Base *> enemies = collections.get_all_enemies();

   for (auto &bullet : bullets)
   {
      for (auto &enemy : enemies)
      {
         if (bullet->collides(*enemy))
         {
            //int damage_from_bullet = bullet->get_damage(); // TODO
            int damage_from_bullet = 1;

            enemy->take_damage(damage_from_bullet);
            if (enemy->is_dead())
            {
               enemy->flag_for_deletion();

               int points_to_add = enemy->get_points_worth();
               user_event_emitter.emit_increase_player_score(points_to_add);

               float power_up_spawn_x = enemy->place.position.x;
               float power_up_spawn_y = enemy->place.position.y;
               user_event_emitter.emit_spawn_speed_boost_power_up_event(power_up_spawn_x, power_up_spawn_y);
            }

            bullet->flag_for_deletion();
         }
      }
   }
}



void SceneCollisionHelper::update_enemy_collisions_on_player_dragon()
{
   Entities::PlayerDragon *player_dragon = collections.get_player_dragon();
   std::vector<Entities::Enemies::Base *> enemies = collections.get_all_enemies();

   if (!player_dragon) return;
   if (player_dragon && player_dragon->is_dead()) return;

   for (auto &enemy : enemies)
   {
      if (player_dragon->collides(*enemy))
      {
         player_dragon->take_damage(1);
         enemy->flag_for_deletion();

         if (player_dragon->is_dead())
         {
            player_dragon->flag_for_deletion();
         }
      }
   }
}



void SceneCollisionHelper::update_power_up_collisions_on_player_dragon()
{
   Entities::PlayerDragon *player_dragon = collections.get_player_dragon();
   std::vector<Entities::PowerUps::Base *> power_ups = collections.get_all_power_ups();

   if (!player_dragon) return;
   if (player_dragon && player_dragon->is_dead()) return;

   for (auto &power_up : power_ups)
   {
      if (player_dragon->collides(*power_up))
      {
         // TODO
         power_up->flag_for_deletion();

         int points_to_add = 200;
         user_event_emitter.emit_increase_player_score(points_to_add);

         if (power_up->is_type("SpeedBoost"))
         {
            user_event_emitter.emit_player_dragon_gets_speed_boost();
         }
      }
   }
}



void SceneCollisionHelper::destroy_entities_that_are_off_screen()
{
   std::vector<Entities::Base *> all_entities = collections.get_all_entities();

   //float padding = -50;
   for (auto &entity : all_entities)
   {
      if (entity->place.x < 0) entity->flag_for_deletion();
      if (entity->place.x > 1920) entity->flag_for_deletion();
      if (entity->place.y < 0) entity->flag_for_deletion();
      if (entity->place.y > 1080) entity->flag_for_deletion();
   }
}



//void SceneCollisionHelper::limit_sprites_to_world_bounds()
//{
   //float min_y, max_y;
   //scene->get_y_bounds(&min_y, &max_y);
   //float max_x = scene->get_width();

   //for (auto &entity : collections.get_entities_bound_in_world())
   //{
      //if (entity->place.y < min_y) entity->place.y = min_y;
      //if (entity->place.y > max_y) entity->place.y = max_y;
      //if (entity->place.x < 0) entity->place.x = 0;
      //if (entity->place.x > max_x) entity->place.x = max_x;
   //}
//}



//void SceneCollisionHelper::check_damage_zones_on_enemies()
//{
   //// damage zone <-> enemy collisions
   //for (auto &damage_zone : collections.get_all_damage_zones_that_damage_enemies())
   //{
      //for (auto &enemy : collections.get_enemies())
      //{
         //if (damage_zone->is_dealing_damage() && damage_zone->collides(*enemy))
         //{
            //if (damage_zone->is_krampus_damage_zone()) enemy->take_hit();
            //else if (damage_zone->is_krampus_damage_zone_with_club()) enemy->flag_for_deletion();
         //}
      //}
   //}
//}



//void SceneCollisionHelper::check_damage_zones_on_krampus()
//{
   //KrampusEntity *krampus = collections.get_krampus();

   //// damage zone <-> krampus collisions
   //for (auto &damage_zone : collections.get_all_damage_zones_that_damage_krampus())
   //{
      //if (damage_zone->collides(*krampus))
      //{
         //krampus->take_hit();
      //}
   //}
//}



//void SceneCollisionHelper::check_krampus_on_door()
//{
   //KrampusEntity *krampus = collections.get_krampus();
   //for (auto &door : collections.get_doors())
   //{
      //if (door->place.collide(krampus->place.x, krampus->place.y))
      //{
         //int destination_scene = door->get_as_int("destination_scene");
         //std::string destination_door_name = door->get_as_string("destination_door_name");
         //char dest_door_char = destination_door_name.size() == 1 ? destination_door_name[0] : '!';

         //UserEventEmitter::emit_event(ENTER_DOOR_EVENT, destination_scene, dest_door_char);
      //}
   //}
//}



//void SceneCollisionHelper::check_krampus_on_items()
//{
   //KrampusEntity *krampus = collections.get_krampus();
   //for (auto &item : collections.get_items())
   //{
      //if (item->place.collide(krampus->place.x, krampus->place.y, 20, 10, 20, 10))
      //{
         //int item_type_int = item->get_as_int("item_type_int");
         //UserEventEmitter::emit_event(COLLECT_ITEM_EVENT, item_type_int);
         //item->flag_for_deletion();
      //}
   //}
//}


void SceneCollisionHelper::resolve_collisions()
{
   if (!scene) return;

   update_entities();
   update_entities_position_by_velocity();
   update_player_bullet_collisions_on_enemies();
   update_power_up_collisions_on_player_dragon();
   update_enemy_collisions_on_player_dragon();
   destroy_entities_that_are_off_screen();
   //limit_sprites_to_world_bounds();
   //check_damage_zones_on_enemies();
   //check_damage_zones_on_krampus();
   //check_krampus_on_door();
   //check_krampus_on_items();
};


} // namespace DragonWrath


