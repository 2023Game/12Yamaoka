#ifndef CXPLAYER_H
#define CXPLAYER_H
#include "CXCharacter.h"
#include "CInput.h"

class CXPlayer : public CXCharacter
{
public:
	//XVˆ—
	void Update();
private:
	CModelX mModelX;
	CInput mInput;
	CXCharacter mCharacter;
};

#endif