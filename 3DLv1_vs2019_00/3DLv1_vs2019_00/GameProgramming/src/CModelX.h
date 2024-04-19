#ifndef CMODELX_H // �C���N���[�h�K�[�h
#define CMODELX_H
#define MODEL_FILE "res\\sample.blend.x" //�t�@�C����
#include <vector> //vector�N���X�̃C���N���[�h(���I�z�u)
#include "CMatrix.h" //�}�g���N�X�N���X�̃C���N���[�h
class CModelX; //CModel�N���X�̐錾
class CModelXFrame; //CModelXFrame�N���X�̐錾

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
private:
	std::vector<CModelXFrame*> mChild; //�q�t���[���̔z��
	CMatrix mTransformMatrix; //�ϊ��s��
	char* mpName; //�t���[�����O
	int mIndex; //�t���[���ԍ�
};

#endif