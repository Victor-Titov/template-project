#pragma once
#include "defines.h"
class Space_debree {
public:
	void init(int start, int2 speed, SDL_Texture* texture, int2 size, int type);
	void draw();
	void update();
	void destroy();
	int getType();

	SDL_Rect getRect();
protected:
	Drawable m_drawable;
	int2 m_speed;
	int m_type;// 1 - pepper, 2 - meteor, 3 - star, 4 - cat

};
