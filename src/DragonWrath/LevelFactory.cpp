
#include <DragonWrath/LevelFactory.hpp>

namespace DragonWrath
{


LevelFactory::LevelFactory()
{
}


LevelFactory::~LevelFactory()
{
}


DragonWrath::Levels::TimedScroll *LevelFactory::create_timed_scroll_level()
{
   DragonWrath::Levels::TimedScroll *timed_scroll_level = new DragonWrath::Levels::TimedScroll();
   return timed_scroll_level;
}


}


