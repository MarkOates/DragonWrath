
//#include <DragonWrath/ProgramRunner.hpp>

#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Display.hpp>
#include <World/ScreenManager.hpp>
#include <World/BasicScreens/Factory.hpp>
#include <World/EventEmitter.hpp>
#include <iostream>


namespace MyGame
{
   static std::map<std::string, AudioRepositoryElement> MUSIC_TRACK_ELEMENTS = std::map<std::string, AudioRepositoryElement>{
      { "TITLE_SCREEN_MUSIC", { "TitleScreen - With Edit - 01.ogg", false } },
      { "LEVEL_1_MUSIC", { "02 sawsquarenoise - Stage 1.ogg", true } },
      { "GAME_OVER_SCREEN_MUSIC", { "05 sawsquarenoise - Boss Splash.ogg", false } },
      { "GAME_WON_SCREEN_MUSIC", { "sawsquarenoise_-_10_-_Towel_Defence_Ending.ogg", false } },
      { "FINAL_BOSS_MUSIC", { "Boss Theme.ogg", true } },
   };
   static std::map<std::string, AudioRepositoryElement> SOUND_EFFECT_ELEMENTS = std::map<std::string, AudioRepositoryElement>{
      { "PLAYER_SHOOT_BULLET_SOUND_EFFECT", { "sfx_wpn_laser8.wav", false } },
         { "ENEMY_TAKES_HIT_SOUND_EFFECT", { "sfx_wpn_punch3.wav", false } },
         { "ENEMY_EXPLOSION_SOUND_EFFECT", { "sfx_wpn_punch4.wav", false } },
         { "BULLET_DEFLECTED_SOUND_EFFECT", { "sfx_wpn_noammo1.wav", false } },
   };

   std::string const MY_MAIN_SCREEN_IDENTIFIER = "MyMainScreen";
   std::string const MY_OTHER_SCREEN_IDENTIFIER = "MyOtherScreen";

   class MyMainScreen : public AllegroFlare::Screen
   {
   private:
      World::EventEmitter &event_emitter;

   public:
      MyMainScreen(World::EventEmitter &event_emitter)
        : event_emitter(event_emitter)
      {}
      ~MyMainScreen() {}

      void primary_timer_func() override
      {
         std::cout << "Woo!" << std::endl;
      }

      void key_down_func(ALLEGRO_EVENT *ev) override
      {
         event_emitter.emit_start_screen_by_identifier(MY_OTHER_SCREEN_IDENTIFIER);
      }
   };

   class MyOtherScreen : public AllegroFlare::Screen
   {
   private:
      World::EventEmitter &event_emitter;

   public:
      MyOtherScreen(World::EventEmitter &event_emitter)
         : event_emitter(event_emitter)
      {}
      ~MyOtherScreen() {}

      void primary_timer_func() override
      {
         std::cout << "Howdy!" << std::endl;
      }

      void key_down_func(ALLEGRO_EVENT *ev) override
      {
         event_emitter.emit_start_screen_by_identifier(MY_MAIN_SCREEN_IDENTIFIER);
      }
   };

   class ScreenFactory : public World::ScreenFactory
   {
   private:
      World::EventEmitter &event_emitter;

   public:
      ScreenFactory(World::EventEmitter &event_emitter)
         : World::ScreenFactory()
         , event_emitter(event_emitter)
      {}
      ~ScreenFactory()
      {}

      AllegroFlare::Screen *create_from_identifier(std::string identifier) override
      {
         if (identifier == MY_MAIN_SCREEN_IDENTIFIER) return new MyMainScreen(event_emitter);
         if (identifier == MY_OTHER_SCREEN_IDENTIFIER) return new MyOtherScreen(event_emitter);

         std::stringstream error_message;
         error_message
            << "MyGame::ScreenFactory::create_from_identifier(): error: "
            << "unrecognized identifier \""
            << identifier
            << "\"";
         throw std::runtime_error(error_message.str());
      }
   };

   class ProgramConfig
   {
   public:
      std::map<std::string, AudioRepositoryElement> music_track_elements;
      std::map<std::string, AudioRepositoryElement> sound_effect_elements;
      MyGame::ScreenFactory screen_factory;

      ProgramConfig(AllegroFlare::Display *display, World::EventEmitter &event_emitter)
         : music_track_elements(MUSIC_TRACK_ELEMENTS)
         , sound_effect_elements(SOUND_EFFECT_ELEMENTS)
         , screen_factory(event_emitter)
      {}
      ~ProgramConfig() {}
   };
}


int main(int argc, char **argv)
{
   AllegroFlare::Display *display;
   AllegroFlare::Screens screens;
   AllegroFlare::Framework framework(screens);

   framework.initialize();
   display = framework.create_display(AllegroFlare::Display::RESOLUTION_HD_1080);

   // these two lists are essentially a fragment of a master config:

   ALLEGRO_EVENT_SOURCE event_emitter_source;
   World::EventEmitter event_emitter(event_emitter_source);

   MyGame::ProgramConfig program_config(display, event_emitter);

   al_init_user_event_source(&event_emitter_source);
   al_register_event_source(framework.event_queue, &event_emitter_source);

   World::ScreenManager *screen_manager = new World::ScreenManager(framework, screens, program_config.music_track_elements, program_config.sound_effect_elements, &event_emitter, &program_config.screen_factory, MyGame::MY_MAIN_SCREEN_IDENTIFIER);
   screen_manager->initialize();

   screens.add(screen_manager);
   screen_manager->start();

   framework.run_loop();

   delete screen_manager;

   return 0;
}


