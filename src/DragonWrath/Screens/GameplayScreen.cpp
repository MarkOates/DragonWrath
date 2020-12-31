#include <DragonWrath/Screens/GameplayScreen.hpp>

#include <DragonWrath/Entities/Base.hpp>
#include <DragonWrath/Weapons/Base.hpp>
#include <DragonWrath/Weapons/BasicRefire.hpp>
#include <DragonWrath/Weapons/FastRefire.hpp>
#include <DragonWrath/Weapons/FastRefireWithAngledOut.hpp>
#include <DragonWrath/Weapons/TwinFastRefire.hpp>
#include <DragonWrath/SceneCollectionHelper.hpp>
#include <DragonWrath/EntityAttributeNames.hpp>
#include <DragonWrath/LevelTypeNames.hpp>
#include <DragonWrath/EntityFactory.hpp>
#include <DragonWrath/LevelFactory.hpp>
#include <AllegroFlare/Useful.hpp>
#include <DragonWrath/Levels/TimedScroll.hpp>
#include <DragonWrath/UserEventEmitter.hpp>
#include <DragonWrath/UserEventNames.hpp>


namespace DragonWrath
{
namespace Screens
{


GameplayScreen::GameplayScreen(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter)
   : DragonWrath::Screens::Base()
   , framework(framework)
   , user_event_emitter(user_event_emitter)
   , current_level(nullptr)
   , hud(framework)
   , world(framework, this->user_event_emitter, "World of DragonWrath", { "level_1", "boss" })
   , player_lives(3)
   , player_score(0)
{
}

GameplayScreen::~GameplayScreen()
{
}

DragonWrath::Entities::PlayerDragon *GameplayScreen::get_player_dragon()
{
   if (current_level)
   {
      DragonWrath::SceneCollectionHelper collection_helper(current_level);
      DragonWrath::Entities::PlayerDragon *player_dragon = collection_helper.get_player_dragon();
      if (player_dragon) return player_dragon;
   }
   return nullptr;
}

void GameplayScreen::initialize()
{
   load_next_level();
}

void GameplayScreen::dequip_upgrade_and_equp_weapon_upgrade_on_player_dragon()
{
   DragonWrath::Entities::PlayerDragon *player_dragon = get_player_dragon();
   if (!player_dragon) return;
   if (player_dragon->is_bullet_level_at_max()) return;

   if (player_dragon->has_weapon())
   {
      DragonWrath::Weapons::Base *weapon = player_dragon->get_weapon();
      player_dragon->dequip_weapon();
      delete weapon;
   }

   player_dragon->increment_bullet_level();

   int player_weapon_level = player_dragon->get_bullet_level();
   DragonWrath::Weapons::Base *weapon_to_equip = nullptr;
   switch (player_weapon_level)
   {
   case 0:
      weapon_to_equip = new DragonWrath::Weapons::BasicRefire(player_dragon, user_event_emitter);
      break;
   case 1:
      weapon_to_equip = new DragonWrath::Weapons::FastRefire(player_dragon, user_event_emitter);
      break;
   case 2:
      weapon_to_equip = new DragonWrath::Weapons::FastRefireWithAngledOut(player_dragon, user_event_emitter);
      break;
   case 3:
      weapon_to_equip = new DragonWrath::Weapons::TwinFastRefire(player_dragon, user_event_emitter);
      break;
   default:
      {
         std::stringstream error_message;
         error_message << "GameplayScreen::dequip_upgrade_and_equp_weapon_upgrade_on_player_dragon(): "
            << "error: unrecognized player_weapon_level of \""
            << player_weapon_level
            << "\""
            << std::endl;
         throw std::runtime_error(error_message.str());
      }
      break;
   }

   if (weapon_to_equip)
   {
      player_dragon->equip_weapon(weapon_to_equip);
   }
}

void GameplayScreen::restart_current_level()
{
   hud.deactivate_all_banners();
   current_level = world.reload_current_level();
   user_event_emitter.emit_stop_all_music_and_sound_effects_event();
   user_event_emitter.emit_play_level_1_music_event();
}


void GameplayScreen::load_next_level()
{
   hud.deactivate_all_banners();
   current_level = world.create_next_level_and_destroy_current();
   user_event_emitter.emit_stop_all_music_and_sound_effects_event();
   user_event_emitter.emit_play_level_1_music_event();
}


void GameplayScreen::update_current_level()
{
   // update the player dragon's weapon
   DragonWrath::Entities::PlayerDragon *player_dragon = get_player_dragon();
   if (!player_dragon) return;

   if (player_dragon->has_weapon())
   {
      DragonWrath::Weapons::Base *weapon = player_dragon->get_weapon();
      if (weapon) weapon->update();
   }

   // update the current level
   if (current_level) current_level->update();
}


void GameplayScreen::update_achievements()
{
   DragonWrath::Entities::PlayerDragon *player_dragon = get_player_dragon();

   // check if we need to load the next level
   if (current_level && current_level->is_ready_to_destroy())
   {
      user_event_emitter.emit_load_next_level_event();
   }

   // check if the player dragon is dead
   if (player_dragon && player_dragon->is_dead()) // <---- sloppy
   {
      user_event_emitter.emit_player_dragon_dies_event();
   }

   // check if the game has been won
   if (!current_level)
   {
      user_event_emitter.emit_game_won_event(); // <---- also sloppy, this assumes the game won event is captured
                                                //       otherwise this will continue to emit repeatedly
   }
}


void GameplayScreen::update_hud()
{
   DragonWrath::SceneCollectionHelper collection_helper(current_level);
   DragonWrath::Entities::PlayerDragon *player_dragon = collection_helper.get_player_dragon();

   if (current_level && current_level->is_completed())
   {
      hud.activate_level_complete_banner();
   }

   hud.set_player_lives(this->player_lives);

   if (player_dragon)
   {
      hud.set_player_shield_level(player_dragon->get_shield_level());
      hud.set_player_bullet_level(player_dragon->get_bullet_level());
      hud.set_player_speed_level(player_dragon->get_speed_level());
      hud.set_player_option_level(player_dragon->get_option_level());
   }

   hud.set_player_score(this->player_score);

   if (current_level && current_level->is_type(TIMED_SCROLL))
   {
      DragonWrath::Levels::TimedScroll *timed_scroll_level =
         static_cast<DragonWrath::Levels::TimedScroll *>(current_level);
      float level_scroll_timer = timed_scroll_level->get_timer();
      hud.debug__set_level_scroll_timer(level_scroll_timer);

      float level_progress_position = timed_scroll_level->calculate_level_progress_percentage();
      hud.set_level_progress_position(level_progress_position);
   }
}


void GameplayScreen::update()
{
   update_current_level();
   update_achievements();
   update_hud();
}


void GameplayScreen::draw()
{
   al_clear_to_color(AllegroFlare::color::black);

   if (current_level)
   {
      current_level->draw();
   }

   hud.draw();
}


void GameplayScreen::cleanup()
{
   if (current_level)
   {
      current_level->cleanup();
   }
}


void GameplayScreen::primary_timer_func()
{
   update();
   draw();
   cleanup();
}


void GameplayScreen::key_down_func(ALLEGRO_EVENT *ev)
{
   DragonWrath::SceneCollectionHelper scene_collection_helper(current_level);
   Entities::PlayerDragon *player_dragon = scene_collection_helper.get_player_dragon();

   DragonWrath::EntityFactory entity_factory(framework, current_level);

   switch(ev->keyboard.keycode)
   {
   case ALLEGRO_KEY_UP:
      if (player_dragon) player_dragon->velocity.y = -player_dragon->calculate_max_velocity();
      break;
   case ALLEGRO_KEY_DOWN:
      if (player_dragon) player_dragon->velocity.y = player_dragon->calculate_max_velocity();
      break;
   case ALLEGRO_KEY_LEFT:
      if (player_dragon) player_dragon->velocity.x = -player_dragon->calculate_max_velocity();
      break;
   case ALLEGRO_KEY_RIGHT:
      if (player_dragon) player_dragon->velocity.x = player_dragon->calculate_max_velocity();
      break;
   case ALLEGRO_KEY_SPACE:
      if (player_dragon && player_dragon->has_weapon())
      {
         DragonWrath::Weapons::Base *weapon = player_dragon->get_weapon();
         if (weapon) weapon->activate();
      }
      break;
   case ALLEGRO_KEY_ESCAPE:
      framework.shutdown_program = true;
      break;
   default:
      break;
   }
}

void GameplayScreen::key_up_func(ALLEGRO_EVENT *ev)
{
   Entities::PlayerDragon *player_dragon = get_player_dragon();

   switch(ev->keyboard.keycode)
   {
   case ALLEGRO_KEY_UP:
      if (player_dragon) player_dragon->velocity.y = 0;
      break;
   case ALLEGRO_KEY_DOWN:
      if (player_dragon) player_dragon->velocity.y = 0;
      break;
   case ALLEGRO_KEY_LEFT:
      if (player_dragon) player_dragon->velocity.x = 0;
      break;
   case ALLEGRO_KEY_RIGHT:
      if (player_dragon) player_dragon->velocity.x = 0;
      break;
   case ALLEGRO_KEY_SPACE:
      if (player_dragon && player_dragon->has_weapon())
      {
         DragonWrath::Weapons::Base *weapon = player_dragon->get_weapon();
         if (weapon) weapon->deactivate();
      }
      break;
   default:
      break;
   }
}


void GameplayScreen::user_event_func(ALLEGRO_EVENT *ev)
{
   switch (ev->type)
   {
   case SPAWN_PLAYER_BULLET_EVENT:
      {
         if (current_level)
         {
            DragonWrath::EntityFactory entity_factory(framework, current_level);
            float spawn_x = ev->user.data1;
            float spawn_y = ev->user.data2;
            entity_factory.create_player_bullet(spawn_x, spawn_y);
         }
      }
      break;
   case INCREASE_PLAYER_SCORE_EVENT:
      {
         int points_to_add = ev->user.data1;
         player_score += points_to_add;
      }
      break;
   case SPAWN_EXTRA_LIFE_POWER_UP_EVENT:
      {
         if (current_level)
         {
            DragonWrath::EntityFactory entity_factory(framework, current_level);
            float spawn_x = ev->user.data1;
            float spawn_y = ev->user.data2;
            entity_factory.create_extra_life(spawn_x, spawn_y);
         }
      }
      break;
   case SPAWN_SPEED_BOOST_POWER_UP_EVENT:
      {
         if (current_level)
         {
            DragonWrath::EntityFactory entity_factory(framework, current_level);
            float spawn_x = ev->user.data1;
            float spawn_y = ev->user.data2;
            entity_factory.create_speed_boost(spawn_x, spawn_y);
         }
      }
      break;
   case SPAWN_BULLET_BOOST_POWER_UP_EVENT:
      {
         if (current_level)
         {
            DragonWrath::EntityFactory entity_factory(framework, current_level);
            float spawn_x = ev->user.data1;
            float spawn_y = ev->user.data2;
            entity_factory.create_bullet_boost(spawn_x, spawn_y);
         }
      }
      break;
   case SPAWN_SHIELD_BOOST_POWER_UP_EVENT:
      {
         if (current_level)
         {
            DragonWrath::EntityFactory entity_factory(framework, current_level);
            float spawn_x = ev->user.data1;
            float spawn_y = ev->user.data2;
            entity_factory.create_shield_boost(spawn_x, spawn_y);
         }
      }
      break;
   case SPAWN_OPTION_BOOST_POWER_UP_EVENT:
      {
         if (current_level)
         {
            DragonWrath::EntityFactory entity_factory(framework, current_level);
            float spawn_x = ev->user.data1;
            float spawn_y = ev->user.data2;
            entity_factory.create_option_boost(spawn_x, spawn_y);
         }
      }
      break;
   case SPAWN_SLASH_POOF_EVENT:
      {
         if (current_level)
         {
            DragonWrath::EntityFactory entity_factory(framework, current_level);
            float spawn_x = ev->user.data1;
            float spawn_y = ev->user.data2;
            entity_factory.create_slash_poof(spawn_x, spawn_y);
         }
      }
      break;
   case PLAYER_DRAGON_GETS_EXTRA_LIFE_EVENT:
      {
         player_lives++;
      }
      break;
   case PLAYER_DRAGON_GETS_SHIELD_BOOST_EVENT:
      {
         DragonWrath::Entities::PlayerDragon *player_dragon = get_player_dragon();
         if (player_dragon) player_dragon->increment_shield_level();
      }
      break;
   case PLAYER_DRAGON_GETS_BULLET_BOOST_EVENT:
      {
         DragonWrath::Entities::PlayerDragon *player_dragon = get_player_dragon();
         if (player_dragon) dequip_upgrade_and_equp_weapon_upgrade_on_player_dragon();
      }
      break;
   case PLAYER_DRAGON_GETS_SPEED_BOOST_EVENT:
      {
         DragonWrath::Entities::PlayerDragon *player_dragon = get_player_dragon();
         if (player_dragon) player_dragon->increment_speed_level();
      }
      break;
   case PLAYER_DRAGON_GETS_OPTION_BOOST_EVENT:
      {
         DragonWrath::Entities::PlayerDragon *player_dragon = get_player_dragon();
         if (player_dragon) player_dragon->increment_option_level();
      }
      break;
   case PLAYER_DRAGON_DIES_EVENT:
      {
         if (player_lives <= 0)
         {
            user_event_emitter.emit_game_over_event();
         }
         else
         {
            player_lives--;
            user_event_emitter.emit_restart_current_level_event();
         }
      }
      break;
   case RESTART_CURRENT_LEVEL_EVENT:
      {
         restart_current_level();
      }
      break;
   case LOAD_NEXT_LEVEL_EVENT:
      {
         load_next_level();
      }
      break;
   default:
      break;
   }
}


} // GameplayScreen
} // DragonWrath

