#ifndef CPLAYER_H
#define CPLAYER_H
#include "CCharacter.h"
#include "CInput.h"
#include <vector>
#include "CRectangle.h"

class CPlayer :public CCharacter
{
	bool isInCorrectPosition;
public:
	CPlayer():players(nullptr),isSnapped(false){}

	bool isActive = false;
	bool moveUp = false;
	bool moveDown = false;
	bool moveLeft = false;
	bool moveRight = false;
	bool isMoving = true;
	bool isSnapped;
	bool IsInCorrectPosition() const
	{
		return isInCorrectPosition;
	}
	
	int activePlayerIndex = 0;

	float width;
	float height;
	float targetX;
	float targetY;

	void Update();
	void HandleInput();
	void SetActivePlayer(int index);
	void Render();
	void SetInCorrecoPosition(bool value)
	{
		isInCorrectPosition = value;
	}
	void SetSize(float width, float height)
	{
		this->width = width;
		this->height = height;
	}
	void SetPlayers(std::vector<CPlayer>& players)
	{
		this->players = &players;
	}
	void Set(float x, float y, float w, float h, float targetX, float targetY)
	{
		CCharacter::Set(x, y, w, h);
		this->targetX = targetX;
		this->targetY = targetY;
		this->isSnapped = false;
	}
private:
	CInput mInput;
	std::vector<CPlayer>* players;
};

#endif