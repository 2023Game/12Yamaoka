#ifndef CMATRIX_H
#define CMATRIX_H

/*
�}�g���N�X�N���X
�S�s�S��̍s��f�[�^�������܂�
*/

class CVector;
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
	//��]�s��(Y��)�̍쐬
	//RetateY(�p�x)
	CMatrix RotateY(float degree);
	//��]�s��(Z��)�̍쐬
	//RotateZ(�p�x)
	CMatrix RotateZ(float degree);
	//��]�s��(X��)�̍쐬
	//RptateX(�p�x)
	CMatrix RotateX(float degree);
	//�ړ��s��̍쐬
	//Translate(�ړ���X,�ړ���Y,�ړ���Z)
	CMatrix Translate(float mx, float my, float mz);
	//�s��l�̑��
	//M(�s��,��,�l)
	void M(int row, int col, float value);
	//*���Z�q�̃I�[�o�[���[�h
	//CMatrix * CMatrix �̉��Z���ʂ�Ԃ�
	const CMatrix operator*(const CMatrix &m) const;
	//�s��̎擾
	float* M() const;
	//�t�s��擾
	CMatrix Transpose() const;
	CVector VectorZ() const; //Z���x�N�g���̎擾
	CVector VectorX() const; //X���x�N�g���̎擾
	CVector VectorY() const; //Y���x�N�g���̎擾
	//�v�f���̎擾
	int Size();
	CMatrix Quaternion(float x, float y, float z, float w);
private:
	//�S�~�S�̍s��f�[�^��ݒ�
	float mM[4][4];
};

#endif