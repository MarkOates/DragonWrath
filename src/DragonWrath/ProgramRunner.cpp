#include <DragonWrath/ProgramRunner.hpp>

#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Display.hpp>
#include <DragonWrath/ScreenManager.hpp>
#include <iostream>

#include <DragonWrath/MusicAndSoundEffectTrackNames.hpp> // for AudioRepositoryElement


DragonWrath::ProgramRunner::ProgramRunner()
{}

DragonWrath::ProgramRunner::~ProgramRunner()
{}

void DragonWrath::ProgramRunner::run()
{
   AllegroFlare::Display *display;
   AllegroFlare::Screens screens;
   AllegroFlare::Framework framework(screens);

   framework.initialize();
   display = framework.create_display(AllegroFlare::Display::RESOLUTION_HD_1080);

   std::map<std::string, AudioRepositoryElement> music_track_elements = std::map<std::string, AudioRepositoryElement>{
         { TITLE_SCREEN_MUSIC, { "TitleScreen - With Edit - 01.ogg", false } },
         { LEVEL_1_MUSIC, { "02 sawsquarenoise - Stage 1.ogg", true } },
         { GAME_OVER_SCREEN_MUSIC, { "05 sawsquarenoise - Boss Splash.ogg", false } },
         { GAME_WON_SCREEN_MUSIC, { "sawsquarenoise_-_10_-_Towel_Defence_Ending.ogg", false } },
         { FINAL_BOSS_MUSIC, { "Boss Theme.ogg", true } },
      };
   std::map<std::string, AudioRepositoryElement> sound_effect_elements = std::map<std::string, AudioRepositoryElement>{
         { PLAYER_SHOOT_BULLET_SOUND_EFFECT, { "sfx_wpn_laser8.wav", false } },
         { ENEMY_TAKES_HIT_SOUND_EFFECT, { "sfx_wpn_punch3.wav", false } },
         { ENEMY_EXPLOSION_SOUND_EFFECT, { "sfx_wpn_punch4.wav", false } },
         { BULLET_DEFLECTED_SOUND_EFFECT, { "sfx_wpn_noammo1.wav", false } },
      };

   DragonWrath::ScreenManager *screen_manager = new DragonWrath::ScreenManager(framework, screens, music_track_elements, sound_effect_elements);
   screen_manager->initialize();

   screens.add(screen_manager);

   screen_manager->load_initial_screen();

   framework.run_loop();

   delete screen_manager;
}

