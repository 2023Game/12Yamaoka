#ifndef CPLAYER_H
#define CPLAYER_H
#include "CCharacter.h"
#include "CInput.h"
#include <vector>
#include "CRectangle.h"

class CPlayer :public CCharacter
{
public:
	bool isActive = false;
	CPlayer():players(nullptr){}

	bool moveUp = false;
	bool moveDown = false;
	bool moveLeft = false;
	bool moveRight = false;

	void Update();
	void HandleInput();

	float width;
	float height;

	void SetSize(float width, float height)
	{
		this->width = width;
		this->height = height;
	}

	void SetPlayers(std::vector<CPlayer>& players)
	{
		this->players = &players;
	}

	void SetActivePlayer(int index);
private:
	CInput mInput;
	std::vector<CPlayer>* players;
};

#endif