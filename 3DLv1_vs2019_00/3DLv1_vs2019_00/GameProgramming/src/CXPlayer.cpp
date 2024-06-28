#include "CXPlayer.h"
#define VELOCITY CVector(0.0f,0.0f,0.1f) //�ړ����x

void CXPlayer::Update()
{
	//A�L�[�������ƍ���2�x��]�AD�L�[�������ƉE��2�x��]�AW�L�[�������ƌ����Ă��������0.1�ړ�
	//A�L�[��������Ă���΁AY���̉�]�l��2���Z
	if (mInput.Key('A'))
	{
		mMatrix = mMatrix * CMatrix().RotateY(2);
	}
	//D�L�[��������Ă���΁AY���̉�]�l��2���Z
	if (mInput.Key('D'))
	{
		mMatrix = mMatrix * CMatrix().RotateY(-2);
	}
	//W�L�[��������Ă���΁A�A�j���[�V�����ԍ�1�A����60�ɐ؂�ւ�
	//��]�s�񂩂��]���Z���x�N�g�����擾���A���݈ʒu�������Ă��������0.1�ړ�
	if (mInput.Key('W'))
	{
		mCharacter.ChangeAnimation(1, true, 60);
		mPosition = mPosition + VELOCITY * mMatrixRotate;
	}
	//W�L�[��������Ă��Ȃ���΁A�A�j���[�V�����ԍ�0�A����60�ɐ؂�ւ�
	else
	{
		mCharacter.ChangeAnimation(0, true, 60);
	}

	mCharacter.Update();
	mCharacter.Render();
}