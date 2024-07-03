#include "CXPlayer.h"

void CXPlayer::Update()
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
	
	CXCharacter::Update();
}