#pragma once

#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/Levels/Base.hpp>
#include <DragonWrath/Entities/Base.hpp>
#include <DragonWrath/Entities/Enemies/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace Enemies
      {
         class SuperBoss : public DragonWrath::Entities::Enemies::Base
         {
         public:
            SuperBoss(AllegroFlare::ElementID *parent);
           ~SuperBoss();
         };
      }
   }
}

