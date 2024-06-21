#ifndef CMODELX_H    // インクルードガード
#define CMODELX_H
//#define MODEL_FILE "res\\sample.blend.x" //ファイル名
#define MODEL_FILE "res\\ラグナ.x" //入力ファイル名
#include <vector>    //vectorクラスのインクルード(動的配置)
#include "CMatrix.h" //マトリクスクラスのインクルード
class CModelX;       //CModelクラスの宣言
class CModelXFrame;  //CModelXFrameクラスの宣言
class CMesh;         //CMeshクラスの宣言
class CMaterial;     //マテリアルの宣言
class CSkinWeights;  //スキンウェイトクラス
class CAnimationSet; //アニメーションセットクラス
class CAnimation;    //アニメーションクラス
class CAnimationKey; //アニメーションキークラス

//領域開放をマクロ化
#define SAFE_DELETE_ARRAY(a) { if(a) delete[] a; a = nullptr;}
//配列のサイズ取得をマクロ化
#define ARRAY_SIZE(a)(sizeof(a)/sizeof(a[0]))

//CModelX Xファイル形式の3Dモデルデータをプログラムで認識する
class CModelX
{
	friend CModelXFrame;
	friend CAnimationSet;
	friend CAnimation;
public:
	~CModelX();
	CModelX();
	//ノードの読み飛ばし
	void SkipNode();
	//ファイル読み込み
	void Load(char* file);
	void Render();
	void AnimateFrame();
	void SetSkinWeightFrameIndex(); //スキンウェイトのフレーム番号設定
	void AnimateVertex(); //頂点にアニメーションを適用
	//単語の取り出し
	char* GetToken();
	char* Token();
	bool EOT(); // トークンが無くなったらtrue
	CModelXFrame* FindFrame(char* name); //フレーム名に該当するフレームのアドレスを返す
	std::vector<CAnimationSet*>& CModelX::AnimationSet()
	{
		return mAnimationSet;
	}
	std::vector<CModelXFrame*>& Frames();
	CMaterial* FindMaterial(char* name); //マテリアルの検索
	std::vector<CMaterial*>& Material(); //マテリアル配列の取得
private:
	std::vector<CModelXFrame*> mFrame; //フレームの配列
	char* mpPointer; //読み込み位置
	char mToken[1024]; //取り出した単語の領域
	//cが区切り文字ならtrueを返す
	bool IsDelimiter(char c);
	std::vector<CAnimationSet*> mAnimationSet; //アニメーションセットの配列
	std::vector<CMaterial*>mMaterial; //マテリアル配列
};

//CModelXFrameクラスの定義
class CModelXFrame
{
	friend CModelX;
	friend CAnimation;
	friend CAnimationSet;
public:
	//コンストラクタ
	CModelXFrame(CModelX* model);
	//デストラクタ
	~CModelXFrame();
	void Render();
	int Index()
	{
		return mIndex;
	}
	//合成行列の作成
	void AnimateCombined(CMatrix* parent);
	const CMatrix& CombinedMatrix();
private:
	std::vector<CModelXFrame*> mChild; //子フレームの配列
	CMatrix mTransformMatrix; //変換行列
	char* mpName;  //フレーム名前
	int mIndex;    //フレーム番号
	CMesh* mpMesh; //Meshデータ
	CMatrix mCombinedMatrix; //合成行列
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
	//スキンウェイトにフレーム番号を設定する
	void SetSkinWeightFrameIndex(CModelX* model);
	//頂点にアニメーション適用
	void AnimateVertex(CModelX* model);
private:
	int mVertexNum;     //頂点座標
	int mFaceNum;       //面積
	int* mpVertexIndex; //面を構成する頂点インデックス
	int mNormalNum;     //法線数
	int mMaterialNum;	//マテリアル数
	int mMaterialIndexNum; //マテリアル番号数（面数）
	int* mpMaterialIndex;  //マテリアル番号
	float* mpTextureCoords; //テクスチャ座標データ
	CVector* mpVertex;  //頂点データ
	CVector* mpNormal;  //法線ベクトル
	CVector* mpAnimateVertex; //アニメーション用頂点
	CVector* mpAnimateNormal; //アニメーション用法線
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

//アニメーションセット
class CAnimationSet
{
	friend CModelX;
public:
	CAnimationSet(CModelX* model);
	~CAnimationSet();
	void Time(float time);      //時間の設定
	void Weight(float Weight);  //重みの設定
	void AnimateMatrix(CModelX* model);
	std::vector<CAnimation*>& Animation();
	float Time();
	float MaxTime();
private:
	char* mpName; //アニメーションセット名
	std::vector<CAnimation*> mAnimation; //アニメーション
	float mTime;     //現在時間
	float mWeight;   //重み
	float  mMaxTime; //最大時間
};

//アニメーションクラス
class CAnimation
{
	friend CAnimationSet;
	friend CModelX;
public:
	CAnimation(CModelX* model);
	~CAnimation();
private:
	char* mpFrameName; //フレーム名
	int mFrameIndex;   //フレーム番号
	int mKeyNum; //キー数(時間数)
	CAnimationKey* mpKey; //キーの配列
};

//アニメーションキークラス
class CAnimationKey
{
	friend CAnimation;
	friend CAnimationSet;
private:
	float mTime; //時間
	CMatrix mMatrix; //行列
};

#endif