
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

float angle = 0;
int ylocation = 0;
int xc = 220, yc = 240;
int xc1 = 500 , yc1 = 240 ;

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void plot_point(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(xc+x, yc+y);
  glVertex2i(xc+x, yc-y);
  glVertex2i(xc+y, yc+x);
  glVertex2i(xc+y, yc-x);
  glVertex2i(xc-x, yc-y);
  glVertex2i(xc-y, yc-x);
  glVertex2i(xc-x, yc+y);
  glVertex2i(xc-y, yc+x);
  glEnd();
}
void plot_point2(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(xc1+x, yc1+y);
  glVertex2i(xc1+x, yc1-y);
  glVertex2i(xc1+y, yc1+x);
  glVertex2i(xc1+y, yc1-x);
  glVertex2i(xc1-x, yc1-y);
  glVertex2i(xc1-y, yc1-x);
  glVertex2i(xc1-x, yc1+y);
  glVertex2i(xc1-y, yc1+x);
  glEnd();
}

void bresenham_circle(int r)
{
  int x=0,y=r;
float pk = 3 -(2*r);

  plot_point(x,y);
  int k;
  /* Find all vertices till x=y */
  while(x < y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + 2*x+1;
    else
    {
      y = y - 1;
      pk = pk + 2*(x - y) + 1;
    }
    plot_point(x,y);
  }
  glFlush();
}

void bresenham_circle2(int r)
{
  int x=0,y=r;
float pk = 3 -(2*r);

  plot_point(x,y);
  int k;
  /* Find all vertices till x=y */
  while(x < y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + 2*x+1;
    else
    {
      y = y - 1;
      pk = pk + 2*(x - y) + 1;
    }
    plot_point2(x,y);
  }
  glFlush();
}

 void line(int r)
 {

   int y_2 , y_1 , x_1 , x_2 ;
   y_1 = 140 , y_2 =140 ;
   x_1 = 0 ; x_2 = 2000 ;
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

 void spokes(int x1, int x2, int y_1, int y2) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y_1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y_1) incy = -1;
	x = x1; y = y_1;
	x = x1; y = y_1;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_pixel(x, y);
		}
	}
   glFlush();
}

void concentric_circles(void)
{
 
  glClear(GL_COLOR_BUFFER_BIT);

  int radius1 = 100 , radius2 = 25;
   int temp1 = radius1/(sqrt(2));
   int temp2 = radius2/(sqrt(2));

   
 
   glPushMatrix();
    glTranslatef(ylocation,0,0);
   glTranslatef(220,240,0);
  
	//rotate (x-axis,y axis,z axis)
	glRotatef(angle,0,0,1);
 
	//bring back the center point to the origin
	glTranslatef(-220,-240,0);
    bresenham_circle(radius1);
   bresenham_circle(radius2);
   spokes(220, 220 ,340  , 265);
    spokes(220, 220 ,140  , 215);
     spokes(320, 245 ,240  , 240);
      spokes(120, 195 ,240  , 240);
       spokes(220+temp1, 220+temp2 ,240+temp1  , 240 + temp2);
        spokes(220-temp1, 220 - temp2 ,240 -temp1  , 240 -temp2);
         spokes(220 -temp1, 220 - temp2 ,240 + temp1  , 240 +temp2);
          spokes(220 + temp1, 220 + temp2 ,240 - temp1  , 240 - temp2);
          glPopMatrix();

          
          

// 2 wheels 

 glPushMatrix();
 glTranslatef(ylocation,0,0);
   glTranslatef(500,240,0);
	//rotate (x-axis,y axis,z axis)
  
	glRotatef(angle,0,0,1);

	//bring back the center point to the origin
	glTranslatef(-500,-240,0);
    bresenham_circle2(radius1);
   bresenham_circle2(radius2);
   spokes(500, 500 ,340  , 265);
    spokes(500, 500 ,140  , 215);
     spokes(600, 525 ,240  , 240);
      spokes(400, 475 ,240  , 240);
       spokes(500+temp1, 500+temp2 ,240+temp1  , 240 + temp2);
        spokes(500-temp1, 500 - temp2 ,240 -temp1  , 240 -temp2);
         spokes(500 -temp1, 500 - temp2 ,240 + temp1  , 240 +temp2);
          spokes(500 + temp1, 500 + temp2 ,240 - temp1  , 240 - temp2);
          glPopMatrix();





   line(radius1);

   
}

void rotate()
{

angle+=2.0;
int b=1;

if(angle>360.)
{
angle-=360;
}
if(ylocation >= 100)
b = 1;
else if(ylocation <= -100)
{
  b = 0;
}



if(b == 0)
{
ylocation++;
}
else
{
  ylocation--;
}




glutPostRedisplay();
glutTimerFunc(25,rotate,0);

}

void Init()
{
  
  glClearColor(0.0,0.0,0.0,0);
  
  glColor3f(1.0,1.0,1.0);
  
  gluOrtho2D(0 , 640 , 0 , 480);
}

void main(int argc, char **argv)
{
 
  glutInit(&argc,argv);
  
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  
  glutCreateWindow("bresenham_circle");
 
  Init();

  glutDisplayFunc(concentric_circles);
  glutTimerFunc(25, rotate,0);
  
  glutMainLoop();
}

