#pragma once


#include <DragonWrath/UserEventEmitter.hpp>


namespace DragonWrath
{
   namespace Weapons
   {
      class Base
      {
      private:
         DragonWrath::UserEventEmitter &user_event_emitter;

      public:
         Base(DragonWrath::UserEventEmitter &user_event_emitter);
         ~Base();

         virtual void activate();
         virtual void deactivate();
         virtual void update();
      };
   }
}




