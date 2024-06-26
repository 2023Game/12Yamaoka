#include "CApplication.h"
#include <vector>
#include "CUi.h"
#include <iostream>
#include <random>
#include <chrono>
#include <thread>

void CApplication::Start()
{
	//�v���C���[�̏����ʒu�������_���ɐݒ�
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<float> dist(10.0f, 400.0f);

	texture1.Load("apple.png");
	CPlayer player1;
	player1.Set(dist(mt), dist(mt), 50.0f, 50.0f, 350.0f, 350.0f);
	player1.Texture(&texture1, 0, 300, 200, 0);
	players.push_back(player1);

	texture2.Load("apple.png");
	CPlayer player2;
	player2.Set(dist(mt), dist(mt), 50.0f, 50.0f, 450.0f, 350.0f);
	player2.Texture(&texture2, 300, 600, 200, 0);
	players.push_back(player2);

	texture3.Load("apple.png");
	CPlayer player3;
	player3.Set(dist(mt), dist(mt), 50.0f, 50.0f, 350.0f, 250.0f);
	player3.Texture(&texture3, 0, 300, 400, 200);
	players.push_back(player3);

	texture4.Load("apple.png");
	CPlayer player4;
	player4.Set(dist(mt), dist(mt), 50.0f, 50.0f, 450.0f, 250.0f);
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
	mpClear = new CClear();
}

POINT prevMousePos;
bool prevLeftClickState = false;
bool prevRightClickState = false;

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
		//()�~���b�x��
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	POINT mousePos;
	if (GetCursorPos(&mousePos))
	{
		HWND hWnd = GetActiveWindow();
		ScreenToClient(hWnd, &mousePos);

		bool rightClickState = (GetAsyncKeyState(VK_RBUTTON) != 0);
		
		//�}�E�X�̃N���b�N�󋵂��ω������ꍇ
		if (rightClickState != prevRightClickState)
		{
			//�}�E�X���N���b�N���ꂽ�ꍇ
			if (rightClickState)
			{
				for (int i = 0; i < players.size(); i++)
				{
					//�}�E�X���N���b�N���ꂽ�ʒu���摜�̓����ɂ��邩�ǂ������`�F�b�N
					if (mousePos.x >= players[i].X() && mousePos.x <= players[i].X() + players[i].width &&
						mousePos.y >= players[i].Y() && mousePos.y <= players[i].Y() + players[i].height)
					{
						//�N���b�N���ꂽplayer�̃A�N�e�B�u�ɐݒ�
						activePlayerIndex = i;
						SetActivePlayer(activePlayerIndex);
						break;
					}
				}
			}
		prevRightClickState = rightClickState; //���݂̃N���b�N��Ԃ�ۑ�
		}	
	}

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (mCurrentState == GameState::START_SCREEN)
		{
			ChangeState(GameState::GAMEPLAY);
		}
	}

	if (GetCursorPos(&mousePos))
	{
		HWND hWnd = GetActiveWindow();
		ScreenToClient(hWnd, &mousePos);

		bool leftClickState = (GetAsyncKeyState(VK_LBUTTON) != 0);

		if (leftClickState != prevLeftClickState)
		{
			if (mCurrentState == GameState::START_SCREEN)
			{
				ChangeState(GameState::GAMEPLAY);
			}
			/*
			else if (mCurrentState == GameState::GAMEPLAY)
			{
				if (CheckIfPuzzleIsComplete())
				{
					ChangeState(GameState::GAMECLEAR);
				}
				else
				{
					for (auto& player : players)
					{
						player.Render();
						player.Update();
					}
				}
			}
			*/
		}
		prevLeftClickState = leftClickState;
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

	case GameState::GAMECLEAR:
		mRectangle.Render();
		mpClear->Update();
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

bool CApplication::CheckIfPuzzleIsComplete() const
{
	for (const auto& player : players)
	{
		if (!player.IsInCorrectPosition())
		{
			return false;
		}
	}
	return true;
}