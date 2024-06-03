
/*
#include "jigsawpuzzle.h"
#include <vector>
#include <map>

JigsawPiece piece;
DefineJigsawPieceEdges(piece);

struct JigsawPiece
{
	std::vector<POINT> shape; //�s�[�X�̌`��
	std::map<int, JigsawPiece> connections; //�s�[�X�̐ڑ����
	float x, y; //�s�[�X�̈ʒu
	bool isInCorrectPosition; //�������ʒu�ɂ��邩

	//�R���X�g���N�^
	JigsawPiece() :x(0), y(0), isInCorrectPosition(false) {}

	//�s�[�X�̌`���ݒ肷�郁�\�b�h
	void SetShape(const std::vector<POINT>& newShape)
	{
		shape = newShape;
	}

	//�s�[�X�̐ڑ�����ǉ����郁�\�b�h
	void AddConnection(int edgeIndex, JigsawPiece* otherPiece)
	{
		connections[edgeIndex] = otherPiece;
	}

	//�s�[�X�̈ʒu���X�V���郁�\�b�h
	void SetPointion(float newX, float newY)
	{
		x = newX;
		y = newY;
	}

	//�s�[�X���������ʒu�ɂ��邩���`�F�b�N���郁�\�b�h
	void ChackPosition()
	{

	}
};

void DefineJigsawPieceEdges(JigsawPiece& piece)
{
	std::vector<POINT> edges;

	edges.push_back({ 0,0 });    //����̒��_
	edges.push_back({ 25,-10 }); //��G�b�W�̂ւ���
	edges.push_back({ 50,0 });   //�E��̒��_
	edges.push_back({ 60,25 });  //�E�G�b�W�̂ւ���
	edges.push_back({ 50,50 });  //�E���̒��_
	edges.push_back({ 25,60 });  //���G�b�W�̂ւ���
	edges.push_back({ 0,50 });   //�����̒��_
	edges.push_back({ -10,25 }); //���G�b�W�̂ւ���

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
		case 0:movePos.y++;   break; //���Ɉړ�
		case 1:movePos.y--;   break; //��Ɉړ�
		case 2:movePos.x++;   break; //�E�Ɉړ�
		case 3:movePos.x--;   break; //���Ɉړ�
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
		case 72:movePos.y++; break; //���Ɉړ�
		case 80:movePos.y--; break; //��Ɉړ�
		case 75:movePos.x++; break; //�E�Ɉړ�
		case 77:movePos.x--; break; //���Ɉړ�

		case 'w':movePos.y++;   break; //���Ɉړ�
		case 's':movePos.y--;   break; //��Ɉړ�
		case 'a':movePos.x++;   break; //�E�Ɉړ�
		case 'd':movePos.x--;   break; //���Ɉړ�
		}
		moveToBlank(movePos);
	}
}

BOOL isDragging = FALSE;

*/