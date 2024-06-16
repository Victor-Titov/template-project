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
	for (int i = 0; i < m_debree_amount; i++) {
		if (m_cat.collisionDetection(generator.getDebreeRect(i), generator.getDebreeType(i))) {
			generator.reset(i);
		}
		
	}
	m_cat.update();
	if (m_cat.getHealth() <= 0) {
		world.m_stateManager.changeGameState(GAME_STATE::WIN_SCREEN);
	}
	
}

void Board::destroy()
{
	m_cat.destroy();
	generator.destroy();
	SDL_DestroyTexture(m_background);
}

int Board::getScore()
{
	return m_cat.getScore();
}

