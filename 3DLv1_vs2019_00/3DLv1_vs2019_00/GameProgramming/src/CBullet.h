#ifndef CBULLET_H
#define CBULLET_H
//キャラクタクラスのインクルード
#include "CCharacter3.h"
//三角形クラスのインクルード
#include "CTriangle.h"
#include "CCollider.h"

/*
弾クラス
三角形を飛ばす
*/
class CBullet : public CCharacter3 
{
public:
	//幅と奥行きの設定
	//Set(幅, 奥行)
	void Set(float w, float d);
	//更新
	void Update();
	//描画
	void Render();
	CBullet();
	//衝突判定
	//Collision(コライダ1,コライダ2)
	void Collision(CCollider* m, CCollider* o);
	void Collision();
private:
	//三角形
	CTriangle mT;
	//生存時間
	int mLife;
	//コライダ
	CCollider mCollider;
};

#endif