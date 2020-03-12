// 8*8 chess board


#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

int xc,yc,R;
float s;
void myInit (void) 
{ 
   glClearColor(0.0, 0.0, 0.0, 1.0); 
   glColor3f(0.0, 1.0, 0.0); 
   glPointSize(1.0); 
   glMatrixMode(GL_PROJECTION); 
   glLoadIdentity(); 
   gluOrtho2D(-780, 780, -420, 420); 
} 

void drawCircle(int c1, int c2, int x, int y) 
{ 
   
   glBegin(GL_POINTS);
   glVertex2i(c1+x, c2+y); 
   glVertex2i(c1-x, c2+y); 
   glVertex2i(c1+x, c2-y); 
   glVertex2i(c1-x, c2-y); 
   glVertex2i(c1+y, c2+x); 
   glVertex2i(c1-y, c2+x); 
   glVertex2i(c1+y, c2-x); 
   glVertex2i(c1-y, c2-x); 
   glEnd();
} 
void bresenCircle(int c1,int c2,int r)
{
   int x = 0, y = r; 
   int d = 3 - 2 * r; 
   drawCircle(c1, c2, x, y); 
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
      drawCircle(c1, c2, x, y); 
      // delay(50); 
   } 
}
void display (void) 
{ 
   glClear(GL_COLOR_BUFFER_BIT); 
   bresenCircle(xc,yc,R);
   bresenCircle(xc,yc,R*s);
   glFlush();

} 

int main (int argc, char** argv) 
{ 

    printf("Enter xc,yc\n");
    scanf("%d %d",&xc,&yc);
    printf("Enter r\n");
    scanf("%d",&R);
    printf("Enter s\n");
    scanf("%f",&s);
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
