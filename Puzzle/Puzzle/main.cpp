/*
enum ��ʐ���
{
	TITLE,
	GAME,
	ENDING,
	GAMEEND,
};

��ʐ��� Title()
{
	��ʐ��� tmp = TITLE;
		if (W�������ꂽ)�I��������ɂ���
			if (S�������ꂽ)�I���������ɂ���
				if (Z�������ꂽ)
				{
					�͂��߂邪�I�΂�Ă�Ȃ� tmp = GAME;
					����邪�I�΂�Ă�Ȃ� tmp = GAMEEND;
				}
	printf(�^�C�g������, �I����)
		return tmp
}

��ʐ��� Game();
��ʐ��� Ending();

void main()
{
	bool �Q�[���I������ = false;
	��ʐ��� ���̏�� = TITLE;
	int �e�L�[�����Ă鎞��[�L�[�̐�];

	while (!�Q�[���I������)
	{
		if (kbhit())
		{
			char ���� = getch();
			�e�L�[�����Ă鎞��[����]++;

			for (int i = 0; i < �L�[�̐�; i++)
			{
				if (���� != i)�e�L�[�����Ă鎞��[i] = 0;
			}
		}
		switch (���̏��)
		{
		case TITLE:
			���̏�� = Title();
			break;

		case GAME:
			���̏�� = Game();
			break;

		case ENDING:
			���̏�� = Ending();
			break;

		case GAMEEND:
			�Q�[���I������ = true;
			break;
		}
	}
}
*/