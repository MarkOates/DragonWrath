#pragma once


#include <DragonWrath/Screens/Base.hpp>
#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/Levels/Base.hpp>
#include <DragonWrath/UserEventEmitter.hpp>
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
         DragonWrath::UserEventEmitter &user_event_emitter;
         DragonWrath::Levels::Base *current_level;
         DragonWrath::Screens::GameplayScreenHud hud;
         DragonWrath::Worlds::Base world;

         int player_lives;
         int player_score;

         DragonWrath::Entities::PlayerDragon *get_player_dragon();

         void update_current_level();
         void update_achievements();
         void update_hud();

         void update();
         void draw();
         void cleanup();


      public:
         GameplayScreen(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter);
         ~GameplayScreen();

         void initialize();

         void restart_current_level();
         void load_next_level();
         void dequip_upgrade_and_equp_weapon_upgrade_on_player_dragon();

         void primary_timer_func() override;
         void key_down_func(ALLEGRO_EVENT *ev) override;
         void key_up_func(ALLEGRO_EVENT *ev) override;
         void user_event_func(ALLEGRO_EVENT *ev) override;
      };
   }
}
