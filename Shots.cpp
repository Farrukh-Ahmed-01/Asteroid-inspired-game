/*
 * Shots.cpp
 *
 *  Created on: May 5, 2018
 *      Author: farrukh
 */

#include "Shots.h"

Shots::Shots( Point c):Direction_controller(1)
{
	C=c;
	R.setX(GetRandInRange(0, 1020));
	R.setY(GetRandInRange(0, 840));
	Slope=((float)(C.getY()-R.getY()))/((float)(C.getX()-R.getX()));
	Constant=(float)C.getY()-(float)Slope*C.getX();
	Direction_controller=rand()%2;
	if(Direction_controller==0)
		Direction_controller=-1;

}
void Shots::Display()
{
	//DrawRoundRect(C.getX(), C.getY(), 30, 30,colors[WHITE],
//		30);
	DrawCircle(C.getX(), C.getY(), 5, colors[WHITE]);
}
void Shots::Movement(float speed)
{
	if(Slope>=-1 && Slope<=1)
		{
			C.setX(C.getX()+Direction_controller*speed);
			C.setY(Slope*C.getX()+Constant);
		}
		else
		{
			C.setY(C.getY()+Direction_controller*speed);
			C.setX((float)(C.getY()-Constant)/(Slope*1.0));
		}

}

void Shots::setSlope(float slope) {
	Slope = slope;
}

void Shots::setConstant(float constant) {
	Constant = constant;
}

float Shots::getSlope() const {
	return Slope;
}

float Shots::getConstant() const {
	return Constant;
}

Point& Shots::getC()  {
	return C;
}

void Shots::setC(Point c) {
	C = c;
}

int Shots::getDirectionController() const {
	return Direction_controller;
}

void Shots::setDirectionController(int directionController) {
	Direction_controller = directionController;
}

Point Shots::getR() const {
	return R;
}

void Shots::setR(Point r) {
	R = r;
}
