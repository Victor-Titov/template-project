#include "Menu.h"
#include "World.h"
#include "InputManager.h"

extern World world;

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::init()
{
	m_menu = loadTexture(MENU_FOLDER + "startscreen.bmp");
	m_play.init("play.txt", MENU_FOLDER);
	m_exit.init("exit.txt", MENU_FOLDER);

}

void Menu::run()
{
	drawObject(m_menu);
	m_play.update();
	if (m_play.isClicked()) {
		world.m_stateManager.changeGameState(GAME_STATE::GAME);
	}
	m_exit.update();
	if (m_exit.isClicked()) {
		world.m_stateManager.changeGameState(GAME_STATE::NONE);
	}
	m_play.draw();
	m_exit.draw();
}

void Menu::destroy()
{
	SDL_DestroyTexture(m_menu);
}
