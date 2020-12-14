#include <AllegroFlare/Screen.hpp>
#include <AllegroFlare/Framework.hpp>


namespace DragonWrath
{
   class GameplayScreen : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Framework &framework;

   public:
      GameplayScreen(AllegroFlare::Framework &framework);
      ~GameplayScreen();

      void primary_timer_func() override;
      void key_down_func(ALLEGRO_EVENT *ev) override;
   };
}
