#pragma once
#include "Space_debree.h"

class debree_generator {
public:

	vector<Space_debree> debree;
	void init(string config);
	void draw();
	void update();
	void destroy();
	SDL_Rect getDebreeRect(int debree_num);
	int getDerbeeAmount();
	int getDebreeType(int debree_num);
private:
	Space_debree temp_debree;
	int m_debreeAmount;
	SDL_Texture* m_textures[3];
	int2 m_spawnRange;
	int2 m_verticalSpeedRange;
	int2 m_horizontalSpeedRange;
	int2 debree_size;
	int m_currStart;
	int2 m_currSpeed;
	int m_currType;
	
	
};