#pragma once

#include "defines.h"
#include "State.h"
#include "Button.h"

class Menu : public State
{
public:
	Menu();
	~Menu();

	void init();
	void run();
	void destroy();

private:
	 SDL_Texture* m_menu;
	 Button m_play;
	 Button m_exit;
};