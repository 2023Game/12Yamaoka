#include "CXPlayer.h"

void CXPlayer::Update()
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
	
	CXCharacter::Update();
}