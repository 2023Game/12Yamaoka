#include "CXEnemy.h"
#include "CXPlayer.h"

CXEnemy::CXEnemy()
	:mColSphereBody(this, nullptr, CVector(), 0.5f, CCollider::ETag::EBODY)
	, mColSphereHead(this, nullptr, CVector(0.0f, 0.5f, -0.3f), 0.5f)
	, mColSphereSword(this, nullptr, CVector(-10.0f, 10.0f, 50.0f), 0.3f)
{
}

void CXEnemy::Init(CModelX* model)
{
	CXCharacter::Init(model);
	mColSphereBody.Matrix(&mpCombinedMatrix[8]);
	mColSphereHead.Matrix(&mpCombinedMatrix[11]);
	mColSphereSword.Matrix(&mpCombinedMatrix[21]);
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