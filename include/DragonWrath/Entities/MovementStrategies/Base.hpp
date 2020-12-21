#pragma once


namespace DragonWrath
{
   namespace Entities
   {
      namespace MovementStrategies
      {
         class Base
         {
         public:
            Base();
            virtual ~Base();

            virtual void update();
         };
      }
   }
}


