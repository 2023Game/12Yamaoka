#include "CBullet.h"
#define VELOCITY CVector(0.0f,0.0f,1.0f)

//���Ɖ��s���̐ݒ�
//Set(��, ���s)
void CBullet::Set(float w, float d) 
{
	//�X�P�[���ݒ�
	mScale = CVector(1.0f, 1.0f, 1.0f);
	//�O�p�`�̒��_�ݒ聨�q���g 3
	mT.Vertex(CVector(-w, 0, 0), CVector(w, 0, 0), CVector(0, 0, -d));
	//�O�p�`�̖@���ݒ�
	mT.Normal(CVector(0.0f, 1.0f, 0.0f));
}

//�X�V
void CBullet::Update() 
{
	CTransform::Update();
	//�ʒu�X�V�@�i�s�����ւP�i�ށ��q���g 17
	mPosition = mPosition + VELOCITY * mMatrixRotate;
}

//�`��
void CBullet::Render()
{
	//DIFFUSE���F�ݒ�
	float c[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	//�O�p�`�`�恨�q���g 12
	mT.Render(mMatrix);
}