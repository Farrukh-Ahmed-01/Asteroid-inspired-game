/*
 * ComplexAsteroid.cpp
 *
 *  Created on: May 2, 2018
 *      Author: farrukh
 */

#include "ComplexAsteroid.h"
ComplexAsteroid::ComplexAsteroid():Slope_changer(0),Stopper(100)//initially i choose 3 but since its speed would be 3 so 100
{}
void ComplexAsteroid::Display()
	{
		DrawAsteroid(getC().getX(), getC().getY(),YELLOW , 60);
	}
void ComplexAsteroid::Movement(float speed)//,int slope_changer)
{
	if(Slope_changer==Stopper)
		{
		setSlope2((rand() % 1000)/100);
		setConstant();
		Slope_changer=0;
		}
	Asteroid::Movement(speed);
	++Slope_changer;
}

int ComplexAsteroid::getSlopeChanger() const {
	return Slope_changer;
}

int ComplexAsteroid::getStopper() const {
	return Stopper;
}

void ComplexAsteroid::setStopper(int stopper) {
	Stopper = stopper;
}

void ComplexAsteroid::setSlopeChanger(int slopeChanger) {
	Slope_changer = slopeChanger;
}
