#include <DragonWrath/ProgramRunner.hpp>

#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Display.hpp>
#include <DragonWrath/ScreenManager.hpp>
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


   DragonWrath::ScreenManager *screen_manager = new DragonWrath::ScreenManager(framework, screens);
   screen_manager->initialize();

   screens.add(screen_manager);

   screen_manager->load_initial_screen();

   framework.run_loop();

   delete screen_manager;


   std::cout << "DragonWrath exited the master loop successfully." << std::endl;
}

