


#include <DragonWrath/AudioController.hpp>

//#include <DragonWrath/MusicTrackNames.hpp>
//#include <framework/framework.hpp>


namespace DragonWrath
{


AudioController::AudioController(AllegroFlare::SampleBin &sample_bin,
      std::vector<AudioRepositoryElement> music_track_elements,
      std::vector<AudioRepositoryElement> sound_effect_elements
   )
   : sample_bin(sample_bin)
   , sound_effects_identifier_prefix("sound_effects/")
   , music_tracks_identifier_prefix("music_tracks/")
   , sound_effect_elements(sound_effect_elements)
   , music_track_elements(music_track_elements)
   , sound_effects()
   , music_tracks()
   , current_music_track_id(-1)
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
      int id = sound_effect_element.id;
      std::string filename = sound_effect_element.filename;
      bool loop = sound_effect_element.loop;

      std::string asset_key = sound_effects_identifier_prefix + filename;

      if (output_loading_debug_to_cout) std::cout << "- asset_key: " << asset_key << std::endl;

      ALLEGRO_SAMPLE *sample = sample_bin.auto_get(asset_key);
      Sound *sound = new Sound(sample);
      sound->loop(loop);
      sound->volume(global_volume);

      // TODO manage case where id already exists for this record

      sound_effects[id] = sound;
   }
   if (output_loading_debug_to_cout) std::cout << "music_tracks:" << std::endl;
   for (auto &music_track_element : music_track_elements)
   {
      int id = music_track_element.id;
      std::string filename = music_track_element.filename;
      bool loop = music_track_element.loop;

      std::string asset_key = music_tracks_identifier_prefix + filename;

      if (output_loading_debug_to_cout) std::cout << "- asset_key: " << asset_key << std::endl;

      ALLEGRO_SAMPLE *sample = sample_bin.auto_get(asset_key);
      Sound *sound = new Sound(sample);
      sound->loop(loop);
      sound->volume(global_volume);

      // TODO manage case where id already exists for this record

      music_tracks[id] = sound;
   }
}


void AudioController::stop_all()
{
   for (auto &sound_effect : sound_effects) sound_effect.second->stop();
   for (auto &music_track : music_tracks) music_track.second->stop();

   current_music_track_id = -1;
}


Sound *AudioController::find_sound_effect_by_id(int id)
{
   std::map<int, Sound*>::iterator it = sound_effects.find(id);
   if (it == sound_effects.end())
   {
      std::cout << "AudioController::play_sound_effect_by_id() error: "
         << "unable to find element with id \""
         << id
         << "\""
         << std::endl;
      return nullptr;
   }

   return it->second;
}


Sound *AudioController::find_music_track_by_id(int id)
{
   std::map<int, Sound*>::iterator it = music_tracks.find(id);
   if (it == sound_effects.end())
   {
      std::cout << "AudioController::play_music_track_by_id() error: "
         << "unable to find element with id \""
         << id
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


void AudioController::play_music_track_by_id(int id)
{
   if (id == current_music_track_id) return;

   stop_all();

   Sound *sound = find_music_track_by_id(id);
   if (sound) sound->play();
}


void AudioController::play_sound_effect_by_id(int id)
{
   Sound *sound = find_sound_effect_by_id(id);
   if (sound) sound->play();
}


} // DragonWrath


