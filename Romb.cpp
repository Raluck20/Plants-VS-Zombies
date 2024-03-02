#include "lab_m1/Tema1/Romb.h"

Romb::Romb()
{
}

Romb::~Romb()
{
}

void Romb::setCoordinates(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Romb::getX()
{
	return this->x;
}

float Romb::getY()
{
	return this->y;
}

void Romb::setScale(float x, float y)
{
	this->scaleX = x;
	this->scaleY = y;
}

float Romb::getScaleX()
{
	return this->scaleX;
}

float Romb::getScaleY()
{
	return this->scaleY;
}
