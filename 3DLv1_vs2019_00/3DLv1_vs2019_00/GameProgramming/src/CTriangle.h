#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include "CVector.h"
#include "CMatrix.h"

//三角形クラス
class CTriangle
{
public:
	//頂点座標設定
	//Vertex(頂点１，頂点２，頂点３)
	void Vertex(const CVector& v0, const CVector& v1, const CVector& v2);
	//法線設定
	//Normal(法線ベクトル)
	void Normal(const CVector& n);
	//Normal(法線ベクトル1,法線ベクトル2,法線ベクトル3)
	void Normal(const CVector& v0, const CVector& v1, const CVector& v2);
	//描画
	void Render();
	//マテリアル番号の取得
	int MaterialIdx();
	//マテリアル番号の設定
	//Material(マテリアル番号)
	void MaterialIdx(int idx);
	//UV設定
	void UV(const CVector& v0, const CVector& v1, const CVector& v2);
	//描画
	//Render(行列)
	void Render(const CMatrix& m);
	//頂点座標を得る
	const CVector& V0() const; //mV[0]を返します
	const CVector& V1() const; //mV[1]を返します
	const CVector& V2() const; //mV[2]を返します
	//法線を得る
	const CVector& N0() const; //mN[0]を返します
	const CVector& N1() const; //mN[1]を返します
	const CVector& N2() const; //mN[2]を返します
	//UVを得る
	const CVector& U0() const; //mUv[0]を返します
	const CVector& U1() const; //mUv[1]を返します
	const CVector& U2() const; //mUv[2]を返します
private:
	CVector mV[3]; //頂点座標
	CVector mN[3]; //法線
	int mMaterialIdx; //マテリアル番号
	CVector mUv[3]; //テクスチャマッピング
};
#endif