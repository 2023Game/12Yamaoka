#include "CApplication.h"
//OpenGL
#include "glut.h"
#include "CVector.h"
#include "CTriangle.h"
#include "CMatrix.h"
#include "CTransform.h"
#include "CPlayer.h"
#include "CBillBoard.h"
#include "CEnemy3.h"
#include "CCamera.h"
//���f���f�[�^�̎w��
#define MODEL_OBJ "res\\f14.obj","res\\f14.mtl"
//�w�i���f���f�[�^�̎w��
#define MODEL_BACKGROUND  "res\\sky.obj", "res\\sky.mtl"

//�N���X��static�ϐ�
CTexture CApplication::mTexture;

#define SOUND_BGM "res\\mario.wav" //BGM�����t�@�C��
#define SOUND_OVER "res\\mdai.wav" //�Q�[���I�[�o�[�����t�@�C��
//�G�A���@���f��
#define MODEL_C5 "res\\c5.obj","res\\c5.mtl"

CTexture* CApplication::Texture()
{
	return &mTexture;
}

CVector mEye;

void CApplication::Start()
{
	mFont.Load("FontG.png", 1, 4096 / 64);
}

void CApplication::Update()
{
	//�J�����̃p�����[�^���쐬����
	CVector e, c, u; //���_,�����_,�����
	//���_�����߂�
	e = CVector(1.0f, 2.0f, 10.0f);
	//�����_�����߂�
	c = CVector();
	//����������߂�
	u = CVector(0.0f, 1.0f, 0.0f);
	//�J�����̐ݒ�
	gluLookAt(e.X(), e.Y(), e.Z(), c.X(), c.Y(), c.Z(), u.X(), u.Y(), u.Z());
	//���f���r���[�̎擾
	glGetFloatv(GL_MODELVIEW_MATRIX, mModelViewInverse.M());
	//�t�s��̎擾dd
	mModelViewInverse = mModelViewInverse.Transpose();
	mModelViewInverse.M(0, 3, 0);
	mModelViewInverse.M(1, 3, 0);
	mModelViewInverse.M(2, 3, 0);

	//2D�`��J�n
	CCamera::Start(0, 800, 0, 600);

	mFont.Draw(20, 20, 10, 12, "3D PROGRAMMING");

	//2D�̕`��I��
	CCamera::End();
}

CMatrix CApplication::mModelViewInverse;

const CMatrix& CApplication::ModelViewInverse()
{
	return mModelViewInverse;
}

CUi* CApplication::spUi = nullptr;

CUi* CApplication::Ui()
{
	return spUi; //�C���X�^���X�̃|�C���^��Ԃ�
}

CApplication::~CApplication()
{
	delete spUi; //�C���X�^���XUi�̍폜
}