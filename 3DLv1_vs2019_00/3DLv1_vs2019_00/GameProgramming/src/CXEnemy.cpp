#include "CXEnemy.h"
#include "CXPlayer.h"

CXEnemy::CXEnemy()
	:mColSphereBody(this, nullptr, CVector(0.5f, -1.0f, 0.0f), 1.0f, CCollider::ETag::EBODY)
	, mColSphereHead(this, nullptr, CVector(0.0f, 1.0f, 0.0f), 1.5f)
	, mColSphereSword0(this, nullptr, CVector(0.7f, 3.5f, -0.2f), 0.5f)
	, mColSphereSword1(this, nullptr, CVector(0.5f, 2.5f, -0.2f), 0.5f)
	, mColSphereSword2(this, nullptr, CVector(0.3f, 1.5f, -0.2f), 0.5f)
{
}

void CXEnemy::Init(CModelX* model)
{
	//�����s��̐ݒ�
	mColSphereBody.Matrix(&mpCombinedMatrix[1]);
	//��
	mColSphereHead.Matrix(&mpCombinedMatrix[1]);
	//��
	mColSphereSword0.Matrix(&mpCombinedMatrix[26]);
	mColSphereSword1.Matrix(&mpCombinedMatrix[26]);
	mColSphereSword2.Matrix(&mpCombinedMatrix[26]);
}

void CXEnemy::Collision(CCollider* m, CCollider* o)
{
	switch (o->Tag())
	{
	case CCollider::ETag::ESWORD: //����̃R���C�_������
		switch (o->Type())
		{
		case CCollider::EType::ESPHERE: //����̃R���C�_�^�C�v����
			//�����̃R���C�_�Ƒ���̃R���C�_���Փ˂��Ă���
			if (CCollider::Collision(m, o))
			{
				//30�t���[�������ă_�E�����A�J��Ԃ��Ȃ�
				ChangeAnimation(11, false, 30);
			}
			break;
		}
	}
}