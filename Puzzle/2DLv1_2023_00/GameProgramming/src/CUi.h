#pragma once
#include "CFont.h"

//���[�U�[�C���^�[�t�F�[�X�N���X
class CUi
{
public:
	CUi();
	void Time(int time);
	void Render();
	void Start(); //�X�^�[�g���
private:
	int mTime; //�o�ߎ���
	CFont mFont;
};