#include<stdio.h>
#include<GL/glut.h>
void myInit();
void draw_pixel(int ,int);
void draw_line(int ,int , int , int);
void myDisplay();
int x1, Y1,x2, y2;
void myInit()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,700.0,0.0,700.0);
}
void main(int argc,char * argv[])
{
	printf("Enter the 2 end points of line \n");
	scanf("%d %d %d %d",&x1,&Y1,&x2,&y2);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(700,700);
	glutCreateWindow("Bresenhem's Line Dreawing Algorithm");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}


void draw_line(int x1,int x2, int y1, int y2)
{
	int x, y, dx, dy,i,e,inc1,inc2;
	int incx=1,incy=1;
	dx= x2-x1;
	dy= y2-y1;
	x=x1;
	y=y1;
	if(dx < 0) dx = -dx;
	if(dy < 0) dy = -dy;
	if(x2 < x1) incx = -1;
	if(y2 < y1) incy = -1;
	if(dx > dy)
	{
		draw_pixel(x,y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for(i=0;i<dx;i++)
		{
			if(e >= 0)
			{
				y = y+ incy;
				e = e+ inc1;
			}
			else
			{
				e += inc2;
			}
			x += incx;
			draw_pixel(x,y);
		}
		}
		else
		{
		draw_pixel(x,y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for(i=0;i<dy;i++)
		{
			if(e >= 0)
			{
				x += incx;
				e +=inc1;
			}
			else
			{
				e += inc2;
			}
			y += incy;
			draw_pixel(x,y);
		}
	}
}
void draw_pixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
void myDisplay()
{
	draw_line(x1,x2,Y1,y2);
	glFlush();
}
	
