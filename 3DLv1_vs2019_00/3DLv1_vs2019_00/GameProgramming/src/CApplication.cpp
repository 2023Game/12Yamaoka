//OpenGL
#include "glut.h"
#include "CApplication.h"
#include "CVector.h"
#include "CTriangle.h"
#include "CMatrix.h"
#include "CTransform.h"
#include "CPlayer.h"
#include "CBillBoard.h"
#include "CEnemy3.h"
#include "CCamera.h"
//モデルデータの指定
#define MODEL_OBJ "res\\f14.obj","res\\f14.mtl"
//背景モデルデータの指定
#define MODEL_BACKGROUND  "res\\sky.obj", "res\\sky.mtl"
#define SOUND_BGM "res\\mario.wav" //BGM音声ファイル
#define SOUND_OVER "res\\mdai.wav" //ゲームオーバー音声ファイル
#define MODEL_C5 "res\\c5.obj","res\\c5.mtl" //敵輸送機モデル

//クラスのstatic変数
CTexture CApplication::mTexture;

CTexture* CApplication::Texture()
{
	return &mTexture;
}

CVector mEye;

void CApplication::Start()
{
	//3Dモデルファイルの読み込み
	mModelX.Load(MODEL_FILE);
	mFont.Load("FontG.png", 1, 4096 / 64);
	//キャラクターにモデルを設定
	mXPlayer.Init(&mModelX);

	//mKnightにknight_low.xファイルを読む
	mKnight.Load("res\\knight\\knight_low.x");
	mKnight.SeparateAnimationSet(0, 10, 80, "walk"); //1:移動
	mKnight.SeparateAnimationSet(0, 1530, 1830, "idle1"); //2:待機
	mKnight.SeparateAnimationSet(0, 10, 80, "walk"); //3:ダミー
	mKnight.SeparateAnimationSet(0, 10, 80, "walk"); //4:ダミー
	mKnight.SeparateAnimationSet(0, 10, 80, "walk"); //5:ダミー
	mKnight.SeparateAnimationSet(0, 10, 80, "walk"); //6:ダミー
	mKnight.SeparateAnimationSet(0, 440, 520, "attack1"); //7:Attack1
	mKnight.SeparateAnimationSet(0, 520, 615, "attack2"); //8:Attack2
	mKnight.SeparateAnimationSet(0, 10, 80, "walk"); //9:ダミー
	mKnight.SeparateAnimationSet(0, 10, 80, "walk"); //10:ダミー
	mKnight.SeparateAnimationSet(0, 1160, 1260, "death1"); //11:ダウン
	//敵の初期位置
	mXEnemy.Init(&mKnight);
	//敵の配置
	mXEnemy.Position(CVector(7.0f, 0.0f, 0.0f));
	//敵のアニメーション
	mXEnemy.ChangeAnimation(2, true, 200);

	mpPaladin = new CPaladin();
	mpPaladin->Position(CVector(-1.0f, 0.0f, 5.0f));
	mpPaladin->ChangeAnimation(1, true, 60);
}

void CApplication::Update()
{
	//キャラクタークラスの更新
	mXPlayer.Update();
	//敵の更新
	mXEnemy.Update();
	//mpPaladin
	mpPaladin->Update();

	//カメラのパラメータを作成する
	CVector e, c, u; //視点,注視点,上方向
	//視点を求める
	e = CVector(1.0f, 2.0f, 10.0f);
	//注視点を求める
	c = CVector();
	//上方向を求める
	u = CVector(0.0f, 1.0f, 0.0f);
	//カメラの設定
	gluLookAt(e.X(), e.Y(), e.Z(), c.X(), c.Y(), c.Z(), u.X(), u.Y(), u.Z());
	//モデルビューの取得
	glGetFloatv(GL_MODELVIEW_MATRIX, mModelViewInverse.M());
	//逆行列の取得dd
	mModelViewInverse = mModelViewInverse.Transpose();
	mModelViewInverse.M(0, 3, 0);
	mModelViewInverse.M(1, 3, 0);
	mModelViewInverse.M(2, 3, 0);

	//アニメーションの時間を加算
	mModelX.AnimationSet()[0]->Time(
		mModelX.AnimationSet()[0]->Time() + 1.0f);
	mModelX.AnimationSet()[0]->Time(
		(int)mModelX.AnimationSet()[0]->Time() %
		(int)(mModelX.AnimationSet()[0]->MaxTime() + 1));

	//X軸＋回転
	if (mInput.Key('K'))
	{
		mMatrix = mMatrix * CMatrix().RotateX(1);  //下
	}
	if (mInput.Key('I'))
	{
		mMatrix = mMatrix * CMatrix().RotateX(-1); //上
	}
	//Y軸＋回転
	if (mInput.Key('L'))
	{
		mMatrix = mMatrix * CMatrix().RotateY(1);  //右
	}
	if (mInput.Key('J'))
	{
		mMatrix = mMatrix * CMatrix().RotateY(-1); //左
	}

	//行列設定
	glMultMatrixf(mMatrix.M());
	//頂点にアニメーションを適用する
	mModelX.AnimateVertex();
	//モデル描画
	mXPlayer.Render();
	//mpPaladin
	mpPaladin->Render();
	//コライダの描画
	CCollisionManager::Instance()->Render();
	//敵描画
	mXEnemy.Render();
	//2D描画開始
	CCamera::Start(0, 800, 0, 600);
	mFont.Draw(20, 20, 10, 12, "3D PROGRAMMING");
	//2Dの描画終了
	CCamera::End();

	//衝突処理
	CCollisionManager::Instance()->Collision();
}

CMatrix CApplication::mModelViewInverse;

const CMatrix& CApplication::ModelViewInverse()
{
	return mModelViewInverse;
}

CUi* CApplication::spUi = nullptr;

CUi* CApplication::Ui()
{
	return spUi; //インスタンスのポインタを返す
}

CApplication::~CApplication()
{
	delete spUi; //インスタンスUiの削除
}