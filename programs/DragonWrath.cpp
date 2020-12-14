
#include <DragonWrath/ProgramRunner.hpp>

#include <iostream>

int main(int argc, char **argv)
{
   AllegroFlare::Screens screens;
   AllegroFlare::Framework framework(screens);

   DragonWrath::ProgramRunner program_runner(framework, screens);

   std::cout << "DragonWrath exited the master loop successfully." << std::endl;

   return 0;
}
