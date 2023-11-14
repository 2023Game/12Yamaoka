#ifndef CPLAYER_H
#define CPLAYER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"
#include "CInput.h"
#include "CMatrix.h"
#include "CBullet.h"

/*
�v���C���[�N���X
�L�����N�^�N���X���p��
*/

class CPlayer : public CCharacter3
{
public:
	CPlayer() {}
	//CPlayer(�ʒu�A��]�A�X�P�[��)
	CPlayer(const CVector& pos, const CVector& rot, const CVector& scale);
	//�X�V����
	void Update();
	CBullet bullet;
private:
	CInput mInput;
};

#endif