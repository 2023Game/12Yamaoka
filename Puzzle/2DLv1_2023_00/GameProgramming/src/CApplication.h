#pragma once
#include "CRectangle.h"
#include "CTexture.h"
#include "CPlayer.h"

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
	CPlayer mPlayer;
};