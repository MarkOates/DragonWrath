#pragma once


#include <DragonWrath/Entities/Base.hpp>

#include <DragonWrath/Entities/Backgrounds/Base.hpp>
#include <AllegroFlare/BitmapBin.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace Backgrounds
      {
         class Boss : public DragonWrath::Entities::Backgrounds::Base
         {
         private:
            float global_speed_rate;
            float next_target_speed_rate;

         public:
            Boss(AllegroFlare::ElementID *parent, AllegroFlare::BitmapBin &bitmap_bin);
            ~Boss();

            void speed_up();

            void update() override;
         };
      }
   }
}



