/*
 * Globalvariables.h
 *
 *  Created on: May 8, 2018
 *      Author: farrukh
 */
#include"Shots.h"
#include "Board.h"
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
#ifndef GLOBALVARIABLES_H_
#define GLOBALVARIABLES_H_

class Globalvariables {
public:
	Asteroid **ast;
	ComplexAsteroid **cast;
	Shooter *user;
	Bomberman **s_enemy;
	Complexbomberman **l_enemy;
	float Speed;
	bool allow ;
	bool ok;
	short total_asteroids;
	short total_complexasteroids;
	short total_smallenemies;
	short total_lmallenemies;
	Globalvariables();

};

#endif /* GLOBALVARIABLES_H_ */
