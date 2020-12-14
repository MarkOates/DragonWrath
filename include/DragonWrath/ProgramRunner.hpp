#pragma once

#include <allegro5/allegro.h>
#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/GameplayScreen.hpp>

namespace DragonWrath
{
   class ProgramRunner
   {
   private: 
      AllegroFlare::Framework &framework;
      AllegroFlare::Screens &screens;
      DragonWrath::GameplayScreen gameplay_screen;

   public:
      ProgramRunner(AllegroFlare::Framework &framework, AllegroFlare::Screens &screens);
      ~ProgramRunner();
   };
}

