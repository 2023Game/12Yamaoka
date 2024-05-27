#include "CGame.h"
#include "CApplication.h"

CGame::CGame()
	:mpUi(nullptr)
	,mTime(0)
{
	mpUi = new CUi();
}

void CGame::Update()
{
	mpUi->Time(mTime++);
	mpUi->Render();
}