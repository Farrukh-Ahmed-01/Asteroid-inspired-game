/*
 * Point.h
 *
 *  Created on: May 1, 2018
 *      Author: farrukh
 */
#include<iostream>
#include <stdlib.h>
#include<cmath>
#include<cstring>
#include"Board.h"
using namespace std;
#ifndef POINT_H_
#define POINT_H_
void DrawAsteroid(int x/*starting x*/, int y/*starting y*/,
		ColorNames color/*color*/, float radius/*Asteroid radius in Units*/,
		const int corners=6/*Asteroid corners*/);
class Point {
	float X,Y;//had to make them float because of  shooter rotation
public:
	Point(int x=0,int y=0);
	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);
	void set(float x=50,float y=50);
	const Point& operator=(const Point&);
};

#endif /* POINT_H_ */
