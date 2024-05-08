#pragma once
//#include "CRectangle.h"
#include "CTexture.h"
//#include "CCharacter.h"
#include "CBullet.h"
#include "CEnemy.h"
#include "CPlayer.h"
#include "CInput.h"
#include "CFont.h"
//#include "CMiss.h"
#include <vector>
//#include "CCharacterManager.h"
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

class CApplication
{
public:
	~CApplication();
//	static CCharacterManager* CharacterManager();
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
//	static CCharacterManager mCharacterManager;
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
//	CMiss* mpMiss;
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
};