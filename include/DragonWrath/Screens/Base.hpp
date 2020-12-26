#pragma once

#include <AllegroFlare/Screen.hpp>

namespace DragonWrath
{
   namespace Screens
   {
      class Base : public AllegroFlare::Screen
      {
      public:
         Base();
         ~Base();

         virtual void start();
      };
   }
}

