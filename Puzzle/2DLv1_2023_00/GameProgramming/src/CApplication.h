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
private:
	CRectangle mRectangle;
	CTexture mTexture;
	CCharacter mCharacter;
	CPlayer mPlayer;
};