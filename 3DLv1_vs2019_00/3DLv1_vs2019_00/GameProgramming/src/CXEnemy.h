#ifndef CXENEMY_H
#define CXENEMY_H
#include "CXCharacter.h"
#include "CCollider.h"

class CXEnemy : public CXCharacter
{
public:
	CXEnemy();
	void Init(CModelX* model);
	void Collision(CCollider* m, CCollider* o); //�Փˏ���
private:
	CCollider mColSphereBody;
	CCollider mColSphereHead;
	CCollider mColSphereSword0;	//��
	CCollider mColSphereSword1;	//��
	CCollider mColSphereSword2;	//��
};

#endif