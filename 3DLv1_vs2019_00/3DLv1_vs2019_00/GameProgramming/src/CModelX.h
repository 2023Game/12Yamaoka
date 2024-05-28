#ifndef CMODELX_H // インクルードガード
#define CMODELX_H
#define MODEL_FILE "res\\sample.blend.x" //ファイル名
#include <vector> //vectorクラスのインクルード(動的配置)
#include "CMatrix.h" //マトリクスクラスのインクルード
class CModelX; //CModelクラスの宣言
class CModelXFrame; //CModelXFrameクラスの宣言
class CMesh; //CMeshクラスの宣言
class CMaterial; //マテリアルの宣言
class CSkinWeights; //スキンウェイトクラス

//領域開放をマクロ化
#define SAFE_DELETE_ARRAY(a) { if(a) delete[] a; a = nullptr;}
/*
CModelX
Xファイル形式の3Dモデルデータをプログラムで認識する
*/
class CModelX
{
	friend CModelXFrame;
public:
	~CModelX();
	//ノードの読み飛ばし
	void SkipNode();
	CModelX();
	//ファイル読み込み
	void Load(char* file);
	//単語の取り出し
	char* GetToken();
	char* Token();
	void Render();
	bool EOT(); // トークンが無くなったらtrue
private:
	std::vector<CModelXFrame*> mFrame; //フレームの配列
	char* mpPointer; //読み込み位置
	char mToken[1024]; //取り出した単語の領域
	//cが区切り文字ならtrueを返す
	bool IsDelimiter(char c);
};

//CModelXFrameクラスの定義
class CModelXFrame
{
	friend CModelX;
public:
	//コンストラクタ
	CModelXFrame(CModelX* model);
	//デストラクタ
	~CModelXFrame();
	void Render();
private:
	std::vector<CModelXFrame*> mChild; //子フレームの配列
	CMatrix mTransformMatrix; //変換行列
	char* mpName;  //フレーム名前
	int mIndex;    //フレーム番号
	CMesh* mpMesh; //Meshデータ
};

class CMesh
{
public:
	//コンストラクタ
	CMesh();
	//デストラクタ
	~CMesh();
	//読み込み処理
	void Init(CModelX* model);
	void Render();
private:
	int mVertexNum;     //頂点座標
	CVector* mpVertex;  //頂点データ
	int mFaceNum;       //面積
	int* mpVertexIndex; //面を構成する頂点インデックス
	int mNormalNum;     //法線数
	CVector* mpNormal;  //法線ベクトル
	int mMaterialNum;	//マテリアル数
	int mMaterialIndexNum; //マテリアル番号数（面数）
	int* mpMaterialIndex;  //マテリアル番号
	std::vector<CMaterial*> mMaterial;      //マテリアルデータ
	std::vector<CSkinWeights*>mSkinWeights; //スキンウェイト
};

//スキンウェイトクラス
class CSkinWeights 
{
	friend CModelX;
	friend CMesh;
public:
	CSkinWeights(CModelX* model);
	~CSkinWeights();
	const int& FrameIndex();
	const CMatrix& Offiset();
private:
	char* mpFrameName; //フレーム名
	int mFrameIndex;   //フレーム番号
	int mIndexNum;     //頂点番号数
	int* mpIndex;      //頂点番号配列
	float* mpWeight;   //頂点ウェイト配列
	CMatrix mOffset;   //オフセットマトリックス
};

#endif