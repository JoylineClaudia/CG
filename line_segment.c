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
	glVertex2i(180,15);
	glVertex2i(10,145);
	glEnd();
	glFlush();
}
void main(int argc,char * argv[])
{
	printf("Name : Joyline \nUSN : 4MT20CS400 \n");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Line 	Segment");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	myInit();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
}
