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

CTitle::CTitle()
{

}

void CTitle::Update()
{
	mFont.Load("FontBlack.png", 1, 64);
	mFont.Draw(150, 300, 30, 30, "GAME TART");
}