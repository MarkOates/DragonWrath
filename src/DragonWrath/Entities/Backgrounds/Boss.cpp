


#include <DragonWrath/Entities/Backgrounds/Boss.hpp>

#include <AllegroFlare/Useful.hpp>
#include <allegro_flare/blender.h>
#include <DragonWrath/Levels/TimedScroll.hpp>
#include <DragonWrath/LevelTypeNames.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace Backgrounds
{


Boss::Boss(AllegroFlare::ElementID *parent, AllegroFlare::BitmapBin &bitmap_bin)
   : DragonWrath::Entities::Backgrounds::Base(
      parent,
      bitmap_bin,
      std::vector<DragonWrath::Entities::Backgrounds::Base::BackgroundLayer>{
            { 0, 0, 1.0, bitmap_bin.auto_get("backgrounds/SkyAndCloud8.png") },
            //{ 0, -116, 50.0, bitmap_bin.auto_get("backgrounds/Cloud3a.png") }
         },
      std::vector<DragonWrath::Entities::Backgrounds::Base::ForegroundLayer>{
            //{ 0, 100, 40.0, bitmap_bin.auto_get("backgrounds/Cloud3b.png") },
            { 0, -120, 120.0, bitmap_bin.auto_get("backgrounds/Cloud3b.png") },
            { 0, 100, 40.0, bitmap_bin.auto_get("backgrounds/Cloud9.png") },
         }
      )
   , global_speed_rate(1.0)
   , next_target_speed_rate(2.0)
{
}


Boss::~Boss()
{
}



void Boss::speed_up()
{
   next_target_speed_rate *= 1.2;
}


void Boss::update()
{
   // udpate the speed rate
   if (global_speed_rate <= next_target_speed_rate) global_speed_rate += 0.01;

   // scroll the backgrounds
   int layer_num = 0;
   for (auto &foreground_layer : foreground_layers)
   {
      layer_num++;
      foreground_layer.offset_x += (layer_num * 1.0) * global_speed_rate;
   }
}


} // Backgrounds
} // Entities
} // DragonWrath


