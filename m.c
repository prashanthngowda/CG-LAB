#include<GL/glut.h>

void display()
{

glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_LINE_LOOP);
glVertex2i(10,10);
glVertex2i(50,100);
glVertex2i(100,10);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2i(27,50);
glVertex2i(78,50);
glVertex2i(50,10);
glEnd();

glFlush();
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(200,100);
glutInitWindowSize(500,250);
glutCreateWindow("atme");
glClearColor(1.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,500.0,0.0,500.0);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
