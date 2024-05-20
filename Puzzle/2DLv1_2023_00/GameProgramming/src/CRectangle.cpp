#include "CRectangle.h"
#include <stdio.h>
#include "glut.h"

CRectangle::CRectangle()
{
	printf("インスタンスが生まれました\n");
}

CRectangle::~CRectangle()
{
	printf("インスタンスが破壊されました\n");
}

void CRectangle::Render()
{
	glBegin(GL_QUADS);
	glVertex2f(100.0f, 100.0f);
	glVertex2f(700.0f, 100.0f);
	glVertex2f(700.0f, 500.0f);
	glVertex2f(100.0f, 500.0f);
	glEnd();
}

void CRectangle::Render(float x, float y, float w, float h)
{

	glBegin(GL_QUADS);
	glVertex2f(x - w, y - h);
	glVertex2f(x + w, y - h);
	glVertex2f(x + w, y + h);
	glVertex2f(x - w, y + h);
	glEnd();
}

void CRectangle::Set(float x, float y, float w, float h)
{
	mX = x;
	mY = y;
	mW = w;
	mH = h;
}

float CRectangle::X()
{
	return mX;
}

float CRectangle::Y()
{
	return mY;
}

float CRectangle::W()
{
	return mW;
}

float CRectangle::H()
{
	return mH;
}

void CRectangle::X(float x)
{
	mX = x;
}

void CRectangle::Y(float y)
{
	mY = y;
}