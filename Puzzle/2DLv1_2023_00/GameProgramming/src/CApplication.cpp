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
	player1.SetPlayers(players);
	
	texture2.Load("orange.psd");
	CPlayer player2;
	player2.Set(600.0f, 50.0f, 50.0f, 50.0f);
	player2.Texture(&texture2, 0, 600, 400, 0);
	players.push_back(player2);
	player2.SetPlayers(players);

	mFont.Load("FontWhite.png", 1, 64);
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
		/*
		if (player.IsPointInside(x, y))
		{
			activePlayer = &player;
			break;
		}
		*/
	}
}