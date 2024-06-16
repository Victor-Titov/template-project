#pragma once
#include "defines.h"
class Space_debree {
public:
	void init(int start, int2 speed, string texture, int2 size, int value);
	void draw();
	void update(SDL_Rect playerRect);
	void destroy();
	
	SDL_Rect getRect();
protected:
	Drawable m_drawable;
	int2 m_speed;
	int m_type;// 1 - pepper, 2 - meteor, 3 - star
  	int m_value;
};
