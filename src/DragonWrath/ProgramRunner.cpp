#include <DragonWrath/ProgramRunner.hpp>

#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Display.hpp>
#include <DragonWrath/Screens/GameplayScreen.hpp>
#include <DragonWrath/Screens/TitleScreen.hpp>
#include <iostream>

DragonWrath::ProgramRunner::ProgramRunner()
{}

DragonWrath::ProgramRunner::~ProgramRunner()
{}

void DragonWrath::ProgramRunner::run()
{
   std::cout << "DragonWrath run started successfully." << std::endl;

   AllegroFlare::Display *display;
   AllegroFlare::Screens screens;
   AllegroFlare::Framework framework(screens);

   framework.initialize();
   display = framework.create_display(AllegroFlare::Display::RESOLUTION_HD_1080);


   DragonWrath::Screens::Base *current_screen = nullptr;

   
   {
      DragonWrath::Screens::TitleScreen *title_screen = new DragonWrath::Screens::TitleScreen(framework);
      current_screen = title_screen;
   }
   {
      //DragonWrath::Screens::GameplayScreen *gameplay_screen =
         //new DragonWrath::Screens::GameplayScreen(framework);
      //gameplay_screen->initialize();
      //current_screen = gameplay_screen;
   }


   screens.add(current_screen);

   framework.run_loop();

   std::cout << "DragonWrath exited the master loop successfully." << std::endl;
}

