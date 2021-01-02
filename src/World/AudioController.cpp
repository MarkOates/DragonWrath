


#include <World/AudioController.hpp>

//#include <DragonWrath/MusicTrackNames.hpp>
//#include <framework/framework.hpp>


namespace World
{


AudioController::AudioController(AllegroFlare::SampleBin &sample_bin,
      std::map<std::string, AudioRepositoryElement> music_track_elements,
      std::map<std::string, AudioRepositoryElement> sound_effect_elements
   )
   : sample_bin(sample_bin)
   , sound_effects_identifier_prefix("sound_effects/")
   , music_tracks_identifier_prefix("music_tracks/")
   , sound_effect_elements(sound_effect_elements)
   , music_track_elements(music_track_elements)
   , sound_effects()
   , music_tracks()
   , current_music_track_identifier("")
   , global_volume(0.1)
   , output_loading_debug_to_cout(false)
{
}


AudioController::~AudioController()
{
   stop_all();

   for (auto &sound_effect : sound_effects) delete sound_effect.second;
   for (auto &music_track : music_tracks) delete music_track.second;
}


void AudioController::initialize()
{
   if (output_loading_debug_to_cout) std::cout << "Loading assets in AudioController... " << std::endl;
   if (output_loading_debug_to_cout) std::cout << "sound_effects:" << std::endl;
   for (auto &sound_effect_element : sound_effect_elements)
   {
      std::string identifier = sound_effect_element.first;
      std::string filename = sound_effect_element.second.filename;
      bool loop = sound_effect_element.second.loop;

      std::string asset_key = sound_effects_identifier_prefix + filename;

      if (output_loading_debug_to_cout) std::cout << "- asset_key: " << asset_key << std::endl;

      ALLEGRO_SAMPLE *sample = sample_bin.auto_get(asset_key);
      Sound *sound = new Sound(sample);
      sound->loop(loop);
      sound->volume(global_volume);

      // TODO manage case where identifier already exists for this record

      sound_effects[identifier] = sound;
   }
   if (output_loading_debug_to_cout) std::cout << "music_tracks:" << std::endl;
   for (auto &music_track_element : music_track_elements)
   {
      std::string identifier = music_track_element.first;
      std::string filename = music_track_element.second.filename;
      bool loop = music_track_element.second.loop;

      std::string asset_key = music_tracks_identifier_prefix + filename;

      if (output_loading_debug_to_cout) std::cout << "- asset_key: " << asset_key << std::endl;

      ALLEGRO_SAMPLE *sample = sample_bin.auto_get(asset_key);
      Sound *sound = new Sound(sample);
      sound->loop(loop);
      sound->volume(global_volume);

      // TODO manage case where identifier already exists for this record

      music_tracks[identifier] = sound;
   }
}


void AudioController::stop_all()
{
   for (auto &sound_effect : sound_effects) sound_effect.second->stop();
   for (auto &music_track : music_tracks) music_track.second->stop();

   current_music_track_identifier = "";
}


Sound *AudioController::find_sound_effect_by_identifier(std::string identifier)
{
   std::map<std::string, Sound*>::iterator it = sound_effects.find(identifier);
   if (it == sound_effects.end())
   {
      std::cout << "AudioController::play_sound_effect_by_identifier() error: "
         << "unable to find element with identifier \""
         << identifier
         << "\""
         << std::endl;
      return nullptr;
   }

   return it->second;
}


Sound *AudioController::find_music_track_by_identifier(std::string identifier)
{
   std::map<std::string, Sound*>::iterator it = music_tracks.find(identifier);
   if (it == sound_effects.end())
   {
      std::cout << "AudioController::play_music_track_by_identifier() error: "
         << "unable to find element with identifier \""
         << identifier
         << "\""
         << std::endl;
      return nullptr;
   }

   return it->second;
}


void AudioController::set_global_volume(float volume)
{
   for (auto &sound_effect : sound_effects) sound_effect.second->volume(global_volume);
   for (auto &music_track : music_tracks) music_track.second->volume(global_volume);
}


void AudioController::play_music_track_by_identifier(std::string identifier)
{
   if (identifier == current_music_track_identifier) return;

   stop_all();

   Sound *sound = find_music_track_by_identifier(identifier);
   if (sound) sound->play();
}


void AudioController::play_sound_effect_by_identifier(std::string identifier)
{
   Sound *sound = find_sound_effect_by_identifier(identifier);
   if (sound) sound->play();
}


} // World


