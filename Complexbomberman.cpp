/*
 * Complexbomberman.cpp
 *
 *  Created on: May 5, 2018
 *      Author: farrukh
 */

#include "Complexbomberman.h"
Complexbomberman::Complexbomberman():Relod_time(90),Shoot_controller(0),S_knower(0)
{
	S=new Shots*[10];
	for(int i=0;i<10;i++)
		S[i]=NULL;
}
void Complexbomberman::Display()
{
	DrawRoundRect(getC().getX(), getC().getY(), 60, 60,colors[RED],
		100);
	for(int i=0;i<=S_knower && S[i]!=NULL;i++)
			S[i]->Display();
}

void Complexbomberman::Movement(float speed)
{
		ComplexAsteroid::Movement(speed);
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



int Complexbomberman::getKnower() const {
	return S_knower;
}

void Complexbomberman::setKnower(int knower) {
	S_knower = knower;
}

 Shots**& Complexbomberman::getS()  {
	return S;
}

void Complexbomberman::setS( Shots**& s) {
	S = s;
}
