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
#define SOUND_BGM "res\\mario.wav" //BGM�����t�@�C��
#define SOUND_OVER "res\\mdai.wav" //�Q�[���I�[�o�[�����t�@�C��
#define MODEL_C5 "res\\c5.obj","res\\c5.mtl" //�G�A���@���f��

//�N���X��static�ϐ�
CTexture CApplication::mTexture;

CTexture* CApplication::Texture()
{
	return &mTexture;
}

CVector mEye;

void CApplication::Start()
{
	//3D���f���t�@�C���̓ǂݍ���
	mModelX.Load(MODEL_FILE);
	mFont.Load("FontG.png", 1, 4096 / 64);
	//�L�����N�^�[�Ƀ��f����ݒ�
	mXPlayer.Init(&mModelX);

	//�G�̏����ʒu
	mXEnemy.Init(&mModelX);
	//�G�̔z�u
	mXEnemy.Position(CVector(7.0f, 0.0f, 0.0f));
}

void CApplication::Update()
{
	//�L�����N�^�[�N���X�̍X�V
	mXPlayer.Update();
	//�G�̍s�i
	mXEnemy.Update();

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

	//�A�j���[�V�����̎��Ԃ����Z
	mModelX.AnimationSet()[0]->Time(
		mModelX.AnimationSet()[0]->Time() + 1.0f);
	mModelX.AnimationSet()[0]->Time(
		(int)mModelX.AnimationSet()[0]->Time() %
		(int)(mModelX.AnimationSet()[0]->MaxTime() + 1));
	
	//X���{��]
	if (mInput.Key('K'))
	{
		mMatrix = mMatrix * CMatrix().RotateX(1);  //��
	}
	if (mInput.Key('I'))
	{
		mMatrix = mMatrix * CMatrix().RotateX(-1); //��
	}
	//Y���{��]
	if (mInput.Key('L'))
	{
		mMatrix = mMatrix * CMatrix().RotateY(1);  //�E
	}
	if (mInput.Key('J'))
	{
		mMatrix = mMatrix * CMatrix().RotateY(-1); //��
	}

	//�s��ݒ�
	glMultMatrixf(mMatrix.M());
	//���_�ɃA�j���[�V������K�p����
	mModelX.AnimateVertex();
	//���f���`��
	mXPlayer.Render();
	//�G�`��
	mXEnemy.Render();
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