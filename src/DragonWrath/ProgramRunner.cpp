#include <DragonWrath/ProgramRunner.hpp>

#include <iostream>

DragonWrath::ProgramRunner::ProgramRunner()
   : screens()
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

   framework.run_loop();

   std::cout << "DragonWrath exited the master loop successfully." << std::endl;
}

