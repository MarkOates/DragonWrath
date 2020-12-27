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
   GAME_OVER_SCREEN_MUSIC,

   PLAYER_SHOOT_BULLET_SOUND_EFFECT,
   ENEMY_TAKES_HIT_SOUND_EFFECT,
   ENEMY_EXPLOSION_SOUND_EFFECT,
};

