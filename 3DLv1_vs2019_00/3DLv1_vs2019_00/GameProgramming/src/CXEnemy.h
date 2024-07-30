#ifndef CXENEMY_H
#define CXENEMY_H
#include "CXCharacter.h"
#include "CCollider.h"

class CXEnemy : public CXCharacter
{
public:
	CXEnemy();
	void Init(CModelX* model);
	void Collision(CCollider* m, CCollider* o); //衝突処理
private:
	CCollider mColSphereBody;
	CCollider mColSphereHead;
	CCollider mColSphereSword0; //剣
	CCollider mColSphereSword1; //剣
	CCollider mColSphereSword2; //剣
};

#endif