#pragma once


#include <DragonWrath/Screens/Base.hpp>
#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/Levels/Base.hpp>
#include <DragonWrath/Worlds/Base.hpp>
#include <DragonWrath/Screens/GameplayScreenHud.hpp>
#include <DragonWrath/Entities/PlayerDragon.hpp>


namespace DragonWrath
{
   namespace Screens
   {
      class GameplayScreen : public DragonWrath::Screens::Base
      {
      private:
         AllegroFlare::Framework &framework;
         DragonWrath::Levels::Base *current_level;
         DragonWrath::Screens::GameplayScreenHud hud;
         DragonWrath::Worlds::Base world;

         int player_lives;
         int player_score;

         DragonWrath::Entities::PlayerDragon *get_player_dragon();

      public:
         GameplayScreen(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter);
         ~GameplayScreen();

         void initialize();

         void draw_you_have_won_banner();

         void load_next_level();

         void primary_timer_func() override;
         void key_down_func(ALLEGRO_EVENT *ev) override;
         void key_up_func(ALLEGRO_EVENT *ev) override;
         void user_event_func(ALLEGRO_EVENT *ev) override;
      };
   }
}
