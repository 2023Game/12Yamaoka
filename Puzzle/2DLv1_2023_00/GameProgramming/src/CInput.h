#ifndef CINPUT_H
#define CINPUT_H
#include "GLFW/glfw3.h"
#include <Windows.h>

class CInput
{
	static GLFWwindow* mpWindow;
public:
	CInput();
	bool Key(char key);
	static void Init(GLFWwindow* w); //ウィンドウポインタ
	static void GetMousePos(int* px, int* py);
};

#endif