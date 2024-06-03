#ifndef CPLAYER_H
#define CPLAYER_H
#include "CCharacter.h"
#include "CInput.h"
#include <vector>
#include "CRectangle.h"

class CPlayer :public CCharacter
{
public:
	CPlayer():players(nullptr){}

	bool isActive = false;
	bool moveUp = false;
	bool moveDown = false;
	bool moveLeft = false;
	bool moveRight = false;
	bool isMoving = true;

	int activePlayerIndex = 0;

	float width;
	float height;

	void Update();
	void HandleInput();
	void SetActivePlayer(int index);
	void Render();

	void SetSize(float width, float height)
	{
		this->width = width;
		this->height = height;
	}

	void SetPlayers(std::vector<CPlayer>& players)
	{
		this->players = &players;
	}
private:
	CInput mInput;
	std::vector<CPlayer>* players;
};

#endif