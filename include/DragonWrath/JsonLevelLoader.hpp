#pragma once

#include <string>
#include <DragonWrath/Levels/TimedScroll.hpp>

namespace DragonWrath
{
   class JsonLevelLoader
   {
   private:
      bool output_loading_debug_to_cout;

   public:
      JsonLevelLoader();
      ~JsonLevelLoader();

      DragonWrath::Levels::TimedScroll *create_timed_scroll_from_source(
         std::string source_json,
         AllegroFlare::Framework &framework,
         DragonWrath::UserEventEmitter &user_event_emitter
      );
   };
}
