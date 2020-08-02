/*
 * Complexbomberman.h
 *
 *  Created on: May 5, 2018
 *      Author: farrukh
 */
#include"ComplexAsteroid.h"
#include"Shots.h"
#ifndef COMPLEXBOMBERMAN_H_
#define COMPLEXBOMBERMAN_H_

class Complexbomberman :public ComplexAsteroid {
	Shots **S;
	int Relod_time;
	int Shoot_controller;
	int S_knower;
public:
	Complexbomberman();
	void Display();
	void Movement(float speed);
	int getKnower() const;
	void setKnower(int knower);
	 Shots**& getS() ;
	void setS( Shots**& s);
};

#endif /* COMPLEXBOMBERMAN_H_ */
