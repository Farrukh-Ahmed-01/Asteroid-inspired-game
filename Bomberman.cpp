/*
 * Bomberman.cpp
 *
 *  Created on: May 5, 2018
 *      Author: farrukh
 */

#include "Bomberman.h"
Bomberman::Bomberman():Relod_time(90),Shoot_controller(0),S_knower(0),destroy_checker(0)
{
	S=new Shots*[10];
	for(int i=0;i<10;i++)
		S[i]=NULL;
}
void Bomberman::Display()
{
	if(!destroy_checker)
	{
		DrawRoundRect(getC().getX(), getC().getY(), 30, 30,colors[BROWN],
				50);
		for(int i=0;i<=S_knower && S[i]!=NULL;i++)
			S[i]->Display();
	}
}
void Bomberman::Movement(float speed)
{
	if(!destroy_checker)
	{
	Asteroid::Movement(speed);
	++Shoot_controller;
	if(Shoot_controller==Relod_time)
	{
		if(S_knower==10)
			S_knower=0;
		if(S[S_knower]!=NULL)
			delete S[S_knower];
		S[S_knower]=new Shots(getC());
		++S_knower;
		Shoot_controller=0;
	}
	for(int i=0;i<=S_knower && (S[i]!=NULL);i++)
	{
		S[i]->Movement(speed*5);
		//cout<<"ok\n";
		}
	}
}

int Bomberman::getKnower() const {
	return S_knower;
}

void Bomberman::setKnower(int knower) {
	S_knower = knower;
}

 Shots**& Bomberman::getS()  {
	return S;
}

void Bomberman::setS( Shots**& s) {
	S = s;
}

bool Bomberman::isDestroyChecker() const {
	return destroy_checker;
}

void Bomberman::setDestroyChecker(bool destroyChecker) {
	destroy_checker = destroyChecker;
}
