#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>

float R=1,G=1,B=0;
GLint xc=450,yc=350,rds=200;
int h=100,k=100;
GLfloat xp=0,yp=40,r,y=330;


void *currentfont;

void setFont(void *font) //to setfont size of texts
{
currentfont=font;
}


void drawstring(float x,float y,char *string) //to display text
{
char *c;
glRasterPos2f(x,y);
for(c=string;*c!='\0';c++)
{
glutBitmapCharacter(currentfont,*c);
}
}


void draw_pixel(GLint cx,GLint cy) //to draw points at each pixels
{
glBegin(GL_POINTS);
glVertex2i(cx,cy);
glEnd();
}

void plotpixels(GLint h,GLint k,GLint x,GLint y) //(for curve facing)
{
draw_pixel(x+h,-y+k);
draw_pixel(-x+h,-y+k);
}

void plotpixels2(GLint h,GLint k,GLint x,GLint y) //(for curve facing downwards)
{
draw_pixel(-x+h,y+k);
draw_pixel(x+h,y+k);
}

void circle_smile1(GLint h,GLint k,GLint r) //draw half circle facing upward
{
GLint d=1-r,x=0,y=r;
while(y>x)
{
plotpixels(h,k,x,y);
if(d<0)
d+=2*x+3;
else
{
d+2*(x-y)+5;
--y;
}
++x;
}
plotpixels(h,k,x,y);
}

 
void circle_smile3(GLint h,GLint k,GLint r) //draw half circle facing downward
{
GLint d=1-r,x=0,y=r;
while(y>x)
{
plotpixels2(h,k,x,y);
if(d<0)
d+=2*x+3;
else
{
d+2*(x-y)+5;
--y;
}
++x;
}
plotpixels2(h,k,x,y);
}

void circle_smile2(GLint h,GLint k,GLint r) //draw half circle facing upward(d)
{
GLint d=1-r,x=0,y=r;
while(y>x)
{
plotpixels(h,k,x,y);
if(d<0)
d+=2*x+3;
else
{
d+2*(x-y)+5;
y=y-3;
}
++x;
}
plotpixels(h,k,x,y);
}

void draw_circle(float rds,float xc,float yc) //to plot ponits of circle
{
float x,y,angle,angle_radians;
for(angle=0;angle<360;angle++)
{
angle_radians=angle*(float)3.14159/(float)180; //converting into radians
x=xc+rds*(float)cos(angle_radians);
y=yc+rds*(float)sin(angle_radians);
glVertex2f(x,y);
}
}


void myinit()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,899.0,0.0,699.0);
glMatrixMode(GL_MODELVIEW);
}

void circles() //for displaying simley name within circle
{
glColor3f(1,0,0);
glBegin(GL_POLYGON); //upper circles
draw_circle(20,xp,yp+600);
glEnd();
glBegin(GL_POLYGON); 
draw_circle(20,xp+45,yp+600);
glEnd();
glBegin(GL_POLYGON); 
draw_circle(20,xp+90,yp+600);
glEnd();
glBegin(GL_POLYGON);
draw_circle(20,xp+135,yp+600);
glEnd();
glBegin(GL_POLYGON);
draw_circle(20,xp+180,yp+600);
glEnd();
glBegin(GL_POLYGON);
draw_circle(20,xp+225,yp+600);
glEnd();
glBegin(GL_POLYGON);
draw_circle(20,xp+270,yp+600);
glEnd();

glBegin(GL_POLYGON); //lower circle
draw_circle(30,xp,yp);
glEnd();
glBegin(GL_POLYGON);
draw_circle(30,xp+65,yp);
glEnd();
glBegin(GL_POLYGON);
draw_circle(30,xp+130,yp);
glEnd();
glBegin(GL_POLYGON); 
draw_circle(30,xp+195,yp);
glEnd();
glBegin(GL_POLYGON); 
draw_circle(30,xp+260,yp);
glEnd();
glBegin(GL_POLYGON);
draw_circle(30,xp+325,yp);
glEnd();

glColor3f(1.0,1.0,1.0);
setFont(GLUT_BITMAP_TIMES_ROMAN_24); //text font
drawstring(xp-5,yp-5,"S");
drawstring(xp+60,yp-5,"M");
drawstring(xp+125,yp-5,"I");
drawstring(xp+190,yp-5,"L");
drawstring(xp+255,yp-5,"E");
drawstring(xp+320,yp-5,"Y");
}

void startScreen() //for displaying names
{
glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(.8,.0,.5);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
drawstring(350,600,"MINI PROJECT ON");
glColor3f(1,0,0);
drawstring(390,570,"\"SMILEY\"");
glColor3f(.8,.0,.5);
setFont(GLUT_BITMAP_HELVETICA_18);
drawstring(440,500,"BY,");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
drawstring(50,440,"PRASHANT N");
setFont(GLUT_BITMAP_HELVETICA_18);
drawstring(50,420,"4AD15CS428");
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
drawstring(620,440,"PUNITH KUMAR CM");
setFont(GLUT_BITMAP_HELVETICA_18);
drawstring(620,420,"4AD15CS429");
glColor3f(1.0,0.0,0.0);
drawstring(250,200,"PRESS'i'FOR INSTRUCTIONS");
glFlush();
}


void instructions() //instscreen
{
glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,0,0);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
drawstring(350,600,"INSTRUCTIONS");
glColor3f(.3,.3,1.0);
drawstring(100,550,"KEYBOARD OPERATION:");
drawstring(100,350,"MOUSE OPERATION:");
glColor3f(0.0,0.0,0.0);
drawstring(80,495,"*");
drawstring(80,450,"*");
drawstring(80,405,"*");
drawstring(80,310,"*");
glColor3f(1.8,0.3,1.0);
drawstring(100,500,"press keys a,s,d,f,g,h,j,k,l to change the smiley color");
drawstring(100,455,"press z to move the smiley LEFT");
drawstring(100,410,"press x to move the smiley RIGHT");
drawstring(100,310,"click RIGHT MOUSE BUTTON for menu");
glColor3f(1.8,0.3,1.0);
drawstring(250,250,"PRESS 'c' FOR INITIAL SMILEY");
glFlush();
}

void idle(void) //for tear to mov down
{
y-=1.0;
if(y<100)
y=320;
glutPostRedisplay();
}

void idle1(void) //to mov text
{
xp+=1.0;
if(xp>=899)
xp=0;
glutPostRedisplay();
}

void draw_face(void) //to draw initial smiley face
{
glBegin(GL_POLYGON);
glColor3f(R,G,B);
draw_circle(rds,xc,yc);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1,1,1);
draw_circle(25,xc-80,yc+80);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0,0,0);
draw_circle(15,xc-80,yc+80);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
draw_circle(25,xc+80,yc+80);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0,0,0);
draw_circle(15,xc+80,yc+80);
glEnd();
}

void initial() //to draw smile
{
glColor3f(.8,.0,.0);
glPointSize(8);
circle_smile1(xc,yc+70,150);
glPointSize(7);
circle_smile1(xc-105,yc-20,15);
circle_smile1(xc+105,yc-20,15);
}

void smiley1() //laugh
{
draw_face();
glColor3f(0.0,0.0,0.0);
glPointSize(18.7);
circle_smile1(xc,yc-16,113);
glBegin(GL_POLYGON);
glColor3f(.8,.0,.0);
draw_circle(20,xc,yc-120);
glEnd();
glColor3f(1.0,1.0,1.0);
glPointSize(12);
circle_smile1(xc,yc+20,130);
glColor3f(1.0,1.0,1.0);
glPointSize(15);
circle_smile1(xc,yc-60,88);
glColor3f(.8,0.0,0.0);
glPointSize(7);
circle_smile1(xc,yc+50,150);
circle_smile2(xc,yc+50,210);
circle_smile1(xc-105,yc-38,15);
circle_smile1(xc+105,yc-38,15);
}

void smiley2() //angry
{
glColor3f(.3,.3,.3);
glBegin(GL_TRIANGLES);
glVertex2f(xc-80,yc+180);
glColor3f(.3,.0,.0);
glVertex2f(xc-60,yc+235);
glColor3f(.1,.0,.0);
glVertex2f(xc-40,yc+180);
glEnd();
glColor3f(1,0,0);
glBegin(GL_TRIANGLES);
glVertex2f(xc+80,yc+180);
glColor3f(.3,.0,.0);
glVertex2f(xc+60,yc+235);
glColor3f(.1,.0,.0);
glVertex2f(xc+40,yc+180);
glEnd();

draw_face();

glColor3f(0,0,0);
glBegin(GL_TRIANGLES);
glVertex2f(xc+70,yc+110);
glColor3f(0.1,0.1,0.2);
glVertex2f(xc+60,yc+115);
glColor3f(.1,.2,.1);
glVertex2f(xc+110,yc+135);
glEnd();

glColor3f(0,0,0);
glBegin(GL_TRIANGLES);
glVertex2f(xc-70,yc+110);
glColor3f(.1,.1,.2);
glVertex2f(xc-60,yc+115);
glColor3f(.1,.1,.2);
glVertex2f(xc-110,yc+135);
glEnd();

glColor3f(0,0,0);
glPointSize(30);
 
glBegin(GL_POLYGON);
glVertex2f(xc-73,yc-40);
glVertex2f(xc-45,yc-138);
glVertex2f(xc-20,yc-130);
glVertex2f(xc-40,yc-60);
glVertex2f(xc,yc-80);
glVertex2f(xc,yc-118);
glVertex2f(xc-20,yc-130);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc,yc-118);
glVertex2f(xc-20,yc-110);
glVertex2f(xc-20,yc-130);
glVertex2f(xc+60,yc-107);
glVertex2f(xc+70,yc-80);
glVertex2f(xc,yc-80);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(xc+60,yc-70);
glVertex2f(xc+90,yc-72);
glVertex2f(xc+90,yc-130);
glVertex2f(xc+40,yc-110);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc+90,yc-72);
glVertex2f(xc+130,yc-45);
glVertex2f(xc+105,yc-145);
glVertex2f(xc+90,yc-130);
glEnd();

glColor3f(.8,.0,.0);
glBegin(GL_POLYGON);
draw_circle(15,xc+30,yc-90);
glEnd();

glColor3f(0.8,0.8,0.8);
glBegin(GL_TRIANGLE_STRIP); //teeth
glVertex2f(xc-70,yc-45);glVertex2f(xc-68,yc-90);glVertex2f(xc-50,yc-60);
glVertex2f(xc-50,yc-60);glVertex2f(xc-40,yc-95);glVertex2f(xc-30,yc-68);
glVertex2f(xc-30,yc-68);glVertex2f(xc-20,yc-95);glVertex2f(xc-10,yc-70);
glVertex2f(xc-10,yc-70);glVertex2f(xc,yc-95);glVertex2f(xc+10,yc-80);
glVertex2f(xc+10,yc-80);glVertex2f(xc+20,yc-95);glVertex2f(xc+30,yc-80);
glVertex2f(xc+30,yc-80);glVertex2f(xc+40,yc-95);glVertex2f(xc+50,yc-80);
glVertex2f(xc+50,yc-80);glVertex2f(xc+60,yc-105);glVertex2f(xc+70,yc-75);
glVertex2f(xc+70,yc-75);glVertex2f(xc+80,yc-90);glVertex2f(xc+90,yc-63);
glVertex2f(xc+90,yc-63);glVertex2f(xc+100,yc-90);glVertex2f(xc+110,yc-60);
glVertex2f(xc+110,yc-60);glVertex2f(xc+128,yc-90);glVertex2f(xc+130,yc-45);
glEnd();

glBegin(GL_TRIANGLE_STRIP); //teeth
glVertex2f(xc-45,yc-138);glVertex2f(xc-45,yc-110);glVertex2f(xc-30,yc-130);
glVertex2f(xc-30,yc-130);glVertex2f(xc-30,yc-90);glVertex2f(xc-10,yc-115);
glVertex2f(xc-10,yc-115);glVertex2f(xc-5,yc-95);glVertex2f(xc+10,yc-110);
glVertex2f(xc+10,yc-110);glVertex2f(xc+18,yc-95);glVertex2f(xc+30,yc-105);
glVertex2f(xc+30,yc-105);glVertex2f(xc+35,yc-90);glVertex2f(xc+50,yc-110);
glVertex2f(xc+50,yc-110);glVertex2f(xc+55,yc-100);glVertex2f(xc+65,yc-115);
glVertex2f(xc+65,yc-115);glVertex2f(xc+75,yc-100);glVertex2f(xc+85,yc-120);
glVertex2f(xc+85,yc-120);glVertex2f(xc+95,yc-90);glVertex2f(xc+105,yc-136);
glEnd();

glColor3f(.5,0.0,0.0);
circle_smile1(xc+30,yc+60,140);
circle_smile3(xc+30,yc-210,100);
}

void smiley3() //cry
{
glBegin(GL_POLYGON);
glColor3f(R,G,B);
draw_circle(rds,xc,yc);
glEnd();

glBegin(GL_POLYGON); //wht le
glColor3f(1.0,1.0,1.0);
draw_circle(15,xc-60,yc+80);
glEnd();

glBegin(GL_POLYGON); //wht re
glColor3f(1.0,1.0,1.0);
draw_circle(15,xc+60,yc+80);
glEnd();

glBegin(GL_POLYGON); //re
glColor3f(0.0,0.0,0.0);
draw_circle(10,xc+60,yc+78);
glEnd();

glBegin(GL_POLYGON); //le
glColor3f(0.0,0.0,0.0);
draw_circle(10,xc-60,yc+78);
glEnd();


glColor3f(0,0,0);

glBegin(GL_POLYGON); //mout
draw_circle(50,xc,yc-50);
glEnd();

glPointSize(3);

circle_smile3(xc-60,yc+100,20);
circle_smile3(xc+60,yc+100,20);

glBegin(GL_POLYGON); //teet
glColor3f(1,1,1);

glBegin(GL_POLYGON);
glVertex2f(xc-45,yc-22);
glVertex2f(xc-45,yc-35);glVertex2f(xc-35,yc-25);glVertex2f(xc-35,yc-13);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc-33,yc-10);
glVertex2f(xc-33,yc-25);glVertex2f(xc-20,yc-30);glVertex2f(xc-20,yc-3);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc-20,yc);
glVertex2f(xc-18,yc-35);glVertex2f(xc-5,yc-30);glVertex2f(xc-5,yc);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc-3,yc);
glVertex2f(xc-3,yc-25);glVertex2f(xc+10,yc-30);glVertex2f(xc+10,yc);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc+12,yc);
glVertex2f(xc+12,yc-35);glVertex2f(xc+25,yc-25);glVertex2f(xc+25,yc-5);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc+28,yc-8);
glVertex2f(xc+28,yc-25);glVertex2f(xc+38,yc-30);glVertex2f(xc+38,yc-15);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc+40,yc-20);
glVertex2f(xc+40,yc-30);glVertex2f(xc+45,yc-30);glVertex2f(xc+45,yc-28);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc-45,yc-75);
glVertex2f(xc-45,yc-65);glVertex2f(xc-35,yc-62);glVertex2f(xc-35,yc-90);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc-33,yc-90);
glVertex2f(xc-33,yc-75);glVertex2f(xc-20,yc-65);glVertex2f(xc-20,yc-97);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc-20,yc-97);
glVertex2f(xc-18,yc-75);glVertex2f(xc-5,yc-72);glVertex2f(xc-5,yc-100);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc-3,yc-102);
glVertex2f(xc-3,yc-70);glVertex2f(xc+10,yc-70);glVertex2f(xc+10,yc-102);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc+12,yc-100);
glVertex2f(xc+12,yc-75);glVertex2f(xc+25,yc-80);glVertex2f(xc+25,yc-95);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc+28,yc-92);
glVertex2f(xc+28,yc-65);glVertex2f(xc+38,yc-60);glVertex2f(xc+38,yc-83);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc+40,yc-83);
glVertex2f(xc+40,yc-65);glVertex2f(xc+45,yc-60);glVertex2f(xc+45,yc-75);
glEnd();

glColor3f(0.0,0.5,.8); //tear drops
glBegin(GL_POLYGON);
draw_circle(3,xc-65,y+100);
glEnd();

glBegin(GL_POLYGON);
draw_circle(3,xc+65,y+100);
glEnd();

glBegin(GL_POLYGON);
draw_circle(5,xc-65,y+90);
glEnd();

glBegin(GL_POLYGON);
draw_circle(5,xc+65,y+90);
glEnd();

glBegin(GL_POLYGON); //tear drop
draw_circle(10,xc-65,y+70);
glEnd();

glBegin(GL_POLYGON); //tear drop
draw_circle(10,xc+65,y+70);
glEnd();

glBegin(GL_POLYGON); //tear drop
draw_circle(15,xc-65,y+50);
glEnd();

glBegin(GL_POLYGON); //tear drop
draw_circle(15,xc+65,y+50);
glEnd();

glBegin(GL_POLYGON); //tear drop
draw_circle(2,xc-65,y+110);
glEnd();

glBegin(GL_POLYGON); //tear drop
draw_circle(2,xc+65,y+110);
glEnd();

}

void smiley4() //cool
{
draw_face();
glColor3f(.5,.5,.5); //edges of sunglass
glBegin(GL_POLYGON); 
draw_circle(52,xc+65,yc+100);
glEnd();

glBegin(GL_POLYGON);
draw_circle(52,xc-65,yc+100);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc-17,yc+92);
glVertex2f(xc+17,yc+92);
glVertex2f(xc+22,yc+118);
glVertex2f(xc-17,yc+118);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc+113,yc+93);
glVertex2f(xc+113,yc+108);
glVertex2f(xc+173,yc+122);
glVertex2f(xc+173,yc+115);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc-113,yc+103);
glVertex2f(xc-113,yc+110);
glVertex2f(xc-173,yc+130);
glVertex2f(xc-173,yc+122);
glEnd();

glColor3f(0.0,0.0,0.0); //sunglass

glBegin(GL_POLYGON);
glVertex2f(xc-15,yc+95);
glVertex2f(xc+15,yc+95);
glVertex2f(xc+20,yc+115);
glVertex2f(xc-20,yc+115);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc+115,yc+95);
glVertex2f(xc+115,yc+105);
glVertex2f(xc+175,yc+120);
glVertex2f(xc+175,yc+115);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc-115,yc+105);
glVertex2f(xc-115,yc+115);
glVertex2f(xc-175,yc+130);
glVertex2f(xc-175,yc+125);
glEnd();

glColor3f(.0,.0,.0); //sunglass
glBegin(GL_POLYGON);
draw_circle(50,xc-65,yc+100);
glEnd();

glBegin(GL_POLYGON);
draw_circle(50,xc+65,yc+100);
glEnd();

glColor3f(0.0,0.0,0.0); //fill b
glBegin(GL_POLYGON);
glVertex2f(xc-95,yc-40);
glVertex2f(xc+95,yc-40);
glVertex2f(xc+55,yc-100);
glVertex2f(xc+15,yc-130);
glVertex2f(xc-15,yc-130);
glVertex2f(xc-55,yc-100);
glEnd();

glColor3f(0.8,0.0,0.0); //red ton
glBegin(GL_POLYGON);
draw_circle(30,xc,yc-60);
glEnd();

glColor3f(1.0,1.0,1.0); //teet
glBegin(GL_POLYGON);
glVertex2f(xc-90,yc-40);
glVertex2f(xc-60,yc-40);
glVertex2f(xc-60,yc-60);
glVertex2f(xc-90,yc-60);
glEnd();

glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(xc-50,yc-100);
glVertex2f(xc-10,yc-100);
glVertex2f(xc-10,yc-130);
glVertex2f(xc-30,yc-130);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc-9,yc-100);
glVertex2f(xc+20,yc-100);
glVertex2f(xc+20,yc-130);
glVertex2f(xc-9,yc-130);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc+21,yc-100);
glVertex2f(xc+50,yc-100);
glVertex2f(xc+30,yc-130);
glVertex2f(xc+21,yc-130);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc-59,yc-40);
glVertex2f(xc-30,yc-40);
glVertex2f(xc-30,yc-60);
glVertex2f(xc-59,yc-60);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc-29,yc-40);
glVertex2f(xc,yc-40);
glVertex2f(xc,yc-60);
glVertex2f(xc-29,yc-60);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc+1,yc-40);
glVertex2f(xc+30,yc-40);
glVertex2f(xc+30,yc-60);
glVertex2f(xc+1,yc-60);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc+31,yc-40);
glVertex2f(xc+60,yc-40);
glVertex2f(xc+60,yc-60);
glVertex2f(xc+31,yc-60);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(xc+61,yc-40);
glVertex2f(xc+90,yc-40);
glVertex2f(xc+90,yc-60);
glVertex2f(xc+61,yc-60);
glEnd();

glColor3f(0.8,0.0,0.0); //lips
glBegin(GL_POLYGON);
glVertex2f(xc-100,yc-30);
glVertex2f(xc+100,yc-30);
glVertex2f(xc+100,yc-40);
glVertex2f(xc-100,yc-40);
glEnd();

glPointSize(10);
glColor3f(0.8,0.0,0.0);
circle_smile2(xc,yc+60,190);
}

void smiley5() //sad
{
draw_face();
glColor3f(0.0,0.0,0.0);
circle_smile3(xc,yc-160,120);
}

void display(void)  //to call initial smile
{
glClearColor(0.0,0.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT);
draw_face();
initial();
circles();
glColor3f(1.0,1.0,0.0);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
drawstring(xp-5,yp+595,"S");
drawstring(xp+40,yp+595,"I");
drawstring(xp+85,yp+595,"M");
drawstring(xp+130,yp+595,"P");
drawstring(xp+175,yp+595,"L");
drawstring(xp+220,yp+595,"E");

glColor3f(0.0,0.0,0.0); //to fill unwaned circles
glBegin(GL_POLYGON);
draw_circle(20,xp+270,yp+600);
glEnd();
glutIdleFunc(idle1); //to mov text
glFlush();
}

void display1(void) //laugh
{
glClearColor(0.0,0.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT);
smiley1();
circles();
glColor3f(1.0,1.0,1.0);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
drawstring(xp-5,yp+595,"L");
drawstring(xp+40,yp+595,"A");
drawstring(xp+85,yp+595,"G");
drawstring(xp+130,yp+595,"H");
drawstring(xp+175,yp+595,"T");
drawstring(xp+220,yp+595,"E");
drawstring(xp+265,yp+595,"R");
glutIdleFunc(idle1);
glFlush();
}

void display2(void) //angry
{
glClearColor(0.0,0.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT);
smiley2();
circles();
glColor3f(1.0,1.0,1.0);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
drawstring(xp+40,yp+595,"A");
drawstring(xp+85,yp+595,"N");
drawstring(xp+130,yp+595,"G");
drawstring(xp+175,yp+595,"R");
drawstring(xp+220,yp+595,"Y");
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
draw_circle(20,xp,yp+600);
glEnd();
glBegin(GL_POLYGON);
draw_circle(20,xp+270,yp+600);
glEnd();

glutIdleFunc(idle1);
glFlush();
}

void display3() //cry
{
glClearColor(0.0,0.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT);
smiley3();
circles();
glColor3f(1.0,1.0,1.0);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
drawstring(xp-5,yp+595,"C");
drawstring(xp+40,yp+595,"R");
drawstring(xp+85,yp+595,"Y");
drawstring(xp+130,yp+595,"I");
drawstring(xp+175,yp+595,"N");
drawstring(xp+220,yp+595,"G");
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
draw_circle(20,xp+270,yp+600);
glEnd();
idle();
idle1();
glFlush();
}

void display4(void) //cool
{
glClearColor(0.0,0.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT);
smiley4();
circles();
glColor3f(1.0,1.0,1.0);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
drawstring(xp-5,yp+595,"C");
drawstring(xp+40,yp+595,"O");
drawstring(xp+85,yp+595,"O");
drawstring(xp+130,yp+595,"O");
drawstring(xp+175,yp+595,"O");
drawstring(xp+220,yp+595,"L");
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
draw_circle(20,xp,yp+600);
glEnd();
glBegin(GL_POLYGON);
draw_circle(20,xp+270,yp+600);
glEnd();
glutIdleFunc(idle1);
glFlush();
}

void display5(void) //sad
{
glClearColor(0.0,0.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT);
smiley5();
circles();
glColor3f(1.0,1.0,1.0);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
drawstring(xp+85,yp+595,"S");
drawstring(xp+130,yp+595,"A");
drawstring(xp+175,yp+595,"D");
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
draw_circle(20,xp,yp+600);
glEnd();
glBegin(GL_POLYGON);
draw_circle(20,xp+45,yp+600);
glEnd();
glBegin(GL_POLYGON);
draw_circle(20,xp+270,yp+600);
glEnd();
glBegin(GL_POLYGON);
draw_circle(20,xp+225,yp+600);
glEnd();
glutIdleFunc(idle1);
glFlush();
}

void menu(int a)
{
switch(a)
{
case 1:glutDisplayFunc(display);
glutPostRedisplay();
break;

case 2:glutDisplayFunc(display1);
glutPostRedisplay();
break;

case 3:glutDisplayFunc(display2);
glutPostRedisplay();
break;

case 4:glutDisplayFunc(display3);
glutPostRedisplay();
break;

case 5:glutDisplayFunc(display4);
glutPostRedisplay();
break;

case 6:glutDisplayFunc(display5);
glutPostRedisplay();
break;

case 7:exit(0);
}
}

void keyboard(unsigned char key,int x,int y)
{
switch(key)
{
case'i':glutDisplayFunc(instructions);
break;

case'c':glutDisplayFunc(display);
break;

case'a':R=1.0,G=1.0,B=0.0;
break;

case's':R=1.0,G=1.0,B=0.3;
break;

case'd':R=0.0,G=1.0,B=0.3;
break;

case'f':R=0.0,G=0.0,B=1.0;
break;

case'g':R=1.0,G=0.3,B=0.1;
break;

case'h':R=1.0,G=0.3,B=0.8;
break;

case'j':R=0.4,G=0.2,B=0.6;
break;

case'k':R=0.8,G=0.5,B=0.3;
break;

case'l':R=0.5,G=0.855,B=0.5553;
break;

case'z':

xc=5;
if(xc<200)
xc=700;
glutPostRedisplay();
break;

case'x':xc+=5;
if(xc>700)
xc=200;
glutPostRedisplay();
break;
}
glutPostRedisplay();
}

void main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(900,700);
glutInitWindowPosition(200,0);
glutCreateWindow("SMILEYS");
glutDisplayFunc(startScreen);
glutKeyboardFunc(keyboard);

myinit();
glutCreateMenu(menu);
glutAddMenuEntry("smile",1);
glutAddMenuEntry("laugh",2);
glutAddMenuEntry("angry",3);
glutAddMenuEntry("cry",4);
glutAddMenuEntry("happy and cool",5);
glutAddMenuEntry("sad",6);
glutAddMenuEntry("quit",7);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutMainLoop();
}

