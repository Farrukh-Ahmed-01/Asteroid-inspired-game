/*
 * Shots.h
 *
 *  Created on: May 5, 2018
 *      Author: farrukh
 */
#include"Point.h"
#include"Asteroid.h"
#ifndef SHOTS_H_
#define SHOTS_H_

class Shots:Asteroid {
	Point R;
	Point C;
	float Slope,Constant;
	int Direction_controller;
public:
	Shots( Point c);
	void Display();
	void Movement(float speed);
	void setSlope(float slope);
	void setConstant(float constant);
	float getSlope() const;
	float getConstant() const;
	Point& getC() ;
	void setC(Point c);
	int getDirectionController() const;
	void setDirectionController(int directionController);
	Point getR() const;
	void setR(Point r);
};

#endif /* SHOTS_H_ */
