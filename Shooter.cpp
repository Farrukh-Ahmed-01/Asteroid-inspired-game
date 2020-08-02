/*
 * Shooter.cpp
 *
 *  Created on: May 3, 2018
 *      Author: farrukh
 */

#include "Shooter.h"
Shooter::Shooter():Key(0),A1(90),S_knower(0),destroy_checker(0),Life(3)//here 50 is distance between bottom 2 points
{
	P1.setY(60);//so 30 will be the height of shooter
	P1.setX(420);
	P2.setY(0);
	P2.setX(420-25);
	P3.setY(0);
	P3.setX(420+25);
	S=new Shots*[150];//allowing ship maximun 50 shots
	for(int i=0;i<150;i++)
		S[i]=NULL;
}
void Shooter::Display()
{
	if(!destroy_checker){
	 DrawTriangle(P1.getX(), P1.getY(), P2.getX(), P2.getY(), P3.getX(), P3.getY(),colors[77]);
	 for(int i=0;i<=S_knower && S[i]!=NULL;i++)
	 	{
	 	 S[i]->Movement(1*5);
	 	 S[i]->Display();
	 	}
	}
}

 Shots**& Shooter::getS()  {
	return S;
}

int Shooter::getKnower() const {
	return S_knower;
}

void Shooter::Fire()
{
	if(!destroy_checker){
	if(S_knower==150)
		S_knower=0;
	if(S[S_knower]!=NULL)
		delete S[S_knower];
	S[S_knower]=new Shots(P1);
	S[S_knower]->setSlope(tan(Deg2Rad(A1)));
	S[S_knower]->setConstant((float)P1.getY()-(float)tan(Deg2Rad(A1))*P1.getX());
	S[S_knower]->setDirectionController(1);
	if((S[S_knower]->getSlope()>=-1 && S[S_knower]->getSlope()<=1)&& P1.getX()<P2.getX() )
	{
		S[S_knower]->setDirectionController(-1);
		cout<<S[S_knower]->getDirectionController();
	}
	else if((S[S_knower]->getSlope()<-1 || S[S_knower]->getSlope()>1) && P1.getY()<P2.getY())
		S[S_knower]->setDirectionController(-1);
	//cout<<"Slope: "<<S[S_knower]->getConstant()<<" tan(angle): "<<(float)P1.getY()-(float)tan(Deg2Rad(A1))*P1.getX();
	++S_knower;
	}

}
void Shooter::Movement(float speed)
{	if(!destroy_checker){
	if(speed!=0)
	{
		P1.setX(P1.getX()+(cos(Deg2Rad(A1))*speed));
		P1.setY(P1.getY()+(sin(Deg2Rad(A1))*speed));
		P2.setX(P2.getX()+(cos(Deg2Rad(A1))*speed));
		P2.setY(P2.getY()+(sin(Deg2Rad(A1))*speed));
		P3.setX(P3.getX()+(cos(Deg2Rad(A1))*speed));
		P3.setY(P3.getY()+(sin(Deg2Rad(A1))*speed));

	//int width = 1020, height = 840;
	if(P1.getX()>=1020 || P1.getX()<=0 )
	{
		int x=0;
		if(P1.getX()<=0)
			x=1020;
		float temp2=P2.getX()-P1.getX();
		float temp3=P3.getX()-P1.getX();
		P1.setX(x);
		P2.setX(P1.getX()+temp2);
		P3.setX(P1.getX()+temp3);
	}
	else if(P1.getY()>=840 || P1.getY()<=0 )
	{
		int y=0;
		if(P1.getY()<=0)
			y=840;
		float temp2=P2.getY()-P1.getY();
		float temp3=P3.getY()-P1.getY();
		P1.setY(y);
		P2.setY(P1.getY()+temp2);
		P3.setY(P1.getY()+temp3);
			}
		}
	}
}
void Shooter::Rotate(float speed,int direction)
{
	float angle=5;
	A1+=5*direction;
	float tx1=P1.getX();
	float ty1=P1.getY();
	float tx,ty;
	//point 1:
	//point moved to origin
	P1.setX(P1.getX()-tx1);
	P1.setY(P1.getY()-ty1);
	P2.setX((P2.getX()-tx1));
	P2.setY(P2.getY()-ty1);
	P3.setX(P3.getX()-tx1);
	P3.setY(P3.getY()-ty1);
	//rotation from here
	tx=P2.getX();
	ty=P2.getY();
	P2.setX(tx*cos(Deg2Rad(angle*direction))-ty*sin(Deg2Rad(angle*direction)));
	P2.setY(tx*sin(Deg2Rad(angle*direction))+ty*cos(Deg2Rad(angle*direction)));
	tx=P3.getX();
	ty=P3.getY();
	P3.setX(tx*cos(Deg2Rad(angle*direction))-ty*sin(Deg2Rad(angle*direction)));
	P3.setY(tx*sin(Deg2Rad(angle*direction))+ty*cos(Deg2Rad(angle*direction)));
	//point moved backed to its initial position
	P1.setX(P1.getX()+tx1);
	P1.setY(P1.getY()+ty1);
	P2.setX((P2.getX()+tx1));
	P2.setY(P2.getY()+ty1);
	P3.setX(P3.getX()+tx1);
	P3.setY(P3.getY()+ty1);



}

Point Shooter::getP1() const {
	return P1;
}

Point Shooter::getP2() const {
	return P2;
}

Point Shooter::getP3() const {
	return P3;
}
Shooter::~Shooter()
{
	for(int i=0;i<150  && i<S_knower;i++)
		delete S[i];
	delete []S;
	S=NULL;
}

bool Shooter::isDestroyChecker() const {
	return destroy_checker;
}

void Shooter::setDestroyChecker(bool destroyChecker) {
	destroy_checker = destroyChecker;
}

int Shooter::getLife() const {
	return Life;
}

void Shooter::setLife(int life) {
	Life = life;
}
