#pragma once


#include <allegro_flare/sound_object.h>
#include <AllegroFlare/SampleBin.hpp>
#include <map>


namespace DragonWrath
{
   class AudioController
   {
   private:
      AllegroFlare::SampleBin &sample_bin;

      Sound game_show_music;
      Sound storyboard_music;
      Sound haunting_music;
      Sound hurt_sound_effect;
      Sound tada_sound_effect;
      Sound win_cheer_sound_effect;
      Sound strong_punch_sound_effect;
      int current_music_track_num;

      std::map<std::string, Sound*> sound_effects;

   public:
      AudioController(AllegroFlare::SampleBin &sample_bin);
      ~AudioController();

      void play_game_show_music();
      void play_storyboard_music();
      void play_haunting_music();
      void play_hurt_sound_effect();
      void play_tada_sound_effect();
      void play_strong_punch_sound_effect();

      void stop_all();

      void play_audio_track_by_id(int id);
      void play_sound_effect_by_id(int id);
      void play_sound_effect_by_name(std::string id_str);
   };
}


