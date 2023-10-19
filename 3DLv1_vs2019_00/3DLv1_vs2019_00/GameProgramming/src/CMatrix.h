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
	//�g��k���s��̍쐬
	//Scale(�{��X, �{��Y, �{��Z)
	CMatrix Scale(float sx, float sy, float sz);
	//�s��l�̎擾
	//M(�s,��)
	//mM[�s][��]���擾
	//float M(int r, int c) const;
	float CMatrix::M(int r, int c) const
	{
		return mM[r][c];
	}
	//�S�~�S�̍s��f�[�^��ݒ�
	float mM[4][4];
};

#endif