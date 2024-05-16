/*
enum 場面制御
{
	TITLE,
	GAME,
	ENDING,
	GAMEEND,
};

場面制御 Title()
{
	場面制御 tmp = TITLE;
		if (Wが押された)選択肢を上にする
			if (Sが押された)選択肢を下にする
				if (Zが押された)
				{
					はじめるが選ばれてるなら tmp = GAME;
					おわるが選ばれてるなら tmp = GAMEEND;
				}
	printf(タイトル文字, 選択肢)
		return tmp
}

場面制御 Game();
場面制御 Ending();

void main()
{
	bool ゲーム終了する = false;
	場面制御 今の場面 = TITLE;
	int 各キー押してる時間[キーの数];

	while (!ゲーム終了する)
	{
		if (kbhit())
		{
			char 入力 = getch();
			各キー押してる時間[入力]++;

			for (int i = 0; i < キーの数; i++)
			{
				if (入力 != i)各キー押してる時間[i] = 0;
			}
		}
		switch (今の場面)
		{
		case TITLE:
			今の場面 = Title();
			break;

		case GAME:
			今の場面 = Game();
			break;

		case ENDING:
			今の場面 = Ending();
			break;

		case GAMEEND:
			ゲーム終了する = true;
			break;
		}
	}
}
*/