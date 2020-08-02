/*
 * Asteroid.h
 *
 *  Created on: May 1, 2018
 *      Author: farrukh
 */
#include"Point.h"
#include"util.h"
#ifndef ASTEROID_H_
#define ASTEROID_H_

class Asteroid {
	Point C,R;
	int Radius,Direction_controller;
	float Slope,Constant;
	bool destroy_checker;
public:
	Asteroid();
	virtual void Display();
	void setSlope();
	void setSlope2(float s);
	virtual void Movement(float speed);
	Point& getC() ;
	void setC(Point c);
	Point& getR() ;
	void setR(Point r);
	int getRadius() const;
	void setRadius(int radius);
	float getSlope() const;
	void setConstant(float constant);
	void setConstant();
	bool getDestroyChecker() const;
	void setDestroyChecker(bool destroyChecker);
	virtual ~Asteroid();
};
#endif /* ASTEROID_H_ */
