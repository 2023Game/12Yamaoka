#ifndef CAPPLICARION_H
#define CAPPLICARION_H
#include "CRectangle.h"
#include "CTexture.h"
#include "CPlayer.h"
#include "CCharacter.h"
#include "CFont.h"
#include "CGame.h"

enum class GameState
{
	START_SCREEN,
	GAMEPLAY,
	GAMECLEAR,
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
	void SetActivePlayer(int index);
	void ChangeState(GameState newState);
	int activePlayerIndex = 0;
	std::vector<CPlayer> players;
	bool isActive;
	bool CheckIfPuzzleIsComplete() const;
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
	GameState mCurrentState;
	CGame* mpGame;
	CTitle* mpTitle;
	CClear* mpClear;
};

#endif