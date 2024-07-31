#pragma once
#include "CTexture.h"
#include "CBullet.h"
#include "CEnemy.h"
#include "CPlayer.h"
#include "CInput.h"
#include "CFont.h"
#include <vector>
#include "CGame.h"
#include "CSound.h"
#include "CModel.h"
#include "CCharacter3.h"
#include "CTaskManager.h"
#include "CCollisionManager.h"
#include "CColliderTriangle.h"
#include "CColliderMesh.h"
#include "CUi.h"
#include "CModelX.h"
#include "CXCharacter.h"
#include "CXPlayer.h"
#include "CXEnemy.h"
#include "CPaladin.h"

class CApplication
{
public:
	~CApplication();
	static CTexture* Texture();
	//�ŏ��Ɉ�x�������s����v���O����
	void Start();
	//�J��Ԃ����s����v���O����
	void Update();
	//���f���r���[�s��̎擾
	static const CMatrix& ModelViewInverse();
	static CUi* Ui(); //UI�N���X�̃C���X�^���X���擾
private:
	CSound mSoundBgm;	//BGM
	CSound mSoundOver;	//�Q�[���I�[�o�[
	CGame* mpGame;
	enum class EState
	{
		ESTART,	//�Q�[���J�n
		EPLAY,	//�Q�[����
		ECLEAR,	//�Q�[���N���A
		EOVER,	//�Q�[���I�[�o�[
	};
	EState mState;
	CPlayer* mpPlayer;
	static CTexture mTexture;
	CEnemy* mpEnemy;
	CInput mInput;
	CFont mFont;
	//���f���N���X�̃C���X�^���X�쐬
	CModel mModel;
	CModel mBackGround; //�w�i���f��
	CPlayer mPlayer;
	CModel Render;
	//C5���f��
	CModel mModelC5;
	//���f���r���[�̋t�s��
	static CMatrix mModelViewInverse;
	//���f������R���C�_�𐶐�
	CColliderMesh mColliderMesh;
	static CUi* spUi;
	CModelX mModelX;
	CMatrix mMatrix;
	CXPlayer mXPlayer; //�L�����N�^�̃C���X�^���X
	CXEnemy mXEnemy;   //�G�̃C���X�^���X
	CModelX mKnight;
	CPaladin* mpPaladin;
};