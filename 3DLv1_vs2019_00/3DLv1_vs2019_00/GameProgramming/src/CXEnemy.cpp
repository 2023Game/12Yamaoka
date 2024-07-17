#include "CXEnemy.h"
#include "CXPlayer.h"

CXEnemy::CXEnemy()
	:mColSphereBody(this, nullptr, CVector(0.5f, -1.0f, 0.0f), 1.0f, CCollider::ETag::EBODY)
	, mColSphereHead(this, nullptr, CVector(0.0f, 1.0f, 0.0f), 1.5f)
	, mColSphereSword0(this, nullptr, CVector(0.7f, 3.5f, -0.2f), 0.5f)
	, mColSphereSword1(this, nullptr, CVector(0.5f, 2.5f, -0.2f), 0.5f)
	, mColSphereSword2(this, nullptr, CVector(0.3f, 1.5f, -0.2f), 0.5f)
{
}

void CXEnemy::Init(CModelX* model)
{
	//合成行列の設定
	mColSphereBody.Matrix(&mpCombinedMatrix[1]);
	//頭
	mColSphereHead.Matrix(&mpCombinedMatrix[1]);
	//剣
	mColSphereSword0.Matrix(&mpCombinedMatrix[26]);
	mColSphereSword1.Matrix(&mpCombinedMatrix[26]);
	mColSphereSword2.Matrix(&mpCombinedMatrix[26]);
}

void CXEnemy::Collision(CCollider* m, CCollider* o)
{
	switch (o->Tag())
	{
	case CCollider::ETag::ESWORD: //相手のコライダが剣先
		switch (o->Type())
		{
		case CCollider::EType::ESPHERE: //相手のコライダタイプが球
			//自分のコライダと相手のコライダが衝突している
			if (CCollider::Collision(m, o))
			{
				//30フレームかけてダウンし、繰り返さない
				ChangeAnimation(11, false, 30);
			}
			break;
		}
	}
}