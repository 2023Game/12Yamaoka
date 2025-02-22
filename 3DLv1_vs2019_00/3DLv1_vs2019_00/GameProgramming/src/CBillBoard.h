#ifndef CBILLBOARD_H
#define CBILLBOARD_H
#include "CCharacter3.h"
/*
ビルボードクラス
常にカメラの方を向く四角形
*/
class CBillBoard : public CCharacter3
{
public:
	//コンストラクタ
	CBillBoard();
	//CBillBoard(位置、幅、高さ)
	CBillBoard(CVector pos, float w, float h);
	//位置と大きさの設定
	//Set(位置、幅、高さ)
	void Set(CVector pos, float w, float h);
	//更新
	void Update();
	//描画
	void Render();
	void Render(CMaterial* mpMaterial);
	//CBillBoard(位置、幅、高さ、優先度)
	CBillBoard(CVector pos, float w, float h, int priority);
protected:
	//三角形２つ
	CTriangle mT[2];
	//マテリアル
	CMaterial mMaterial;
};

#endif