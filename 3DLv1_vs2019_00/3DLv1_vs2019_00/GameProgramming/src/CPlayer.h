#ifndef CPLAYER_H
#define CPLAYER_H
//キャラクタクラスのインクルード
#include "CCharacter3.h"
#include "CInput.h"
#include "CMatrix.h"
#include "CBullet.h"
#include "CColliderLine.h"

/*
プレイヤークラス
キャラクタクラスを継承
*/

class CPlayer : public CCharacter3
{
public:
	CPlayer::CPlayer()
		: mLine(this, &mMatrix, CVector(0.0f, 0.0f, -14.0f), CVector(0.0f, 0.0f, 17.0f))
		, mLine2(this, &mMatrix, CVector(0.0f, 5.0f, -8.0f), CVector(0.0f, -3.0f, -8.0f))
		, mLine3(this, &mMatrix, CVector(9.0f, 0.0f, -8.0f), CVector(-9.0f, 0.0f, -8.0f))
	{
		//インスタンスの設定
		spInstance = this;
	}
	//CPlayer(位置、回転、スケール)
	CPlayer(const CVector& pos, const CVector& rot, const CVector& scale);
	//更新処理
	void Update();
	//衝突処理
	void Collision(CCollider* m, CCollider* o);
	void Collision();
	//インスタンスのポインタの取得
	static CPlayer* Instance();
private:
	CInput mInput;
	CColliderLine mLine; //線分コライダ
	CColliderLine mLine2;
	CColliderLine mLine3;
	//プレイヤーのインスタンス
	static CPlayer* spInstance;
};

#endif