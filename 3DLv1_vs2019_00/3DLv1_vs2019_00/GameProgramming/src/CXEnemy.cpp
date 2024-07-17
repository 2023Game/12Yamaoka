#include "CXEnemy.h"
#include "CXPlayer.h"

CXEnemy::CXEnemy()
	:mColSphereBody(this, nullptr, CVector(), 0.5f, CCollider::ETag::EBODY)
	, mColSphereHead(this, nullptr, CVector(0.0f, 0.5f, -0.3f), 0.5f)
	, mColSphereSword(this, nullptr, CVector(-10.0f, 10.0f, 50.0f), 0.3f)
{
}

void CXEnemy::Init(CModelX* model)
{
	CXCharacter::Init(model);
	mColSphereBody.Matrix(&mpCombinedMatrix[8]);
	mColSphereHead.Matrix(&mpCombinedMatrix[11]);
	mColSphereSword.Matrix(&mpCombinedMatrix[21]);
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