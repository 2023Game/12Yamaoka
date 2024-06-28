#ifndef CXPLAYER_H
#define CXPLAYER_H
#include "CXCharacter.h"
#include "CInput.h"

class CXPlayer : public CXCharacter
{
public:
	//XVˆ—
	void Update();
	void Render();
private:
	CModelX* mpModel;
	CModelX mModelX;
	CInput mInput;
	CXCharacter mCharacter;
};

#endif