#pragma once


#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace MotionFX
      {
         class Base : public DragonWrath::Entities::Base
         {
         protected:
            float duration;
            float counter;

         public:
            Base(ElementID *parent, std::string motion_fx_type, float x, float y, float duration);
            virtual ~Base();

            virtual void update();
         };
      }
   }
}


