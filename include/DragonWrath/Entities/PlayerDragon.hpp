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
         int max_health;
         int health;

      public:
         PlayerDragon(ElementID *parent, float x, float y);
         ~PlayerDragon();

         void take_damage(int amount);
         bool is_dead();
         int get_health();
         int get_max_health();
      };
   }
}


