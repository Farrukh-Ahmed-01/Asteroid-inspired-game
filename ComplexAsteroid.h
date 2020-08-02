/*
 * ComplexAsteroid.h
 *
 *  Created on: May 2, 2018
 *      Author: farrukh
 */
#include"Asteroid.h"
#ifndef COMPLEXASTEROID_H_
#define COMPLEXASTEROID_H_

class ComplexAsteroid :public Asteroid
{
	int Slope_changer,Stopper;


public:
	ComplexAsteroid();
	void Display();
	void Movement(float speed=1);//,int slope_change=0);
	int getSlopeChanger() const;
	void setSlopeChanger(int slopeChanger);
	int getStopper() const;
	void setStopper(int stopper);
};

#endif /* COMPLEXASTEROID_H_ */
