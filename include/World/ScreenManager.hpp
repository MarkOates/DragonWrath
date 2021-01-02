#pragma once


#include <AllegroFlare/Screen.hpp>
#include <AllegroFlare/Framework.hpp>
#include <World/EventEmitter.hpp>
#include <World/AudioController.hpp>
#include <World/ScreenFactory.hpp>


namespace World
{
   class ScreenManager : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Framework &framework;
      AllegroFlare::Screens &screens;
      AllegroFlare::Screen *current_screen;
      ALLEGRO_EVENT_SOURCE event_emitter_souce;
      World::EventEmitter event_emitter;
      World::AudioController audio_controller;
      World::ScreenFactory *screen_factory;
      std::string initial_screen_identifier;

   public:
      ScreenManager(
            AllegroFlare::Framework &framework,
            AllegroFlare::Screens &screens,
            std::map<std::string, AudioRepositoryElement> music_track_elements={},
            std::map<std::string, AudioRepositoryElement> sound_effect_elements={},
            World::ScreenFactory *screen_factory=nullptr,
            std::string initial_screen_identifier="uninitialized-initial-screen-identifier"
         );
      ~ScreenManager();

      void start() override;

      void initialize() override;

      void user_event_func(ALLEGRO_EVENT *ev) override;
   };
}



