#ifndef CXENEMY_H
#define CXENEMY_H
#include "CXCharacter.h"
#include "CCollider.h"

class CXEnemy : public CXCharacter
{
public:
	CXEnemy();
	void Init(CModelX* model);
	void Collision(CCollider* m, CCollider* o); //Õ“Ëˆ—
private:
	CCollider mColSphereBody;
	CCollider mColSphereHead;
	CCollider mColSphereSword0;	//Œ•
	CCollider mColSphereSword1;	//Œ•
	CCollider mColSphereSword2;	//Œ•
};

#endif