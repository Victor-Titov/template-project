#pragma once

#include "Engine.h"
#include "Button.h"
#include "TextField.h"
#include "Player.h"

class Board
{
public:
	Board();
	~Board();
	void init();
	void draw();
	void update();
	void destroy();

private:

	Player m_cat;

};