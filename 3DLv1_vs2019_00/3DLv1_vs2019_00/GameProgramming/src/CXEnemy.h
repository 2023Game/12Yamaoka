#ifndef CXENEMY_H
#define CXENEMY_H
#include "CXCharacter.h"
#include "CCollider.h"

class CXEnemy : public CXCharacter
{
public:
	CXEnemy();
	void Init(CModelX* model);
private:
	CCollider mColSphereBody;
	CCollider mColSphereHead;
	CCollider mColSphereSword;
};

#endif