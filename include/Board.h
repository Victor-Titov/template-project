#pragma once

#include "Engine.h"
#include "Button.h"
#include "TextField.h"
#include "Player.h"
#include "debree_generator.h"
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
	debree_generator generator;
	int m_debree_amount;

};