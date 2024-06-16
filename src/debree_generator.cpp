#include "debree_generator.h"
#include "Presenter.h"
void debree_generator::init(string config)
{
	fstream stream;
	string tmp, pepperImg, meteorImg, starImg;
	stream.open(CONFIG_FOLDER + GAME_FOLDER + config);
	stream >> tmp >> m_debreeAmount;
	stream >> tmp >> m_spawnRange.x >> m_spawnRange.y;
	stream >> tmp >> m_verticalSpeedRange.x >> m_verticalSpeedRange.y;
	stream >> tmp >> m_horizontalSpeedRange.x >> m_horizontalSpeedRange.y;
	stream >> tmp >> pepperImg;
	stream >> tmp >> meteorImg;
	stream >> tmp >> starImg;
	stream >> tmp >> debree_size.x >> debree_size.y;
	stream.close();
	m_textures[0] = loadTexture(GAME_FOLDER + pepperImg);
	m_textures[1] = loadTexture(GAME_FOLDER + meteorImg);
	m_textures[2] = loadTexture(GAME_FOLDER + starImg);
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
			
			m_currStart = rand() % (m_spawnRange.y - m_spawnRange.x) + m_spawnRange.x;
			m_currSpeed.x = rand() % (m_horizontalSpeedRange.y - m_horizontalSpeedRange.x) + m_horizontalSpeedRange.x;
			m_currSpeed.y = rand() % (m_verticalSpeedRange.y - m_verticalSpeedRange.x) + m_verticalSpeedRange.x;
			m_currType = rand() % 5 + 1;
			if (m_currType > 3) {
				m_currType = 2;
			}
			debree[i].init(m_currStart, m_currSpeed, m_textures[m_currType - 1], debree_size, m_currType);
		}
	}
}

void debree_generator::destroy()
{
	for (int i = 0; i < m_debreeAmount; i++) {
		debree[i].destroy();
	}
}
