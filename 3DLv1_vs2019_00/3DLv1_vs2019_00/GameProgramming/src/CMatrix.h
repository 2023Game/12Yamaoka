#ifndef CMATRIX_H
#define CMATRIX_H

/*
�}�g���N�X�N���X
�S�s�S��̍s��f�[�^�������܂�
*/

class CMatrix
{
public:
	//�\���m�F�p
	//�S�~�S�̍s�����ʏo��
	void Print();
	//�f�t�H���g�R���X�g���N�^
	CMatrix();
	//�P�ʍs��̍쐬
	CMatrix Identity();
private:
	//�S�~�S�̍s��f�[�^��ݒ�
	float mM[4][4];
};

#endif