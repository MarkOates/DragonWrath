#pragma once


#include <DragonWrath/Entities/PowerUps/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace PowerUps
      {
         class ExtraLife : public DragonWrath::Entities::PowerUps::Base
         {
         public:
            ExtraLife(ElementID *parent, float x, float y);
            ~ExtraLife();
         };
      }
   }
}


