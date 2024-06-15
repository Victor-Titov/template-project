#pragma once

#include"defines.h"

class Button {
public:

	
	Button();
	~Button();
	bool isClicked();
	virtual void init(string config_file, string folder);
	virtual void update();
	virtual void draw();
	virtual void destroy();
protected:
	int m_maxIncrease;
	int m_increasePerFrameX, m_increasePerFrameY;
	int m_currIncreaseX, m_currIncreaseY;

	bool m_isClicked = false;
	Drawable m_button_drawable;
	SDL_Rect originalRect;


	virtual void hover();
	virtual void reset();

};