#include<stdio.h>
#include<GL/glut.h>
void myInit()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,200.0,0.0,200.0);
}
void lineSegment()
{
	glBegin(GL_LINES);
	glVertex2i(25,200);
	glVertex2i(25,190);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glVertex2i(25,200);
	glVertex2i(25,190);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glVertex2i(25,100);
	glVertex2i(65,160);
	glVertex2i(100,100);
	glEnd();
	glColor3f(0.8,0.1,0.1);
	glBegin(GL_LINE_LOOP);
	glVertex2i(100,15);
	glVertex2i(25,15);
	glVertex2i(25,100);
	glVertex2i(100,100);
	glEnd();
	glColor3f(0.2,0.6,0.4);
	glBegin(GL_LINE_LOOP);
	glVertex2i(100,100);
	glVertex2i(180,110);
	glVertex2i(180,25);
	glVertex2i(100,15);
	glEnd();
	glColor3f(0.6,0.1,0.5);
	glBegin(GL_LINE_STRIP);
	glVertex2i(65,160);
	glVertex2i(150,165);
	glVertex2i(180,110);
	glEnd();

	glFlush();
}
void main(int argc, char * argv[])
{
	printf("Name : Joyline \nUSN : 4MT20CS400 \n");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Displaying a line");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	myInit();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
}
