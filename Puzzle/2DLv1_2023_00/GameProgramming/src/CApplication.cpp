#include "CApplication.h"
#include "CRectangle.h"

void CApplication::Start()
{
	mTexture.Load("apple.psd");
	mPlayer.Set(200.0f, 50.0f, 50.0f, 50.0f);
	mPlayer.Texture(&mTexture, 0, 600, 400, 0);
}

void CApplication::Update()
{
	mRectangle.Render();
	//mCharacter.Render();
	//mTexture.DrawImage(0.0f, 100.0f, 10.0f, 75.0f, 0, 600, 400, 0);
	mPlayer.Render();
	mPlayer.Update();
}