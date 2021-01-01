#pragma once


#include <AllegroFlare/ElementID.hpp>
#include <DragonWrath/UserEventEmitter.hpp>


namespace DragonWrath
{
   namespace Levels
   {
      class Base : public AllegroFlare::ElementID
      {
      protected:
         DragonWrath::UserEventEmitter &user_event_emitter;
         virtual void update_level_specific_behavior() = 0;
         void update_collisions();
         float level_end_padding_timer;

      public:
         Base(std::string type, DragonWrath::UserEventEmitter &user_event_emitter);
         ~Base();

         void update();
         void draw();
         void cleanup();

         bool is_type(std::string type);
         virtual bool is_completed() = 0;
         bool is_ready_to_destroy();
      };
   }
}



