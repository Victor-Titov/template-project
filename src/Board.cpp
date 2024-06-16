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
}

void Board::draw()
{
	m_cat.draw();
	
}

void Board::update()
{
	m_cat.moveRocket();
}

void Board::destroy()
{
	m_cat.destroy();
}

