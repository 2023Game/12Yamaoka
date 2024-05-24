#pragma once
#include "CUi.h"

class CGame
{
public:
	CGame();
	void Update();
private:
	CUi* mpUi;
	int mTime;
};