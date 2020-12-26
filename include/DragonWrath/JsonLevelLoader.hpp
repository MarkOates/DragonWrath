#pragma once

#include <string>
#include <DragonWrath/Levels/TimedScroll.hpp>

namespace DragonWrath
{
   class JsonLevelLoader
   {
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
