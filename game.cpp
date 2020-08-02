//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Brick Slayer...
//============================================================================
#include"ComplexAsteroid.h"
#include"Shooter.h"
#include"Bomberman.h"
#include"Complexbomberman.h"
#include"Shots.h"
#include "Globalvariables.h"
#ifndef AsteroidS_CPP_
#define AsteroidS_CPP_
#include "Board.h"
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
Board *b;

//Globalvariables G();
Asteroid **ast;
ComplexAsteroid **cast;
Shooter *user;
Bomberman **s_enemy;
Complexbomberman **l_enemy;
Asteroid ***WOW;
float Speed=0;
bool allow =1;
bool ok=1;
short total_asteroids=3;
short total_complexasteroids=2;
short total_smallenemies=2;
short total_lmallenemies=1;
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

void DrawAsteroid(const int & cx, const int &cy, const ColorNames & cname,int R) // center of Asteroid
		{
	int radius = R; // sample radius
	int rndpoint = GetRandInRange(0, 9);
	int npoints = MAX(4, rndpoint);
	cout << npoints << endl;
	int dtheta = 360 / npoints;
	// using the formula rcostheta and rsin theta;
	float theta = GetRandInRange(0, dtheta);
	int sx = cx + radius * cos(Deg2Rad(theta)), sy = cy
			+ radius * sin(Deg2Rad(theta));
	int x1 = sx;
	int y1 = sy;
	int stheta = dtheta;
	for (int i = 0; i < npoints - 1; ++i) {
		theta = GetRandInRange(stheta, stheta + dtheta);
		int x2 = cx + radius * cos(Deg2Rad(theta)), y2 = cy
				+ radius * sin(Deg2Rad(theta));
		DrawLine(x1, y1, x2, y2, 10, colors[cname]);
		x1 = x2;
		y1 = y2;
		stheta += dtheta;
	}
	DrawLine(x1, y1, sx, sy, 10, colors[cname]);

}
void DrawAsteroid(int x/*starting x*/, int y/*starting y*/,
		ColorNames color/*color*/, float radius/*Asteroid radius in Units*/,
		const int corners/*Asteroid corners*/) {
	int ogr = 6, ogh = 7;

	glPushMatrix();
	float sx = (float) radius / ogr;
	//glTranslatef(x, y, 1);
	//glScalef(sx, 1, 1);

	// Draw Asteroid here
	const int nvertices = 722;
	GLfloat vertices[nvertices][2];
	float hdegree = M_PI / (corners / 2);
	float angle = 0;
	for (int i = 0; i < nvertices; ++i) {
		vertices[i][0] = radius * cos(angle);
		vertices[i][1] = radius * sin(angle);
		angle += hdegree;
	}

	glColor3fv(colors[color]); // set the circle color
	glBegin (GL_TRIANGLE_FAN);
	glVertex4f(x, y, 0, 1);
	for (int i = 0; i < nvertices; ++i)
		glVertex4f(x + vertices[i][0], y + vertices[i][1], 0, 1);
	glEnd();

	glPopMatrix();
}

/*
 * Main Canvas drawing function.
 * */
//Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	if(ok)
		{
		user->Display();
		user->Movement(Speed);

		}
	//user->Movement(1);
	// draw four asteroids
	//int randX,RandY;
	if(ok){//removed user!=NULL
	//Shooter ckecking collision with asteroids(for POINT P1)
	int tx=user->getP1().getX();
	int ty=user->getP1().getY();
	int tx1=user->getP2().getX();
	int ty1=user->getP2().getY();
	int tx2=user->getP3().getX();
	int ty2=user->getP3().getY();
	bool not_Destroy=1;
	for(int m=0;m<total_asteroids&& ast[m]!=NULL && not_Destroy;m++)//removed && ok
			{
				if((sqrt(((tx-ast[m]->getC().getX())*(tx-ast[m]->getC().getX()))+((ty-ast[m]->getC().getY())*(ty-ast[m]->getC().getY())))<=ast[m]->getRadius())||(sqrt(((tx1-ast[m]->getC().getX())*(tx1-ast[m]->getC().getX()))+((ty1-ast[m]->getC().getY())*(ty1-ast[m]->getC().getY())))<=ast[m]->getRadius())||(sqrt(((tx2-ast[m]->getC().getX())*(tx2-ast[m]->getC().getX()))+((ty2-ast[m]->getC().getY())*(ty2-ast[m]->getC().getY())))<=ast[m]->getRadius()))
				{
					user->setLife(user->getLife()-1);
					if(user->getLife()==0)
					{
					user->getP1().setX(-10000);
					user->getP1().setY(-10000);
					user->getP2().setX(-10000);
					user->getP2().setY(-10000);
					user->getP3().setX(-10000);
					user->getP3().setY(-10000);
					ok=0;
					cout<<user->getP1().getX();}
					//delete ast[m];
					//ast[m]=NULL;
					ast[m]->getC().set(1000000,1000000);
					ast[m]->setDestroyChecker(1);

				}
			}
			//
	for(int m=0;m<total_smallenemies && s_enemy[m]!=NULL &&user!=NULL &&not_Destroy ;m++)
			{
				if((sqrt(((tx-s_enemy[m]->getC().getX())*(tx-s_enemy[m]->getC().getX()))+((ty-s_enemy[m]->getC().getY())*(ty-s_enemy[m]->getC().getY())))<=s_enemy[m]->getRadius())||(sqrt(((tx1-s_enemy[m]->getC().getX())*(tx1-s_enemy[m]->getC().getX()))+((ty1-s_enemy[m]->getC().getY())*(ty1-s_enemy[m]->getC().getY())))<=s_enemy[m]->getRadius())||(sqrt(((tx2-s_enemy[m]->getC().getX())*(tx2-s_enemy[m]->getC().getX()))+((ty2-s_enemy[m]->getC().getY())*(ty2-s_enemy[m]->getC().getY())))<=s_enemy[m]->getRadius()))
				{
					//delete user;
					//user=NULL;
					user->setLife(user->getLife()-1);
										if(user->getLife()==0){
					user->getP1().setX(-10000);
					user->getP1().setY(-10000);
					user->getP2().setX(-10000);
					user->getP2().setY(-10000);
					user->getP3().setX(-10000);
					user->getP3().setY(-10000);
					ok=0;}
					//cout<<G.user->getP1().getX();
					delete s_enemy[m];
					s_enemy[m]=NULL;
				}
			}
			//
	for(int m=0;m<total_complexasteroids && cast[m]!=NULL &&user!=NULL &&not_Destroy;m++)
			{
				if((sqrt(((tx-cast[m]->getC().getX())*(tx-cast[m]->getC().getX()))+((ty-cast[m]->getC().getY())*(ty-cast[m]->getC().getY())))<=cast[m]->getRadius())||(sqrt(((tx1-cast[m]->getC().getX())*(tx1-cast[m]->getC().getX()))+((ty1-cast[m]->getC().getY())*(ty1-cast[m]->getC().getY())))<=cast[m]->getRadius())||(sqrt(((tx2-cast[m]->getC().getX())*(tx2-cast[m]->getC().getX()))+((ty2-cast[m]->getC().getY())*(ty2-cast[m]->getC().getY())))<=cast[m]->getRadius()))
				{
					//delete user;
					//user=NULL;
					user->setLife(user->getLife()-1);
										if(user->getLife()==0){
					user->getP1().setX(-10000);
					user->getP1().setY(-10000);
					user->getP2().setX(-10000);
					user->getP2().setY(-10000);
					user->getP3().setX(-10000);
					user->getP3().setY(-10000);
					ok=0;
					cout<<user->getP1().getX();}
					delete cast[m];
					cast[m]=NULL;
				}
			}
			//
	for(int m=0;m<total_lmallenemies && l_enemy[m]!=NULL &&user!=NULL &&not_Destroy;m++)
			{
				if((sqrt(((tx-l_enemy[m]->getC().getX())*(tx-l_enemy[m]->getC().getX()))+((ty-l_enemy[m]->getC().getY())*(ty-l_enemy[m]->getC().getY())))<=l_enemy[m]->getRadius())||(sqrt(((tx1-l_enemy[m]->getC().getX())*(tx1-l_enemy[m]->getC().getX()))+((ty1-l_enemy[m]->getC().getY())*(ty1-l_enemy[m]->getC().getY())))<=l_enemy[m]->getRadius())||(sqrt(((tx2-l_enemy[m]->getC().getX())*(tx2-l_enemy[m]->getC().getX()))+((ty2-l_enemy[m]->getC().getY())*(ty2-l_enemy[m]->getC().getY())))<=l_enemy[m]->getRadius()))
				{
					//delete user;
					//user=NULL;
					user->setLife(user->getLife()-1);
									if(user->getLife()==0){
					user->getP1().setX(-10000);
					user->getP1().setY(-10000);
					user->getP2().setX(-10000);
					user->getP2().setY(-10000);
					user->getP3().setX(-10000);
					user->getP3().setY(-10000);
					ok=0;
					DrawString(840/2-300,1020/2-300,600,600,"GAME OVER",colors[BLUE]);
					//cout<<G.user->getP1().getX();}
										}
					delete l_enemy[m];
					l_enemy[m]=NULL;
				}
			}

	//Shooter not ckecking collision with asteroids
//if(user!=NULL){
//Shooter shots checking collision

for(int i=0; i<user->getKnower() &&user!=NULL;i++)
	{	bool wow=1;
		int tx=user->getS()[i]->getC().getX();
		int ty=user->getS()[i]->getC().getY();
		for(int m=0;m<total_asteroids && ast[m]!=NULL && wow;m++)
		{
			if(sqrt(((tx-ast[m]->getC().getX())*(tx-ast[m]->getC().getX()))+((ty-ast[m]->getC().getY())*(ty-ast[m]->getC().getY())))<=ast[m]->getRadius())
			{
				//delete *(ast+m);
				//ast[m]=NULL;
				//cout<<"\nlol"<<ast[m]->getC().getX()<<"lol\n";
				//cout<<"\nlol"<<ast[m]->getC().getY()<<"lol\n";
				//Point temp(-6,30000);
				ast[m]->getC().setX(20000);
				ast[m]->getC().setY(50000);
				ast[m]->setDestroyChecker(1);
				//cout<<"\nwow"<<ast[m]->getC().getX()<<"wow\n";
				//cout<<"\nwow"<<ast[m]->getC().getY()<<"wow\n";
				wow=0;

			}
		}
		//
		for(int m=0;m<total_smallenemies &&s_enemy[m]!=NULL &&wow;m++)
		{
			if(sqrt(((tx-s_enemy[m]->getC().getX())*(tx-s_enemy[m]->getC().getX()))+((ty-s_enemy[m]->getC().getY())*(ty-s_enemy[m]->getC().getY())))<=s_enemy[m]->getRadius())
			{
				delete s_enemy[m];
				s_enemy[m]=NULL;
				wow=0;
			}
		}
		//
		for(int m=0;m<total_complexasteroids && cast[m]!=NULL && wow;m++)
		{
			if(sqrt(((tx-cast[m]->getC().getX())*(tx-cast[m]->getC().getX()))+((ty-cast[m]->getC().getY())*(ty-cast[m]->getC().getY())))<=cast[m]->getRadius())
			{
				Point p;
				p=cast[m]->getC();
				delete cast[m];
				cast[m]=NULL;
				Asteroid **a;
				a=new Asteroid*[total_asteroids+2];
				for(int i=0;i<total_asteroids;i++)
					a[i]=ast[i];
				delete ast;
				total_asteroids+=2;
				ast=new Asteroid*[total_asteroids];
				for(int i=0;i<total_asteroids-2;i++)
					ast[i]=a[i];
				delete a;
				ast[total_asteroids-2]=new Asteroid;
				ast[total_asteroids-2]->setC(p);
				Point tp;
				tp.set(GetRandInRange(0,840),GetRandInRange(0,1020));
				ast[total_asteroids-2]->setR(tp);
				ast[total_asteroids-2]->setSlope();
				ast[total_asteroids-1]=new Asteroid;
				tp.set(GetRandInRange(0,840),GetRandInRange(0,1020));
				ast[total_asteroids-2]->setR(tp);
				ast[total_asteroids-1]->setC(p);
				ast[total_asteroids-1]->setSlope();
				wow=0;
				user->getS()[i]->getC().set(1000000,1000000);
			}
		}
		//
		for(int m=0;m<total_lmallenemies && l_enemy[m]!=NULL && wow;m++)
		{
			if(sqrt(((tx-l_enemy[m]->getC().getX())*(tx-l_enemy[m]->getC().getX()))+((ty-l_enemy[m]->getC().getY())*(ty-l_enemy[m]->getC().getY())))<=l_enemy[m]->getRadius())
			{
				delete l_enemy[m];
				l_enemy[m]=NULL;
				wow=0;
			}
		}
}//
}
//Shooter shots not checking collision


//Bomber shots checking collision
	for(int k=0;k<total_smallenemies && s_enemy[k]!=NULL ;k++)
	{
		for(int i=0; i<s_enemy[k]->getKnower();i++)
			{	bool wow=1;
				int tx=s_enemy[k]->getS()[i]->getC().getX();
				int ty=s_enemy[k]->getS()[i]->getC().getY();
				for(int m=0;m<total_asteroids && ast[m]!=NULL && wow;m++)
				{
					if(sqrt(((tx-ast[m]->getC().getX())*(tx-ast[m]->getC().getX()))+((ty-ast[m]->getC().getY())*(ty-ast[m]->getC().getY())))<=ast[m]->getRadius())
					{
						//delete ast[m];
						//ast[m]=NULL;
						wow=0;
						ast[m]->getC().set(1000000,1000000);
						ast[m]->setDestroyChecker(1);
						s_enemy[k]->getS()[i]->getC().set(1000000,1000000);
					}
				}
				//
				//
				//Point 2
				int temcx=user->getP2().getX();
				int temcy=user->getP2().getY();
				int temcr=25;
				if(sqrt(((tx-temcx)*(tx-temcx))+((ty-temcy)*(ty-temcy)))<=temcr)
				{
					user->setLife(user->getLife()-1);
										if(user->getLife()==0){
					user->getP1().setX(-10000);
					user->getP1().setY(-10000);
					user->getP2().setX(-10000);
					user->getP2().setY(-10000);
					user->getP3().setX(-10000);
					user->getP3().setY(-10000);
					s_enemy[k]->getS()[i]->getC().set(1000000,1000000);
					cout<<"OK";
					user->setDestroyChecker(1);}
				}
				//Point 1
				temcx=user->getP1().getX();
				temcy=user->getP1().getY();
				if(sqrt(((tx-temcx)*(tx-temcx))+((ty-temcy)*(ty-temcy)))<=temcr)
					{
					user->setLife(user->getLife()-1);
										if(user->getLife()==0){
						user->getP1().setX(-10000);
						user->getP1().setY(-10000);
						user->getP2().setX(-10000);
						user->getP2().setY(-10000);
						user->getP3().setX(-10000);
						user->getP3().setY(-10000);
						s_enemy[k]->getS()[i]->getC().set(1000000,1000000);
						cout<<"OK";
						user->setDestroyChecker(1);}
					}
				//Point 3
				temcx=user->getP3().getX();
				temcy=user->getP3().getY();
				if(sqrt(((tx-temcx)*(tx-temcx))+((ty-temcy)*(ty-temcy)))<=temcr)
						{
					user->setLife(user->getLife()-1);
										if(user->getLife()==0){
					user->getP1().setX(-10000);
					user->getP1().setY(-10000);
					user->getP2().setX(-10000);
					user->getP2().setY(-10000);
					user->getP3().setX(-10000);
					user->getP3().setY(-10000);
					s_enemy[k]->getS()[i]->getC().set(1000000,1000000);
							cout<<"OK";
							user->setDestroyChecker(1);}
						}
				//
				//
				for(int m=0;m<total_smallenemies && s_enemy[m]!=NULL &&wow;m++)
				{
					if(sqrt(((tx-s_enemy[m]->getC().getX())*(tx-s_enemy[m]->getC().getX()))+((ty-s_enemy[m]->getC().getY())*(ty-s_enemy[m]->getC().getY())))<=s_enemy[m]->getRadius())
					{
						//delete s_enemy[m];
						//s_enemy[m]=NULL;
						wow=0;
					}
				}
				//
				for(int m=0;m<total_complexasteroids && cast[m]!=NULL && wow;m++)
				{
					if(sqrt(((tx-cast[m]->getC().getX())*(tx-cast[m]->getC().getX()))+((ty-cast[m]->getC().getY())*(ty-cast[m]->getC().getY())))<=cast[m]->getRadius())
					{
						Point p;
						p=cast[m]->getC();
						//delete cast[m];
						//cast[m]=NULL;
						Asteroid **a;
						a=new Asteroid*[total_asteroids+2];
						for(int i=0;i<total_asteroids;i++)
							a[i]=ast[i];
						delete ast;
						total_asteroids+=2;
						ast=new Asteroid*[total_asteroids];
						for(int i=0;i<total_asteroids-2;i++)
							ast[i]=a[i];
						delete a;
						ast[total_asteroids-2]=new Asteroid;
						ast[total_asteroids-2]->setC(p);
						Point tp;
						tp.set(GetRandInRange(0,840),GetRandInRange(0,1020));
						ast[total_asteroids-2]->setR(tp);
						ast[total_asteroids-2]->setSlope();
						ast[total_asteroids-1]=new Asteroid;
						tp.set(GetRandInRange(0,840),GetRandInRange(0,1020));
						ast[total_asteroids-2]->setR(tp);
						ast[total_asteroids-1]->setC(p);
						ast[total_asteroids-1]->setSlope();
						wow=0;
						cast[m]->getC().set(1000000,1000000);
						s_enemy[k]->getS()[i]->getC().set(1000000,1000000);
					}
				}
				/////////////////////////////////
				for(int m=0;m<total_lmallenemies && l_enemy[m]!=NULL && wow;m++)
				{
					if(sqrt(((tx-l_enemy[m]->getC().getX())*(tx-l_enemy[m]->getC().getX()))+((ty-l_enemy[m]->getC().getY())*(ty-l_enemy[m]->getC().getY())))<=l_enemy[m]->getRadius())
					{
						//delete l_enemy[m];
						//l_enemy[m]=NULL;
						wow=0;
						l_enemy[m]->getC().set(1000000,1000000);
						s_enemy[k]->getS()[i]->getC().set(1000000,1000000);
					}
				}
		}

	}
//complex_Bomber shots not checking collision
	//Bomber shots checking collision
		for(int k=0;total_lmallenemies && l_enemy[k]!=NULL ;k++)
		{
			for(int i=0; i<l_enemy[k]->getKnower();i++)
				{	bool wow=1;
					int tx=l_enemy[k]->getS()[i]->getC().getX();
					int ty=l_enemy[k]->getS()[i]->getC().getY();
					for(int m=0;m<total_asteroids &&ast[i]!=NULL && wow;m++)
					{
						if(sqrt(((tx-ast[m]->getC().getX())*(tx-ast[m]->getC().getX()))+((ty-ast[m]->getC().getY())*(ty-ast[m]->getC().getY())))<=ast[m]->getRadius())
						{
							//delete ast[m];
							//ast[m]=NULL;
							wow=0;
							ast[m]->getC().set(1000000,1000000);
							l_enemy[k]->getS()[i]->getC().set(1000000,1000000);
						}
					}
					////
					//Point 1;
					int temcx=user->getP1().getX();
					int temcy=user->getP1().getY();
					int temcr=25;
					if(sqrt(((tx-temcx)*(tx-temcx))+((ty-temcy)*(ty-temcy)))<=temcr)
					{
						user->getP1().setX(-10000);
						user->getP1().setY(-10000);
						user->getP2().setX(-10000);
						user->getP2().setY(-10000);
						user->getP3().setX(-10000);
						user->getP3().setY(-10000);
						l_enemy[k]->getS()[i]->getC().set(1000000,1000000);
					}
					//POint 2
					 temcx=user->getP2().getX();
					 temcy=user->getP2().getY();
					//int temcr=25;
					if(sqrt(((tx-temcx)*(tx-temcx))+((ty-temcy)*(ty-temcy)))<=temcr)
					{
						user->getP1().setX(-10000);
						user->getP1().setY(-10000);
						user->getP2().setX(-10000);
						user->getP2().setY(-10000);
						user->getP3().setX(-10000);
						user->getP3().setY(-10000);
						l_enemy[k]->getS()[i]->getC().set(1000000,1000000);
										}
					//Point 3
					 temcx=user->getP2().getX();
					 temcy=user->getP2().getY();
					//int temcr=25;
					if(sqrt(((tx-temcx)*(tx-temcx))+((ty-temcy)*(ty-temcy)))<=temcr)
					{
						user->getP1().setX(-10000);
						user->getP1().setY(-10000);
						user->getP2().setX(-10000);
						user->getP2().setY(-10000);
						user->getP3().setX(-10000);
						user->getP3().setY(-10000);
						l_enemy[k]->getS()[i]->getC().set(1000000,1000000);
									}
					////
					for(int m=0;m<total_smallenemies && s_enemy[m]!=NULL &&wow;m++)
					{
						if(sqrt(((tx-s_enemy[m]->getC().getX())*(tx-s_enemy[m]->getC().getX()))+((ty-s_enemy[m]->getC().getY())*(ty-s_enemy[m]->getC().getY())))<=s_enemy[m]->getRadius())
						{
							//delete s_enemy[m];
							//s_enemy[m]=NULL;
							wow=0;
							s_enemy[m]->getC().set(5000,1000000);
							l_enemy[k]->getS()[i]->getC().set(1000000,1000000);
							cout<<"lololololol";
							cout<<s_enemy[m]->getC().getX();
							cout<<"lololololol";
							s_enemy[m]->setDestroyChecker(1);

						}
					}
					//
					for(int m=0;m<total_complexasteroids && cast[m]!=NULL && wow;m++)
					{
						if(sqrt(((tx-cast[m]->getC().getX())*(tx-cast[m]->getC().getX()))+((ty-cast[m]->getC().getY())*(ty-cast[m]->getC().getY())))<=cast[m]->getRadius())
						{
							Point p;
							p=cast[m]->getC();
							//delete cast[m];
							//cast[m]=NULL;
							Asteroid **a;
							a=new Asteroid*[total_asteroids+2];
							for(int i=0;i<total_asteroids;i++)
								a[i]=ast[i];
							delete ast;
							total_asteroids+=2;
							ast=new Asteroid*[total_asteroids];
							for(int i=0;i<total_asteroids-2;i++)
								ast[i]=a[i];
							delete a;
							ast[total_asteroids-2]=new Asteroid;
							ast[total_asteroids-2]->setC(p);
							Point tp;
							tp.set(GetRandInRange(0,840),GetRandInRange(0,1020));
							ast[total_asteroids-2]->setR(tp);
							ast[total_asteroids-2]->setSlope();
							ast[total_asteroids-1]=new Asteroid;
							tp.set(GetRandInRange(0,840),GetRandInRange(0,1020));
							ast[total_asteroids-2]->setR(tp);
							ast[total_asteroids-1]->setC(p);
							ast[total_asteroids-1]->setSlope();
							wow=0;
							cast[m]->getC().set(1000000,1000000);
							l_enemy[k]->getS()[i]->getC().set(1000000,1000000);
						}
					}
					//

			}

		}
	//complex_Bomber shots not checking collision

	for(int i=0;i<total_asteroids && ast[i]!=NULL;i++)
	{
		ast[i]->Display();
		ast[i]->Movement(2);
	}
	for(int i=0;i<total_complexasteroids && cast[i]!=NULL;i++)
		{
		cast[i]->Display();
		cast[i]->Movement(2);
		}
	for(int i=0;i<total_smallenemies && s_enemy[i]!=NULL;i++)
	{
		s_enemy[i]->Display();
		s_enemy[i]->Movement(2);
	}
	for(int i=0;i<total_lmallenemies&& l_enemy[i]!=NULL;i++)
	{
		l_enemy[i]->Display();
		l_enemy[i]->Movement(1);
	}

	//seperation here
	//cast->Display();
	//cast->Movement(2,0);
	//DrawAsteroid(b->GetWidth() / 2, b->GetHeight() / 2);
	glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line..

	}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT && user!=NULL /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		user->Rotate(1,1);
	} else if (key
			== GLUT_KEY_RIGHT && user!=NULL/*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		user->Rotate(1,-1);
	} else if (key
			== GLUT_KEY_UP && user!=NULL/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		//int speed =15;
		//for(int i=0;i<speed;i++)
			//user->Movement(1);
		Speed+=0.2;
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		if(Speed<0)
			Speed=0;
		if(Speed>0)
			Speed-=0.2;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;
		if(user!=NULL)
			user->Fire();
	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	glutPostRedisplay();
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	//glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	//glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	//glutPostRedisplay();
}


/*
// * our gateway main function
 * */
int main(int argc, char*argv[]) {
	//experiment stars here
	//Asteroid *ast;

	ast=new Asteroid *[total_asteroids];
	for(int i=0;i<total_asteroids;i++)
		ast[i]=new Asteroid;
	cast=new ComplexAsteroid *[total_complexasteroids];
	for(int i=0;i<total_complexasteroids;i++)
		cast[i]=new ComplexAsteroid;
	s_enemy=new Bomberman*[total_smallenemies];
	for(int i=0;i<total_smallenemies;i++)
		s_enemy[i]=new Bomberman;

	user=new Shooter;
	l_enemy=new Complexbomberman *[total_lmallenemies];
	for(int i=0;i<total_lmallenemies;i++)
		l_enemy[i]=new Complexbomberman;
	int size_array[]={total_asteroids,total_complexasteroids,total_smallenemies,total_lmallenemies};
	//Grand=new Asteroid***[4];//could not do polymorphysim because i made my project on the basics of  double pointer and when i tried to do polymorsim i ject in parent objectlearned we cant store adress of child ob
	//Grand[0]=&ast;
	//Grand[1]=&cast;
	//Grand[2]=&s_enemy;
	//Grand[3]=&l_enemy;




	//experiment ends here
	//cout<<"R-X: "<<cast->getR().getX()<<"   "<<"R-y: "<<cast->getR().getY()<<endl;
	//cout<<"C-X: "<<cast->getC().getX()<<"   "<<"C-y: "<<cast->getC().getY()<<endl;
	b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("CP's Bomber Bomberman"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
