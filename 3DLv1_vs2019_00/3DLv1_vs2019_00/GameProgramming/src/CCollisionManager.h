#ifndef CCOLLISIONMANAGER_H
#define CCOLLISIONMANAGER_H
//�Փˏ����͈͂�藣��Ă���R���C�_�͏Փˏ������Ȃ�
#define COLLISIONRANGE 30

#include "CTaskManager.h"

class CCollisionManager : public CTaskManager
{
public:
	//�C���X�^���X�̎擾
	static CCollisionManager* Instance();
	//�Փˏ���
	void Collision();
	void Collision(CCollider* c, int range);
private:
	//�}�l�[�W���̃C���X�^���X
	static CCollisionManager* mpInstance;
};

#endif