#pragma once


#include <AllegroFlare/Screen.hpp>
#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/Levels/Base.hpp>
#include <DragonWrath/Worlds/Base.hpp>
#include <DragonWrath/Screens/GameplayScreenHud.hpp>


namespace DragonWrath
{
   namespace Screens
   {
      class GameplayScreen : public AllegroFlare::Screen
      {
      private:
         AllegroFlare::Framework &framework;
         DragonWrath::Levels::Base *current_level;
         DragonWrath::Screens::GameplayScreenHud hud;
         DragonWrath::Worlds::Base world;

      public:
         GameplayScreen(AllegroFlare::Framework &framework);
         ~GameplayScreen();

         void initialize();

         void draw_you_have_won_banner();

         void load_next_level();

         void primary_timer_func() override;
         void key_down_func(ALLEGRO_EVENT *ev) override;
         void key_up_func(ALLEGRO_EVENT *ev) override;
      };
   }
}
