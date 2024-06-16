#include "debree_generator.h"
#include "Presenter.h"
void debree_generator::init(string config)
{
	fstream stream;
	string tmp, pepperImg, meteorImg, starImg, catImg;
	stream.open(CONFIG_FOLDER + GAME_FOLDER + config);
	stream >> tmp >> m_debreeAmount;
	stream >> tmp >> m_spawnRange.x >> m_spawnRange.y;
	stream >> tmp >> m_verticalSpeedRange.x >> m_verticalSpeedRange.y;
	stream >> tmp >> m_horizontalSpeedRange.x >> m_horizontalSpeedRange.y;
	stream >> tmp >> pepperImg;
	stream >> tmp >> meteorImg;
	stream >> tmp >> starImg;
	stream >> tmp >> catImg;
	stream >> tmp >> debree_size.x >> debree_size.y;
	stream.close();
	m_textures[0] = loadTexture(GAME_FOLDER + pepperImg);
	m_textures[1] = loadTexture(GAME_FOLDER + meteorImg);
	m_textures[2] = loadTexture(GAME_FOLDER + starImg);
	m_textures[3] = loadTexture(GAME_FOLDER + catImg);
	for (int i = 0; i < m_debreeAmount; i++) {
		m_currStart = rand() % (m_spawnRange.y - m_spawnRange.x) + m_spawnRange.x;
		m_currSpeed.x = rand() % (m_horizontalSpeedRange.y - m_horizontalSpeedRange.x) + m_horizontalSpeedRange.x;
		m_currSpeed.y=rand()% (m_verticalSpeedRange.y - m_verticalSpeedRange.x) + m_verticalSpeedRange.x;
		m_currType = rand() % 3 + 1;
		temp_debree.init(m_currStart, m_currSpeed, m_textures[m_currType-1], debree_size, m_currType);
		debree.push_back(temp_debree);
	}
}

void debree_generator::draw()
{
	for (int i = 0; i < m_debreeAmount; i++) {
		debree[i].draw();
	}
}

void debree_generator::update()
{
	for (int i = 0; i < m_debreeAmount; i++) {
		debree[i].update();
		if (debree[i].getRect().x > 1920 || debree[i].getRect().y > 1080) {
			reset(i);
			
		}
	}
}

void debree_generator::destroy()
{
	for (int i = 0; i < m_debreeAmount; i++) {
		debree[i].destroy();
	}
}

SDL_Rect debree_generator::getDebreeRect(int debree_num)
{
	return debree[debree_num].getRect();
}

int debree_generator::getDerbeeAmount()
{
	return m_debreeAmount;
}

int debree_generator::getDebreeType(int debree_num)
{
	return debree[debree_num].getType();
}

void debree_generator::reset(int debree_num)
{
	m_currStart = rand() % (m_spawnRange.y - m_spawnRange.x) + m_spawnRange.x;
	m_currSpeed.x = rand() % (m_horizontalSpeedRange.y - m_horizontalSpeedRange.x) + m_horizontalSpeedRange.x;
	m_currSpeed.y = rand() % (m_verticalSpeedRange.y - m_verticalSpeedRange.x) + m_verticalSpeedRange.x;
	m_currType = rand() % 6 + 1;
	if (m_currType > 4) {
		m_currType = 2;
	}
	debree[debree_num].init(m_currStart, m_currSpeed, m_textures[m_currType - 1], debree_size, m_currType);
}
