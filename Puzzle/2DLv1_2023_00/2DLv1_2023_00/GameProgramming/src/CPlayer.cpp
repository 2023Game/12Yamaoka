#include "CPlayer.h"

void CPlayer::Update()
{
	if (mInput.Key('A'))
	{
		float x = X() - 4.0f;
		X(x);
	}
}