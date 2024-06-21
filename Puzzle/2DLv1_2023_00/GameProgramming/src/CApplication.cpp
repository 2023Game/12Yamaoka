#include "CApplication.h"
#include <vector>
#include "CUi.h"
#include <iostream>

void CApplication::Start()
{	
	texture1.Load("apple.psd");
	CPlayer player1;
	player1.Set(100.0f, 100.0f, 50.0f, 50.0f, 350.0f, 350.0f);
	player1.Texture(&texture1, 0, 300, 200, 0);
	players.push_back(player1);

	texture2.Load("apple.psd");
	CPlayer player2;
	player2.Set(300.0f, 100.0f, 50.0f, 50.0f, 450.0f, 350.0f);
	player2.Texture(&texture2, 300, 600, 200, 0);
	players.push_back(player2);

	texture3.Load("apple.psd");
	CPlayer player3;
	player3.Set(500.0f, 100.0f, 50.0f, 50.0f, 350.0f, 250.0f);
	player3.Texture(&texture3, 0, 300, 400, 200);
	players.push_back(player3);

	texture4.Load("apple.psd");
	CPlayer player4;
	player4.Set(700.0f, 100.0f, 50.0f, 50.0f, 450.0f, 250.0f);
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

POINT prevMousePos;
bool prevLeftClickState = false;

void CApplication::Update()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		//現在のplayerを非アクティブに設定
		players[activePlayerIndex].isActive = false;
		//次のplayerのインデックスに移動
		activePlayerIndex++;
		//プレイヤーリストの最後に達したら最初に戻る
		if (activePlayerIndex >= players.size())
		{
			activePlayerIndex = 0;
		}
		//新しいアクティブプレイヤーを設定
		SetActivePlayer(activePlayerIndex);
	}

	POINT mousePos;
	if (GetCursorPos(&mousePos))
	{
		HWND hWnd = GetActiveWindow();
		ScreenToClient(hWnd, &mousePos);

		//マウスの位置が変化した場合にのみ出力
		if (mousePos.x != prevMousePos.x || mousePos.y != prevMousePos.y)
		{
			std::cout << "Mouse poaition: (" << mousePos.x << "," << mousePos.y << ")" << std::endl;
			prevMousePos = mousePos; //現在のマウスの位置を保存
		}

		bool leftClickState = (GetAsyncKeyState(VK_LBUTTON) != 0);

		//マウスのクリック状況が変化した場合にのみ出力
		if (leftClickState!=prevLeftClickState)
		{
			if (leftClickState)
			{
				std::cout << "Left mouse button clicked." << std::endl;
			}
			else
			{
				std::cout << "Left mouse button released." << std::endl;
			}
			std::cout << "Left mouse buttonstate: " << (leftClickState ? "Down" : "Up") << std::endl;
			prevLeftClickState = leftClickState; //現在のクリック状態を保存

			bool isPlayerActive = false;
			for (int i = 0; i < players.size(); i++)
			{
				//マウスがクリックされた位置が画像の内部にあるかどうかをチェック
				if (mousePos.x >= players[i].X() && mousePos.x <= players[i].X() + players[i].width &&
					mousePos.y >= players[i].Y() && mousePos.y <= players[i].Y() + players[i].height)
				{
					std::cout << "Image" << i << "cliced." << std::endl;
					//画像を選択し、isActiveをtrueに設定
					activePlayerIndex = i;
					isPlayerActive = true;
					SetActivePlayer(i);

					std::cout << "Player" << i << "position: (" << players[i].X() << "." << players[i].Y() << std::endl;
					std::cout << "Player" << i << "size: (" << players[i].width << "," << players[i].height << ")" << std::endl;
					std::cout << "Player" << i << "isActive" << (players[i].isActive ? "True" : "False") << std::endl;
				}
				else
				{
					//画像の外側がクリックされた場合isActiveをfalseに設定
					players[i].isActive = false;
				}
			}
			//選択された画像(isActiveがtrue)を動かす
			if (isPlayerActive)
			{
				//画像をマウスの位置に移動
				players[activePlayerIndex].X(mousePos.x - players[activePlayerIndex].width / 2);
				players[activePlayerIndex].Y(mousePos.y - players[activePlayerIndex].height / 2);
			}
		}
	}
	
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (mCurrentState == GameState::START_SCREEN)
		{
			ChangeState(GameState::GAMEPLAY);
		}
	}

	if (CheckIfPuzzleIsComplete())
	{

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