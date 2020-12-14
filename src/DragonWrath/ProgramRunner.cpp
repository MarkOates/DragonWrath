#include <DragonWrath/ProgramRunner.hpp>

#include <iostream>

DragonWrath::ProgramRunner::ProgramRunner()
   : display(nullptr)
   , screens()
   , framework(screens)
   , gameplay_screen(framework)
{
   std::cout << "DragonWrath initialized successfully." << std::endl;
}

DragonWrath::ProgramRunner::~ProgramRunner()
{
}

void DragonWrath::ProgramRunner::run()
{
   framework.initialize();
   display = framework.create_display(AllegroFlare::Display::RESOLUTION_HD_1080);

   screens.add(&gameplay_screen);

   framework.run_loop();

   std::cout << "DragonWrath exited the master loop successfully." << std::endl;
}

