#include <stdio.h>
#include "CUi.h"

CUi::CUi()
	: mTime(0)
{
	mFont.Load("FontWhite.png", 1, 64);
}

void CUi::Time(int time)
{
	mTime = time;
}

void CUi::Render()
{
	char str[16];
	sprintf(str, "TIME:%03d", mTime);

	float x = 400;
	float y = 300;
	float w = 10;
	float h = 20;

	for (int i = 0; str[i] != '\0'; i++)
	{
		mFont.Draw(x, y, w, h, str[i]);
		x += w;
	}
	//mFont.Draw(620, 580, 10, 20, str);
}