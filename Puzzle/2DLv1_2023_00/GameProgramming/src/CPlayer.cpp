#include "CPlayer.h"
#include <windows.h>
#include "CApplication.h"
#include <math.h>

#define MOS_POS_X 400 //�}�E�X���W��X�␳
#define MOS_POS_Y 300 //�}�E�X���W��Y�␳

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
        //�g�̐F�Ƒ���
        glColor3f(0.0f, 1.0f, 0.0f);
        glLineWidth(3.0f);
        //�g
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
    activePlayerIndex = index; //�A�N�e�B�u�ȃv���C���[��ݒ�
    //�A�N�e�B�u�ȃv���C���[��isActive��true�ɁA����false�ɐݒ�
    for (int i = 0; i < players->size(); ++i) 
    {
        (*players)[i].isActive = (i == index);
    }
}

/*
int mx, my; //�}�E�X�J�[�\�����W�擾�p
    CInput::GetMousePos(&mx, &my); //�}�E�X�J�[�\�����W�̎擾
    if (CKey::Push(VK_LBUTTON)) //�}�E�X�N���b�N���o
    {
        printf("%d,%d\n", mx, my); //�}�E�X���W�R���\�[���o��
    }

    //�Q�[����ʒ��S����̍��W�֕ϊ�
    mx -= MOS_POS_X;
    my = MOS_POS_Y - my;
    //�v���C���[�ƃ}�E�X���W�Ƃ̍�
    mx -= X();
    my -= Y();
    //�������������ֈړ�������
    if (abs(mx) > abs(my))
    {
        //X���ňړ�
        if (mx < 0)
        {
            //���ֈړ�
            X() -= 3;
            mFx = -1;
            mFy = 0;
        }
        else
        {
            //�E�ֈړ�
            X() += 3;
            mFx = 1;
            mFy = 0;
        }
    }
    else
    {
        //Y���ňړ�
        if (my < 0)
        {
            //���ֈړ�
            Y() -= 3;
            mFx = 0;
            mFy = -1;
        }
        else
        {
            //��ֈړ�
            Y() += 3;
            mFx = 0;
            mFy = 1;
        }
    }
*/