#ifndef CXPLAYER_H
#define CXPLAYER_H
#include "CXCharacter.h"
#include "CInput.h"
#include "CCollider.h"

class CXPlayer : public CXCharacter
{
public:
	//�X�V����
	void Update();
	CXPlayer();
	void Init(CModelX* model);
private:
	CInput mInput;
	CCollider mColSphereBody;  //��
	CCollider mColSphereHead;  //��
	CCollider mColSphereSword; //��
};

#endif