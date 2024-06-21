#include "CPlayer.h"
#include <windows.h>
#include "CApplication.h"
#include <math.h>
#include "glut.h"

#define MOS_POS_X 400 //マウス座標のX補正
#define MOS_POS_Y 300 //マウス座標のY補正
#define SNAP_DISTANCE 10.0f //スナップする距離

void CPlayer::Update()
{
    if (players == nullptr) return;

    if (isMoving && isActive && !isSnapped)
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
        HWND hWnd = GetActiveWindow();
        if (GetCursorPos(&mousePos))
        {
            ScreenToClient(hWnd, &mousePos);
            if (GetAsyncKeyState(VK_LBUTTON))
            {
                //マウスがクリックされた位置がパズルピースの内部にあるかどうかをチェック
                if (mousePos.x >= X() && mousePos.x <= X() + width &&
                    mousePos.y >= Y() && mousePos.y <= Y() + height)
                {
                    //パズルピースをマウスの位置に移動
                    X(mousePos.x - width / 2);
                    Y(mousePos.y - height / 2);
                }
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

        //パズルピースがターゲット位置に十分近づいているかチェック
        if (!isSnapped && abs(X() - targetX) < SNAP_DISTANCE && abs(Y() - targetY) < SNAP_DISTANCE)
        {
            X(targetX);
            Y(targetY);
            isSnapped = true;
        }

        if (isSnapped)
        {
            return;
        }
    }
}

void CPlayer::HandleInput()
{
    if (players == nullptr)return;

    POINT mousePos;
    HWND hWnd = GetActiveWindow();  // アクティブなウィンドウのハンドルを取得
    if (GetCursorPos(&mousePos))
    {
        ScreenToClient(hWnd, &mousePos);
        // mousePos.y = ScreenHeight - mousePos.y;
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

void CPlayer::Render()
{
    CCharacter::Render();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * 3.14159f / 180;
        glVertex2f(targetX + cos(degInRad) * 10, targetY + sin(degInRad) * 10);
    }
    glEnd();

    if (isActive)
    {
        //スナップした場合は緑色、そうでない場合は赤色で枠を描画
        if (isSnapped)
            glColor3f(0.0f, 1.0f, 0.0f);
        else
            glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(3.0f);
        //枠
        glBegin(GL_LINE_LOOP);
        glVertex2f(X() - 10, Y() - 10);
        glVertex2f(X() + 10, Y() - 10);
        glVertex2f(X() + 10, Y() + 10);
        glVertex2f(X() - 10, Y() + 10);
        glEnd();
    }
}

void CPlayer::SetActivePlayer(int index)
{
    activePlayerIndex = index; //アクティブなプレイヤーを設定
    //アクティブなプレイヤーのisActiveをtrueに、他をfalseに設定
    for (int i = 0; i < players->size(); ++i)
    {
        (*players)[i].isActive = (i == index);
    }
}