#include "CXPlayer.h"
#define VELOCITY CVector(0.0f,0.0f,0.1f) //移動速度

void CXPlayer::Update()
{
	//Aキーを押すと左へ2度回転、Dキーを押すと右へ2度回転、Wキーを押すと向いている方向へ0.1移動
	//Aキーが押されていれば、Y軸の回転値に2加算
	if (mInput.Key('A'))
	{
		mMatrix = mMatrix * CMatrix().RotateY(2);
	}
	//Dキーが押されていれば、Y軸の回転値に2減算
	if (mInput.Key('D'))
	{
		mMatrix = mMatrix * CMatrix().RotateY(-2);
	}
	//Wキーが押されていれば、アニメーション番号1、長さ60に切り替え
	//回転行列から回転後のZ軸ベクトルを取得し、現在位置より向いている方向へ0.1移動
	if (mInput.Key('W'))
	{
		mCharacter.ChangeAnimation(1, true, 60);
		mPosition = mPosition + VELOCITY * mMatrixRotate;
	}
	//Wキーが押されていなければ、アニメーション番号0、長さ60に切り替え
	else
	{
		mCharacter.ChangeAnimation(0, true, 60);
	}

	mCharacter.Update();
	mCharacter.Render();
}