#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <iostream>
#include <math.h>
#include <GL/glut.h>

#define GL_GLEXT_PROTOTYPES
#define PI 3.141592654
#define SHARPNESS_FACTOR 1000 //Defines number of lines in object

double world_y = 0;		 //Used for rotation of world coordinates about y-axis
double wing_z = 0;		 //Angle by which wings rotate about z-axis
double r_amount = 5.0;	 //Angle by which wind_y is incremented/decremented
double scale = 1.0;		 //Used for zooming in and out
double wing_speed = 1.0; //Rotational speed of wings

#include "objects.h"
#include "settings.h"

//Utility Function to reload identity matrix for objects
void resetIdentity()
{
	glLoadIdentity();
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(scale, scale, scale); //Scaling used for zooming in and out
}

//Display Function
void drawWindMill()
{
	GLUquadricObj *quadObj = gluNewQuadric();			//Used for constructing wing axle
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

	resetIdentity();
	glRotatef(world_y + 90, 0.0, 1.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	Shaft(.03, .02, .75);

	resetIdentity();
	glRotatef(world_y, 0.0, 1.0, 0.0);
	glTranslatef(0, -0.03, -.07);
	gluCylinder(quadObj, .03, .03, .05, 100, 100);

	resetIdentity();
	glRotatef(world_y, 0.0, 1.0, 0.0);
	glTranslatef(0, -0.03, -.07);
	Cone(.03, .2, .6);

	//Construct Three Wings
	TriangularWing(0.055, 0.05, 0.4, 0.025, 30);
	TriangularWing(0.055, 0.05, 0.4, 0.025, 150);
	TriangularWing(0.055, 0.05, 0.4, 0.025, 270);

	//Ground below windmill
	resetIdentity();
	glRotatef(-10, 1.0, 0.0, 0.0);
	glRotatef(world_y + 45, 0.0, 1.0, 0.0);
	for (int i = 0; i < 1000; ++i)
	{
		glBegin(GL_LINES);
		glColor3f(100, .1 + .3 * i / 1000.0, 0);
		glVertex3f(-.5 + i / 1000.0, -.75, .5);
		glColor3f(100, .7 + .3 * i / 1000.0, 0);
		glVertex3f(-.5 + i / 1000.0, -.75, -.5);
		glEnd();
	}

	glFlush();
	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);									  // Initialize GLUT and give window access to GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Display mode setup. Request double buffered true color window with Z-buffer
	glutInitWindowSize(1000, 1000);							  // Set Window Size
	glutInitWindowPosition(100, 100);						  // Specify Position of Window on screen
	glutCreateWindow("CG Project WindMill");				  // Create Window and add name
	glEnable(GL_DEPTH_TEST);								  // Enable Z-buffer depth test (for solidity of objects)

	// Callback Functions of Gult
	glutDisplayFunc(drawWindMill);
	glutIdleFunc(rotate);
	glutSpecialFunc(specialKeys);
	glutMouseFunc(mouseWheel);
	glutMainLoop(); // Used to recall the gult functions which are defined
}

// g++ windmill.cpp -lglut -lGL -lGLU -o windmill
// .windmill