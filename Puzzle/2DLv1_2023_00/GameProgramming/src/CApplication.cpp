#include "CApplication.h"
#include <vector>
#include "CUi.h"

std::vector<CPlayer> players;

void CApplication::Start()
{	
	texture1.Load("apple.psd");
	CPlayer player1;
	player1.Set(100.0f, 50.0f, 50.0f, 50.0f);
	player1.Texture(&texture1, 0, 600, 400, 0);
	players.push_back(player1);
	
	texture2.Load("orange.psd");
	CPlayer player2;
	player2.Set(600.0f, 50.0f, 50.0f, 50.0f);
	player2.Texture(&texture2, 0, 600, 400, 0);
	players.push_back(player2);
	
	for (auto& player : players)
	{
		player.SetPlayers(players);
	}

	mFont.Load("FontWhite.png", 1, 64);

	players[0].isActive = true;
}

void CApplication::Update()
{
	mRectangle.Render();
	for (auto& player : players)
	{
		player.Render();
		player.Update();
	}

	mFont.Draw(40.0f, 300.0f, 15.0f, 30.0f, 'I');
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