#include "Board.h"
#include "Presenter.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "World.h"
#include "Player.h"

extern World world; 

Board::Board()
{

}

Board::~Board()
{

}

void Board::init()
{
	m_cat.init("rocket_config.txt", 10);
	generator.init("debree_generator.txt");
	m_background = loadTexture(GAME_FOLDER + "space_background.bmp");
}

void Board::draw()
{
	//m_cat.burningFuel();
	drawObject(m_background);
	m_cat.draw();
	generator.draw();

}

void Board::update()
{
	m_cat.moveRocket();
	generator.update();
	
}

void Board::destroy()
{
	m_cat.destroy();
	generator.destroy();
	
}

