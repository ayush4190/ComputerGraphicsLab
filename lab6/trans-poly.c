
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

float xa,ya,xb,yb,xc,yc;
float tx,ty;
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
   glBegin(GL_POLYGON);
   glVertex2f(xa, ya); 
   glVertex2f(xb, yb); 
   glVertex2f(xc,yc); 
   glEnd();
   glBegin(GL_POLYGON);
   glVertex2f(xa+tx, ya+ty); 
   glVertex2f(xb+tx, yb+ty); 
   glVertex2f(xc+tx,yc+ty); 
   glEnd();
   glFlush();

} 

int main (int argc, char** argv) 
{ 

    printf("Enter x1,y1 for triangle\n");
    scanf("%f %f",&xa,&ya);
    printf("Enter x2,y2\n");
    scanf("%f %f",&xb,&yb);
    printf("Enter x2,y2\n");
    scanf("%f %f",&xc,&yc);
    printf("Enter tx,ty\n");
    scanf("%f %f",&tx,&ty);
   glutInit(&argc, argv); 
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
   
   // giving window size in X- and Y- direction 
   glutInitWindowSize(1366, 768); 
   glutInitWindowPosition(0, 0); 
   
   // Giving name to window 
   glutCreateWindow("Chess Board"); 
   myInit(); 
   
   glutDisplayFunc(display); 
   glutMainLoop(); 
} 
  