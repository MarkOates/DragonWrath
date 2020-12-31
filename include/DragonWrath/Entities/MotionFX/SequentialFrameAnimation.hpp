#pragma once


#include <DragonWrath/Entities/MotionFX/Base.hpp>
#include <DragonWrath/SpriteSheet.hpp>


namespace DragonWrath
{
   namespace MotionFX
   {
      class SequentialFrameAnimation : public DragonWrath::Entities::MotionFX::Base
      {
      private:
         DragonWrath::SpriteSheet sprite_sheet;
         float frames_per_second;
         int num_frames;
         int current_frame;

      public:
         SequentialFrameAnimation(
               ElementID *parent,
               ALLEGRO_BITMAP *atlas,
               int frame_width,
               int frame_height,
               int scale,
               float x,
               float y
            );
         ~SequentialFrameAnimation();

         void set_frames_per_second(float fps);
         float get_frames_per_second();

         void advance_frame();

         void update() override;
         void draw() override;
      };
   }
}


