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
	mpTitle = new CTitle();
}

void CApplication::Update()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		//���݂�player���A�N�e�B�u�ɐݒ�
		players[activePlayerIndex].isActive = false;
		//����player�̃C���f�b�N�X�Ɉړ�
		activePlayerIndex++;
		//�v���C���[���X�g�̍Ō�ɒB������ŏ��ɖ߂�
		if (activePlayerIndex >= players.size())
		{
			activePlayerIndex = 0;
		}
		//�V�����A�N�e�B�u�v���C���[��ݒ�
		SetActivePlayer(activePlayerIndex);
	}
	
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (mCurrentState == GameState::START_SCREEN)
		{
			ChangeState(GameState::GAMEPLAY);
		}
	}
	
	switch (mCurrentState)
	{
	case GameState::START_SCREEN:
		mRectangle.Render();
		mpTitle->Update();
		break;

	case GameState::GAMEPLAY:
		mpGame->Update();
		for (auto& player : players)
		{
			player.Render();
			player.Update();
		}
		break;

	case GameState::PAUSE:
		break;
	}
}

void CApplication::SetActivePlayer(int index)
{
	if (index >= 0 && index < players.size())
	{
		players[activePlayerIndex].isActive = false;
		activePlayerIndex = index;
		players[activePlayerIndex].isActive = true;
	}
}

void CApplication::ChangeState(GameState newState)
{
	mCurrentState = newState;
}

/*
CApplication::CApplication()
	:mCurrentState(GameState::START_SCREEN)
{

}
*/

/*
void CApplication::OnMouseClick(float x, float y)
{
	if (mText.IsClicked(x, y))
	{

	}
}
*/