// 8*8 chess board


#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

int xa,ya,xb,yb,xc,yc,s;
// float angle;

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
   glBegin(GL_LINES);
   glVertex2f(xa, ya); 
   glVertex2f(xb, yb);
   glVertex2f(xb, yb);
   glVertex2f(xc, yc);
   glVertex2f(xc, yc);
   glVertex2f(xa, ya);   
   glEnd();
   glBegin(GL_LINES);
    glVertex2f(-xa, ya); 
   glVertex2f(-xb, yb);
   glVertex2f(-xb, yb);
   glVertex2f(-xc, yc);
   glVertex2f(-xc, yc);
   glVertex2f(-xa, ya);  
   glEnd();
   glFlush();

} 

int main (int argc, char** argv) 
{ 

    printf("Enter x1,y1\n");
    scanf("%d %d",&xa,&ya);
    printf("Enter x2,y2\n");
    scanf("%d %d",&xb,&yb);
    printf("Enter x3,y3\n");
    scanf("%d %d",&xc,&yc);
    // printf("Enter s\n");
    // scanf("%d",&s);
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
  