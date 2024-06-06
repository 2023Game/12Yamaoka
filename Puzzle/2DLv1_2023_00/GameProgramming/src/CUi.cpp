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
	mFont.Draw(620, 580, 10, 20, str);
}

void CUi::Title()
{
	mFont.Load("FontBlack.png", 1, 64);
	mFont.Draw(240, 300, 18, 36, "GAME START");
}