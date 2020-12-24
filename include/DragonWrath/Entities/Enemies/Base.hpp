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
            bool dead;

         public:
            Base(AllegroFlare::ElementID *parent, std::string type, float x, float y, int initial_health);
            ~Base();

            int get_health();
            void take_damage(int damage);
            bool is_dead();
         };
      }
   }
}

