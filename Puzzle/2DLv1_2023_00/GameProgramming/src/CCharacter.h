#ifndef CCHARACTER_H
#define CCHARACTER_H
#include "CRectangle.h"
#include "CTexture.h"

class CCharacter :public CRectangle
{
public:
	void Texture(CTexture* pTexture, int left, int right, int bottom, int top);
	void Render();
private:
	CTexture* mpTexture;
	int mLeft, mRight, mBottom, mTop;
};

#endif