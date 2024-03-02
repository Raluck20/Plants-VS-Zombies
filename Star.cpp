#include "lab_m1/Tema1/Star.h"
namespace Star{
	Star::Star()
	{
	}

	Star::~Star()
	{
	}

	void Star::setCoordinates(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	float Star::getX()
	{
		return this->x;
	}

	float Star::getY()
	{
		return this->y;
	}

	void Star::setScale(float x, float y)
	{
		this->scaleX = x;
		this->scaleY = y;
	}

	float Star::getScaleX()
	{
		return this->scaleX;
	}

	float Star::getScaleY()
	{
		return this->scaleY;
	}

	void Star::setRotation(float angle)
	{
		this->angle = angle;
	}

	float Star::getRotation()
	{
		return this->angle;
	}
}
