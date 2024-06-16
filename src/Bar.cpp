#include "Bar.h"
#include "Engine.h"
#include "inputManager.h"
#include "Presenter.h"

Bar::Bar()
{
}

Bar::~Bar()
{
}

void Bar::init(string configFile)
{
	string tmp, textureImgPathBar1, textureImgPathBar2;

	fstream stream;

	stream.open(CONFIG_FOLDER + configFile);
	stream >> tmp >> textureImgPathBar1;
	stream >> tmp >> blackBar.rect.x >> blackBar.rect.y >> blackBar.rect.w >> blackBar.rect.h;
	stream >> tmp >> textureImgPathBar2;
	stream >> tmp >> colouredBar.rect.x >> colouredBar.rect.y >> colouredBar.rect.w >> colouredBar.rect.h;
	stream.close();

	blackBar.texture = loadTexture(GAME_FOLDER + textureImgPathBar1);
	colouredBar.texture = loadTexture(GAME_FOLDER + textureImgPathBar2);

	original_width = colouredBar.rect.w;

	//cout << colouredBar.rect.x << colouredBar.rect.y << colouredBar.rect.w << colouredBar.rect.h << endl;
	//cout << GAME_FOLDER + textureImgPathBar1 << endl;
	//cout << GAME_FOLDER + textureImgPathBar2 << endl;

}

void Bar::update()
{
}

void Bar::draw()
{
	drawObject(blackBar);
	drawObject(colouredBar);
}

void Bar::destroy()
{
	SDL_DestroyTexture(blackBar.texture);
	SDL_DestroyTexture(colouredBar.texture);
}

void Bar::lowerBar(int offset, int barSize)
{
	colouredBar.rect.w = colouredBar.rect.w - ((1.0*offset) / barSize) * original_width;
}

void Bar::increaseBar(int offset, int barSize)
{
	colouredBar.rect.w = colouredBar.rect.w + ((1.0*offset) / barSize) * original_width;
}
