#include "CInput.h"

CInput::CInput()
{
	
}

bool CInput::Key(char key)
{
	return GetAsyncKeyState(key) < 0;
}