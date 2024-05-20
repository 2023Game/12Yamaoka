#include "CCharacter.h"

void CCharacter::Texture(CTexture* pTexture, int left, int right, int bottom, int top)
{
	mpTexture = pTexture;
	mLeft = left;
	mRight = right;
	mBottom = bottom;
	mTop = top;
}