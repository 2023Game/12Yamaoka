#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>
#include<strsafe.h>

#define BOARD_WIDTH  (4)
#define BOARD_HEIGHT (BOARD_WIDTH)
#define BLANK_NUMBER (16)
#define BUFFRSIZE 128

typedef struct
{
	int x, y;
}VEC2;

int board[BOARD_HEIGHT][BOARD_WIDTH];

VEC2 getBlankPos()
{
	VEC2 blankPos = { -1,-1 };
	for (int y = 0; y < BOARD_HEIGHT; y++)
		for (int x = 0; x < BOARD_WIDTH; x++)
			if (board[y][x] == BLANK_NUMBER)
				blankPos = { x,y };

	return blankPos;
}

void moveToBlank(VEC2 _movePos)
{
	if ((_movePos.x < 0) || (_movePos.x >= BOARD_WIDTH)
		|| (_movePos.y < 0) || (_movePos.y >= BOARD_HEIGHT))
		return;
	VEC2 blankPos = getBlankPos();
	int temp = board[blankPos.y][blankPos.x];
	board[blankPos.y][blankPos.x] = board[_movePos.y][_movePos.x];
	board[_movePos.y][_movePos.x] = temp;
}

int main(void)
{
	srand((unsigned int)(NULL));

	for (int y = 0; y < BOARD_HEIGHT; y++)
		for (int x = 0; x < BOARD_WIDTH; x++)
			board[y][x] = y * BOARD_WIDTH + x + 1;

	for (int i = 0; i < 1000; i++)
	{
		VEC2 blankPos = getBlankPos();
		VEC2 movePos = blankPos;
		switch (rand()%4)
		{
		case 0:movePos.y++;   break; //下に移動
		case 1:movePos.y--;   break; //上に移動
		case 2:movePos.x++;   break; //右に移動
		case 3:movePos.x--;   break; //左に移動
		}
		moveToBlank(movePos);
	}

	while (true)
	{
		system("cls");
		printf("+--+--+--+--+\n");
		for (int y = 0; y < BOARD_HEIGHT; y++)
		{
			for (int x = 0; x < BOARD_WIDTH; x++)
				if (board[y][x] == BLANK_NUMBER)
					printf("|  ");
				else
					printf("|%2d", board[y][x]);
			printf("|\n");
			printf("+--+--+--+--+\n");
		}

		bool isClear = true;
		for (int y = 0; y < BOARD_HEIGHT; y++)
			for (int x = 0; x < BOARD_WIDTH; x++)
				if (board[y][x] != y * BOARD_WIDTH + x + 1)
					isClear = false;
		if (isClear)
			printf("Clear!\n");

		VEC2 blankPos = getBlankPos();
		VEC2 movePos = blankPos;
		switch (_getch())
		{
		case 72:movePos.y++; break; //下に移動
		case 80:movePos.y--; break; //上に移動
		case 75:movePos.x++; break; //右に移動
		case 77:movePos.x--; break; //左に移動

		case 'w':movePos.y++;   break; //下に移動
		case 's':movePos.y--;   break; //上に移動
		case 'a':movePos.x++;   break; //右に移動
		case 'd':movePos.x--;   break; //左に移動
		}
		moveToBlank(movePos);
	}
}

BOOL isDragging = FALSE;

/*
//ウィンドウプロシージャ
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
		//マウスの左ボタンが押されたときにドラッグを開始
		isDragging = TRUE;
		break;

	case WM_MOUSEMOVE:
		//マウスが移動したとき
		if (isDragging)
		{
			//マウスの現在位置を取得
			int xPos = GET_X_LPARAM(lParam);
			int yPos = GET_Y_LPARAM(lParam);

			//ここでマウスの位置を使用して何かを行う
		}
		break;

	case WM_LBUTTONUP:
		//マウスの左ボタンが離されたときにドラッグを終了
		isDragging = FALSE;
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

*/