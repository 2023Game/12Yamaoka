#include "CPlayer.h"
#include <windows.h>
#include "CApplication.h"
#include <math.h>

#define MOS_POS_X 400 //マウス座標のX補正
#define MOS_POS_Y 300 //マウス座標のY補正

void CPlayer::Update()
{
    if (players == nullptr) return;
    
    /*
    if (GetAsyncKeyState(VK_RETURN) & 0x8000)
    {
        isMoving = !isMoving;
    }
    */

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

/*
int mx, my; //マウスカーソル座標取得用
    CInput::GetMousePos(&mx, &my); //マウスカーソル座標の取得
    if (CKey::Push(VK_LBUTTON)) //マウスクリック検出
    {
        printf("%d,%d\n", mx, my); //マウス座標コンソール出力
    }

    //ゲーム画面中心からの座標へ変換
    mx -= MOS_POS_X;
    my = MOS_POS_Y - my;
    //プレイヤーとマウス座標との差
    mx -= X();
    my -= Y();
    //距離が遠い方へ移動さえる
    if (abs(mx) > abs(my))
    {
        //X軸で移動
        if (mx < 0)
        {
            //左へ移動
            X() -= 3;
            mFx = -1;
            mFy = 0;
        }
        else
        {
            //右へ移動
            X() += 3;
            mFx = 1;
            mFy = 0;
        }
    }
    else
    {
        //Y軸で移動
        if (my < 0)
        {
            //下へ移動
            Y() -= 3;
            mFx = 0;
            mFy = -1;
        }
        else
        {
            //上へ移動
            Y() += 3;
            mFx = 0;
            mFy = 1;
        }
    }
*/