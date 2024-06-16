#pragma once

#include "Engine.h"
#include "inputManager.h"


class Player
{
public:
	Player();
	~Player();

	void init(string configFile, int arg_speed);
	void update();
	void draw();
	void destroy();
	void moveRocket();

private:

	Drawable m_rocket;
	int m_speed; //speed of turn by x cord
	int m_fuel;
	int m_health;
	bool m_nitro;

};