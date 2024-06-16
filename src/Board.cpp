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
	m_debree_amount = generator.getDerbeeAmount();
	
}

void Board::draw()
{
	m_cat.burningFuel();
	m_cat.draw();
	generator.draw();

}

void Board::update()
{
	m_cat.moveRocket();
	generator.update();
	for (int i = 0; i < m_debree_amount; i++) {
		m_cat.collisionDetection(generator.getDebreeRect(i), generator.getDebreeType(i));
		
	}
	
}

void Board::destroy()
{
	m_cat.destroy();
	generator.destroy();
	
}

