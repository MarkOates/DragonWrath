#pragma once

#include <allegro5/allegro.h>
#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/GameplayScreen.hpp>

namespace DragonWrath
{
   class ProgramRunner
   {
   private: 
      AllegroFlare::Screens screens;
      AllegroFlare::Framework framework;
      DragonWrath::GameplayScreen gameplay_screen;

   public:
      ProgramRunner();
      ~ProgramRunner();

      void run();
   };
}

