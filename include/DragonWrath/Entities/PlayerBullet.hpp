#pragma once


#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      class PlayerBullet : public DragonWrath::Entities::Base
      {
      public:
         PlayerBullet(ElementID *parent, float x, float y);
         ~PlayerBullet();
      };
   }
}

