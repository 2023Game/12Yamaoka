#include "CXPlayer.h"

//�R���C�_�̏�����
CXPlayer::CXPlayer()
	: mColSphereBody(this, nullptr, CVector(), 0.5f)
	, mColSphereHead(this, nullptr, CVector(0.0f, 5.0f, -3.0f), 0.5f)
	, mColSphereSword(this, nullptr, CVector(-10.0f, 10.0f, 50.0f), 0.3f)
{
}

void CXPlayer::Update()
{
	//�X�y�[�X�L�[�������ƍU���A�U����͌��̎p���֖߂��A�ҋ@����
	if (mInput.Key(VK_SPACE))
	{
		ChangeAnimation(3, false, 30);
	}
	else
	{
		//�A�j���[�V�����ԍ����R�̎��@�A�j���[�V�������I��������S�ɐ؂�ւ���
		if (AnimationIndex() == 3)
		{
			if (IsAnimationFinished())
			{
				ChangeAnimation(4, false, 30);
			}
		}
		//�A�j���[�V�����ԍ����S�̎��A�A�j���[�V�������I��������O�ɐ؂�ւ���
		else if (AnimationIndex() == 4)
		{
			if (IsAnimationFinished())
			{
				ChangeAnimation(0, true, 60);
			}
		}
		else
		{
			//A�L�[�������ƍ���2�x��]�AD�L�[�������ƉE��2�x��]�AW�L�[�������ƌ����Ă��������0.1�ړ�
			//A�L�[��������Ă���΁AY���̉�]�l��2���Z
			if (mInput.Key('A'))
			{
				mRotation.Y(mRotation.Y() + 2.0f);
			}
			//D�L�[��������Ă���΁AY���̉�]�l��2���Z
			if (mInput.Key('D'))
			{
				mRotation.Y(mRotation.Y() - 2.0f);
			}
			//W�L�[��������Ă���΁A�A�j���[�V�����ԍ�1�A����60�ɐ؂�ւ�
			//��]�s�񂩂��]���Z���x�N�g�����擾���A���݈ʒu�������Ă��������0.1�ړ�
			if (mInput.Key('W'))
			{
				ChangeAnimation(1, true, 60);
				Position(Position() + mMatrixRotate.VectorZ() * 0.1);
			}
			//W�L�[��������Ă��Ȃ���΁A�A�j���[�V�����ԍ�0�A����60�ɐ؂�ւ�
			else
			{
				ChangeAnimation(0, true, 60);
			}
		}
	}
	CXCharacter::Update();
}

void CXPlayer::Init(CModelX* model)
{
	CXCharacter::Init(model);
	//�����s��̐ݒ�
	mColSphereBody.Matrix(&mpCombinedMatrix[8]);
	//��
	mColSphereHead.Matrix(&mpCombinedMatrix[11]);
	//��
	mColSphereSword.Matrix(&mpCombinedMatrix[21]);
}