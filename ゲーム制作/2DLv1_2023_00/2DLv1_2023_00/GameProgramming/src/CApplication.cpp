#include "CApplication.h"
#include "CRectangle.h"

void CApplication::Start()
{
	mTexture.Load("apple.psd");
}

void CApplication::Update()
{
	mRectangle.Render();
	mTexture.DrawImage(0.0f, 100.0f, 10.0f, 75.0f, 0, 600, 400, 0);
}