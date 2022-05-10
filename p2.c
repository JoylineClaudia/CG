#include<stdio.h>
#include<GL/glut.h>
float h=0.0,k=0.0,theta;
int choice;
void myInit();
void rotate_orign();
void rotate_fixed_point();
void draw_triangle();
void display_about_orign();
void display_about_fixed_point();

void rotate_orign()
{
	glRotatef(theta,0,0,1);
}
void rotate_fixed_point()
{
	glTranslatef(h,k,0);
	glRotatef(theta,0,0,1);
	glTranslatef(-h,-k,1);
}
void draw_triangle()
{
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(100,100);
	glVertex2f(400,100);
	glVertex2f(250,350);
	glEnd();
}
void display_about_orign()
{
	draw_triangle();
	rotate_orign();
	draw_triangle();
	glLoadIdentity();
	glFlush();
}
void display_about_fixed_point()
{
	draw_triangle();
	rotate_fixed_point();
	draw_triangle();
	glLoadIdentity();
	glFlush();
}
void myInit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500.0,500.0,-500.0,500.0);
	glMatrixMode(GL_MODELVIEW);
}
void main(int argc,char * argv[])
{
	printf("Enter your Choice : 1 -> Rotate about orign \n");
	printf("Enter your Choice : 2 -> Rotate about fixed point \n");
	scanf("%d",&choice);
	printf("Enter the rotation angle \n");
	scanf("%f",&theta);
	glutInit(&argc,argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	if(choice==1)
	{
		glutCreateWindow("Rotation of triangle w.r.t. orign ");
		glutDisplayFunc(display_about_orign);
	}
	else if(choice==2)
	{
		printf("Enter the pivot (x,y) point \n");
		scanf("%f%f",&h,&k);
		glutCreateWindow("Rotation of triangle w.r.t. fixed point");
		glutDisplayFunc(display_about_fixed_point);
	}
	else
		printf("Wrong Choice \n");
	myInit();
	glutMainLoop();
}
