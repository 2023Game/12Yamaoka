#pragma once

class CRectangle
{
public:
	CRectangle();
	~CRectangle();
	void Render();
	void Render(float x, float y, float w, float h);
	void Set(float x, float y, float w, float h);
private:
	float mX;
	float mY;
	float mW;
	float mH;
};
