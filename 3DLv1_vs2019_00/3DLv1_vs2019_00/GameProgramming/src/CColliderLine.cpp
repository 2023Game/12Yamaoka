#include "CColliderLine.h"

CColliderLine::CColliderLine(CCharacter3* parent, CMatrix* matrix, const CVector& v0, const CVector& v1)
{
	Set(parent, matrix, v0, v1);
}

void CColliderLine::Set(CCharacter3* parent, CMatrix* matrix, const CVector& v0, const CVector & v1)
{
	mType = EType::ELINE; //�����R���C�_
	mpParent = parent; //�e�ݒ�
	if (matrix)
		mpMatrix = matrix; //�e�s�񂠂�ΐݒ�
	//�������_�ݒ�
	mV[0] = v0;
	mV[1] = v1;
}

void CColliderLine::Render()
{
	//�s��ޔ�
	glPushMatrix();
	//�s��K�p
	glMultMatrixf(mpMatrix->M());

	//�A���t�@�u�����h
	glEnable(GL_BLEND);
	//�u�����h���@���w��
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//���C�g�I�t
	glDisable(GL_LIGHTING);

	//DIFFUS�ԐF�ݒ�
	float c[] = { 1.0f,0.0f,0.0f,1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	glColor4fv(c);

	//�O�p�`�`��
	glBegin(GL_LINES);
	glVertex3f(mV[0].X(), mV[0].Y(), mV[0].Z());
	glVertex3f(mV[1].X(), mV[1].Y(), mV[1].Z());
	glEnd();

	//���C�g�I��
	glEnable(GL_LIGHTING);
	//�A���t�@�u�����h����
	glDisable(GL_ALPHA);
	//�s�񕜋A
	glPopMatrix();
}