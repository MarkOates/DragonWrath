#ifndef __AF_OBJECT_2D_HEADER
#define __AF_OBJECT_2D_HEADER




#include <iostream>
#include <string>
#include <allegro_flare/appearance2d.h>
#include <allegro_flare/placement2d.h>




namespace allegro_flare
{
   class object2d
   {
   public:
      float _dummy;
      float *_x, *_y, *_w, *_h;
      placement2d *_placement;
      appearance2d *_appearance;

      float &w();
      float &h();
      float &w(float val);
      float &h(float val);

      void top(float val);
      void left(float val);

      float top();
      float right();
      float bottom();
      float left();
      float center();
      float middle();

      float anchor_x();
      float anchor_y();
      float scale_x();
      float scale_y();
      float align_x();
      float align_y();
      bool flip_x();
      bool flip_y();
      float opacity();
      ALLEGRO_COLOR color();

      object2d(float x, float y, float w, float h);
      virtual ~object2d();

      virtual object2d &transform_on();
      virtual object2d &appearance_on();
      virtual object2d &start_transform();
      virtual object2d &restore_transform();
      virtual object2d &rotation(float rotation);
      virtual object2d &scale(float scale);
      virtual object2d &anchor(float x, float y);
      virtual object2d &scale(float scale_x, float scale_y);
      virtual object2d &flip(bool flip_x, bool flip_y);
      virtual object2d &scale_to(float w, float h);
      virtual object2d &scale_to_width(float w);
      virtual object2d &scale_to_height(float h);
      virtual object2d &scale_to_fit(float w, float h);
      virtual object2d &stretch_to_fit(float w, float h);
      virtual object2d &align(float align_x, float align_y);

      virtual float &get_attr(std::string attr);
      //virtual object2d &markup(std::string str);
      virtual object2d &opacity(float v);
      virtual object2d &color(ALLEGRO_COLOR color);
      virtual object2d &color(const char *color, float opacity=1.0);
      virtual object2d &position(float x, float y);

      virtual object2d &move(float disp_x, float disp_y);

      virtual object2d &draw();
      virtual object2d &draw_raw();

      virtual void draw_origin(ALLEGRO_COLOR col=al_map_rgb(255,0,0));

      bool collide(float x, float y);
   };
}



#endif
