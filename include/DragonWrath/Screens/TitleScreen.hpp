#pragma once

#include <DragonWrath/Screens/Base.hpp>
#include <AllegroFlare/Framework.hpp>

namespace DragonWrath
{
   namespace Screens
   {
      class TitleScreen : public DragonWrath::Screens::Base
      {
      private:
         AllegroFlare::Framework &framework;

      public:
         TitleScreen(AllegroFlare::Framework &framework);
         ~TitleScreen();

         void primary_timer_func() override;
         void key_down_func(ALLEGRO_EVENT *ev) override;
      };
   }
}


