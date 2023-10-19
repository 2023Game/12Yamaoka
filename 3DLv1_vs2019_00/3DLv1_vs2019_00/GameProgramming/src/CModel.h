#ifndef CMODEL_H
#define CMODEL_H
//vector�̃C���N���[�h
#include <vector>
#include "CTriangle.h"
#include "CMaterial.h"
#include "CMatrix.h"

/*
���f���N���X
���f���f�[�^�̓��͂�\��
*/

class CModel
{
public:
	//���f���t�@�C���̓���
	//Load(���f���t�@�C����,�}�e���A���t�@�C����)
	void Load(char* obj, char* mtl);
	//�`��
	void Render();
	~CModel();
	//�`��
	//Render(�s��)
	void Render(const CMatrix& m);
private:
	//�O�p�`�̉ϒ��z��
	std::vector<CTriangle> mTriangles;
	//�}�e���A���|�C���^�̉ϒ��z��
	std::vector<CMaterial*> mpMaterials;
};

#endif