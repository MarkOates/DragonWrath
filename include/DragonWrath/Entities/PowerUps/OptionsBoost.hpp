#pragma once


#include <DragonWrath/Entities/PowerUps/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace PowerUps
      {
         class OptionsBoost : public DragonWrath::Entities::PowerUps::Base
         {
         public:
            OptionsBoost(ElementID *parent, float x, float y);
            ~OptionsBoost();
         };
      }
   }
}


