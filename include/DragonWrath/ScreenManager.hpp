#pragma once


#include <AllegroFlare/Screen.hpp>
#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/Screens/Base.hpp>
#include <DragonWrath/UserEventEmitter.hpp>
#include <DragonWrath/AudioController.hpp>


namespace DragonWrath
{
   class ScreenManager : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Framework &framework;
      AllegroFlare::Screens &screens;
      DragonWrath::Screens::Base *current_screen;
      ALLEGRO_EVENT_SOURCE screen_switcher_event_souce;
      DragonWrath::UserEventEmitter user_event_emitter;
      DragonWrath::AudioController audio_controller;

   public:
      ScreenManager(
            AllegroFlare::Framework &framework,
            AllegroFlare::Screens &screens,
            std::map<std::string, AudioRepositoryElement> music_track_elements={},
            std::map<std::string, AudioRepositoryElement> sound_effect_elements={}
         );
      ~ScreenManager();

      void load_initial_screen();

      void initialize();

      void key_down_func(ALLEGRO_EVENT *ev) override;
      void user_event_func(ALLEGRO_EVENT *ev) override;
   };
}


