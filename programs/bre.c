// bresenham's algorithm 

#include<GL/glut.h>
#include<stdio.h>
int x_1 ,x_2 , y_1,y_2 ;
void bresenham() 
{ 
int m_new = 2 * (y_2 - y_1); 
int slope_error_new = m_new - (x_2 - x_1); 
glBegin(GL_POINTS);
for (int x = x_1, y = y_1; x <= x_2; x++) 
{ 

glVertex2i(x,y);

	slope_error_new += m_new; 

	 
	if (slope_error_new >= 0) 
	{ 
		y++; 
		slope_error_new -= 2 * (x_2 - x_1); 
	} 
} 
glEnd();
glFlush();
} 


void init(void)
{
glClearColor(0.0,0.0,0.0,1.0);
glColor3f(1.0, 1.0, 1.0); 
glPointSize(1.0);

glLoadIdentity();

 gluOrtho2D(-78, 78, -78,78); 
}
 
 
int main(int argc, char** argv) 
{ 
    x_1 = -10;
    x_2 =2 ;
    y_1 = 10 ;
    y_2 = 10;
glutInit(&argc, argv);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("bre Line Algo");
init();
glutDisplayFunc(bresenham);
glutMainLoop(); 
return 0; 
} 
