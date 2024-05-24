#pragma once
#include "CCharacter.h"
#include "CInput.h"
#include <vector>
#include "CRectangle.h"

class CPlayer :public CCharacter
//	, public CRectangle
{
public:
	void Update();
	void HandleInput();

	void SetSize(float width, float height)
	{
		this->width = width;
		this->height = height;
	}

	/*
	bool CPlayer::IsPointInside(float x, float y) const
	{
		return x >= X() && x <= X() + width && y >= Y() && y <= Y() + height;
	}
	*/

private:
	CInput mInput;
	float width;
	float height;
};