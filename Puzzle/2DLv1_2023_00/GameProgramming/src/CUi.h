#pragma once
#include "CFont.h"

//ユーザーインターフェースクラス
class CUi
{
public:
	CUi();
	void Time(int time);
	void Render();
	void Title(); //タイトル画面
private:
	int mTime; //経過時間
	CFont mFont;
};