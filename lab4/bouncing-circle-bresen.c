#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

int  xc=0;
int yc=0;
int r=50;
int refreshMillis=10;

int ballXMax=780, ballXMin=-780, ballYMax=420, ballYMin=-420; // Ball's center (x, y) bounds

int xSpeed = 75;      // Ball's speed in x and y directions
int ySpeed = 25;



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
void bresenCircle(int c1,int c2)
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

   bresenCircle(xc,yc);

   glFlush();

   xc += xSpeed;
   yc += ySpeed;
   // Check if the ball exceeds the edges
   if (xc+r > ballXMax) {
      xc = ballXMax-r;
      xSpeed = -xSpeed;
   } else if (xc-r< ballXMin) {
      xc = ballXMin+r;
      xSpeed = -xSpeed;
   }
   if (yc+r > ballYMax) {
      yc = ballYMax-r;
      ySpeed = -ySpeed;
   } else if (yc-r < ballYMin) {
      yc = ballYMin+r;
      ySpeed = -ySpeed;
   }
} 
void Timer(int value) {
   glutPostRedisplay();    // Post a paint request to activate display()
   glutTimerFunc(refreshMillis, Timer, 0); // subsequent timer call at milliseconds
}

int main (int argc, char** argv) 
{ 
   //  printf("Enter the value of xc : ");
   // scanf("%d",&xc);
   // printf("Enter the value of yc : ");
   // scanf("%d",&yc);
   // printf("Enter the Radius R : ");
   // scanf("%d",&r);


   glutInit(&argc, argv); 
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
   
   // giving window size in X- and Y- direction 
   glutInitWindowSize(1366, 768); 
   glutInitWindowPosition(0, 0); 
   
   // Giving name to window 
   glutCreateWindow("Circle Drawing"); 
   myInit(); 
   
   glutDisplayFunc(display);
   glutTimerFunc(0, Timer, 0); 
   glutMainLoop(); 
} 
   