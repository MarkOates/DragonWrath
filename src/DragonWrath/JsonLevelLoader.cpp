
#include <DragonWrath/JsonLevelLoader.hpp>

#include <DragonWrath/Levels/TimedScroll.hpp>
#include <nlohmann/json.hpp>
#include <sstream>

// for convenience
using json = nlohmann::json;


static std::string type_as_string(json::value_t type)
{
   if (type == json::value_t::null) { return "json::value_t::null"; }
   if (type == json::value_t::boolean) { return "json::value_t::boolean"; }
   if (type == json::value_t::number_integer) { return "json::value_t::number_integer"; }
   if (type == json::value_t::number_unsigned) { return "json::value_t::number_unsigned"; }
   if (type == json::value_t::number_float) { return "json::value_t::number_float"; }
   if (type == json::value_t::object) { return "json::value_t::object"; }
   if (type == json::value_t::array) { return "json::value_t::array"; }
   if (type == json::value_t::string) { return "json::value_t::string"; }
   else
   {
      std::stringstream error_message;
      error_message << "JsonLevelLoader::type_as_string() error: Unidentified type \"" << (int)type << "\"";
      throw std::runtime_error(error_message.str());
   }
}


static float get_or_default_float(json j, std::string key, float default_value)
{
   if (!j.contains(key)) return default_value;
   if (!j[key].is_number())
   {
      std::stringstream error_message;
      error_message << "JsonLevelLoader::get_or_default_float() error: At key \""
         << key
         << "\" expecting type float, but is \""
         << type_as_string(j[key].type())
         << "\"";
      throw std::runtime_error(error_message.str());
   }
   return j[key].get<double>();
}


static float get_or_raise_float(json j, std::string key)
{
   if (!j.contains(key))
   {
      std::stringstream error_message;
      error_message << "JsonLevelLoader::get_or_default_float() error: At key \""
         << key
         << "\" expecting type float, but is \""
         << type_as_string(j[key].type())
         << "\"";
      throw std::runtime_error(error_message.str());
   }
   return j[key].get<double>();
}


static std::string get_or_default_string(json j, std::string key, std::string default_value)
{
   if (!j.contains(key)) return default_value;
   if (!j[key].is_string())
   {
      std::stringstream error_message;
      error_message << "JsonLevelLoader::get_or_default_string() error: At key \""
         << key
         << "\" expecting type string, but is \""
         << type_as_string(j[key].type())
         << "\"";
      throw std::runtime_error(error_message.str());
   }
   return j[key].get<std::string>();
}


static std::string get_or_raise_string(json j, std::string key)
{
   if (!j.contains(key))
   {
      std::stringstream error_message;
      error_message << "JsonLevelLoader::get_or_default_string() error: At key \""
         << key
         << "\" expecting type string, but is \""
         << type_as_string(j[key].type())
         << "\"";
      throw std::runtime_error(error_message.str());
   }
   return j[key].get<std::string>();
}


namespace DragonWrath
{


JsonLevelLoader::JsonLevelLoader()
   : output_loading_debug_to_cout(false)
{
}


JsonLevelLoader::~JsonLevelLoader()
{
}


DragonWrath::Levels::TimedScroll *JsonLevelLoader::create_timed_scroll_from_source(
      std::string source_json,
      AllegroFlare::Framework &framework,
      DragonWrath::UserEventEmitter &user_event_emitter
   )
{
   // parse the json source into an object

   json j = json::parse(source_json);


   // grab the type

   std::string type = get_or_raise_string(j, "type");
   if (type != "TimedScroll")
   {
      std::stringstream error_message;
      error_message << "JsonLevelLoader::create_from_source() expecting \"type\" to be \"TimedScroll\" but is \"" << type << "\"";
      throw std::runtime_error(error_message.str());
   }


   // grab the duration

   float duration = get_or_raise_float(j, "duration");
   if (output_loading_debug_to_cout) std::cout << "duration: " << duration << std::endl;


   // assemble the list of enemies to spawn

   std::vector<EnemyToSpawn> enemies_to_spawn_result = {};
   if (j.contains("enemies"))
   {
      json enemies = j["enemies"];
      if (output_loading_debug_to_cout) std::cout << "enemies: " << enemies.size() << std::endl;
      for (json::iterator it = enemies.begin(); it != enemies.end(); ++it)
      {
         float spawn_time = get_or_raise_float((*it), "spawn_time");
         std::string type = get_or_raise_string((*it), "type");
         float spawn_x = get_or_raise_float((*it), "spawn_x");
         float spawn_y = get_or_raise_float((*it), "spawn_y");
         std::string movement_strategy = get_or_raise_string((*it), "movement_strategy");

         if (output_loading_debug_to_cout)
         {
            std::cout << "- spawn_time: " << spawn_time << std::endl;
            std::cout << "  type: " << type << std::endl;
            std::cout << "  spawn_x: " << spawn_x << std::endl;
            std::cout << "  spawn_y: " << spawn_y << std::endl;
            std::cout << "  movement_strategy: " << movement_strategy << std::endl;
         }

         enemies_to_spawn_result.push_back(EnemyToSpawn(spawn_time, type, spawn_x, spawn_y, movement_strategy));
      }
   }

   // create the level

   DragonWrath::Levels::TimedScroll *created_level =
      new DragonWrath::Levels::TimedScroll(framework, user_event_emitter, duration, enemies_to_spawn_result);

   return created_level;
}


} // DragonWrath


