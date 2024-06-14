#pragma once
#include "CUi.h"
#include "CFont.h"
class CGame;
class CTitle;

class CGame
{
public:
	CGame();
	void Update();
private:
	CUi* mpUi;
	int mTime;
};

class CTitle
{
public:
	CTitle();
	void Update();
private:
	CUi* mpUi;
	int mTime;
	CFont mFont;
};