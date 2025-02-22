#ifndef CCHARACTER3_H
#define CCHARACTER3_H
//変換行列クラスのインクルード
#include "CTransform.h"
//モデルクラスのインクルード
#include "CModel.h"
#include "CTask.h"
//コライダクラスの宣言
class CCollider;

/*
キャラクタークラス
ゲームキャラクタの基本的な機能を定義する
*/

class CCharacter3 : public CTransform, public CTask
{
public:
	//モデルの設定
	//Model(モデルクラスのポインタ)
	void Model(CModel* m);
	//描画処理
	void Render();
	//デストラクタ
	~CCharacter3();
	//コンストラクタ
	CCharacter3();
	//衝突処理
	virtual void Collision(CCollider* m, CCollider* o) {}
	//コンストラクタ
	CCharacter3(int priority);
protected:
	CModel* mpModel; //モデルのポインタ
};

#endif