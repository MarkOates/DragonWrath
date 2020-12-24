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
         public:
            Base(AllegroFlare::ElementID *parent, std::string type, float x, float y);
            ~Base();
         };
      }
   }
}

