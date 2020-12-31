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
   , world(framework, this->user_event_emitter, "World of DragonWrath", { "level_1", "level_2", "level_3", "boss" })
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

void GameplayScreen::draw_you_have_won_banner()
{
   ALLEGRO_FONT *title_text_font = framework.font("ChronoTrigger.ttf 100");
   ALLEGRO_FONT *subtitle_text_font = framework.font("ChronoTrigger.ttf 60");

   std::string title_text = "--  CONGRATULATIONS  --";
   std::string subtitle_text = "You have won the game";

   ALLEGRO_COLOR text_color = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};

   float title_text_x = 1920 / 2;
   float title_text_y = 1080 / 2 - 150;

   float subtitle_text_x = 1920 / 2;
   float subtitle_text_y = 1080 / 2 + 100;

   al_draw_text(
      title_text_font,
      text_color,
      title_text_x,
      title_text_y,
      ALLEGRO_ALIGN_CENTER,
      title_text.c_str()
   );
   al_draw_text(
      subtitle_text_font,
      text_color,
      subtitle_text_x,
      subtitle_text_y,
      ALLEGRO_ALIGN_CENTER,
      subtitle_text.c_str()
   );
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


void GameplayScreen::update_player_dragon_shooting()
{
   DragonWrath::Entities::PlayerDragon *player_dragon = get_player_dragon();
   if (!player_dragon) return;

   if (player_dragon->has_weapon())
   {
      DragonWrath::Weapons::Base *weapon = player_dragon->get_weapon();
      if (weapon) weapon->update();
   }
}


void GameplayScreen::update_hud()
{
   DragonWrath::SceneCollectionHelper collection_helper(current_level);
   DragonWrath::Entities::PlayerDragon *player_dragon = collection_helper.get_player_dragon();

   if (player_dragon && player_dragon->is_dead())
   {
      hud.activate_game_over_banner();
      user_event_emitter.emit_play_game_over_music();
   }
   else if (current_level && current_level->is_completed())
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
   update_player_dragon_shooting();
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

   if (!current_level)
   {
      draw_you_have_won_banner();
   }
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

   if (current_level && current_level->is_ready_to_destroy())
   {
      load_next_level();
   }
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
         std::stringstream error_message;
         error_message << "GameplayScreen::user_event_func(): "
            << "error: PLAYER_DRAGON_DIES_EVENT is not implemented"
            << std::endl;
         throw std::runtime_error(error_message.str());
      }
      break;
   default:
      break;
   }
}


} // GameplayScreen
} // DragonWrath

