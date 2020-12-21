#pragma once


#include <AllegroFlare/Screen.hpp>
#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/Screens/Base.hpp>
#include <DragonWrath/UserEventEmitter.hpp>


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

   public:
      ScreenManager(AllegroFlare::Framework &framework, AllegroFlare::Screens &screens);
      ~ScreenManager();

      void load_initial_screen();

      void initialize();

      void key_down_func(ALLEGRO_EVENT *ev) override;
      void user_event_func(ALLEGRO_EVENT *ev) override;
   };
}


