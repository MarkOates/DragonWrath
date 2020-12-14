#include <DragonWrath/ProgramRunner.hpp>

#include <iostream>

DragonWrath::ProgramRunner::ProgramRunner(AllegroFlare::Framework &framework, AllegroFlare::Screens &screens)
   : framework(framework)
   , screens(screens)
   , gameplay_screen(framework)
{
   std::cout << "DragonWrath initialized successfully." << std::endl;
}

DragonWrath::ProgramRunner::~ProgramRunner()
{
}

