#include <stdio.h>
#include <GL/glut.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float v[4][3]={{0,0,1},{0,1,0},{-1,-0.5,0},{1,-0.5,0}};
float colors[4][3]={{0,0,1},{1,1,0},{1,0.5,0},{1,0.5,1}};
int n;

void triangle(float *va,float *vb,float *vc)
{
	glVertex3fv(va);
	glVertex3fv(vb);
	glVertex3fv(vc);
}

void tetra(float *a,float *b,float *c,float *d)
{
	glColor3fv(colors[0]);
	triangle(a,b,c);
	glColor3fv(colors[1]);
	triangle(a,b,d);
	glColor3fv(colors[2]);
	triangle(a,c,d);
	glColor3fv(colors[3]);
	triangle(b,c,d);
}

void divide_tetra(float *a,float *b,float *c,float *d,int m)
{
	float mid[6][3];
	if(m>0)
	{
		for(int j=0;j<3;j++)
			mid[0][j]=(a[j]+b[j])/2;
		for(int j=0;j<3;j++)
			mid[1][j]=(a[j]+c[j])/2;
		for(int j=0;j<3;j++)
			mid[2][j]=(a[j]+d[j])/2;
		for(int j=0;j<3;j++)
			mid[3][j]=(b[j]+c[j])/2;
		for(int j=0;j<3;j++)
			mid[4][j]=(c[j]+d[j])/2;
		for(int j=0;j<3;j++)
			mid[5][j]=(b[j]+d[j])/2;
		divide_tetra(a,mid[0],mid[1],mid[2],m-1);
		divide_tetra(mid[0],b,mid[3],mid[5],m-1);
		divide_tetra(mid[1],mid[3],c,mid[4],m-1);
		divide_tetra(mid[2],mid[5],mid[4],d,m-1);
	}
	else
	{
		tetra(a,b,c,d);
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	divide_tetra(v[0],v[1],v[2],v[3],n);
	glEnd();
	glFlush();
}

void myReshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
	{
		glOrtho(-2,2,-2*(GLfloat)h/(GLfloat)w,2*(GLfloat)h/(GLfloat)w,-2,2);
	}
	else
	{
		glOrtho(-2*(GLfloat)w/(GLfloat)h,2*(GLfloat)w/(GLfloat)h,-2,2,-2,2);
	}
}
int main(int argc, char** argv) {
	printf("Enter the number");
	scanf("%d",&n);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("Tetrahedron");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
