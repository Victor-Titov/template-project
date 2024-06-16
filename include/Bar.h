#pragma once
#include "defines.h"
#include "Engine.h"
#include "inputManager.h"
#include "Presenter.h"

class Bar
{
public:
	Bar();
	~Bar();

	void init(string configFile);
	void update();
	void draw();
	void destroy();
	void lowerBar(int offset, int barSize);
	void increaseBar(int offset, int barSize);

private:

	Drawable blackBar;
	Drawable colouredBar;
	double original_width;
};