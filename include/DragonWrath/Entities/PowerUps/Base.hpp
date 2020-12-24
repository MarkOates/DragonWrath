#pragma once


#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace PowerUps
      {
         class Base : public DragonWrath::Entities::Base
         {
         public:
            Base(ElementID *parent, std::string type, float x, float y);
            ~Base();
         };
      }
   }
}


