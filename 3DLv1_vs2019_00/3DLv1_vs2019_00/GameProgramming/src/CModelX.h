#ifndef CMODELX_H    // �C���N���[�h�K�[�h
#define CMODELX_H
//#define MODEL_FILE "res\\sample.blend.x" //�t�@�C����
#define MODEL_FILE "res\\���O�i.x" //���̓t�@�C����
#include <vector>    //vector�N���X�̃C���N���[�h(���I�z�u)
#include "CMatrix.h" //�}�g���N�X�N���X�̃C���N���[�h
class CModelX;       //CModel�N���X�̐錾
class CModelXFrame;  //CModelXFrame�N���X�̐錾
class CMesh;         //CMesh�N���X�̐錾
class CMaterial;     //�}�e���A���̐錾
class CSkinWeights;  //�X�L���E�F�C�g�N���X
class CAnimationSet; //�A�j���[�V�����Z�b�g�N���X
class CAnimation;    //�A�j���[�V�����N���X
class CAnimationKey; //�A�j���[�V�����L�[�N���X

//�̈�J�����}�N����
#define SAFE_DELETE_ARRAY(a) { if(a) delete[] a; a = nullptr;}
//�z��̃T�C�Y�擾���}�N����
#define ARRAY_SIZE(a)(sizeof(a)/sizeof(a[0]))

//CModelX X�t�@�C���`����3D���f���f�[�^���v���O�����ŔF������
class CModelX
{
	friend CModelXFrame;
	friend CAnimationSet;
	friend CAnimation;
public:
	~CModelX();
	CModelX();
	//�m�[�h�̓ǂݔ�΂�
	void SkipNode();
	//�t�@�C���ǂݍ���
	void Load(char* file);
	void Render();
	void AnimateFrame();
	void SetSkinWeightFrameIndex(); //�X�L���E�F�C�g�̃t���[���ԍ��ݒ�
	void AnimateVertex(); //���_�ɃA�j���[�V������K�p
	//�P��̎��o��
	char* GetToken();
	char* Token();
	bool EOT(); // �g�[�N���������Ȃ�����true
	CModelXFrame* FindFrame(char* name); //�t���[�����ɊY������t���[���̃A�h���X��Ԃ�
	std::vector<CAnimationSet*>& CModelX::AnimationSet()
	{
		return mAnimationSet;
	}
	std::vector<CModelXFrame*>& Frames();
	CMaterial* FindMaterial(char* name); //�}�e���A���̌���
	std::vector<CMaterial*>& Material(); //�}�e���A���z��̎擾
private:
	std::vector<CModelXFrame*> mFrame; //�t���[���̔z��
	char* mpPointer; //�ǂݍ��݈ʒu
	char mToken[1024]; //���o�����P��̗̈�
	//c����؂蕶���Ȃ�true��Ԃ�
	bool IsDelimiter(char c);
	std::vector<CAnimationSet*> mAnimationSet; //�A�j���[�V�����Z�b�g�̔z��
	std::vector<CMaterial*>mMaterial; //�}�e���A���z��
};

//CModelXFrame�N���X�̒�`
class CModelXFrame
{
	friend CModelX;
	friend CAnimation;
	friend CAnimationSet;
public:
	//�R���X�g���N�^
	CModelXFrame(CModelX* model);
	//�f�X�g���N�^
	~CModelXFrame();
	void Render();
	int Index()
	{
		return mIndex;
	}
	//�����s��̍쐬
	void AnimateCombined(CMatrix* parent);
	const CMatrix& CombinedMatrix();
private:
	std::vector<CModelXFrame*> mChild; //�q�t���[���̔z��
	CMatrix mTransformMatrix; //�ϊ��s��
	char* mpName;  //�t���[�����O
	int mIndex;    //�t���[���ԍ�
	CMesh* mpMesh; //Mesh�f�[�^
	CMatrix mCombinedMatrix; //�����s��
};

class CMesh
{
public:
	//�R���X�g���N�^
	CMesh();
	//�f�X�g���N�^
	~CMesh();
	//�ǂݍ��ݏ���
	void Init(CModelX* model);
	void Render();
	//�X�L���E�F�C�g�Ƀt���[���ԍ���ݒ肷��
	void SetSkinWeightFrameIndex(CModelX* model);
	//���_�ɃA�j���[�V�����K�p
	void AnimateVertex(CModelX* model);
private:
	int mVertexNum;     //���_���W
	int mFaceNum;       //�ʐ�
	int* mpVertexIndex; //�ʂ��\�����钸�_�C���f�b�N�X
	int mNormalNum;     //�@����
	int mMaterialNum;	//�}�e���A����
	int mMaterialIndexNum; //�}�e���A���ԍ����i�ʐ��j
	int* mpMaterialIndex;  //�}�e���A���ԍ�
	float* mpTextureCoords; //�e�N�X�`�����W�f�[�^
	CVector* mpVertex;  //���_�f�[�^
	CVector* mpNormal;  //�@���x�N�g��
	CVector* mpAnimateVertex; //�A�j���[�V�����p���_
	CVector* mpAnimateNormal; //�A�j���[�V�����p�@��
	std::vector<CMaterial*> mMaterial;      //�}�e���A���f�[�^
	std::vector<CSkinWeights*>mSkinWeights; //�X�L���E�F�C�g
};

//�X�L���E�F�C�g�N���X
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
	char* mpFrameName; //�t���[����
	int mFrameIndex;   //�t���[���ԍ�
	int mIndexNum;     //���_�ԍ���
	int* mpIndex;      //���_�ԍ��z��
	float* mpWeight;   //���_�E�F�C�g�z��
	CMatrix mOffset;   //�I�t�Z�b�g�}�g���b�N�X
};

//�A�j���[�V�����Z�b�g
class CAnimationSet
{
	friend CModelX;
public:
	CAnimationSet(CModelX* model);
	~CAnimationSet();
	void Time(float time);      //���Ԃ̐ݒ�
	void Weight(float Weight);  //�d�݂̐ݒ�
	void AnimateMatrix(CModelX* model);
	std::vector<CAnimation*>& Animation();
	float Time();
	float MaxTime();
private:
	char* mpName; //�A�j���[�V�����Z�b�g��
	std::vector<CAnimation*> mAnimation; //�A�j���[�V����
	float mTime;     //���ݎ���
	float mWeight;   //�d��
	float  mMaxTime; //�ő厞��
};

//�A�j���[�V�����N���X
class CAnimation
{
	friend CAnimationSet;
	friend CModelX;
public:
	CAnimation(CModelX* model);
	~CAnimation();
private:
	char* mpFrameName; //�t���[����
	int mFrameIndex;   //�t���[���ԍ�
	int mKeyNum; //�L�[��(���Ԑ�)
	CAnimationKey* mpKey; //�L�[�̔z��
};

//�A�j���[�V�����L�[�N���X
class CAnimationKey
{
	friend CAnimation;
	friend CAnimationSet;
private:
	float mTime; //����
	CMatrix mMatrix; //�s��
};

#endif