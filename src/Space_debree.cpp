#include "Space_debree.h"
#include "Presenter.h"


void Space_debree::init(int start, int2 speed, string texture, int2 size, int type)
{
	m_speed = speed;
	m_drawable.rect.x = start;
	m_drawable.rect.y = 0;
	m_drawable.rect.w = size.x;
	m_drawable.rect.h = size.y;
	m_drawable.texture = loadTexture(GAME_FOLDER + texture);
	cout << GAME_FOLDER + texture;

	m_type = type;
}

void Space_debree::draw()
{
	drawObject(m_drawable);
}

void Space_debree::update()
{
	m_drawable.rect.y += m_speed.y;
	m_drawable.rect.x += m_speed.x;



}

void Space_debree::destroy()
{
	SDL_DestroyTexture(m_drawable.texture);
}

int Space_debree::getType()
{
	return m_type;
}



SDL_Rect Space_debree::getRect()
{
	return m_drawable.rect;
}

