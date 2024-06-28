#ifndef CXCHARACTER_H
#define CXCHARACTER_H
#include "CModelX.h"
#include "CMatrix.h"
#include "CCharacter3.h"

class CXCharacter:public CCharacter3
{
public:
	CXCharacter();
	//����������
	void Init(CModelX* model);
	//�A�j���[�V�����̕ύX
	void ChangeAnimation(int index, bool loop, float framesize);
	//�X�V����
	void Update(CMatrix& m);
	void Update();
	//b��������
	void Render();
	//�A�j���[�V�����̍Đ��I������
	//ture:�I�� false:�Đ���
	bool IsAnimationFinished();
	int AnimationIndex(); //�A�j���[�V�����ԍ��̎擾
private:
	CModelX* mpModel;          //���f���f�[�^
	int mAnimationIndex;       //�A�j���[�V�����ԍ�
	bool mAnimationLoopFlg;    //ture:�A�j���[�V�������J��Ԃ�
	float mAnimationFrame;     //�A�j���[�V�����̍Đ��t���[��
	float mAnimationFrameSize; //�A�j���[�V�����̍Đ��t���[����
};

#endif
