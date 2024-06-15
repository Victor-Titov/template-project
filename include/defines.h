#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

static string IMG_FOLDER = "img\\";
static string CONFIG_FOLDER = "config\\";
static string SOUND_FOLDER = "sound\\";
static string CITIES_FOLDER = "cities\\";
static string STATIONS_FOLDER = "stations\\";
static string QUESTION_FOLDER = "questions\\";
static string MENU_FOLDER = "menu\\";
static string TITLESCREEN_FOLDER = "titlescreen\\";
static string WIN_SCREEN_FOLDER = "WinScreen\\";
static string GAME_FOLDER = "game\\";
static string FONT_FOLDER = "font\\";
static string FIELD_FOLDER = "fields\\";
static string HOUSE_POPUP_FOLDER = "housesB\\";

struct int2
{
	int x;
	int y;

	void reset()
	{
		x = 0;
		y = 0;
	}

	void set(int2 b) 
	{
		x = b.x;
		y = b.y;
	}

	void operator*=(int2 a)
	{
		x *= a.x;
		y *= a.y;
	}

	void operator/=(int2 a)
	{
		x /= a.x;
		y /= a.y;
	}

	int2 operator*(int2 a)
	{
		x *= a.x;
		y *= a.y;

		return *this; //Returns instance of the current class (After the modifications)
	}

	int2 operator/(int2 a)
	{
		x /= a.x;
		y /= a.y;

		return *this;
	}

	bool operator!=(int2 a)
	{
		if (x == a.x && y == a.y)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool operator==(int2 a)
	{
		if (x == a.x && y == a.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

struct float2
{
	//!!!IMPORTANT!!!
	float x;
	float y; 

	void reset()
	{
		x = 0;
		y = 0;
	}

	void set(float2 b)
	{
		x = b.x;
		y = b.y;
	}

	void operator*=(float2 a)
	{
		x *= a.x;
		y *= a.y;
	}

	void operator/=(float2 a)
	{
		x /= a.x;
		y /= a.y;
	}

	float2 operator*(float2 a)
	{
		x *= a.x;
		y *= a.y;

		return *this; //Returns instance of the current class (After the modifications)
	}

	float2 operator/(float2 a)
	{
		x /= a.x;
		y /= a.y;

		return *this;
	}

	bool operator!=(float2 a)
	{
		if (x == a.x && y == a.y)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool operator==(float2 a)
	{
		if (x == a.x && y == a.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

struct Drawable 
{
	SDL_Texture* texture;
	SDL_Rect rect; //dstRect;
};

struct DrawableSrcRect : Drawable
{
	SDL_Rect srcRect;
};

struct DrawableWithOpp : Drawable
{
	int opacity = 0;
	int cpf = 0;
};

enum SOUND 
{
	BACKGORUND_MUSIC
};

enum COLOR
{
	NONE = -1,
	BLACK = 1,
	WHITE = 2,
	BLUE = 3
};

