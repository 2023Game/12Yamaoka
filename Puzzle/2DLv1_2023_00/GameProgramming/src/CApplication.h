#ifndef CAPPLICARION_H
#define CAPPLICARION_H
#include "CRectangle.h"
#include "CTexture.h"
#include "CPlayer.h"
#include "CCharacter.h"
#include "CFont.h"
#include "CGame.h"
#include "CTitle.h"

enum class GameState
{
	START_SCREEN,
	GAMEPLAY,
	PAUSE,
};

class CApplication
{
public:
//	CApplication();
	//最初に一度だけ実行するプログラム
	void Start();
	//繰り返し実行するプログラム
	void Update();
	void OnMouseClick(float x, float y);
	int activePlayerIndex = 0;
	std::vector<CPlayer> players;
	void SetActivePlayer(int index);
	void ChangeState(GameState newState);
private:
	CRectangle mRectangle;
	CTexture mTexture;
	CTexture texture1;
	CTexture texture2;
	CTexture texture3;
	CTexture texture4;
	CCharacter mCharacter;
	CPlayer mPlayer;
	CPlayer* activePlayer;
	CFont mFont;
	CGame* mpGame;
	GameState mCurrentState;
	CTitle* mpTitle;
//	CText mText;
};

#endif