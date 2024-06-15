#include "Writer.h"
#include "Presenter.h"

Writer::Writer()
{
}

Writer::~Writer()
{
}

void Writer::init()
{
	m_fontLocation = FONT_FOLDER + "Oswald-Regular.ttf";

	TTF_Font* font;

	for (int i = 10; i < 300; i++) //Font size from 10 to 299
	{
		font = TTF_OpenFont(m_fontLocation.c_str(), i);
		m_font.insert(pair<int, TTF_Font*>(i, font));
	}

	SDL_Color color;

	color.a = (Uint8)255;

	//Black color
	color.r = (Uint8)0;
	color.g = (Uint8)0;
	color.b = (Uint8)0;

	m_colors.insert(pair<COLOR, SDL_Color>(BLACK, color));

	//White color
	color.r = (Uint8)255;
	color.g = (Uint8)255;
	color.b = (Uint8)255;

	m_colors.insert(pair<COLOR, SDL_Color>(WHITE, color));

	//Blue color
	color.r = (Uint8)30;
	color.g = (Uint8)144;
	color.b = (Uint8)255;

	m_colors.insert(pair<COLOR, SDL_Color>(BLUE, color));
}

pair<int2, SDL_Texture*> Writer::getText(string text, COLOR color, int fontSize)
{
	TTF_Font* font = m_font.at(fontSize);

	const char* c = text.c_str(); //Pointer to the first element of the string

	SDL_Surface* surface = TTF_RenderText_Blended(font, c, m_colors.at(color)); //TTF_RenderUTF8_Shaded for Bulgarian text
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Presenter::m_mainRenderer, surface);

	int2 size = { surface->w, surface->h };

	pair<int2, SDL_Texture*> result = { size, texture };

	SDL_FreeSurface(surface);

	return result;
}
