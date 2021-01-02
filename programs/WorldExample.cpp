
//#include <DragonWrath/ProgramRunner.hpp>

#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Display.hpp>
#include <World/ScreenManager.hpp>
#include <World/BasicScreens/Factory.hpp>
#include <iostream>


class ProgramConfig
{
public:
   std::map<std::string, AudioRepositoryElement> music_track_elements;
   std::map<std::string, AudioRepositoryElement> sound_effect_elements;
   World::BasicScreens::Factory basic_screen_factory;

   ProgramConfig(
      AllegroFlare::Display *display,
      std::map<std::string, AudioRepositoryElement> music_track_elements = std::map<std::string, AudioRepositoryElement>{
         { "TITLE_SCREEN_MUSIC", { "TitleScreen - With Edit - 01.ogg", false } },
         { "LEVEL_1_MUSIC", { "02 sawsquarenoise - Stage 1.ogg", true } },
         { "GAME_OVER_SCREEN_MUSIC", { "05 sawsquarenoise - Boss Splash.ogg", false } },
         { "GAME_WON_SCREEN_MUSIC", { "sawsquarenoise_-_10_-_Towel_Defence_Ending.ogg", false } },
         { "FINAL_BOSS_MUSIC", { "Boss Theme.ogg", true } },
      },
      std::map<std::string, AudioRepositoryElement> sound_effect_elements = std::map<std::string, AudioRepositoryElement>{
            { "PLAYER_SHOOT_BULLET_SOUND_EFFECT", { "sfx_wpn_laser8.wav", false } },
            { "ENEMY_TAKES_HIT_SOUND_EFFECT", { "sfx_wpn_punch3.wav", false } },
            { "ENEMY_EXPLOSION_SOUND_EFFECT", { "sfx_wpn_punch4.wav", false } },
            { "BULLET_DEFLECTED_SOUND_EFFECT", { "sfx_wpn_noammo1.wav", false } },
         }
   )
      : music_track_elements(music_track_elements)
      , sound_effect_elements(sound_effect_elements)
      , basic_screen_factory(display)
   {}

   ~ProgramConfig() {}
};


int main(int argc, char **argv)
{
   AllegroFlare::Display *display;
   AllegroFlare::Screens screens;
   AllegroFlare::Framework framework(screens);

   framework.initialize();
   display = framework.create_display(AllegroFlare::Display::RESOLUTION_HD_1080);

   // these two lists are essentially a fragment of a master config:

   ProgramConfig program_config(display);

   World::ScreenManager *screen_manager = new World::ScreenManager(framework, screens, program_config.music_track_elements, program_config.sound_effect_elements, &program_config.basic_screen_factory);
   screen_manager->initialize();

   screens.add(screen_manager);
   screen_manager->start();

   framework.run_loop();

   delete screen_manager;

   return 0;
}


