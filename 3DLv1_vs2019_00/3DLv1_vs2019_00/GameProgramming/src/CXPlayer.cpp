#include "CXPlayer.h"

//コライダの初期化
CXPlayer::CXPlayer()
	: mColSphereBody(this, nullptr, CVector(), 0.5f)
	, mColSphereHead(this, nullptr, CVector(0.0f, 5.0f, -3.0f), 0.5f)
	, mColSphereSword(this, nullptr, CVector(-10.0f, 10.0f, 50.0f), 0.3f)
{
}

void CXPlayer::Update()
{
	//スペースキーを押すと攻撃、攻撃後は元の姿勢へ戻し、待機する
	if (mInput.Key(VK_SPACE))
	{
		ChangeAnimation(3, false, 30);
	}
	else
	{
		//アニメーション番号が３の時　アニメーションが終了したら４に切り替える
		if (AnimationIndex() == 3)
		{
			if (IsAnimationFinished())
			{
				ChangeAnimation(4, false, 30);
			}
		}
		//アニメーション番号が４の時、アニメーションが終了したら０に切り替える
		else if (AnimationIndex() == 4)
		{
			if (IsAnimationFinished())
			{
				ChangeAnimation(0, true, 60);
			}
		}
		else
		{
			//Aキーを押すと左へ2度回転、Dキーを押すと右へ2度回転、Wキーを押すと向いている方向へ0.1移動
			//Aキーが押されていれば、Y軸の回転値に2加算
			if (mInput.Key('A'))
			{
				mRotation.Y(mRotation.Y() + 2.0f);
			}
			//Dキーが押されていれば、Y軸の回転値に2減算
			if (mInput.Key('D'))
			{
				mRotation.Y(mRotation.Y() - 2.0f);
			}
			//Wキーが押されていれば、アニメーション番号1、長さ60に切り替え
			//回転行列から回転後のZ軸ベクトルを取得し、現在位置より向いている方向へ0.1移動
			if (mInput.Key('W'))
			{
				ChangeAnimation(1, true, 60);
				Position(Position() + mMatrixRotate.VectorZ() * 0.1);
			}
			//Wキーが押されていなければ、アニメーション番号0、長さ60に切り替え
			else
			{
				ChangeAnimation(0, true, 60);
			}
		}
	}
	CXCharacter::Update();
}

void CXPlayer::Init(CModelX* model)
{
	CXCharacter::Init(model);
	//合成行列の設定
	mColSphereBody.Matrix(&mpCombinedMatrix[8]);
	//頭
	mColSphereHead.Matrix(&mpCombinedMatrix[11]);
	//剣
	mColSphereSword.Matrix(&mpCombinedMatrix[21]);
}