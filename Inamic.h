#pragma once

#include "lab_m1/Tema1/object2D.h"

namespace Inamic {
class Inamic
{
public:
	Inamic();
	~Inamic();
	void setCoordinates(float x, float y);
	float getX();
	float getY();
	void setScale(float x, float y);
	float getScaleX();
	float getScaleY();
	//set pentru culoare
	void setColor(glm::vec3 color);
	//get pentru culoare
	glm::vec3 getColor();
	//set pentru linie
	void setLine(glm::vec3 line);
	//get pentru linie
	glm::vec3 getLine();
	void setIndexColor(int index);
	int getIndexColor();

	private:
		float x, y;
		float scaleX, scaleY;
		glm::vec3 color;
		glm::vec3 line;
		int indexColor;
};
}