#pragma once


#include <DragonWrath/Entities/PowerUps/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace PowerUps
      {
         class OptionBoost : public DragonWrath::Entities::PowerUps::Base
         {
         public:
            OptionBoost(ElementID *parent, float x, float y);
            ~OptionBoost();
         };
      }
   }
}


