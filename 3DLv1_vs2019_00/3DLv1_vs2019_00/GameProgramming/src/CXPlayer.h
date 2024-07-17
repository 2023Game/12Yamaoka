#ifndef CXPLAYER_H
#define CXPLAYER_H
#include "CXCharacter.h"
#include "CInput.h"
#include "CCollider.h"

class CXPlayer : public CXCharacter
{
public:
	//XVˆ—
	void Update();
	CXPlayer();
	void Init(CModelX* model);
	//void Collision(CCollider* m, CCollider* o);
private:
	CInput mInput;
	CCollider mColSphereBody;  //‘Ì
	CCollider mColSphereHead;  //“ª
	CCollider mColSphereSword; //Œ•
};

#endif