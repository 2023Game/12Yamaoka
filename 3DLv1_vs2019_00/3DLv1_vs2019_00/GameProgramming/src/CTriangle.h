#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include "CVector.h"
#include "CMatrix.h"

//�O�p�`�N���X
class CTriangle
{
public:
	//���_���W�ݒ�
	//Vertex(���_�P�C���_�Q�C���_�R)
	void Vertex(const CVector& v0, const CVector& v1, const CVector& v2);
	//�@���ݒ�
	//Normal(�@���x�N�g��)
	void Normal(const CVector& n);
	//Normal(�@���x�N�g��1,�@���x�N�g��2,�@���x�N�g��3)
	void Normal(const CVector& v0, const CVector& v1, const CVector& v2);
	//�`��
	void Render();
	//�}�e���A���ԍ��̎擾
	int MaterialIdx();
	//�}�e���A���ԍ��̐ݒ�
	//Material(�}�e���A���ԍ�)
	void MaterialIdx(int idx);
	//UV�ݒ�
	void UV(const CVector& v0, const CVector& v1, const CVector& v2);
	//�`��
	//Render(�s��)
	void Render(const CMatrix& m);
	//���_���W�𓾂�
	const CVector& V0() const; //mV[0]��Ԃ��܂�
	const CVector& V1() const; //mV[1]��Ԃ��܂�
	const CVector& V2() const; //mV[2]��Ԃ��܂�
	//�@���𓾂�
	const CVector& N0() const; //mN[0]��Ԃ��܂�
	const CVector& N1() const; //mN[1]��Ԃ��܂�
	const CVector& N2() const; //mN[2]��Ԃ��܂�
	//UV�𓾂�
	const CVector& U0() const; //mUv[0]��Ԃ��܂�
	const CVector& U1() const; //mUv[1]��Ԃ��܂�
	const CVector& U2() const; //mUv[2]��Ԃ��܂�
private:
	CVector mV[3]; //���_���W
	CVector mN[3]; //�@��
	int mMaterialIdx; //�}�e���A���ԍ�
	CVector mUv[3]; //�e�N�X�`���}�b�s���O
};
#endif