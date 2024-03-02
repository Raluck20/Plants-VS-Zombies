#pragma once

#include "lab_m1/Tema1/object2D.h"

class Romb
{

public:

	Romb();
	~Romb();
	void setCoordinates(float x, float y);
	float getX();
	float getY();
	void setScale(float x, float y);
	float getScaleX();
	float getScaleY();
private:
	float x, y;
	float scaleX, scaleY;
};