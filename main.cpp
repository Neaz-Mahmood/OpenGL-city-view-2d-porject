#include <windows.h>
#include <GL/glut.h>
#include<math.h>>
#include<iostream>
# define PI           3.14159265358979323846

GLfloat position_rain = 0.0f;
GLfloat speed_rain = 0.05f;
GLfloat position = 0.0f;// cloud1
GLfloat speed = 0.02f;//cloud1
GLfloat position_plane = 0.0f;// cloud1
GLfloat speed_plane = 0.05f;//cloud1
//GLfloat position_cloud2 = 0.0f;// cloud1
//GLfloat speed_cloud2 = 0.02f;//cloud1
//for boat 1(positive axis)
GLfloat speed_Boat2 = 0.05f;
GLfloat position_Boat2 = 0.0f;
//for boat 2(negative axis)
GLfloat speed_Boat1 = 0.04f;
GLfloat position_Boat1 = 0.0f;

GLfloat position_rail = 0.0f;
GLfloat speed_rail = 0.05f;

GLfloat position_bus = 0.0f;
GLfloat speed_bus = 0.03f;

void cloud_moving1(int value) {

    if(position <-1.5)
        position = 1.6f;

    position -= speed;// Cloud moving 1..........

	glutPostRedisplay();


	glutTimerFunc(100,cloud_moving1 , 0);
}


void plane_moving(int value) {

    if(position_plane >1.7)
        position_plane = -1.0f;

    position_plane += speed_plane;// plane moving.........

	glutPostRedisplay();


	glutTimerFunc(100,plane_moving , 0);
}


//rail $ road
void update(int value)
{

    if(position_rail < -1.5)
        position_rail = 1.0f;

    position_rail -= speed_rail;

	glutPostRedisplay();

    glutTimerFunc(100, update, 0);
}

void BusMove(int value)
{

    if(position_bus < -1.5)
        position_bus = 1.0f;

    position_bus -= speed_bus;

	glutPostRedisplay();

    glutTimerFunc(100, BusMove, 0);
}

void Rain(int value) {

    if(position_rain <0)
        position_rain = 0.1f;
    position_rain -= speed_rain;
	glutPostRedisplay();
	glutTimerFunc(100, Rain, 0);
}

/*
void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
case 's': // slowly sky moving.....
    speed = 0.025f;
    break;
 case 'm': // medium sky moving......
    speed=0.05;
    break;
case 'q': //quick quick sky moving......
    speed = 0.1f;
    break;
glutPostRedisplay();
	}
}
*/
void init2() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Boat1Moving(int value) {

    if(position_Boat1 <-1.7)
        position_Boat1 = 1.0f;
    position_Boat1 -= speed_Boat1;
	glutPostRedisplay();
	glutTimerFunc(100, Boat1Moving, 0);
}

void Boat2Moving(int value) {

    if(position_Boat2 >1.7)
        position_Boat2 = -1.0f;
    position_Boat2 += speed_Boat2;
	glutPostRedisplay();
	glutTimerFunc(100, Boat2Moving, 0);
}
//Day View
void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_QUADS);
glColor3ub(26,255,255);
glVertex2f(-1,1);
glVertex2f(-1,-.1); // sky ......
glVertex2f(1,-.1);
glVertex2f(1,1);
glEnd();

	int k;

    float a = .7f; float b = .85; float r  = .07f;

    int Amount = 30;

     GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN); // sun draw......
    glColor3ub(255,255,0);

    glVertex2f(a,b);

    for(k = 0; k <=Amount;k++) {

    glVertex2f(

            a + (r * cos(k *  twicePi / Amount)),

            b + (r * sin(k * twicePi / Amount))

             );

    }

     glEnd();



// plan draw start.....


glPushMatrix();
glTranslatef(position_plane,0.0f, 0.0f);
glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2f(-.7,.95);
glVertex2f(-.75,.85);  // plane draw......
glVertex2f(-.3,.85);
glVertex2f(-.3,.95);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,51,0);
glVertex2f(-.75,.85);// plane draw......
glVertex2f(-.7,.95);
glVertex2f(-.75,.98);
glVertex2f(-.8,.98);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,51,0);
glVertex2f(-.55,.88);
glVertex2f(-.6,.81);  // plane wing draw.....
glVertex2f(-.55,.81);
glVertex2f(-.5,.88);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,51,0);
glVertex2f(-.55,.95);
glVertex2f(-.5,.95); // plane wing  draw......
glVertex2f(-.53,.98);
glVertex2f(-.58,.98);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2f(-.3,.95);
glVertex2f(-.3,.87); // plane draw....
glVertex2f(-.23,.87);
glVertex2f(-.27,.92);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(255,255,255);
glVertex2f(-.23,.87);
glVertex2f(-.3,.87); // plane draw.......
glVertex2f(-.3,.85);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(-.33,.93);
glVertex2f(-.33,.9); // plane first window.....
glVertex2f(-.3,.9);
glVertex2f(-.3,.93);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(-.38,.93);
glVertex2f(-.38,.87);
glVertex2f(-.35,.87); // plane door....
glVertex2f(-.35,.93);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(-.43,.93);
glVertex2f(-.43,.9);  // plane 2ND window.....
glVertex2f(-.4,.9);
glVertex2f(-.4,.93);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(-.49,.93);
glVertex2f(-.49,.9);   // plane 3RD window.....
glVertex2f(-.46,.9);
glVertex2f(-.46,.93);
glEnd();


glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(-.55,.93);
glVertex2f(-.55,.9);
glVertex2f(-.52,.9);  // plane 4TH window.....
glVertex2f(-.52,.93);
glEnd();


glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(-.61,.93);
glVertex2f(-.61,.9); // plane 5TH  window.....
glVertex2f(-.58,.9);
glVertex2f(-.58,.93);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(-.67,.93);
glVertex2f(-.67,.9);
glVertex2f(-.64,.9);// plane 6Th window....
glVertex2f(-.64,.93);
glEnd();

glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(-.7,.95);
glVertex2f(-.3,.95);
glEnd();

glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(-.75,.85);
glVertex2f(-.57,.85);
glEnd();

glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(-.52,.85);
glVertex2f(-.3,.85);
glEnd();

glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(-.23,.87);
glVertex2f(-.3,.85);
glEnd();

glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(-.23,.87);
glVertex2f(-.3,.85);
glEnd();

glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(-.3,.95);
glVertex2f(-.27,.92);
glEnd();

glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(-.27,.92);
glVertex2f(-.23,.87);
glEnd();


glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(-.75,.85);
glVertex2f(-.8,.98);
glEnd();

glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(-.8,.98);
glVertex2f(-.75,.98);
glEnd();

glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(-.75,.98);
glVertex2f(-.7,.95);
glEnd();
glPopMatrix();
glLoadIdentity();

// plane draw end.......................



//Cloud 1 draw start.................

    glPushMatrix();
glTranslatef(position,0.0f,0.0f);
    int t2;

    float mu2 = .5; float mn2 =.8; float K8= .05;

    int musa3 = 20;

     GLfloat kepa7 = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);

    glVertex2f(mu2,mn2);

    for(t2 = 0; t2<=musa3;t2++) {

    glVertex2f(

            mu2 + (K8 * cos(t2* kepa7 / musa3 )),

            mn2 + (K8* sin(t2* kepa7 / musa3 ))

             );

    }
glEnd();

int t1;

    float mu3 = .45; float mn3 =.8; float KE= .07;

    int musa007  = 20;

     GLfloat kepa008  = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);

    glVertex2f(mu3,mn3);

    for(t1 = 0; t1<=musa007;t1++) {

    glVertex2f(

            mu3 + (KE * cos(t1 * kepa008 / musa007 )),

            mn3 + (KE* sin(t1* kepa008 / musa007 ))

             );

    }

     glEnd();


    int c2;

    float mu0 = .4; float mn0=.8; float KE0= .05;

    int musa009  = 20;

     GLfloat kepa009 = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);

    glVertex2f(mu0,mn0);

    for(c2 = 0; c2<=musa009;c2++) {

    glVertex2f(

            mu0 + (KE0 * cos(c2 * kepa009/ musa009 )),

            mn0 + (KE0* sin(c2* kepa009 / musa009 ))

             );

    }

     glEnd();
     glPopMatrix();
     glLoadIdentity();
     //cloud 1 draw end..................


   //cloud 2 draw...........start
   glPushMatrix();
glTranslatef(position,0.0f, 0.0f);
   int A1;

    float x1 = -.5; float y1 =.8; float r1= .05;

    int Amount1= 30;

     GLfloat piee1 = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);

    glVertex2f(x1,y1);

     for(A1 = 0; A1<=Amount1;A1++) {

    glVertex2f(

            x1 + (r1 * cos(A1* piee1 / Amount1)),

            y1 + (r1* sin(A1* piee1 / Amount1 ))

             );

    }
glEnd();





int t4;

    float x2 = -.45; float y2 =.8; float r2= .07;

    int amount2  = 30;

     GLfloat piee3  = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);

    glVertex2f(x2,y2);

    for(t4 = 0; t4<=amount2;t4++) {

    glVertex2f(

            x2 + (r2 * cos(t4 * piee3 / amount2 )),

            y2 + (r2* sin(t4* piee3 / amount2 ))

             );

    }

     glEnd();


    int t5;

    float x3 = -.4; float y3=.8; float r3= .05;

    int amount3 = 30;

     GLfloat piee4 = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);

    glVertex2f(x3,y3);

    for(t5 = 0; t5<=amount3;t5++) {

    glVertex2f(

            x3+ (r3 * cos(t5 * piee4 / amount3 )),

            y3+ (r3* sin(t5* piee4 / amount3 ))

             );

    }

     glEnd();
glPopMatrix();
//cloud 2 draw end.........


    //Building part
    int i007;
    GLfloat x=-.3f; GLfloat y=.45f; GLfloat radius =.1f;
    int triangleAmount = 20;
    GLfloat twicePi1 = 2.0f * PI;
glLoadIdentity();
glBegin(GL_QUADS);
glColor3ub(102, 102, 153);//Most left Building
glVertex2f(-.72,-.1);//1st Structure
glVertex2f(-.72,.3);
glVertex2f(-.95,.3);
glVertex2f(-.95,-.1);
glEnd();

glBegin(GL_QUADS);//Most left Building
glColor3ub(255, 77, 77);//2nd Structure
glVertex2f(-.66,.3);
glVertex2f(-.66,.33);
glVertex2f(-1,.33);
glVertex2f(-1,.3);
glEnd();

glBegin(GL_QUADS);//Most left Building
glColor3ub(102, 102, 153);//3rd Structure
glVertex2f(-.69,.33);
glVertex2f(-.69,.4);
glVertex2f(-.98,.4);
glVertex2f(-.98,.33);
glEnd();
glBegin(GL_QUADS);//Most left Building
glColor3ub(102, 102, 153);//4th Structure
glVertex2f(-.77,.4);
glVertex2f(-.77,.43);
glVertex2f(-.9,.43);
glVertex2f(-.9,.4);
glEnd();
glBegin(GL_QUADS);//Most left Building
glColor3ub(102, 102, 153);//5th Structure
glVertex2f(-.73,.4);
glVertex2f(-.73,.43);
glVertex2f(-.94,.43);
glVertex2f(-.94,.4);
glEnd();

glBegin(GL_QUADS);//Most left Building
glColor3ub(128, 191, 255);//6th Structure
glVertex2f(-.77,.43);
glVertex2f(-.77,.53);
glVertex2f(-.9,.53);
glVertex2f(-.9,.43);
glEnd();
glBegin(GL_QUADS);//Most left Building
glColor3ub(51, 0, 26);//7th Structure
glVertex2f(-.81,.53);
glVertex2f(-.81,.65);
glVertex2f(-.86,.65);
glVertex2f(-.86,.53);
glEnd();
glBegin(GL_QUADS);//Most left Building
glColor3ub(0, 0, 51);//main gate
glVertex2f(-.76,-.1);
glVertex2f(-.76,0.0);
glVertex2f(-.91,0.0);
glVertex2f(-.91,-.1);
glEnd();
glBegin(GL_QUADS);//Most left Building
glColor3ub(0, 0, 51);// stair view
glVertex2f(-.82,.04);
glVertex2f(-.82,.28);
glVertex2f(-.85,.28);
glVertex2f(-.85,.04);
glEnd();
glBegin(GL_QUADS);//Most left Building
glColor3ub(0,0,0);// window view 01 (Right)
glVertex2f(-.75,.05);
glVertex2f(-.75,.1);
glVertex2f(-.8,.1);
glVertex2f(-.8,.05);
glEnd();
glTranslatef(0.0f,.07f,0.0f);
glBegin(GL_QUADS);//Most left Building
glColor3ub(0,0,0);// window view 02 (Right)
glVertex2f(-.75,.05);
glVertex2f(-.75,.1);
glVertex2f(-.8,.1);
glVertex2f(-.8,.05);
glEnd();
glTranslatef(0.0f,.075f,0.0f);
glBegin(GL_QUADS);//Most left Building
glColor3ub(0,0,0);// window view 03 (Right)
glVertex2f(-.75,.05);
glVertex2f(-.75,.1);
glVertex2f(-.8,.1);
glVertex2f(-.8,.05);
glEnd();

glLoadIdentity();
glBegin(GL_QUADS);//Most left Building
glColor3ub(0,0,0);// window view 01 (left)
glVertex2f(-.88,.05);
glVertex2f(-.88,.1);
glVertex2f(-.93,.1);
glVertex2f(-.93,.05);
glEnd();
glTranslatef(0.0f,.07f,0.0f);
glBegin(GL_QUADS);//Most left Building
glColor3ub(0,0,0);// window view 02 (left)
glVertex2f(-.88,.05);
glVertex2f(-.88,.1);
glVertex2f(-.93,.1);
glVertex2f(-.93,.05);
glEnd();
glTranslatef(0.0f,.075f,0.0f);
glBegin(GL_QUADS);//Most left Building
glColor3ub(0,0,0);// window view 03 (left)
glVertex2f(-.88,.05);
glVertex2f(-.88,.1);
glVertex2f(-.93,.1);
glVertex2f(-.93,.05);
glEnd();
glLoadIdentity();
glBegin(GL_QUADS);//Most left Building
glColor3ub(0,0,0);// window view 10
glVertex2f(-.92,.35);
glVertex2f(-.92,.38);
glVertex2f(-.95,.38);
glVertex2f(-.95,.35);
glEnd();
glTranslatef(0.05f,0.0f,0.0f);
glBegin(GL_QUADS);//Most left Building
glColor3ub(0,0,0);// window view 20
glVertex2f(-.92,.35);
glVertex2f(-.92,.38);
glVertex2f(-.95,.38);
glVertex2f(-.95,.35);
glEnd();
glTranslatef(0.05f,0.0f,0.0f);
glBegin(GL_QUADS);//Most left Building
glColor3ub(0,0,0);// window view 30
glVertex2f(-.92,.35);
glVertex2f(-.92,.38);
glVertex2f(-.95,.38);
glVertex2f(-.95,.35);
glEnd();
glTranslatef(0.05f,0.0f,0.0f);
glBegin(GL_QUADS);//Most left Building
glColor3ub(0,0,0);// window view 40
glVertex2f(-.92,.35);
glVertex2f(-.92,.38);
glVertex2f(-.95,.38);
glVertex2f(-.95,.35);
glEnd();
glTranslatef(0.05f,0.0f,0.0f);
glBegin(GL_QUADS);//Most left Building
glColor3ub(0,0,0);// window view 50
glVertex2f(-.92,.35);
glVertex2f(-.92,.38);
glVertex2f(-.95,.38);
glVertex2f(-.95,.35);
glEnd();
glLoadIdentity();
///2nd Building Start here....
glBegin(GL_QUADS);//2nd left Building
glColor3ub(153, 153, 102);// main architecture
glVertex2f(-.1,-.1);
glVertex2f(-.1,.4);
glVertex2f(-.5,.4);
glVertex2f(-.5,-.1);
glEnd();
glBegin(GL_QUADS);//2nd left Building
glColor3ub(153, 153, 102);// main architecture right horn
glVertex2f(-.1,.4);
glVertex2f(-.1,.47);
glVertex2f(-.15,.47);
glVertex2f(-.15,.4);
glBegin(GL_QUADS);//2nd left Building
glColor3ub(153, 153, 102);// main architecture left horn
glVertex2f(-.45,.4);
glVertex2f(-.45,.47);
glVertex2f(-.5,.47);
glVertex2f(-.5,.4);
glEnd();
glBegin(GL_QUADS);//2nd left Building
glColor3ub(153, 153, 102);// Between left and Right Horn
glVertex2f(-.15,.4);
glVertex2f(-.15,.44);
glVertex2f(-.45,.44);
glVertex2f(-.45,.4);
glEnd();

glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of 2nd Building
		for(i007 = 0; i007 <= triangleAmount;i007++) {
			glVertex2f(
		            x + (radius * cos(i007 *  twicePi1 / triangleAmount)),
			    y + (radius * sin(i007 * twicePi1 / triangleAmount))
			);
		}
	glEnd();
glBegin(GL_QUADS);////2nd left Building
glColor3ub(130,22,9);//Medical sign
glVertex2f(-.26,.43);
glVertex2f(-.26,.45);
glVertex2f(-.34,.45);
glVertex2f(-.34,.43);
glEnd();

glBegin(GL_QUADS);////2nd left Building
glColor3ub(130,22,9);//Medical sign
glVertex2f(-.29,.4);
glVertex2f(-.29,.48);
glVertex2f(-.31,.48);
glVertex2f(-.31,.4);
glEnd();

glBegin(GL_QUADS);////2nd left Building
glColor3ub(38, 38, 38);// 1st stair
glVertex2f(-.27,.25);
glVertex2f(-.27,.38);
glVertex2f(-.33,.38);
glVertex2f(-.33,.25);
glEnd();
glTranslatef(0.0f,-.15f,0.0);

glBegin(GL_QUADS);////2nd left Building
glColor3ub(38, 38, 38);//2nd stair
glVertex2f(-.27,.25);
glVertex2f(-.27,.38);
glVertex2f(-.33,.38);
glVertex2f(-.33,.25);
glEnd();
glTranslatef(0.0f,-.2f,0.0);

glBegin(GL_QUADS);////2nd left Building
glColor3ub(78,139,140);//3rd stair
glVertex2f(-.27,.25);
glVertex2f(-.27,.38);
glVertex2f(-.33,.38);
glVertex2f(-.33,.25);
glEnd();
glLoadIdentity();
glBegin(GL_QUADS);////2nd left Building
glColor3ub(107,148,210);//shading  right
glVertex2f(-.12,-.07);
glVertex2f(-.12,.35);
glVertex2f(-.26,.35);
glVertex2f(-.26,-.07);
glEnd();
glTranslatef(-.22,0.0,0.0);
glBegin(GL_QUADS);////2nd left Building
glColor3ub(107,148,210);//shading  left
glVertex2f(-.12,-.07);
glVertex2f(-.12,.35);
glVertex2f(-.26,.35);
glVertex2f(-.26,-.07);
glEnd();
glLoadIdentity();






glBegin(GL_QUADS);////2nd left Building
glColor3ub(0,0,0);//1st Window (right)
glVertex2f(-.16,.23);
glVertex2f(-.16,.3);
glVertex2f(-.24,.3);
glVertex2f(-.24,.23);
glEnd();
glTranslatef(0.0,-.09,0.0);
glBegin(GL_QUADS);////2nd left Building
glColor3ub(0,0,0);//2nd Window (right)
glVertex2f(-.16,.23);
glVertex2f(-.16,.3);
glVertex2f(-.24,.3);
glVertex2f(-.24,.23);
glEnd();
glTranslatef(0.0,-.09,0.0);
glBegin(GL_QUADS);////2nd left Building
glColor3ub(0,0,0);//3rd Window (right)
glVertex2f(-.16,.23);
glVertex2f(-.16,.3);
glVertex2f(-.24,.3);
glVertex2f(-.24,.23);
glEnd();
glTranslatef(0.0,-.09,0.0);
glBegin(GL_QUADS);////2nd left Building
glColor3ub(0,0,0);//4th Window (right)
glVertex2f(-.16,.23);
glVertex2f(-.16,.3);
glVertex2f(-.24,.3);
glVertex2f(-.24,.23);
glEnd();
glTranslatef(-.2,0.0,0.0);
glBegin(GL_QUADS);////2nd left Building
glColor3ub(0,0,0);//1st Window (Left)
glVertex2f(-.16,.23);
glVertex2f(-.16,.3);
glVertex2f(-.24,.3);
glVertex2f(-.24,.23);
glEnd();
glTranslatef(0.0,.09,0.0);
glBegin(GL_QUADS);////2nd left Building
glColor3ub(0,0,0);//2nd Window (Left)
glVertex2f(-.16,.23);
glVertex2f(-.16,.3);
glVertex2f(-.24,.3);
glVertex2f(-.24,.23);
glEnd();
glTranslatef(0.0,.09,0.0);
glBegin(GL_QUADS);////2nd left Building
glColor3ub(0,0,0);//3rd Window (Left)
glVertex2f(-.16,.23);
glVertex2f(-.16,.3);
glVertex2f(-.24,.3);
glVertex2f(-.24,.23);
glEnd();
glTranslatef(0.0,.09,0.0);
glBegin(GL_QUADS);////2nd left Building
glColor3ub(0,0,0);//4th Window (Left)
glVertex2f(-.16,.23);
glVertex2f(-.16,.3);
glVertex2f(-.24,.3);
glVertex2f(-.24,.23);
glEnd();
glLoadIdentity();

///3rd Building Start from here
glBegin(GL_QUADS);//3rd Building
glColor3ub(40,105,73);//Basement01
glVertex2f(.5,-.1);
glVertex2f(.5,.2);
glVertex2f(.05,.2);
glVertex2f(.05,-.1);
glEnd();
glBegin(GL_QUADS);//3rd Building
glColor3ub(36,106,72);//Basement 02
glVertex2f(.45,.2);
glVertex2f(.45,.6);
glVertex2f(.25,.6);
glVertex2f(.25,.2);
glEnd();
glBegin(GL_QUADS);//3rd Building
glColor3ub(66,92,239);//Basement 03
glVertex2f(.25,.2);
glVertex2f(.25,.65);
glVertex2f(.2,.65);
glVertex2f(.2,.2);
glEnd();
glBegin(GL_QUADS);//3rd Building
glColor3ub(116,143,117);//Basement 04
glVertex2f(.2,.2);
glVertex2f(.2,.55);
glVertex2f(.1,.55);
glVertex2f(.1,.2);
glEnd();

glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);//1st window[1,1]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(.05,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);//2nd window[1,2]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(.05,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[1,3]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(.05,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[1,4]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(.0,-0.07,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[2,4]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(-.05,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[2,3]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(-.05,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[2,2]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(-.05,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[2,1]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(.0,-0.07,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[3,1]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(.05,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[3,2]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(.05,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[3,3]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(.05,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[3,4]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(.0,-0.07,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[4,4]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(-.05,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[4,3]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(-.05,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[4,2]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(-.05,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[4,1]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(.0,-0.07,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[5,1]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(.05,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[5,2]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(.05,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[5,3]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glTranslatef(.05,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window[5,2]
glVertex2f(.3,.51);
glVertex2f(.3,.56);
glVertex2f(.26,.56);
glVertex2f(.26,.51);
glEnd();
glLoadIdentity();
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window basement 01
glVertex2f(.14,.1);
glVertex2f(.14,.16);
glVertex2f(.08,.16);
glVertex2f(.08,.1);
glEnd();
glTranslatef(.07,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window basement 02
glVertex2f(.14,.1);
glVertex2f(.14,.16);
glVertex2f(.08,.16);
glVertex2f(.08,.1);
glEnd();
glTranslatef(.2,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window basement 03
glVertex2f(.14,.1);
glVertex2f(.14,.16);
glVertex2f(.08,.16);
glVertex2f(.08,.1);
glEnd();
glTranslatef(.07,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window basement 04
glVertex2f(.14,.1);
glVertex2f(.14,.16);
glVertex2f(.08,.16);
glVertex2f(.08,.1);
glEnd();
glTranslatef(.0,-0.07,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window basement 05
glVertex2f(.14,.1);
glVertex2f(.14,.16);
glVertex2f(.08,.16);
glVertex2f(.08,.1);
glEnd();
glTranslatef(-.07,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window basement 06
glVertex2f(.14,.1);
glVertex2f(.14,.16);
glVertex2f(.08,.16);
glVertex2f(.08,.1);
glEnd();
glTranslatef(-.2,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window basement 07
glVertex2f(.14,.1);
glVertex2f(.14,.16);
glVertex2f(.08,.16);
glVertex2f(.08,.1);
glEnd();
glTranslatef(-.07,0.0,0.0);
glBegin(GL_QUADS);//3rd Building
glColor3ub(0,0,0);// window basement 08
glVertex2f(.14,.1);
glVertex2f(.14,.16);
glVertex2f(.08,.16);
glVertex2f(.08,.1);
glEnd();

glLoadIdentity();
glBegin(GL_QUADS);//3rd Building
glColor3ub(203,156,102);//  basement Exit
glVertex2f(.37,-.1);
glVertex2f(.37,0.0);
glVertex2f(.2,0.0);
glVertex2f(.2,-.1);
glEnd();
glLoadIdentity();
///4th Building  start from here
glBegin(GL_QUADS);//4th Building
glColor3ub(202,135,20);//  basement 01
glVertex2f(.95,-.1);
glVertex2f(.95,.3);
glVertex2f(.6,.3);
glVertex2f(.6,-.1);
glEnd();
glBegin(GL_QUADS);//4th Building
glColor3ub(103,64,59);//  basement 02
glVertex2f(.99,.3);
glVertex2f(.99,.32);
glVertex2f(.55,.32);
glVertex2f(.55,.3);
glEnd();
glBegin(GL_QUADS);//4th Building
glColor3ub(202,135,20);//  basement 03
glVertex2f(.9,.32);
glVertex2f(.9,.45);
glVertex2f(.65,.45);
glVertex2f(.65,.32);
glEnd();
glBegin(GL_QUADS);//4th Building
glColor3ub(103,64,59);//  basement 04
glVertex2f(.93,.45);
glVertex2f(.93,.46);
glVertex2f(.62,.46);
glVertex2f(.62,.45);
glEnd();
glBegin(GL_TRIANGLES);//4th Building
glColor3ub(103,64,59);//  basement 04
glVertex2f(.63,.46);
glVertex2f(.77,.6);
glVertex2f(.93,.46);
glEnd();
glBegin(GL_QUADS);//4th Building
glColor3ub(0,0,0);//2nd Lower basement
glVertex2f(.9,-.1);
glVertex2f(.9,.1);
glVertex2f(.7,.1);
glVertex2f(.7,-.1);
glEnd();
glBegin(GL_QUADS);//4th Building
glColor3ub(83,116,121);// Lower basement
glVertex2f(.73,-.1);
glVertex2f(.73,0.0);
glVertex2f(.87,0.0);
glVertex2f(.87,-.1);
glEnd();
glBegin(GL_TRIANGLES);//4th Building
glColor3ub(103,64,59);//  basement rectangle
glVertex2f(.8,.2);
glVertex2f(.67,.1);
glVertex2f(.93,.1);
glEnd();
glBegin(GL_QUADS);//4th Building
glColor3ub(0,0,0);// window 01
glVertex2f(.65,.12);
glVertex2f(.65,.18);
glVertex2f(.61,.18);
glVertex2f(.61,.12);
glEnd();
glTranslatef(0.0,.07,0.0);
glBegin(GL_QUADS);//4th Building
glColor3ub(0,0,0);// window 02
glVertex2f(.65,.12);
glVertex2f(.65,.18);
glVertex2f(.61,.18);
glVertex2f(.61,.12);
glEnd();
glTranslatef(0.29,.0,0.0);
glBegin(GL_QUADS);//4th Building
glColor3ub(0,0,0);// window 03
glVertex2f(.65,.12);
glVertex2f(.65,.18);
glVertex2f(.61,.18);
glVertex2f(.61,.12);
glEnd();
glTranslatef(0.0,-0.07,0.0);
glBegin(GL_QUADS);//4th Building
glColor3ub(0,0,0);// window 04
glVertex2f(.65,.12);
glVertex2f(.65,.18);
glVertex2f(.61,.18);
glVertex2f(.61,.12);
glEnd();
glLoadIdentity();
glBegin(GL_QUADS);//4th Building
glColor3ub(0,0,0);// window 05
glVertex2f(.85,.32);
glVertex2f(.85,.4);
glVertex2f(.7,.4);
glVertex2f(.7,.32);
glEnd();
///Tree start from here
glBegin(GL_QUADS);// First Tree structure
glColor3ub(103,64,59);
glVertex2f(.55,-.1);
glVertex2f(.55,.03);
glVertex2f(.53,.03);
glVertex2f(.53,-.1);
glEnd();
 x=.54f;  y=.01f;  radius =.07f;
     triangleAmount = 50;
    //GLfloat twicePi = 2.0f * PI;
    int j007,k007,l007,m007,n007,o007;

glBegin(GL_TRIANGLE_FAN);//First tree first circle
glColor3ub(12,62,13);
		glVertex2f(x, y);
		for(j007 = 0; j007 <= triangleAmount;j007++) {
			glVertex2f(
		            x + (radius * cos(j007 *  twicePi1 / triangleAmount)),
			    y + (radius * sin(j007 * twicePi1 / triangleAmount))
			);
		}
	glEnd();
	x=.54f;  y=.07f;  radius =.04f;
	glBegin(GL_TRIANGLE_FAN);//First tree second circle
glColor3ub(12,62,13);
		glVertex2f(x, y);
		for(k007 = 0; k007 <= triangleAmount;k007++) {
			glVertex2f(
		            x + (radius * cos(k007 *  twicePi1 / triangleAmount)),
			    y + (radius * sin(k007 * twicePi1 / triangleAmount))
			);
		}
	glEnd();
	glLoadIdentity();
	/// Second Tree start here
    glBegin(GL_QUADS);// Second Tree structure
glColor3ub(103,64,59);
glVertex2f(-.04,-.1);
glVertex2f(-.04,.1);
glVertex2f(-.06,.1);
glVertex2f(-.06,-.1);
glEnd();
x=-.05f;  y=.1f;  radius =.07f;
glBegin(GL_TRIANGLE_FAN);//Second tree first circle
glColor3ub(12,62,13);
		glVertex2f(x, y);
		for(l007 = 0; l007 <= triangleAmount;l007++) {
			glVertex2f(
		            x + (radius * cos(l007*  twicePi1 / triangleAmount)),
			    y + (radius * sin(l007 * twicePi1 / triangleAmount))
			);
		}
	glEnd();
	x=-.05f;  y=.17f;  radius =.04f;
	glBegin(GL_TRIANGLE_FAN);//Second tree second circle
glColor3ub(12,62,13);
		glVertex2f(x, y);
		for(m007 = 0; m007 <= triangleAmount;m007++) {
			glVertex2f(
		            x + (radius * cos(m007 *  twicePi1 / triangleAmount)),
			    y + (radius * sin(m007 * twicePi1 / triangleAmount))
			);
		}
	glEnd();
glLoadIdentity();
///3rd Tree Start from here
glBegin(GL_QUADS);// third Tree structure
glColor3ub(103,64,59);
glVertex2f(.02,-.1);
glVertex2f(.02,0.0);
glVertex2f(0.0,0.0);
glVertex2f(0.0,-.1);
glEnd();
x=.01f;  y=-.03f;  radius =.04f;
glBegin(GL_TRIANGLE_FAN);//third tree first circle
glColor3ub(79,167,80);
		glVertex2f(x, y);
		for(n007 = 0; n007 <= triangleAmount;n007++) {
			glVertex2f(
		            x + (radius * cos(n007 *  twicePi1 / triangleAmount)),
			    y + (radius * sin(n007 * twicePi1 / triangleAmount))
			);
		}
	glEnd();
	x=.01f;  y=.0f;  radius =.02f;
	glBegin(GL_TRIANGLE_FAN);//third tree second circle
glColor3ub(79,167,80);
		glVertex2f(x, y);
		for(o007 = 0; o007 <= triangleAmount;o007++) {
			glVertex2f(
		            x + (radius * cos(o007 *  twicePi1 / triangleAmount)),
			    y + (radius * sin(o007 * twicePi1 / triangleAmount))
			);
		}
	glEnd();
	glLoadIdentity();
///Small Building start here
glBegin(GL_QUADS);//Small Building
glColor3ub(202,135,20);// main basement 01
glVertex2f(-.52,-.1);
glVertex2f(-.52,.1);
glVertex2f(-.7,.1);
glVertex2f(-.7,-.1);
glEnd();
glBegin(GL_QUADS);//Small Building
glColor3ub(0.0,0.0,0.0);//basement 02
glVertex2f(-.5,.1);
glVertex2f(-.5,.11);
glVertex2f(-.72,.11);
glVertex2f(-.72,.1);
glEnd();
glBegin(GL_TRIANGLES);//Small Building
glColor3ub(106,60,63);//basement 03
glVertex2f(-.51,.11);
glVertex2f(-.6,.2);
glVertex2f(-.71,.11);
glEnd();

glBegin(GL_QUADS);//Small Building
glColor3ub(83,116,121);//Entry and Exit
glVertex2f(-.54,-.1);
glVertex2f(-.54,0.0);
glVertex2f(-.68,0.0);
glVertex2f(-.68,-.1);
glEnd();

//End building part

glLoadIdentity();



//Road & Rail
    // #Main Road making start from here#
glBegin(GL_QUADS);

glColor3ub(128, 128, 128);

glVertex2f(-1.0f,-0.5f);//1st
glVertex2f(1.0f,-0.5f);//2nd
glVertex2f(1.0f,-0.1f);//3rd
glVertex2f(-1.0f,-0.1f);//4th

glEnd();

// #Main Road "strip" making start from here#
glBegin(GL_LINES);

glColor3ub(0, 51, 0);

glVertex2f(-1.0f,-0.3f);  //1st
glVertex2f(1.0f,-0.3f);   //2nd

glEnd();
// #Main Road making end here#

glBegin(GL_LINES);   //2nd

glColor3ub(255, 255, 255);

glVertex2f(-0.7f,-0.4f);  //1st
glVertex2f(-0.6f,-0.4f);   //2nd

 glEnd();

 glBegin(GL_LINES);   //3rd

glColor3ub(255, 255, 255);

glVertex2f(-0.5f,-0.4f);  //1st
glVertex2f(-0.4f,-0.4f);   //2nd

 glEnd();
//


//
glBegin(GL_LINES);   //4th

glColor3ub(255, 255, 255);

glVertex2f(-0.3f,-0.4f);  //1st
glVertex2f(-0.2f,-0.4f);   //2nd

glEnd();
//


//
glBegin(GL_LINES);   //5th

glColor3ub(255, 255, 255);

glVertex2f(-0.1f,-0.4f);  //1st
glVertex2f(0.0f,-0.4f);   //2nd

glEnd();
//


//
glBegin(GL_LINES);   //6th

glColor3ub(255, 255, 255);

glVertex2f(0.1f,-0.4f);  //1st
glVertex2f(0.2f,-0.4f);   //2nd

glEnd();
//


//
glBegin(GL_LINES);   //7th

glColor3ub(255, 255, 255);

glVertex2f(0.3f,-0.4f);  //1st
glVertex2f(0.4f,-0.4f);   //2nd

glEnd();
//

//
glBegin(GL_LINES);   //8th

glColor3ub(255, 255, 255);

glVertex2f(0.5f,-0.4f);  //1st
glVertex2f(0.6f,-0.4f);   //2nd

glEnd();
//

//
glBegin(GL_LINES);   //9th

glColor3ub(255, 255, 255);

glVertex2f(0.7f,-0.4f);  //1st
glVertex2f(0.9f,-0.4f);   //2nd

glEnd();
//# Sub-Strips are end here#

//#railway stand start start from here#
glBegin(GL_LINES);   //horizontal stand-1

glColor3ub(255, 255, 255);

glVertex2f(-0.8f,-0.2f);  //1st
glVertex2f(-0.8f,-0.3f);   //2nd

glEnd();

glBegin(GL_LINES);   //horizontal stand-2

glColor3ub(255, 255, 255);

glVertex2f(-0.5f,-0.2f);  //1st
glVertex2f(-0.5f,-0.3f);   //2nd

glEnd();

glBegin(GL_LINES);   //horizontal stand-3

glColor3ub(255, 255, 255);

glVertex2f(-0.2f,-0.2f);  //1st
glVertex2f(-0.2f,-0.3f);   //2nd

glEnd();

glBegin(GL_LINES);   //horizontal stand-4

glColor3ub(255, 255, 255);

glVertex2f(0.1f,-0.2f);  //1st
glVertex2f(0.1f,-0.3f);   //2nd

glEnd();


glBegin(GL_LINES);   //horizontal stand-5

glColor3ub(255, 255, 255);

glVertex2f(0.4f,-0.2f);  //1st
glVertex2f(0.4f,-0.3f);   //2nd

glEnd();


glBegin(GL_LINES);   //horizontal stand-6

glColor3ub(255, 255, 255);

glVertex2f(0.7f,-0.2f);  //1st
glVertex2f(0.7f,-0.3f);   //2nd

glEnd();
//#Railway stand end here#

//Railway making start from here
//glLineWidth(30);
glBegin(GL_QUADS);

glColor3ub(51, 204, 255);

glVertex2f(-1.0f,-0.15f);  //1st
glVertex2f(-1.0f,-0.2f);   //2nd
glVertex2f(1.0f,-0.2f);
glVertex2f(1.0f,-0.15f);

glEnd();
//Railway making end here.

// #Road's Vehicles are start from here#
 glPushMatrix(); //function for object moving
           glTranslatef(-position_bus,0.0f, 0.0f);

glBegin(GL_QUADS); //Car

glColor3ub(102, 0, 204);

glVertex2f(-0.7f,-0.3f);  //1st
glVertex2f(-0.5f,-0.3f);  //2nd
glVertex2f(-0.5f,-0.39f);  //3rd
glVertex2f(-0.7f,-0.39f);  //4th

glEnd();

glBegin(GL_TRIANGLES); //Car right side window

glColor3ub(255, 204, 0);

glVertex2f(-0.5f,-0.3f);  //1st
glVertex2f(-0.55f,-0.3f);   //2nd
glVertex2f(-0.5f,-0.35f);   //3rd

glEnd();

glBegin(GL_TRIANGLES); //Car left side window

glColor3ub(255, 204, 0);

glVertex2f(-0.7f,-0.3f);  //1st
glVertex2f(-0.65f,-0.3f);   //2nd
glVertex2f(-0.7f,-0.35f);   //3rd

glEnd();

int g;

	GLfloat a5=-0.65f; GLfloat b5=-0.39f; GLfloat radius5 =0.015f;
	int triangleAmount_5 = 30; //# of triangles used to draw circle


	GLfloat twicePi_5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(a5, b5); // center of circle
		for(g = 0; g <= triangleAmount_5;g++) {
			glVertex2f(
		            a5 + (radius5 * cos(g *  twicePi_5 / triangleAmount_5)),
			    b5 + (radius5 * sin(g * twicePi_5 / triangleAmount_5))
			);
		}
	glEnd();

	int q;

	GLfloat a6=-0.55f; GLfloat b6=-0.39f;


	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(a6, b6); // center of circle
		for(q = 0; q <= triangleAmount_5;q++) {
			glVertex2f(
		            a6 + (radius5 * cos(q *  twicePi_5 / triangleAmount_5)),
			    b6 + (radius5 * sin(q * twicePi_5 / triangleAmount_5))
			);
		}
	glEnd();

	//2nd bus


	glPopMatrix(); // moving object property

	glPushMatrix(); //function for object moving
           glTranslatef(position_bus,0.0f, 0.0f);

	glBegin(GL_QUADS); //Bus

glColor3ub(255, 102, 255);

glVertex2f(0.4f,-0.38f);  //1st
glVertex2f(0.6f,-0.38f);   //2nd
glVertex2f(0.6f,-0.48f);  //3rd
glVertex2f(0.4f,-0.48f);   //4th

glEnd();

// Bus's wheel start from here
glColor3ub(0, 102, 153);
int i1; //1st wheel

	GLfloat x5=0.55f; GLfloat y5=-0.48f;
	//GLfloat radius =0.015f;
//	int triangleAmount = 30; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	//GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x5, y5); // center of circle
		for(i1 = 0; i1 <= triangleAmount_5;i1++) {
			glVertex2f(
		            x5 + (radius5 * cos(i1 *  twicePi_5 / triangleAmount_5)),
			    y5 + (radius5 * sin(i1 * twicePi_5 / triangleAmount_5))
			);
		}
	glEnd();

	int p;// 2nd wheel

	GLfloat m=0.45f; GLfloat n=-0.48f;
//	GLfloat radius1 =0.015f;
//	int triangleAmount_1 = 30; //# of triangles used to draw circle


	GLfloat twicePi_1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m, n); // center of circle
		for(p = 0; p <= triangleAmount_5;p++) {
			glVertex2f(
		            m + (radius5 * cos(p *  twicePi_5 / triangleAmount_5)),
			    n + (radius5 * sin(p * twicePi_5 / triangleAmount_5))
			);
		}
	glEnd();

// Bus's wheels are end here

glBegin(GL_TRIANGLES); //Bus window

glColor3ub(51, 102, 255);

glVertex2f(0.4f,-0.38f);  //1st
glVertex2f(0.45f,-0.38f);   //2nd
glVertex2f(0.4f,-0.45f);   //3rd

glEnd();

	glPopMatrix(); // moving object property


	//Rail
	// # Railway's vehicle starts from here
           glPushMatrix(); //function for object moving
           glTranslatef(position_rail,0.0f, 0.0f);
	glBegin(GL_QUADS); //Rail Car

glColor3ub(255, 102, 102);

glVertex2f(-0.4f,-0.1f);  //1st
glVertex2f(0.2f,-0.1f);  //2nd
glVertex2f(0.2f,-0.19f);  //3rd
glVertex2f(-0.5f,-0.19f);  //4th

glEnd();

glBegin(GL_QUADS); // Rail Car's  window1

glColor3ub(0, 0, 255);

glVertex2f(-0.2f,-0.17f);  //1st
glVertex2f(-0.2f,-0.12f);  //2nd
glVertex2f(-0.15f,-0.12f);  //3rd
glVertex2f(-0.15f,-0.17f);  //4th

glEnd();

glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(0.2f,-0.15f);
glVertex2f(0.25f,-0.15f);
glEnd();

glBegin(GL_QUADS); // Rail Car's  window2

glColor3ub(0, 0, 255);

glVertex2f(0.02f,-0.12f);  //1st
glVertex2f(0.15f,-0.12f);  //2nd
glVertex2f(0.15f,-0.17f);  //3rd
glVertex2f(0.02f,-0.17f);  //4th

glEnd();




glBegin(GL_QUADS); //Rail Car2

glColor3ub(255, 102, 102);

glVertex2f(0.25f,-0.1f);  //1st
glVertex2f(0.7f,-0.1f);  //2nd
glVertex2f(0.7f,-0.19f);  //3rd
glVertex2f(0.25f,-0.19f);  //4th

glEnd();

glBegin(GL_QUADS); // Rail Car's  window1

glColor3ub(0, 0, 255);

glVertex2f(0.3f,-0.12f);  //1st
glVertex2f(0.35f,-0.12f);  //2nd
glVertex2f(0.35f,-0.17f);  //3rd
glVertex2f(0.3f,-0.17f);  //4th

glEnd();

glBegin(GL_QUADS); // Rail Car's  window1

glColor3ub(0, 0, 255);

glVertex2f(0.5f,-0.12f);  //1st
glVertex2f(0.65f,-0.12f);  //2nd
glVertex2f(0.65f,-0.17f);  //3rd
glVertex2f(0.5f,-0.17f);  //4th

glEnd();

glBegin(GL_LINE);
glColor3ub(29, 29, 36);
glVertex2f(0.2f,-0.14f);
glVertex2f(0.25f,-0.14f);
glEnd();

glPopMatrix();

//End Road Rail


   glLoadIdentity();


	glBegin(GL_QUADS);
    //River
	glColor3ub(52, 155, 235);
	glVertex2f(-1.0f,-0.5f);
	glVertex2f(-1.0f,-1.0f);
	glVertex2f(1.0f,-1.0f);
	glVertex2f(1.0f,-0.5f);

	//river road border
	glColor3ub(171, 167, 167);
	glVertex2f(-1.0f,-0.49f);
	glVertex2f(-1.0f,-0.55f);
	glVertex2f(1.0f,-0.55f);
	glVertex2f(1.0f,-0.49f);

	glEnd();

	//boat 1 (x,y)
	glPushMatrix();
    glTranslatef(position_Boat1,0.0f, 0.0f);

	glBegin(GL_QUADS);

	glColor3ub(28, 41, 43);
	glVertex2f(0.78f,-0.65f);
	glVertex2f(0.78f,-0.75f);
	glVertex2f(0.25f,-0.75f);
	glVertex2f(0.25f,-0.65f);

	glColor3ub(0, 213, 255);
    glVertex2f(0.8f,-0.75f);
	glVertex2f(0.7f,-0.87f);
	glVertex2f(0.4f,-0.87f);
	glVertex2f(0.2f,-0.75f);

	glColor3ub(81, 109, 115);
	glVertex2f(0.7f,-0.87f);
	glVertex2f(0.68f,-0.9f);
	glVertex2f(0.42f,-0.9f);
	glVertex2f(0.4f,-0.87f);

	glColor3ub(250, 162, 241);
	glVertex2f(0.7f,-0.65f);
	glVertex2f(0.4f,-0.65f);
	glVertex2f(0.4f,-0.55f);
	glVertex2f(0.7f,-0.55f);

	//windows
	glColor3ub(255, 252, 252);
	glVertex2f(0.68f,-0.57f);
	glVertex2f(0.68f,-0.62f);
	glVertex2f(0.63f,-0.62f);
	glVertex2f(0.63f,-0.57f);

	glVertex2f(0.59f,-0.57f);
	glVertex2f(0.59f,-0.62f);
	glVertex2f(0.54f,-0.62f);
	glVertex2f(0.54f,-0.57f);

	glVertex2f(0.44f,-0.57f);
	glVertex2f(0.44f,-0.62f);
	glVertex2f(0.49f,-0.62f);
	glVertex2f(0.49f,-0.57f);

	// 2nd floor
	glVertex2f(0.77f,-0.67f);
	glVertex2f(0.77f,-0.72f);
	glVertex2f(0.72f,-0.72f);
	glVertex2f(0.72f,-0.67f);

    glVertex2f(0.68f,-0.67f);
	glVertex2f(0.68f,-0.72f);
	glVertex2f(0.63f,-0.72f);
	glVertex2f(0.63f,-0.67f);

	glVertex2f(0.59f,-0.67f);
	glVertex2f(0.59f,-0.72f);
	glVertex2f(0.54f,-0.72f);
	glVertex2f(0.54f,-0.67f);

	glVertex2f(0.44f,-0.67f);
	glVertex2f(0.44f,-0.72f);
	glVertex2f(0.49f,-0.72f);
	glVertex2f(0.49f,-0.67f);

	glVertex2f(0.34f,-0.67f);
	glVertex2f(0.34f,-0.72f);
	glVertex2f(0.39f,-0.72f);
	glVertex2f(0.39f,-0.67f);

	glVertex2f(0.27f,-0.67f);
	glVertex2f(0.27f,-0.72f);
	glVertex2f(0.31f,-0.72f);
	glVertex2f(0.31f,-0.67f);

	//1st floor
    glVertex2f(0.68f,-0.77f);
	glVertex2f(0.68f,-0.82f);
	glVertex2f(0.63f,-0.82f);
	glVertex2f(0.63f,-0.77f);

	glVertex2f(0.59f,-0.77f);
	glVertex2f(0.59f,-0.82f);
	glVertex2f(0.54f,-0.82f);
	glVertex2f(0.54f,-0.77f);

	glVertex2f(0.44f,-0.77f);
	glVertex2f(0.44f,-0.82f);
	glVertex2f(0.49f,-0.82f);
	glVertex2f(0.49f,-0.77f);

	glVertex2f(0.34f,-0.77f);
	glVertex2f(0.34f,-0.82f);
	glVertex2f(0.39f,-0.82f);
	glVertex2f(0.39f,-0.77f);



	//light box front
	glColor3ub(0, 1, 61);
	glVertex2f(0.24f,-.48f);
	glVertex2f(0.24f,-.5f);
	glVertex2f(0.26f,-.5f);
	glVertex2f(0.26f,-.48f);

	//light box back

	glVertex2f(0.79f,-0.5f);
	glVertex2f(0.79f,-0.48f);
	glVertex2f(0.77f,-0.48f);
	glVertex2f(0.77f,-0.5f);

	glEnd();

	glBegin(GL_LINES);
	//boat 1 raling
	glColor3ub(23, 22, 22);
	glVertex2f(0.78f,-0.65f);
	glVertex2f(0.78f,-0.5f);
	glVertex2f(0.78f,-0.65f);
	glVertex2f(0.7f,-0.65f);
	glVertex2f(0.7f,-0.6f);
	glVertex2f(0.78f,-0.6f);

	glVertex2f(0.25f,-0.65f);
	glVertex2f(0.25f,-0.5f);
	glVertex2f(0.4f,-0.65f);
	glVertex2f(0.25f,-0.65f);
	glVertex2f(0.25f,-0.6f);
	glVertex2f(0.4f,-0.6f);

	glVertex2f(0.4f,-0.625f);
	glVertex2f(0.25f,-0.625f);
	glVertex2f(0.78f,-0.625f);
	glVertex2f(0.7f,-0.625f);

	glEnd();
	glPopMatrix();

	//Boat 2 (-x,-y)
	glPushMatrix();
    glTranslatef(position_Boat2,0.0f, 0.0f);
	glBegin(GL_QUADS);

    glColor3ub(28, 41, 43);
	glVertex2f(-0.78f,-0.75f);
	glVertex2f(-0.78f,-0.85f);
	glVertex2f(-0.25f,-0.85f);
	glVertex2f(-0.25f,-0.75f);

	glColor3ub(0, 87, 12);
	 glVertex2f(-0.8f,-0.85f);
	glVertex2f(-0.7f,-0.97f);
	glVertex2f(-0.4f,-0.97f);
	glVertex2f(-0.2f,-0.85f);

	glColor3ub(247, 73, 15);
	glVertex2f(-0.7f,-0.75f);
	glVertex2f(-0.4f,-0.75f);
	glVertex2f(-0.4f,-0.65f);
	glVertex2f(-0.7f,-0.65f);

	//windows
	glColor3ub(255, 252, 252);
	glVertex2f(-0.68f,-0.67f);
	glVertex2f(-0.68f,-0.72f);
	glVertex2f(-0.63f,-0.72f);
	glVertex2f(-0.63f,-0.67f);

	glVertex2f(-0.59f,-0.67f);
	glVertex2f(-0.59f,-0.72f);
	glVertex2f(-0.54f,-0.72f);
	glVertex2f(-0.54f,-0.67f);

	glVertex2f(-0.44f,-0.67f);
	glVertex2f(-0.44f,-0.72f);
	glVertex2f(-0.49f,-0.72f);
	glVertex2f(-0.49f,-0.67f);

	// 2nd floor
	glVertex2f(-0.77f,-0.77f);
	glVertex2f(-0.77f,-0.82f);
	glVertex2f(-0.72f,-0.82f);
	glVertex2f(-0.72f,-0.77f);

    glVertex2f(-0.68f,-0.77f);
	glVertex2f(-0.68f,-0.82f);
	glVertex2f(-0.63f,-0.82f);
	glVertex2f(-0.63f,-0.77f);

	glVertex2f(-0.59f,-0.77f);
	glVertex2f(-0.59f,-0.82f);
	glVertex2f(-0.54f,-0.82f);
	glVertex2f(-0.54f,-0.77f);

	glVertex2f(-0.44f,-0.77f);
	glVertex2f(-0.44f,-0.82f);
	glVertex2f(-0.49f,-0.82f);
	glVertex2f(-0.49f,-0.77f);

	glVertex2f(-0.34f,-0.77f);
	glVertex2f(-0.34f,-0.82f);
	glVertex2f(-0.39f,-0.82f);
	glVertex2f(-0.39f,-0.77f);

	glVertex2f(-0.27f,-0.77f);
	glVertex2f(-0.27f,-0.82f);
	glVertex2f(-0.31f,-0.82f);
	glVertex2f(-0.31f,-0.77f);

	//1st floor
    glVertex2f(-0.68f,-0.87f);
	glVertex2f(-0.68f,-0.92f);
	glVertex2f(-0.63f,-0.92f);
	glVertex2f(-0.63f,-0.87f);

	glVertex2f(-0.59f,-0.87f);
	glVertex2f(-0.59f,-0.92f);
	glVertex2f(-0.54f,-0.92f);
	glVertex2f(-0.54f,-0.87f);

	glVertex2f(-0.44f,-0.87f);
	glVertex2f(-0.44f,-0.92f);
	glVertex2f(-0.49f,-0.92f);
	glVertex2f(-0.49f,-0.87f);

	glVertex2f(-0.34f,-0.87f);
	glVertex2f(-0.34f,-0.92f);
	glVertex2f(-0.39f,-0.92f);
	glVertex2f(-0.39f,-0.87f);


	//light box front
	glColor3ub(0, 1, 61);
	glVertex2f(-0.24f,-.58f);
	glVertex2f(-0.24f,-.6f);
	glVertex2f(-0.26f,-.6f);
	glVertex2f(-0.26f,-.58f);

	//light box back

	glVertex2f(-0.79f,-0.6f);
	glVertex2f(-0.79f,-0.58f);
	glVertex2f(-0.77f,-0.58f);
	glVertex2f(-0.77f,-0.6f);

	glEnd();


	glBegin(GL_LINES);

	//boat 2 raling
	glColor3ub(23, 22, 22);
	glVertex2f(-0.78f,-0.75f);
	glVertex2f(-0.78f,-0.6f);
	glVertex2f(-0.78f,-0.75f);
	glVertex2f(-0.7f,-0.75f);
	glVertex2f(-0.7f,-0.7f);
	glVertex2f(-0.78f,-0.7f);

	glVertex2f(-0.25f,-0.75f);
	glVertex2f(-0.25f,-0.6f);
	glVertex2f(-0.4f,-0.75f);
	glVertex2f(-0.25f,-0.75f);
	glVertex2f(-0.25f,-0.7f);
	glVertex2f(-0.4f,-0.7f);

	glVertex2f(-0.4f,-0.725f);
	glVertex2f(-0.25f,-0.725f);
	glVertex2f(-0.78f,-0.725f);
	glVertex2f(-0.7f,-0.725f);;


	glEnd();

	glPopMatrix();


	glFlush();
}


// display change
void handleKeypress3(unsigned char key, int x, int y) {
	switch (key) {
case 'p':
    speed_rain = 0.0f;
    speed = 0.0f;//cloud1
    speed_plane = 0.0f;//cloud1
    speed_Boat2 = 0.0f;
    speed_Boat1 = 0.0f;
    speed_rail = 0.0f;
    speed_bus = 0.0f;
    glutPostRedisplay();
    break;
case 'm':
    speed_rain = 0.05f;
    speed = 0.02f;//cloud1
    speed_plane = 0.05f;
    speed_Boat2 = 0.05f;
    speed_Boat1 = 0.04f;
    speed_rail = 0.05f;
    speed_bus = 0.03f;
    glutPostRedisplay();
    break;

	}
}
/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);

    glutCreateWindow("Modern City View");

    glutDisplayFunc(display);


    init2();
    glutTimerFunc(100, Rain, 0);

    glutTimerFunc(100, Boat1Moving, 0);
    glutTimerFunc(100, Boat2Moving, 0);



    glutKeyboardFunc(handleKeypress3);


	glutTimerFunc(100,cloud_moving1, 0);
	glutTimerFunc(100,plane_moving, 0);
	glutTimerFunc(100,update, 0);
	glutTimerFunc(100,BusMove, 0);



    glutMainLoop();

    return EXIT_SUCCESS;
}
