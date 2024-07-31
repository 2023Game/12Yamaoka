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
	//最初に一度だけ実行するプログラム
	void Start();
	//繰り返し実行するプログラム
	void Update();
	//モデルビュー行列の取得
	static const CMatrix& ModelViewInverse();
	static CUi* Ui(); //UIクラスのインスタンスを取得
private:
	CSound mSoundBgm;	//BGM
	CSound mSoundOver;	//ゲームオーバー
	CGame* mpGame;
	enum class EState
	{
		ESTART,	//ゲーム開始
		EPLAY,	//ゲーム中
		ECLEAR,	//ゲームクリア
		EOVER,	//ゲームオーバー
	};
	EState mState;
	CPlayer* mpPlayer;
	static CTexture mTexture;
	CEnemy* mpEnemy;
	CInput mInput;
	CFont mFont;
	//モデルクラスのインスタンス作成
	CModel mModel;
	CModel mBackGround; //背景モデル
	CPlayer mPlayer;
	CModel Render;
	//C5モデル
	CModel mModelC5;
	//モデルビューの逆行列
	static CMatrix mModelViewInverse;
	//モデルからコライダを生成
	CColliderMesh mColliderMesh;
	static CUi* spUi;
	CModelX mModelX;
	CMatrix mMatrix;
	CXPlayer mXPlayer; //キャラクタのインスタンス
	CXEnemy mXEnemy;   //敵のインスタンス
	CModelX mKnight;
	CPaladin* mpPaladin;
};