/*
 * Point.cpp
 *
 *  Created on: May 1, 2018
 *      Author: farrukh
 */

#include "Point.h"
Point::Point(int x,int y):X(x),Y(y)
{}
void Point::set(float x,float y)
{
	X=x;
	Y=y;
}

float Point::getX() const {
	return X;
}

void Point::setX(float x) {
	X = x;
}

float Point::getY() const {
	return Y;
}

void Point::setY(float y) {
	Y = y;
}
const Point& Point::operator =(const Point& p)
{
	X=p.X;
	Y=p.Y;
	return *this;
}
