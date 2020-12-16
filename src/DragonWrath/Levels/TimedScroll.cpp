
#include <DragonWrath/Levels/TimedScroll.hpp>
#include <allegro5/allegro.h>


namespace DragonWrath
{
namespace Levels
{


TimedScroll::TimedScroll()
   : DragonWrath::Levels::Base()
   , timer(0)
   , timer_step(ALLEGRO_BPS_TO_SECS(60))
{}


TimedScroll::~TimedScroll()
{}


void TimedScroll::update()
{
   timer += timer_step;
}


} // namespace Levels
} // namespace DragonWrath


