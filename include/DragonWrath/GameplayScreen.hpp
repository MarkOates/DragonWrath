#include <AllegroFlare/Screen.hpp>
#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/Levels/Base.hpp>


namespace DragonWrath
{
   class GameplayScreen : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Framework &framework;
      DragonWrath::Levels::Base *current_level;

   public:
      GameplayScreen(AllegroFlare::Framework &framework);
      ~GameplayScreen();

      void initialize();

      void load_level();

      void primary_timer_func() override;
      void key_down_func(ALLEGRO_EVENT *ev) override;
      void key_up_func(ALLEGRO_EVENT *ev) override;
   };
}
