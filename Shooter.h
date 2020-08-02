/*
 * Shooter.h
 *
 *  Created on: May 3, 2018
 *      Author: farrukh
 */
#include"Point.h"
#include"Shots.h"
#ifndef SHOOTER_H_
#define SHOOTER_H_

class Shooter {
	Point P1,P2,P3;
	bool Key;
	float A1;
	Shots **S;
	int S_knower;
	bool destroy_checker;
	int Life;
public:
	Shooter();
	void Display();
	void Movement(float speed=5);
	void Rotate(float speed=1,int direction=1);
	void Fire();
	//void Shooting();
	//void up();
	//void down();
	//void right();
	//void left();
	 Shots**& getS();
	int getKnower() const;
	Point getP1() const;
	Point getP2() const;
	Point getP3() const;
	~Shooter();
	bool isDestroyChecker() const;
	void setDestroyChecker(bool destroyChecker);
	int getLife() const;
	void setLife(int life);
};

#endif /* SHOOTER_H_ */
