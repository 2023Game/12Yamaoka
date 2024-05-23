#pragma once
#include "CRectangle.h"
#include "CTexture.h"
#include "CPlayer.h"
#include "CCharacter.h"

class CApplication
{
public:
	//�ŏ��Ɉ�x�������s����v���O����
	void Start();
	//�J��Ԃ����s����v���O����
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