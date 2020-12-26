#pragma once


#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      class PlayerDragon : public DragonWrath::Entities::Base
      {
      private:
         enum state_t {
            NONE = 0,
            ALIVE,
            DEAD
         };
         state_t state;

         int shield_level;
         int bullet_level;
         int speed_level;
         int option_level;

         bool shooting;
         float shooting_start_time;

      public:
         PlayerDragon(ElementID *parent, float x, float y);
         ~PlayerDragon();

         void take_damage(int amount);
         bool is_dead();

         void activate_shooting();
         void deactivate_shooting();
         bool is_shooting();
         float get_shooting_start_time();

         int get_shield_level();
         int get_bullet_level();
         int get_speed_level();
         int get_option_level();

         void increment_shield_level();
         void increment_bullet_level();
         void increment_speed_level();
         void increment_option_level();

         float calculate_max_velocity();
      };
   }
}


