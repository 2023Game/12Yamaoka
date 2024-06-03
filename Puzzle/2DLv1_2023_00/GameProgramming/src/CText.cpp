#include "CText.h"

void CText::Render()
{

}

bool CText::IsClicked(float mouseX, float mouseY)
{
	const float SIZE = 10.0f;
	return (mouseX >= mX && mouseX <= mX + SIZE && mouseY >= mY && mouseY <= mY + SIZE);
}