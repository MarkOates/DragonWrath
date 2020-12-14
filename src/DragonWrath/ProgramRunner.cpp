#include <DragonWrath/ProgramRunner.hpp>

#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Display.hpp>
#include <DragonWrath/GameplayScreen.hpp>
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

   DragonWrath::GameplayScreen gameplay_screen(framework);

   framework.initialize();
   display = framework.create_display(AllegroFlare::Display::RESOLUTION_HD_1080);

   screens.add(&gameplay_screen);

   framework.run_loop();

   std::cout << "DragonWrath exited the master loop successfully." << std::endl;
}

