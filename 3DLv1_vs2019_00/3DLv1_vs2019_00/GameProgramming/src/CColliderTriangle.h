#ifndef CCOLLIDERTRIANGLE_H
#define CCOLLIDERTRIANGLE_H
#include "CCollider.h"
/*
�O�p�`�R���C�_�̒�`
*/
class CColliderTriangle : public CCollider
{
public:
	CColliderTriangle() {}
	//�R���X�g���N�^(�O�p�R���C�_)
	//CCollliderTriangle(�e�A�e�s��A���_�P�A���_�Q�A���_�R)
	CColliderTriangle(CCharacter3* parent, CMatrix* matrix, const CVector& v0, const CVector& v1, const CVector& v2);
	//�O�p�R���C�_�̐ݒ�
	//Set(�e�A�e�s��A���_�P�A���_�Q�A���_�R)
	void Set(CCharacter3* parent, CMatrix* matrix, const CVector& v0, const CVector& v1, const CVector& v2);
	//�`��
	void Render();
};

#endif