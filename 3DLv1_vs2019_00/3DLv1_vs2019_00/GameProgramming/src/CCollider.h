#ifndef CCOLLIDER_H
#define CCOLLIDER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter3.h"

class CCollisionManager;

/*
�R���C�_�N���X
�Փ˔���f�[�^
*/
class CCollider : public CTransform, public CTask
{
	friend CCollisionManager;
public:
	//�R���X�g���N�^
	//CCollider(�e�A�e�s��A�ʒu�A���a)
	CCollider(CCharacter3* parent, CMatrix* matrix, const CVector& position, float radius);
	//�e�|�C���^�̎擾
	CCharacter3* Parent();
	//�`��
	void Render();
	~CCollider();
	//�Փ˔���
	//Collision(�R���C�_1,�R���C�_2)
	//retrun:true(�Փ˂��Ă���)false(�Փ˂��Ă��Ȃ�)
	static bool Collision(CCollider* m, CCollider* o);
	//�R���C�_�^�C�v
	enum class EType
	{
		ESPHERE, //���R���C�_
		ETRIANGLE, //�O�p�R���C�_
		ELINE, //�����R���C�_
	};
	//�f�t�H���g�R���X�g���N�^
	CCollider();
protected:
	CCharacter3* mpParent; //�e
	CMatrix* mpMatrix; //�e�s��
	float mRadius; //���a
	EType mType; //�R���C�_�^�C�v
	//���_
	CVector mV[3];
};

#endif