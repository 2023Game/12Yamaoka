#include "CPlayer.h"
#include <windows.h>
#include "CApplication.h"
#include <math.h>

#define MOS_POS_X 400 //�}�E�X���W��X�␳
#define MOS_POS_Y 300 //�}�E�X���W��Y�␳

bool isMoving = true;
int activePlayerIndex = 0;

void CPlayer::Update()
{
    int mx, my; //�}�E�X�J�[�\�����W�擾�p
    CInput::GetMousePos(&mx, &my); //�}�E�X�J�[�\���̎擾
    
    //�}�E�X�N���b�N���o
    if (CKey::Push(VK_LBUTTON))
    {
        printf("%d,%d\n", mx, my);
    }

    //�Q�[����ʒ��S����̍��W�֕ϊ�����
    mx -= MOS_POS_X;
    my = MOS_POS_Y - my;

    //�v���C���[�ƃ}�E�X���W�Ƃ̍������߂�
    mx -= x;
    my -= y;

    //�������������ֈړ�������
    if (abs(mx) > abs(my))
    {
        if (mx < 0)
        {
            x -= 3;
            mFx = -1;
            mFy = 0;
        }
        else
        {
            x += 3;
            mFx = 1;
            mFy = 0;
        }
    }

    if (players == nullptr) return;

    if (isActive)
    {
        if (GetAsyncKeyState(VK_RETURN)& 0x8000)
        {
            isActive = false;
            activePlayerIndex++;
            if (activePlayerIndex >= players->size())
            {
                activePlayerIndex = 0;
            }
            (*players)[activePlayerIndex].isActive = true;
        }

        if (GetAsyncKeyState('1') & 0x8000)
        {
            SetActivePlayer(0);
        }
        else if (GetAsyncKeyState('2') & 0x8000)
        {
            SetActivePlayer(1);
        }
    }

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

/*
	moveUp = GetAsyncKeyState(VK_UP);
	moveDown = GetAsyncKeyState(VK_DOWN);
	moveLeft = GetAsyncKeyState(VK_LEFT);
	moveRight = GetAsyncKeyState(VK_RIGHT);
*/
