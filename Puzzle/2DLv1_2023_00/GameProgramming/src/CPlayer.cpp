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

void CPlayer::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		isMoving = false;
	}

	if (isMoving)
	{
		if (GetAsyncKeyState(VK_DOWN))
		{
			float y = Y() - 4.0f;
			Y(y);
		}
		if (GetAsyncKeyState(VK_UP))
		{
			float y = Y() + 4.0f;
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