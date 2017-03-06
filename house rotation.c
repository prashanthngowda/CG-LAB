#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
GLfloat house[3][9]={{250,250,300,350,350,275,275,325,325},{250,400,450,400,250,250,325,325,250},{1,1,1,1,1,1,1,1,1}};
GLfloat rot_mat[3][3]={{0},{0},{0}};
GLfloat result[3][9]={{0},{0},{0}};
GLfloat h=250.0;
GLfloat k=250.0;
GLfloat theta,rad;
void multiply()
{
int i,j,l;
for(i=0;i<3;i++)
for(j=0;j<9;j++)
{
result[i][j]=0;
for(l=0;l<3;l++)
result[i][j]=result[i][j]+rot_mat[i][l]*house[l][j];
}
}
void rotate()
{
GLfloat m,n;
m=-h*(cos(theta)-1)+k*(sin(theta));
n=-k*(cos(theta)-1)-h*(sin(theta));
rot_mat[0][0]=cos(theta);
rot_mat[0][1]=-sin(theta);
rot_mat[0][2]=m;
rot_mat[1][0]=sin(theta);
rot_mat[1][1]=cos(theta);
rot_mat[1][2]=n;
rot_mat[2][0]=0;
rot_mat[2][1]=0;
rot_mat[2][2]=1;
multiply();
}
void drawhouse(GLfloat mat[3][9])
{
glBegin(GL_LINE_LOOP);
glColor3f(1,0,0);
glVertex2f(mat[0][0],mat[1][0]);
glVertex2f(mat[0][1],mat[1][1]);
glVertex2f(mat[0][3],mat[1][3]);
glVertex2f(mat[0][4],mat[1][4]);
glEnd();
glBegin(GL_LINE_LOOP);
glColor3f(0,1,0);
glVertex2f(mat[0][5],mat[1][5]);
glVertex2f(mat[0][6],mat[1][6]);
glVertex2f(mat[0][7],mat[1][7]);
glVertex2f(mat[0][8],mat[1][8]);
glEnd();
glBegin(GL_LINE_LOOP);
glColor3f(0,0,1);
glVertex2f(mat[0][1],mat[1][1]);
glVertex2f(mat[0][2],mat[1][2]);
glVertex2f(mat[0][3],mat[1][3]);
glEnd();
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
theta=rad;
drawhouse(house);
rotate();
drawhouse(result);
glFlush();
}
int main(int argc,char **argv)
{
printf("\n enter the rotation angle:");
scanf("%f",&theta);
rad=theta *(3.14/180.0);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(500,500);
glutCreateWindow("house rotation");
glClearColor(1,0.5,0.3,1);
gluOrtho2D(0.0,499.0,0.0,499.0);
glutDisplayFunc(display);
glutMainLoop();
}
