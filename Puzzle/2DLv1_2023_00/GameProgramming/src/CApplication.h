#pragma once
#include "CRectangle.h"
#include "CTexture.h"
#include "CPlayer.h"
#include "CCharacter.h"

class CApplication
{
public:
	//最初に一度だけ実行するプログラム
	void Start();
	//繰り返し実行するプログラム
	void Update();
private:
	CRectangle mRectangle;
	CTexture mTexture;
	CCharacter mCharacter;
	CPlayer mPlayer;
};