#ifndef CCOLLIDERLINE_H
#define CCOLLIDERLINE_H
#include "CCollider.h"
/*
線分コライダの定義
*/
class CColliderLine :public CCollider
{
public:
	CColliderLine() {}
	//コンストラクタ(線分コライダ)
	//CColliderLine(親、親行列、頂点１、頂点２)
	CColliderLine(CCharacter3* parent, CMatrix* matrix, const CVector& v0, const CVector& v1);
	//線分コライダの作成
	//Set(親、親行列、頂点１、頂点２)
	void Set(CCharacter3* parent, CMatrix* matrix, const CVector& v0, const CVector& v1);
	//描画
	void Render();
	//優先度の変更
	void ChangePriority();
};

#endif