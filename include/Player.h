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
	void statsChange(int arg_type); //stats change depending on the type of thing you hit
	void burningFuel();
	void collisionDetection(SDL_Rect debreeRect, int type);
	int getHealth();
	int getFuel();

private:

	Drawable m_rocket;
	int m_speed; //speed of turn by x cord
	int original_speed; //tape
	int m_fuel;
	int m_health;
	bool m_nitro;

};