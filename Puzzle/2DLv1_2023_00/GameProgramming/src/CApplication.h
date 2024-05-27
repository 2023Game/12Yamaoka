#pragma once
#include "CRectangle.h"
#include "CTexture.h"
#include "CPlayer.h"
#include "CCharacter.h"
#include "CFont.h"
#include "CGame.h"

class CApplication
{
public:
	//�ŏ��Ɉ�x�������s����v���O����
	void Start();
	//�J��Ԃ����s����v���O����
	void Update();
	void OnMouseClick(float x, float y);
	int activePlayerIndex = 0;
private:
	CRectangle mRectangle;
	CTexture mTexture;
	CTexture texture1;
	CTexture texture2;
	CCharacter mCharacter;
	CPlayer mPlayer;
	CPlayer* activePlayer;
	CFont mFont;
	CGame* mpGame;
};