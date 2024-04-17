#ifndef CMODELX_H // �C���N���[�h�K�[�h
#define CMODELX_H

#define MODEL_FILE "res\\sample.blend.x" //�t�@�C����

//�̈�J�����}�N����
#define SAFE_DELETE_ARRAY(a) { if(a) delete[] a; a = nullptr;}
/*
CModelX
X�t�@�C���`����3D���f���f�[�^���v���O�����ŔF������
*/
class CModelX
{
public:
	CModelX();
	//�t�@�C���ǂݍ���
	void Load(char* file);
	//�P��̎��o��
	char* GetToken();
private:
	char* mpPointer; //�ǂݍ��݈ʒu
	char mToken[1024]; //���o�����P��̗̈�
	//c����؂蕶���Ȃ�true��Ԃ�
	bool IsDelimiter(char c);
};

#endif