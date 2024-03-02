#include "lab_m1/Tema1/Inamic.h"

namespace Inamic{
Inamic::Inamic()
{
}

Inamic::~Inamic()
{
}

void Inamic::setCoordinates(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Inamic::getX()
{
	return this->x;
}

float Inamic::getY()
{
	return this->y;
}

void Inamic::setScale(float x, float y)
{
	this->scaleX = x;
	this->scaleY = y;
}

float Inamic::getScaleX()
{
	return this->scaleX;
}

float Inamic::getScaleY()
{
	return this->scaleY;
}

//set pentru culoare
void Inamic::setColor(glm::vec3 color)
{
	this->color = color;
}

//get pentru culoare
glm::vec3 Inamic::getColor()
{
	return this->color;
}

//set pentru linie
void Inamic::setLine(glm::vec3 line)
{
	this->line = line;
}

//get pentru linie
glm::vec3 Inamic::getLine()
{
	return this->line;
}

void Inamic::setIndexColor(int a) {
	this->indexColor = a;
}

int Inamic::getIndexColor() {
	return this->indexColor;
}
}
