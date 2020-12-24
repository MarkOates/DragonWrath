#pragma once


#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace Enemies
      {
         class Base : public DragonWrath::Entities::Base
         {
         private:
            int health;
            int points_worth;
            bool dead;

         public:
            Base(AllegroFlare::ElementID *parent, std::string type, float x, float y, int initial_health, int points_worth);
            ~Base();

            int get_health();
            int get_points_worth();
            void take_damage(int damage);
            bool is_dead();
         };
      }
   }
}

