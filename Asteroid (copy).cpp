/*
 * Asteroid.cpp
 *
 *  Created on: May 1, 2018
 *      Author: farrukh
 */

#include "Asteroid.h"
Asteroid::Asteroid():Radius(30),Slope(0),Constant(0),destroy_checker(0)
{
	Direction_controller=rand()%2;
	if(Direction_controller==0)
		Direction_controller=-1;
	C.setX(GetRandInRange(0, 1020));
	C.setY(GetRandInRange(0, 840));
	setSlope();
}
void Asteroid::Display()
{
	DrawAsteroid(C.getX(),  C.getY(), ORANGE,Radius);
	//DrawCircle(C.getX(), C.getY(), Radius,);
}void Asteroid::setSlope()
{
	Slope=((float)(C.getY()-R.getY()))/((float)(C.getX()-R.getX()));
	//cout<<"Actual Slope: :"<<Slope<<"weeeeeeeeeeeeeeeeeeeeeeee\n";
	Constant=(float)C.getY()-(float)Slope*C.getX();
}
void Asteroid::setSlope2(float s)
{
	Slope=s;
}
Point& Asteroid::getC()  {
	return C;
}

void Asteroid::setC(Point c) {
	C = c;
}

Point& Asteroid::getR()  {
	return R;
}

void Asteroid::setR(Point r) {
	R = r;
}

int Asteroid::getRadius() const {
	return Radius;
}

void Asteroid::setConstant(float constant) {
	Constant = constant;
}
void Asteroid::setConstant()
{
	Constant=(float)C.getY()-(float)Slope*C.getX();
}
float Asteroid::getSlope() const {
	return Slope;
}

void Asteroid::setRadius(int radius) {
	Radius = radius;
}
void Asteroid::Movement(float speed)
{if(!destroy_checker){
	if(C.getX()>1020)
	{
		C.setX(0);
		Constant=(float)C.getY()-(float)Slope*C.getX();
	}
	else if(C.getX()<0)
		{
			C.setX(1020);
			Constant=(float)C.getY()-(float)Slope*C.getX();
		}
	else if(C.getY()>840)
		{
			C.setY(0);
			Constant=(float)C.getY()-(float)Slope*C.getX();
		}
	else if(C.getY()<0)
		{
			C.setY(840);
			Constant=(float)C.getY()-(float)Slope*C.getX();
		}
	if(Slope>=-1 && Slope<=1)
	{
		C.setX(C.getX()+speed*Direction_controller);//3 will be its speed
		C.setY(Slope*C.getX()+Constant);//replace constant with 1//Slope*C.getX()
	}
	else
	{
		C.setY(C.getY()+speed*Direction_controller);
		C.setX((C.getY()-Constant)/Slope);
	}

}


}

bool Asteroid::getDestroyChecker() const {
	return destroy_checker;
}

void Asteroid::setDestroyChecker(bool destroyChecker) {
	destroy_checker = destroyChecker;
}
Asteroid::~Asteroid()
{}
