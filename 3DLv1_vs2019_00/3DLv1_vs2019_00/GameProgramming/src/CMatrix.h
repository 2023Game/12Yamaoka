#ifndef CMATRIX_H
#define CMATRIX_H

/*
マトリクスクラス
４行４列の行列データを扱います
*/

class CVector;
class CMatrix
{
public:
	//表示確認用
	//４×４の行列を画面出力
	void Print();
	//デフォルトコンストラクタ
	CMatrix();
	//単位行列の作成
	CMatrix Identity();
	//拡大縮小行列の作成
	//Scale(倍率X, 倍率Y, 倍率Z)
	CMatrix Scale(float sx, float sy, float sz);
	//行列値の取得
	//M(行,列)
	//mM[行][列]を取得
	//float M(int r, int c) const;
	float CMatrix::M(int r, int c) const
	{
		return mM[r][c];
	}
	//回転行列(Y軸)の作成
	//RetateY(角度)
	CMatrix RotateY(float degree);
	//回転行列(Z軸)の作成
	//RotateZ(角度)
	CMatrix RotateZ(float degree);
	//回転行列(X軸)の作成
	//RptateX(角度)
	CMatrix RotateX(float degree);
	//移動行列の作成
	//Translate(移動量X,移動量Y,移動量Z)
	CMatrix Translate(float mx, float my, float mz);
	//行列値の代入
	//M(行数,列数,値)
	void M(int row, int col, float value);
	//*演算子のオーバーロード
	//CMatrix * CMatrix の演算結果を返す
	const CMatrix operator*(const CMatrix &m) const;
	//行列の取得
	float* M() const;
	//逆行列取得
	CMatrix Transpose() const;
	CVector VectorZ() const; //Z軸ベクトルの取得
	CVector VectorX() const; //X軸ベクトルの取得
	CVector VectorY() const; //Y軸ベクトルの取得
	//要素数の取得
	int Size();
	CMatrix Quaternion(float x, float y, float z, float w);
private:
	//４×４の行列データを設定
	float mM[4][4];
};

#endif