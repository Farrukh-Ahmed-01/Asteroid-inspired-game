
 /*
 *  Created on: May 5, 2018
 *      Author: farrukh
 */
#include"Asteroid.h"
#include"Shots.h"
#ifndef BOMBERMAN_H_
#define BOMBERMAN_H_

class Bomberman:public Asteroid {
	Shots **S;
	int Relod_time;
	int Shoot_controller;
	int S_knower;
	bool destroy_checker;

public:
	Bomberman();
	void Display();
	void Movement(float speed);
	int getKnower() const;
	void setKnower(int knower);
	 Shots**& getS() ;
	void setS( Shots**& s);
	bool isDestroyChecker() const;
	void setDestroyChecker(bool destroyChecker);
};

#endif /* BOMBERMAN_H_ */
