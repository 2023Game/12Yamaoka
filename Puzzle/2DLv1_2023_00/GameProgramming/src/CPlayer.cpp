#include "CPlayer.h"
#include <windows.h>
#include "CApplication.h"
#include <math.h>

#define MOS_POS_X 400 //マウス座標のX補正
#define MOS_POS_Y 300 //マウス座標のY補正

bool isMoving = true;
int activePlayerIndex = 0;

void CPlayer::Update()
{
    if (players == nullptr) return;

    if (isMoving && isActive)
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

void CPlayer::SetActivePlayer(int index)
{
    if (players != nullptr && index >= 0 && index < players->size())
    {
        (*players)[activePlayerIndex].isActive = false;
        activePlayerIndex = index;
        (*players)[activePlayerIndex].isActive = true;
    }
}

void CPlayer::Render()
{
    CCharacter::Render();

    if (isActive)
    {
        //枠の色と太さ
        glColor3f(0.0f, 1.0f, 0.0f);
        glLineWidth(3.0f);
        //枠
        glBegin(GL_LINE_LOOP);
        glVertex2f(X() - width / 2, Y() - height / 2);
        glVertex2f(X() + width / 2, Y() - height / 2);
        glVertex2f(X() + width / 2, Y() + height / 2);
        glVertex2f(X() - width / 2, Y() + height / 2);
        glEnd();
    }
}