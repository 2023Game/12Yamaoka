#include "CApplication.h"
#include <vector>
#include "CUi.h"

void CApplication::Start()
{	
	texture1.Load("apple.psd");
	CPlayer player1;
	player1.Set(100.0f, 100.0f, 50.0f, 50.0f);
	player1.Texture(&texture1, 0, 300, 200, 0);
	players.push_back(player1);

	texture2.Load("apple.psd");
	CPlayer player2;
	player2.Set(300.0f, 100.0f, 50.0f, 50.0f);
	player2.Texture(&texture2, 300, 600, 200, 0);
	players.push_back(player2);

	texture3.Load("apple.psd");
	CPlayer player3;
	player3.Set(500.0f, 100.0f, 50.0f, 50.0f);
	player3.Texture(&texture3, 0, 300, 400, 200);
	players.push_back(player3);

	texture4.Load("apple.psd");
	CPlayer player4;
	player4.Set(700.0f, 100.0f, 50.0f, 50.0f);
	player4.Texture(&texture4, 300, 600, 400, 200);
	players.push_back(player4);

	for (auto& player : players)
	{
		player.SetPlayers(players);
	}

	mFont.Load("FontWhite.png", 1, 64);

	players[0].isActive = true;

	mpGame = new CGame();
}

void CApplication::Update()
{
	mRectangle.Render();
	mpGame->Update();
	for (auto& player : players)
	{
		player.Render();
		player.Update();
	}
}

void CApplication::OnMouseClick(float x, float y)
{
	for (int i = 0; i < players.size(); i++)
	{
		if (x >= players[i].X() && x <= players[i].X() + players[i].width &&
			y >= players[i].Y() && y <= players[i].Y() + players[i].height)
		{
			players[activePlayerIndex].isActive = false;
			activePlayerIndex = i;
			players[activePlayerIndex].isActive = true;
			break;
		}
	}
}

/*
void CApplication::SetActivePlayer(int index)
{
	if (index>=0&&index<players.size())
	{
		players[activePlayerIndex].isActive = false;
		activePlayerIndex = index;
		players[activePlayerIndex].isActive = true;
	}
}
*/