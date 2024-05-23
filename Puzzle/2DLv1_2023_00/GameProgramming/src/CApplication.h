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
	void OnMouseClick(float x, float y);
private:
	CRectangle mRectangle;
	CTexture mTexture;
	CTexture texture1;
	CTexture texture2;
	CCharacter mCharacter;
	CPlayer mPlayer;
	CPlayer* activePlayer;
};