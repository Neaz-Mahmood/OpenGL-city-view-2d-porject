#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>

double windowWidth= 2000, windowHeight = 800;
bool carFlag = false, sunFlag = false, boatFlag = false, cloudFlag = false;
bool moveRight=false, moveLeft = false;
double carXval = 0, boatXval = 0, cloudXval = 0, sunYval = 0;


void drawCircle(double x, double y, double s){

    glBegin(GL_TRIANGLE_FAN);
        for(int i=0;i<360;i++)
        {
            x=x+cos((i*3.14)/180)*s;
            y=y+sin((i*3.14)/180)*s;

            glVertex2f(x,y);

        }
    glEnd();
}


void sky()
{
    glPushMatrix();
    glBegin(GL_QUADS);

   glVertex2f(-70,12);
   glVertex2f(70, 12);
   glVertex2f(70,50);
   glVertex2f(-70, 50);
   glEnd();
   glPopMatrix();
}

void river()
{
    glPushMatrix();
    glBegin(GL_POLYGON);
     glVertex2f(-70, -30);
     glVertex2f(-70, -50);
     glVertex2f(70, -50);
     glVertex2f(70, -25);
    glEnd();
    glPopMatrix();
}

void greenField()
{
    glPushMatrix();
    glBegin(GL_POLYGON);
     glVertex2f(-70, -30);
     glVertex2f(70, -25);
     glVertex2f(70, 12);
     glVertex2f(-70, 12);
    glEnd();
    glPopMatrix();
}

void house()
{
    glPushMatrix();
    //roof
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2f(-55,0);
    glVertex2f(-60,-6);
    glVertex2f(-42,-6);
    glVertex2f(-37,0);
    glEnd();
    //front
    glBegin(GL_QUADS);
    glColor3f(0.960, 0.954, 0.912);
    glVertex2f(-59,-6);
    glVertex2f(-59,-16);
    glVertex2f(-42,-16);
    glVertex2f(-42,-6);
    glEnd();
    //back
    glBegin(GL_POLYGON);
    glColor3f(0.960, 0.954, 0.912);
    glVertex2f(-42,-6);
    glVertex2f(-42,-16);
    glVertex2f(-32,-16);
    glVertex2f(-32,-6);
    glVertex2f(-37,0);
    glEnd();
    //shade
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2f(-37, 0);
    glVertex2f(-32,-6);
    glVertex2f(-31,-6);
    glVertex2f(-36,0);
    glEnd();
    //window
    glBegin(GL_QUADS);
    glColor3f(0.0800, 0.0723, 0.0136);
    glVertex2f(-39,-9);
    glVertex2f(-39,-13);
    glVertex2f(-35,-13);
    glVertex2f(-35,-9);
    glEnd();



    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glVertex2f(-42,-6);
    glVertex2f(-42,-16);
    glEnd();
    //door
    glBegin(GL_QUADS);
    glColor3f(0.260, 0.250, 0.172);
    glVertex2f(-53,-16);
    glVertex2f(-48,-16);
    glVertex2f(-48,-9);
    glVertex2f(-53,-9);
    glEnd();
    glPopMatrix();



}

void house_night()
{
    glPushMatrix();
    //roof
    glBegin(GL_QUADS);
    glColor3f(0.650, 0.0656, 0.0455);
    glVertex2f(-55,0);
    glVertex2f(-60,-6);
    glVertex2f(-42,-6);
    glVertex2f(-37,0);
    glEnd();
    //front
    glBegin(GL_QUADS);
    glColor3f(0.610, 0.607, 0.549);
    glVertex2f(-59,-6);
    glVertex2f(-59,-16);
    glVertex2f(-42,-16);
    glVertex2f(-42,-6);
    glEnd();
    //back
    glBegin(GL_POLYGON);
    glColor3f(0.610, 0.607, 0.549);
    glVertex2f(-42,-6);
    glVertex2f(-42,-16);
    glVertex2f(-32,-16);
    glVertex2f(-32,-6);
    glVertex2f(-37,0);
    glEnd();
    //shade
    glBegin(GL_QUADS);
    glColor3f(0.650, 0.0656, 0.0455);
    glVertex2f(-37, 0);
    glVertex2f(-32,-6);
    glVertex2f(-31,-6);
    glVertex2f(-36,0);
    glEnd();
    //window
    glBegin(GL_QUADS);
    glColor3f(0.0800, 0.0723, 0.0136);
    glVertex2f(-39,-9);
    glVertex2f(-39,-13);
    glVertex2f(-35,-13);
    glVertex2f(-35,-9);
    glEnd();



    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glVertex2f(-42,-6);
    glVertex2f(-42,-16);
    glEnd();
    //door
    glBegin(GL_QUADS);
    glColor3f(0.260, 0.250, 0.172);
    glVertex2f(-53,-16);
    glVertex2f(-48,-16);
    glVertex2f(-48,-9);
    glVertex2f(-53,-9);
    glEnd();
    glPopMatrix();



}


void sun()
{

    glPushMatrix();
    drawCircle(40, 30, 0.1);
    glPopMatrix();


}

void cloud()
{
    double s= 0.05;

    glPushMatrix();
    glColor3ub(220,220,220);
	glTranslatef(0,-5,0);
	drawCircle(-41,45 , s);
	drawCircle(-43,43, s);
	drawCircle(-40,42, s);
	drawCircle(-42,47, s);
	drawCircle(-39,48, s);
	drawCircle(-36,45, s);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(220,220,220);
	glTranslatef(20,-10,0);
	drawCircle(-41,45 , s);
	drawCircle(-43,43, s);
	drawCircle(-40,42, s);
	drawCircle(-42,47, s);
	drawCircle(-39,48, s);
	drawCircle(-36,45, s);
    glPopMatrix();

}

void walkingRoad()
{
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(-55,-11);
    glVertex2f(-20,-5);
    glVertex2f(-20, -28);
    glVertex2f(-52, -29);
    glVertex2f(-53, -25);
    glEnd();
    glPopMatrix();
}

void boat()
{
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(17,0);
    glVertex2f(23,-5);
    glVertex2f(35,-5);
    glVertex2f(40,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3f(0,0,1);
    glVertex2f(20,0);
    glVertex2f(23,5);
    glVertex2f(25,0);
    glEnd();
    glPopMatrix();

   glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1 ,0,0);
    glVertex2f(23,5);
    glVertex2f(25,0);
    glVertex2f(37,0);
    glVertex2f(34,5);
    glEnd();
    glPopMatrix();

}


void boat_night()
{
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.232, 0.250, 0.234);
    glVertex2f(17,0);
    glVertex2f(23,-5);
    glVertex2f(35,-5);
    glVertex2f(40,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0704, 0.120, 0.440);
    glVertex2f(20,0);
    glVertex2f(23,5);
    glVertex2f(25,0);
    glEnd();
    glPopMatrix();

   glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.630, 0.171, 0.0315);
    glVertex2f(23,5);
    glVertex2f(25,0);
    glVertex2f(37,0);
    glVertex2f(34,5);
    glEnd();
    glPopMatrix();

}


void boatStand()
{
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glVertex2f(-40,-28);
    glVertex2f(-40,-18);
    glEnd();
    glPopMatrix();
}

void hill()
{
    glPushMatrix;
    glBegin(GL_TRIANGLES);
    glVertex2f(70,12);
    glVertex2f(55,30);
    glVertex2f(30,12);
    glEnd();

    glPopMatrix();

}

void mountain()
{
    glPushMatrix();
    hill();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 0.7, 0);
    glTranslatef(10, 5, 0);
    hill();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.2, 0.7, 0);
    glTranslatef(10, 5, 0);
    hill();
    glPopMatrix();

    glPushMatrix();
    glScalef(1, 1.2, 0);
    glTranslatef(-40, -2, 0);
    hill();
    glPopMatrix();

    glPushMatrix();
    glScalef(1, 1.2, 0);
    glTranslatef(-50, -2, 0);
    hill();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.2, 0.7, 0);
    glTranslatef(-70, 05, 0);
    hill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-90, 0, 0);
    hill();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 0.7, 0);
    glTranslatef(-160, 5, 0);
    hill();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.9, 0.5, 0);
    glTranslatef(-130, 12, 0);
    hill();
    glPopMatrix();

}

void tree()
{
    double s = 0.1;

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.2,0,0);
    glVertex2f(-60,0);
    glVertex2f(-60,-25);
    glVertex2f(-55,-25);
    glVertex2f(-55,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
     glTranslatef(-10,0,0);
    glColor3f(0.0355, 0.710, 0.0805);

    drawCircle(-47,3, s);
    drawCircle(-44,-2, s);
    drawCircle(-48,-2, s);
    drawCircle(-52,-2, s);
    drawCircle(-50,3, s);
    drawCircle(-45,3, s);
    drawCircle(-47,9, s);
    glEnd();
    glPopMatrix();
}


void tree_night()
{
    double s = 0.1;

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.2,0,0);
    glVertex2f(-60,0);
    glVertex2f(-60,-25);
    glVertex2f(-55,-25);
    glVertex2f(-55,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
     glTranslatef(-10,0,0);
    glColor3f(0.00660, 0.330, 0.0282);

    drawCircle(-47,3, s);
    drawCircle(-44,-2, s);
    drawCircle(-48,-2, s);
    drawCircle(-52,-2, s);
    drawCircle(-50,3, s);
    drawCircle(-45,3, s);
    drawCircle(-47,9, s);
    glEnd();
    glPopMatrix();
}


void Zebra()
{
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex2f(70, 4);
    glVertex2f(65, 4);
    glVertex2f(65, 2);
    glVertex2f(70, 2);
    glEnd();
    glPopMatrix();
}

void road()
{
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.3,0.1,0);
    glVertex2f(-70, 10);
    glVertex2f(-70,-4);
    glVertex2f(70,-4);
    glVertex2f(70, 10);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, 0, 0);
    glColor3f(1,1,1);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20, 0, 0);
    glColor3f(1,1,1);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-30, 0, 0);
    glColor3f(1,1,1);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-40, 0, 0);
    glColor3f(1,1,1);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-50, 0, 0);
    glColor3f(1,1,1);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-60, 0, 0);
    glColor3f(1,1,1);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-70, 0, 0);
    glColor3f(1,1,1);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-80, 0, 0);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-90, 0, 0);
    glColor3f(1,1,1);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-100, 0, 0);
    glColor3f(1,1,1);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-110, 0, 0);
    glColor3f(1,1,1);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-120, 0, 0);
    glColor3f(1,1,1);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-130, 0, 0);
    glColor3f(1,1,1);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-140, 0, 0);
    glColor3f(1,1,1);
    Zebra();
    glPopMatrix();


}

void road_night()
{
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.230, 0.157, 0.0115);
    glVertex2f(-70, 10);
    glVertex2f(-70,-4);
    glVertex2f(70,-4);
    glVertex2f(70, 10);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.560, 0.546, 0.442);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, 0, 0);
    glColor3f(0.560, 0.546, 0.442);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20, 0, 0);
    glColor3f(0.560, 0.546, 0.442);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-30, 0, 0);
    glColor3f(0.560, 0.546, 0.442);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-40, 0, 0);
    glColor3f(0.560, 0.546, 0.442);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-50, 0, 0);
    glColor3f(0.560, 0.546, 0.442);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-60, 0, 0);
    glColor3f(0.560, 0.546, 0.442);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-70, 0, 0);
    glColor3f(0.560, 0.546, 0.442);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-80, 0, 0);
    glColor3f(0.560, 0.546, 0.442);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-90, 0, 0);
    glColor3f(0.560, 0.546, 0.442);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-100, 0, 0);
    glColor3f(0.560, 0.546, 0.442);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-110, 0, 0);
    glColor3f(0.560, 0.546, 0.442);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-120, 0, 0);
    glColor3f(0.560, 0.546, 0.442);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-130, 0, 0);
    glColor3f(0.560, 0.546, 0.442);
    Zebra();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-140, 0, 0);
    glColor3f(0.560, 0.546, 0.442);
    Zebra();
    glPopMatrix();


}


void car()
{
    glPushMatrix();
    glTranslatef(60, 55, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.930, 0.110, 0.0186);
    glVertex2f(-45,-55);
    glVertex2f(-28,-55);
    glVertex2f(-28,-50);
    glVertex2f(-45,-50);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.970, 0.955, 0.0485);
    glVertex2f(-42,-50);
    glVertex2f(-37,-50);
    glVertex2f(-37,-47);
    glVertex2f(-40,-47);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3f(0.0475, 0.168, 0.950);
    glVertex2f(-36,-50);
    glVertex2f(-31,-50);
    glVertex2f(-33,-47);
    glVertex2f(-36,-47);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-37,-50);
    glVertex2f(-36,-50);
    glVertex2f(-36,-47);
    glVertex2f(-37,-47);
    glEnd();

    glColor3f(0,0,0);
    drawCircle(-40.5,-57, 0.04);
    drawCircle(-32,-57, 0.04);
    glPopMatrix();


}

void car_night()
{
    glPushMatrix();
    glTranslatef(60, 55, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.380, 0.0619, 0.0266);
    glVertex2f(-45,-55);
    glVertex2f(-28,-55);
    glVertex2f(-28,-50);
    glVertex2f(-45,-50);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.500, 0.492, 0.0150);
    glVertex2f(-42,-50);
    glVertex2f(-37,-50);
    glVertex2f(-37,-47);
    glVertex2f(-40,-47);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3f(0.0195, 0.0689, 0.390);
    glVertex2f(-36,-50);
    glVertex2f(-31,-50);
    glVertex2f(-33,-47);
    glVertex2f(-36,-47);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-37,-50);
    glVertex2f(-36,-50);
    glVertex2f(-36,-47);
    glVertex2f(-37,-47);
    glEnd();

    glColor3f(0,0,0);
    drawCircle(-40.5,-57, 0.04);
    drawCircle(-32,-57, 0.04);
    glPopMatrix();


}


void star()
{
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,1);
    glVertex2f(-35,50);
    glVertex2f(-37,50);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,1);
    glVertex2f(-36,49);
    glVertex2f(-36,51);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,1);
    glVertex2f(-37,51);
    glVertex2f(-35,49);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,1);
    glVertex2f(-35,51);
    glVertex2f(-37,49);
    glEnd();

    glPopMatrix();
}

void stars()
{
    glPushMatrix();
    glTranslatef(0, -5, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2, -6, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-15, -4, 0);
    star();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9, -5, 0);
    star();
    glPopMatrix();



}


void StartingText()
{
    char text[120];

        sprintf(text, "UNIVERSITY OF INFORMATION TECHNOLOGY & SCIENCE",5.00,8.00);
    glColor3f(0, 1, 0);
    glRasterPos2f( -35 , 55 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

    sprintf(text, "VILLAGE SCENARIO",5.00,8.00);
    glColor3f(1, 1, 0);
    glRasterPos2f( -20 , 45 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

        sprintf(text, "NAME-Neaz Mahmood",5.00,8.00);
    glColor3f(0.0616, 0.375, 0.880);
    glRasterPos2f( -20 , 35 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
        sprintf(text, "ID-1914551057",5.00,8.00);
    glColor3f(0.0616, 0.375, 0.880);
    glRasterPos2f( -20 , 30 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
            sprintf(text, "DEPARTMENT OF CSE",5.00,8.00);
    glColor3f(0.0616, 0.375, 0.880);
    glRasterPos2f( -20 , 25 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
            sprintf(text, "SUBMITTED TO-",5.00,8.00);
    glColor3f(0.880, 0.233, 0.0176);
    glRasterPos2f( -20 , 17 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
                sprintf(text, "SALIM SHADMAN ANKUR & PROPA PUNAM",5.00,8.00);
    glColor3f(0.880, 0.233, 0.0176);
    glRasterPos2f( -10 , 12 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
                sprintf(text, "PRESS 'd' FOR DAY MODE",5.00,8.00);
    glColor3f(1, 1, 1);
    glRasterPos2f( -20 , 0 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
        sprintf(text, " PRESS 'n' FOR NIGHT MODE",5.00,8.00);
    glColor3f(1, 1, 1);
    glRasterPos2f( -21 , -5 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

     sprintf(text, " PRESS 'r' FOR SET THE DIRECTION TO RIGHT",5.00,8.00);
    glColor3f(1, 1, 1);
    glRasterPos2f( -21 , -10 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
    sprintf(text, " PRESS 'l' FOR SET THE DIRECTION TO LEFT",5.00,8.00);
    glColor3f(1, 1, 1);
    glRasterPos2f( -21 , -15 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
    sprintf(text, " PRESS '1'(ONE) TO MOVE THE CAR",5.00,8.00);
    glColor3f(1, 1, 1);
    glRasterPos2f( -21 , -20 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
    sprintf(text, " PRESS '2' TO MOVE THE BOAT",5.00,8.00);
    glColor3f(1, 1, 1);
    glRasterPos2f( -21 , -25 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
    sprintf(text, " PRESS '3' TO MOVE THE CLOUD",5.00,8.00);
    glColor3f(1, 1, 1);
    glRasterPos2f( -21 , -30 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
    sprintf(text, " PRESS '4' TO MOVE THE SUN/MOVE",5.00,8.00);
    glColor3f(1, 1, 1);
    glRasterPos2f( -21 , -35 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
    sprintf(text, " PRESS 's' TO STOP MOVEMENT",5.00,8.00);
    glColor3f(1, 1, 1);
    glRasterPos2f( -21 , -40 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' '  && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -32 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }


}


void night(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(-70,70,-50,50);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glPushMatrix();
    glColor3f(0.2, 0.1, 0.4);
    sky();
    glPopMatrix();

    //moon
    glPushMatrix();
    glTranslatef(0, sunYval, 0);
    glColor3f(1, 1, 1);
    sun();
    glPopMatrix();
    //moon shadow
    glPushMatrix();
    glTranslatef(-2, sunYval, 0);
    glColor3f(0.2, 0.1, 0.4);
    sun();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.260, 0.215, 0.148);
    mountain();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0506, 0.350, 0.0455);
    greenField();
    glPopMatrix();

    glPushMatrix();
    road_night();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(carXval, 0, 0);
    car_night();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0460, 0.460, 0.398);
    river();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 0);
    glTranslatef(-37, -5, 0);
    tree_night();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 0);
    glTranslatef(-27, 0, 0);
    tree_night();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.290, 0.159, 0.0290);
    walkingRoad();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7, 0, 0);
    glScalef(0.7, 0.7, 0);
    house_night();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -5, 0);
    house_night();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(boatXval, 0, 0);
    glPushMatrix();
    glScalef(0.7, 0.7, 1);
    glTranslatef(-40, -60, 0);
    boat_night();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    boatStand();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 1);
    glTranslatef(-80, -40, 0);
    boat_night();
    glPopMatrix();

    glPushMatrix();
    stars();
    glPopMatrix();


    glFlush();
    glutSwapBuffers();
}



void day(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(-70,70,-50,50);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glPushMatrix();
    glColor3f(0, 0.2, 0.9);
    sky();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, sunYval, 0);
    glColor3f(0.950, 0.475, 0.219);
    sun();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.4,0.1,0.1);
    mountain();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.215, 0.860, 0.181);
    greenField();
    glPopMatrix();

    glPushMatrix();
    road();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(carXval, 0, 0);
    car();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.3,0.8,1);
    river();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 0);
    glTranslatef(-37, -5, 0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 0);
    glTranslatef(-27, 0, 0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.620, 0.332, 0.0434);
    walkingRoad();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7, 0, 0);
    glScalef(0.7, 0.7, 0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -5, 0);
    house();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(boatXval, 0, 0);
    glPushMatrix();
    glScalef(0.7, 0.7, 1);
    glTranslatef(-40, -60, 0);
    boat();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    boatStand();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 1);
    glTranslatef(-80, -40, 0);
    boat();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloudXval, 0, 0);
    cloud();
    glPopMatrix();


    glFlush();
    glutSwapBuffers();
}




void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(-70,70,-50,50);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glPushMatrix();
    StartingText();
    glEnd();
    glPopMatrix();
     glFlush();
    glutSwapBuffers();



}


void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {

        case  'd':
            glutDestroyWindow(1);
            glutInitWindowSize(windowWidth, windowHeight);

            glutCreateWindow("Day in village");
            glutKeyboardFunc(myKeyboardFunc);
            glutDisplayFunc(day);
              break;

        case 'n':
            glutDestroyWindow(1);
            glutInitWindowSize(windowWidth, windowHeight);

            glutCreateWindow("Night in village");
            glutKeyboardFunc(myKeyboardFunc);
            glutDisplayFunc(night);

            glutPostRedisplay();
            break;

        case 'r':
            moveRight=true;
            moveLeft = false;
            break;
        case 'l':
            moveLeft=true;
            moveRight = false;
            break;
        case 's':
            moveRight=false;
            moveLeft= false;
            break;
        case '1':
            carFlag = !carFlag;
            moveRight = true;
            break;
        case '2':
            boatFlag = !boatFlag;
            moveRight = true;
            break;
        case '3':
            cloudFlag = !cloudFlag;
            moveRight = true;
            break;
        case '4':
            sunFlag = !sunFlag;
            moveRight = true;
            break;


        case '0':	// Escape key
            exit(1);
    }
    glutPostRedisplay();
}


void animate()
{
	if (moveLeft == true)
	{
	    if(carFlag == true){
            carXval-=0.05;
            if(carXval < -100){
            carXval = 50;
            }
	    }
		if(boatFlag == true){
            boatXval -= 0.05;
            if(boatXval < -100){
                boatXval = 90;
            }
		}
        if(sunFlag == true){
            sunYval -= 0.02;
            if(sunYval < -50){
                sunYval = 20;
            }
        }

        if(cloudFlag == true){
            cloudXval -= 0.03;
            if(cloudXval < -80){
                cloudXval = 120;
            }
        }


	}
	if (moveRight == true)
	{
	    if(carFlag == true){
            carXval+=0.05;
            if(carXval > 50){
                carXval = -100;
            }
	    }
		if(boatFlag == true){
            boatXval += 0.05;
            if(boatXval > 90){
                boatXval = -100;
            }
		}

        if(sunFlag == true){
            sunYval += 0.02;
            if(sunYval > 20){
                sunYval = -50;
            }
        }
        if(cloudFlag == true){
            cloudXval += 0.03;
            if(cloudXval > 120){
                cloudXval = -80;
            }
        }


	}

	glutPostRedisplay();
}


int main (int argc, char **argv)
{
glutInit(&argc, argv);
glutInitWindowSize(windowWidth, windowHeight);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode

glutInitWindowPosition(8,10);

glutCreateWindow("Neaz Village");
glShadeModel( GL_SMOOTH );
glEnable( GL_DEPTH_TEST );


glutKeyboardFunc(myKeyboardFunc);
glutIdleFunc(animate);


glutDisplayFunc(day);
glutDisplayFunc(night);
glutDisplayFunc(display);


glDepthFunc(GL_LEQUAL);    // Set the type of depth-test

glutMainLoop();
return 0;
}

