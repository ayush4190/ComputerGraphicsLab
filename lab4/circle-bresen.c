#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

int  xc,yc,r;

void myInit (void) 
{ 
   glClearColor(0.0, 0.0, 0.0, 1.0); 
   glColor3f(0.0, 1.0, 0.0); 
   glPointSize(1.0); 
   glMatrixMode(GL_PROJECTION); 
   glLoadIdentity(); 
   gluOrtho2D(-780, 780, -420, 420); 
} 

void drawCircle(int xc, int yc, int x, int y) 
{ 
   
   glBegin(GL_POINTS);
   glVertex2i(xc+x, yc+y); 
   glVertex2i(xc-x, yc+y); 
   glVertex2i(xc+x, yc-y); 
   glVertex2i(xc-x, yc-y); 
   glVertex2i(xc+y, yc+x); 
   glVertex2i(xc-y, yc+x); 
   glVertex2i(xc+y, yc-x); 
   glVertex2i(xc-y, yc-x); 
   glEnd();
} 

void display (void) 
{ 
   glClear(GL_COLOR_BUFFER_BIT); 

   int x = 0, y = r; 
   int d = 3 - 2 * r; 
   drawCircle(xc, yc, x, y); 
   while (y >= x) 
   { 
      x++; 
      if (d > 0) 
      { 
         y--; 
         d = d + 4 * (x - y) + 10; 
      } 
      else
         d = d + 4 * x + 6; 
      drawCircle(xc, yc, x, y); 
      // delay(50); 
   } 

   glFlush(); 
} 

int main (int argc, char** argv) 
{ 
    printf("Enter the value of xc : ");
   scanf("%d",&xc);
   printf("Enter the value of yc : ");
   scanf("%d",&yc);
   printf("Enter the Radius R : ");
   scanf("%d",&r);


   glutInit(&argc, argv); 
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
   
   // giving window size in X- and Y- direction 
   glutInitWindowSize(1366, 768); 
   glutInitWindowPosition(0, 0); 
   
   // Giving name to window 
   glutCreateWindow("Circle Drawing"); 
   myInit(); 
   
   glutDisplayFunc(display); 
   glutMainLoop(); 
} 
   