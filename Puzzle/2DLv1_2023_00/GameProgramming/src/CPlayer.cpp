/*
#include "CPlayer.h"

void CPlayer::Update()
{
	if (mInput.Key('A'))
	{
		float x = X() - 4.0f;
		X(x);
	}
	if (mInput.Key('D'))
	{
		float x = X() + 4.0f;
		X(x);
	}

	if (mInput.Key('W'))
	{
		float y = Y() + 4.0f;
		Y(y);
	}
	if (mInput.Key('S'))
	{
		float y = Y() - 4.0f;
		Y(y);
	}
}
*/

#include "CPlayer.h"
#include <windows.h>

bool isMoving = true;
int activePlayerIndex = 0;

void CPlayer::Update()
{
	if (players == nullptr) return;

	if (isActive)
	{
		if (GetAsyncKeyState(VK_RETURN))
		{
			isActive = false;
			activePlayerIndex++;
			if (activePlayerIndex >= players->size())
			{
				activePlayerIndex = 0;
			}
			(*players)[activePlayerIndex].isActive = true;
		}
	}

	if (isMoving && this == &(*players)[activePlayerIndex])
	{
		if (GetAsyncKeyState(VK_UP))
		{
			float y = Y() + 4.0f;
			Y(y);
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			float y = Y() - 4.0f;
			Y(y);
		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			float x = X() - 4.0f;
			X(x);
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			float x = X() + 4.0f;
			X(x);
		}

		static int lastMouseY = 0;
		static int lastMouseX = 0;

		POINT mousePos;
		if (GetCursorPos(&mousePos))
		{
			ScreenToClient(HWND_BOTTOM, &mousePos);
			if (GetAsyncKeyState(VK_LBUTTON))
			{
				if (mousePos.y < lastMouseY)
				{
					float y = Y() + 4.0f;
					Y(y);
				}
				else if (mousePos.y > lastMouseY)
				{
					float y = Y() - 4.0f;
					Y(y);
				}
				lastMouseY = mousePos.y;

				if (mousePos.x < lastMouseX)
				{
					float x = X() - 4.0f;
					X(x);
				}
				else if (mousePos.x > lastMouseX)
				{
					float x = X() + 4.0f;
					X(x);
				}
				lastMouseX = mousePos.x;
			}
		}
	}
}

void CPlayer::HandleInput()
{
	if (players == nullptr)return;

	POINT mousePos;
	if (GetCursorPos(&mousePos))
	{
		ScreenToClient(HWND_BOTTOM, &mousePos);
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			if (mousePos.x >= X() && mousePos.x <= X() + width &&
				mousePos.y >= Y() && mousePos.y <= Y() + height)
			{
				float y = Y() + 4.0f;
				Y(y);
			}
		}
	}
}

/*
	moveUp = GetAsyncKeyState(VK_UP);
	moveDown = GetAsyncKeyState(VK_DOWN);
	moveLeft = GetAsyncKeyState(VK_LEFT);
	moveRight = GetAsyncKeyState(VK_RIGHT);
	*/
