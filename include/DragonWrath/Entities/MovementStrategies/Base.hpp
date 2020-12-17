#pragma once


namespace DragonWrath
{
   namespace Entities
   {
      namespace MovementStrategy
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



