#include "CInput.h"

CInput::CInput()
{
	
}

bool CInput::Key(char key)
{
	return GetAsyncKeyState(key) < 0;
}

GLFWwindow* CInput::mpWindow = nullptr;

void CInput::GetMousePos(int* px, int* py)
{
	double xpos, ypos;
	glfwGetCursorPos(mpWindow, &xpos, &ypos);
	*px = xpos;
	*py = ypos;
	return;
}

void CInput::Init(GLFWwindow* w)
{
	mpWindow = w;
}
