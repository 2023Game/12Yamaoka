#ifndef CXPLAYER_H
#define CXPLAYER_H
#include "CXCharacter.h"
#include "CInput.h"
#include "CCollider.h"

class CXPlayer : public CXCharacter
{
public:
	//更新処理
	void Update();
	CXPlayer();
	void Init(CModelX* model);
	//void Collision(CCollider* m, CCollider* o);
private:
	CInput mInput;
	CCollider mColSphereBody;  //体
	CCollider mColSphereHead;  //頭
	CCollider mColSphereSword; //剣
};

#endif