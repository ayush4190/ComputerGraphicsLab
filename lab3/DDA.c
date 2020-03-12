
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

float X1,Y1,X2,Y2;

void myInit (void) 
{ 
   glClearColor(0.0, 0.0, 0.0, 1.0); 
   glColor3f(0.0, 1.0, 0.0); 
   glPointSize(1.0); 
   glMatrixMode(GL_PROJECTION); 
   glLoadIdentity(); 
   gluOrtho2D(-780, 780, -420, 420); 
} 

void display (void) 
{ 
   glClear(GL_COLOR_BUFFER_BIT); 

   float dy,dx,step,x,y,k,Xin,Yin;
   dx=X2-X1;
   dy=Y2-Y1;
    
   if(abs(dx)> abs(dy))
   {
   step = abs(dx);
   }
   else
   step = abs(dy);
    
   Xin = dx/step;
   Yin = dy/step;
    
   x= X1;
   y=Y1;
   glBegin(GL_POINTS);
   glVertex2i(x,y);
   glEnd();
    
   for (k=1 ;k<=step;k++)
   {
      x= x + Xin;
      y= y + Yin;
       
      glBegin(GL_POINTS);
      glVertex2i(x,y);
      glEnd();
   }
 
   glFlush(); 
} 

int main (int argc, char** argv) 
{ 
    printf("Enter the value of x1 : ");
   scanf("%f",&X1);
   printf("Enter the value of y1 : ");
   scanf("%f",&Y1);
   printf("Enter the value of x2 : ");
   scanf("%f",&X2);
   printf("Enter the value of y2 : ");
   scanf("%f",&Y2);

   glutInit(&argc, argv); 
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
   
   // giving window size in X- and Y- direction 
   glutInitWindowSize(1366, 768); 
   glutInitWindowPosition(0, 0); 
   
   // Giving name to window 
   glutCreateWindow("Line Drawing"); 
   myInit(); 
   
   glutDisplayFunc(display); 
   glutMainLoop(); 
} 
   