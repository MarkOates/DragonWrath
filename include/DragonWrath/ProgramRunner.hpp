#pragma once

#include <allegro5/allegro.h>
#include <AllegroFlare/Framework.hpp>

namespace DragonWrath
{
   class ProgramRunner : public AllegroFlare::Framework
   {
   private: 
      AllegroFlare::Screens screens;

   public:
      ProgramRunner();
      ~ProgramRunner();
   };
}

