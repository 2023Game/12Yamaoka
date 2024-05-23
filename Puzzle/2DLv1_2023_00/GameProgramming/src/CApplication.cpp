#include "CApplication.h"
#include "CRectangle.h"
#include <vector>

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
}

void CApplication::Update()
{
	mRectangle.Render();
	for (auto& player : players)
	{
		player.Render();
		player.Update();
	}
}

void UpdatePlayers()
{
	for (auto& player : players)
	{
		player.HandleInput();
		player.Update();
	}
}

void CApplication::OnMouseClick(float x, float y)
{
	for (auto& player : players)
	{
		if (player.IsPointInside(x, y))
		{
			activePlayer = &player;
			break;
		}
	}
}