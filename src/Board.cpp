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
	int2 temp;
	temp.x = 5;
	temp.y = 15;
	int2 temp2;
	temp2.x = 50;
	temp2.y = 50;
	m_debree.init(500, temp, "No.bmp", temp2, 1);
	
}

void Board::draw()
{
	m_cat.burningFuel();
	m_cat.draw();
	m_debree.draw();
}

void Board::update()
{
	m_cat.moveRocket();
	m_debree.update();
}

void Board::destroy()
{
	m_cat.destroy();
	m_debree.destroy();
}

