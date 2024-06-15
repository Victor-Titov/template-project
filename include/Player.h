#pragma once

#include "Engine.h"


class Player
{
public:
	Player();
	~Player();

	void init(string configFile);
	void update();
	void draw();
	void destroy();

};