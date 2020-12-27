#pragma once


#include <vector>


class AudioRepositoryElement
{
public:
   int id;
   std::string filename;
   bool loop;
};


enum music_track_t
{
   TITLE_SCREEN_MUSIC,
   LEVEL_1_MUSIC,

   PLAYER_SHOOT_BULLET_SOUND_EFFECT,
};


