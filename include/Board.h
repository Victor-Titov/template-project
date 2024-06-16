#pragma once

#include "Engine.h"
#include "Button.h"
#include "TextField.h"
#include "Player.h"
#include "Space_debree.h"
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
	Space_debree m_debree;

};