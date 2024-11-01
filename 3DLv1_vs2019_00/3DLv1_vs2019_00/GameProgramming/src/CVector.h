#ifndef CVECTOR_H
#define CVECTOR_H //CVECROE_Hの定義
#include "CMatrix.h"
/*
 ベクトルクラス
 ベクトルデータを扱います
*/
class CVector
{
public:
	//各種での値の設定
	//Set(X座標,Y座標,Z座標)
	void Set(float x, float y, float z);
	//Xの値を得る
	float X() const;
	//Yの値を得る
	float Y() const;
	//Zの値を得る
	float Z() const;
	//デフォルトコンストラクタ
	CVector();
	//コンストラクタ
	//CVector(X座標,Y座標,Z座標)
	CVector(float x, float y, float z);
	//＋演算子のオーバーロード
	//CVector + CVector の演算結果を返す
	CVector operator+(const CVector& v) const;
	//ー演算子のオーバーロード
	//CVector - CVector の演算結果を返す
	CVector operator-(const CVector& v) const;
	//CVector * CMatrixの結果をCVectorで返す
	CVector operator*(const CMatrix& m);
	//ベクトルの長さを返す
	float Length() const;
	//内積
	//Dot(ベクトル)
	float Dot(const CVector& v) const;
	//外積
	//Cross(ベクトル)
	CVector Cross(const CVector& v) const;
	//*演算子のオーバーロード
	//CVector * float の演算結果を返す
	CVector operator*(const float& f) const;
	//正規化
	//大きさ１のベクトルを返す
	CVector Normalize() const;
	void X(float f);
	void Y(float f);
	void Z(float f);
	//+-演算子のオーバーロード
	//CVector1 += CVector2 の演算を行う
	void operator+=(const CVector& v);
private:
	//3D各種での値を設定
	float mX, mY, mZ;
};
#endif