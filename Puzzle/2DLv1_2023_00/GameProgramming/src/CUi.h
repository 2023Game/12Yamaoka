#pragma once
#include "CFont.h"

class CUi
{
public:
	CUi();
	void Time(int time);
	void Render();
private:
	int mTime;
	CFont mFont;
};