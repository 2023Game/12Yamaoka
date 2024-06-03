
/*
#include "jigsawpuzzle.h"
#include <vector>
#include <map>

JigsawPiece piece;
DefineJigsawPieceEdges(piece);

struct JigsawPiece
{
	std::vector<POINT> shape; //ピースの形状
	std::map<int, JigsawPiece> connections; //ピースの接続情報
	float x, y; //ピースの位置
	bool isInCorrectPosition; //正しい位置にあるか

	//コンストラクタ
	JigsawPiece() :x(0), y(0), isInCorrectPosition(false) {}

	//ピースの形状を設定するメソッド
	void SetShape(const std::vector<POINT>& newShape)
	{
		shape = newShape;
	}

	//ピースの接続情報を追加するメソッド
	void AddConnection(int edgeIndex, JigsawPiece* otherPiece)
	{
		connections[edgeIndex] = otherPiece;
	}

	//ピースの位置を更新するメソッド
	void SetPointion(float newX, float newY)
	{
		x = newX;
		y = newY;
	}

	//ピースが正しい位置にあるかをチェックするメソッド
	void ChackPosition()
	{

	}
};

void DefineJigsawPieceEdges(JigsawPiece& piece)
{
	std::vector<POINT> edges;

	edges.push_back({ 0,0 });    //左上の頂点
	edges.push_back({ 25,-10 }); //上エッジのへこみ
	edges.push_back({ 50,0 });   //右上の頂点
	edges.push_back({ 60,25 });  //右エッジのへこみ
	edges.push_back({ 50,50 });  //右下の頂点
	edges.push_back({ 25,60 });  //下エッジのへこみ
	edges.push_back({ 0,50 });   //左下の頂点
	edges.push_back({ -10,25 }); //左エッジのへこみ

	piece.SetShape(edges);
}



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
		switch (rand() % 4)
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

*/