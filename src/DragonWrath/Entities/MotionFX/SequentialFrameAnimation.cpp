

#include <DragonWrath/Entities/MotionFX/SequentialFrameAnimation.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace MotionFX
{


SequentialFrameAnimation::SequentialFrameAnimation(
      ElementID *parent,
      ALLEGRO_BITMAP *atlas,
      int frame_width,
      int frame_height,
      int scale,
      float x,
      float y
   )
   : Base(parent, "frame_animation", x, y, 0)
   , sprite_sheet(atlas, frame_width, frame_height, scale)
   , frames_per_second(12.0)
   , num_frames(sprite_sheet.get_num_sprites())
   , current_frame(-1)
{
   bitmap.position(0, 0)
      .align(0.5, 1.0)
      .color(AllegroFlare::color::white);
}


SequentialFrameAnimation::~SequentialFrameAnimation()
{
}


void SequentialFrameAnimation::set_frames_per_second(float fps)
{
   this->frames_per_second = fps;
}


float SequentialFrameAnimation::get_frames_per_second()
{
   return frames_per_second;
}


void SequentialFrameAnimation::advance_frame()
{
   current_frame++;
   bitmap.bitmap(sprite_sheet.get_sprite(current_frame));
}


void SequentialFrameAnimation::update()
{
   counter -= 1.0 / 60.0;
   if (counter <= 0)
   {
      advance_frame();

      if (current_frame >= num_frames) flag_for_deletion();
      else counter = 1.0 / frames_per_second;
   }
}


void SequentialFrameAnimation::draw()
{
   place.start_transform();
   bitmap.draw();
   place.restore_transform();
}


} // Entities
} // MotionFX
} // DragonWrath



