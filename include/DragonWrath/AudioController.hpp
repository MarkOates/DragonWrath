#pragma once


#include <allegro_flare/sound_object.h>
#include <AllegroFlare/SampleBin.hpp>
#include <DragonWrath/MusicAndSoundEffectTrackNames.hpp>
#include <map>


namespace DragonWrath
{
   class AudioController
   {
   private:
      AllegroFlare::SampleBin &sample_bin;
      std::string sound_effects_identifier_prefix;
      std::string music_tracks_identifier_prefix;
      std::map<std::string, AudioRepositoryElement> sound_effect_elements;
      std::map<std::string, AudioRepositoryElement> music_track_elements;
      std::map<std::string, Sound*> sound_effects;
      std::map<std::string, Sound*> music_tracks;
      std::string current_music_track_identifier;
      float global_volume;

      bool output_loading_debug_to_cout;

      Sound *find_sound_effect_by_identifier(std::string identifier);
      Sound *find_music_track_by_identifier(std::string identifier);

   public:
      AudioController(
            AllegroFlare::SampleBin &sample_bin,
            std::map<std::string, AudioRepositoryElement> music_track_elements,
            std::map<std::string, AudioRepositoryElement> sound_effect_elements
         );
      ~AudioController();

      void initialize();
      void stop_all();

      void set_global_volume(float volume);

      void play_music_track_by_identifier(std::string identifier);
      void play_sound_effect_by_identifier(std::string identifier);
   };
}


