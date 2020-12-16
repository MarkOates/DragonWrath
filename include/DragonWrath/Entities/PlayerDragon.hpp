#pragma once


#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      class PlayerDragon : public DragonWrath::Entities::Base
      {
      private:
         int max_health;
         int health;

      public:
         PlayerDragon(ElementID *parent, float x, float y);
         ~PlayerDragon();

         void take_damage(int amount);
      };
   }
}


