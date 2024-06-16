#pragma once
#include "defines.h"
class Space_debree {
public:
	virtual void init();
	void draw();
	void update();
	void destroy();
private:
	Drawable m_drawable;
	int speed;
	virtual void react();
};
