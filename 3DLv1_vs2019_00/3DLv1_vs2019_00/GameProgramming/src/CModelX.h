#ifndef CMODELX_H // �C���N���[�h�K�[�h
#define CMODELX_H
#define MODEL_FILE "res\\sample.blend.x" //�t�@�C����
#include <vector> //vector�N���X�̃C���N���[�h(���I�z�u)
#include "CMatrix.h" //�}�g���N�X�N���X�̃C���N���[�h
class CModelX; //CModel�N���X�̐錾
class CModelXFrame; //CModelXFrame�N���X�̐錾
class CMesh; //CMesh�N���X�̐錾
class CMaterial; //�}�e���A���̐錾
class CSkinWeights; //�X�L���E�F�C�g�N���X

//�̈�J�����}�N����
#define SAFE_DELETE_ARRAY(a) { if(a) delete[] a; a = nullptr;}
/*
CModelX
X�t�@�C���`����3D���f���f�[�^���v���O�����ŔF������
*/
class CModelX
{
	friend CModelXFrame;
public:
	~CModelX();
	//�m�[�h�̓ǂݔ�΂�
	void SkipNode();
	CModelX();
	//�t�@�C���ǂݍ���
	void Load(char* file);
	//�P��̎��o��
	char* GetToken();
	char* Token();
	void Render();
	bool EOT(); // �g�[�N���������Ȃ�����true
private:
	std::vector<CModelXFrame*> mFrame; //�t���[���̔z��
	char* mpPointer; //�ǂݍ��݈ʒu
	char mToken[1024]; //���o�����P��̗̈�
	//c����؂蕶���Ȃ�true��Ԃ�
	bool IsDelimiter(char c);
};

//CModelXFrame�N���X�̒�`
class CModelXFrame
{
	friend CModelX;
public:
	//�R���X�g���N�^
	CModelXFrame(CModelX* model);
	//�f�X�g���N�^
	~CModelXFrame();
	void Render();
private:
	std::vector<CModelXFrame*> mChild; //�q�t���[���̔z��
	CMatrix mTransformMatrix; //�ϊ��s��
	char* mpName;  //�t���[�����O
	int mIndex;    //�t���[���ԍ�
	CMesh* mpMesh; //Mesh�f�[�^
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
private:
	int mVertexNum;     //���_���W
	CVector* mpVertex;  //���_�f�[�^
	int mFaceNum;       //�ʐ�
	int* mpVertexIndex; //�ʂ��\�����钸�_�C���f�b�N�X
	int mNormalNum;     //�@����
	CVector* mpNormal;  //�@���x�N�g��
	int mMaterialNum;	//�}�e���A����
	int mMaterialIndexNum; //�}�e���A���ԍ����i�ʐ��j
	int* mpMaterialIndex;  //�}�e���A���ԍ�
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

#endif