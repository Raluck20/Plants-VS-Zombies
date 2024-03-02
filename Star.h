#pragma once

#include "lab_m1/Tema1/object2D.h"

namespace Star {
	class Star
	{
	public:
		Star();
		~Star();
		void setCoordinates(float x, float y);
		float getX();
		float getY();
		void setScale(float x, float y);
		float getScaleX();
		float getScaleY();
		void setRotation(float angle);
		float getRotation();

	private:
		float x, y;
		float scaleX, scaleY;
		float angle;
	};
}