#ifndef CTEXT_H
#define CTEXT_H
#include <string>

class CText
{
public:
	CText(const std::string& text, float x, float y)
		:mText(text), mX(x), mY(y) {}
	void Render();
	bool IsClicked(float mouseX, float mouseY);
private:
	std::string mText;
	float mX, mY;
};


#endif