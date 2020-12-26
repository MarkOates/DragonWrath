#pragma once


#include <DragonWrath/Entities/Base.hpp>
#include <DragonWrath/Weapons/Base.hpp>


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
         bool shooting;

         int shield_level;
         int bullet_level;
         int speed_level;
         int option_level;

         DragonWrath::Weapons::Base *weapon;

      public:
         PlayerDragon(ElementID *parent, float x, float y);
         ~PlayerDragon();

         void equip_weapon(DragonWrath::Weapons::Base *weapon);
         void dequip_weapon();

         void take_damage(int amount);
         bool is_dead();

         void activate_shooting();
         void deactivate_shooting();
         bool is_shooting();

         int get_shield_level();
         int get_bullet_level();
         int get_speed_level();
         int get_option_level();
         DragonWrath::Weapons::Base *get_weapon();
         bool has_weapon();

         void increment_shield_level();
         void increment_bullet_level();
         void increment_speed_level();
         void increment_option_level();

         bool is_shield_level_at_max();
         bool is_bullet_level_at_max();
         bool is_speed_level_at_max();
         bool is_option_level_at_max();

         float calculate_max_velocity();
      };
   }
}


