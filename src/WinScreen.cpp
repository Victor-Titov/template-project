#include "WinScreen.h"
#include "World.h"
extern World world;
WinScreen::WinScreen()
{
}

WinScreen::~WinScreen()
{
}

void WinScreen::init()
{
	string tmp, backraundImageStr, playAgainConfig, quitConfig, scoreConfig;
	fstream stream;
	stream.open(CONFIG_FOLDER + WIN_SCREEN_FOLDER + "WinScreenInit.txt");
	stream >> tmp >> backraundImageStr;
	stream >> tmp >> playAgainConfig;
	stream >> tmp >> quitConfig;
	stream >> tmp >> scoreConfig;
	stream.close();
	m_backround = loadTexture(WIN_SCREEN_FOLDER + backraundImageStr);
	m_playAgain.init(playAgainConfig, WIN_SCREEN_FOLDER);
	m_quit.init(quitConfig, WIN_SCREEN_FOLDER);
	m_score.init(scoreConfig);
	//cout << m_winnerField.m_color;

}

void WinScreen::destroy()
{
	SDL_DestroyTexture(m_backround);
	m_playAgain.destroy();
	m_quit.destroy();
	m_score.destroy();
	
}

void WinScreen::run()
{
	drawObject(m_backround);
	m_playAgain.update();
	m_playAgain.draw();
	m_quit.update();
	m_quit.draw();
	m_score.update();
	m_score.setText(to_string(world.m_stateManager.m_game->m_board.getScore()));
	m_score.draw();
	

	if (m_playAgain.isClicked()) {
		world.m_stateManager.changeGameState(GAME_STATE::MENU);
	}

	if (m_quit.isClicked()) {
		world.m_stateManager.changeGameState(GAME_STATE::NONE);
	}


}
