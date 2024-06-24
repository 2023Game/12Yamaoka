#pragma once
#include "CUi.h"
#include "CFont.h"
class CGame;
class CTitle;
class CClear;

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
	CFont mFont;
};

class CClear
{
public:
	CClear();
	void Update();
private:
	CFont mFont;
};