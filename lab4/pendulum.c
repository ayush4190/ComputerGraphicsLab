#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

int r;

void myInit (void) 
{ 
   glClearColor(0.0, 0.0, 0.0, 1.0); 
   glColor3f(0.0, 1.0, 0.0); 
   glPointSize(1.0); 
   // glMatrixMode(GL_PROJECTION); 
   // glLoadIdentity(); 
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
void bresenLine1(int X1,int Y1,int X2,int Y2 )
{
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
 
}
void bresenLine(int X1,int Y1,int X2,int Y2)
{
       //calculating range for line between start and end point
    int dx = X2 - X1;
    int dy = Y2 - Y1;

    int x = X1;
    int y = Y1;

    //this is the case when slope(m) < 1
    if(abs(dx) > abs(dy))
    {
      glBegin(GL_POINTS);
      glVertex2i(x,y);
      glEnd();
        int pk = (2 * abs(dy)) - abs(dx);
         int i;
        for( i = 0; i < abs(dx) ; i++)
        {
            x = x + 1;
            if(pk < 0)
                pk = pk + (2 * abs(dy));
            else
            {
                y = y + 1;
                pk = pk + (2 * abs(dy)) - (2 * abs(dx));
            }
            glBegin(GL_POINTS);
            glVertex2i(x,y);
            glEnd();
        }
        // delay(30);
    }
    else
    {
        //this is the case when slope is greater than or equal to 1  i.e: m>=1
         glBegin(GL_POINTS);
         glVertex2i(x,y);
         glEnd();
        int pk = (2 * abs(dx)) - abs(dy);
         int i;
        for( i= 0; i < abs(dy) ; i++)
        {
            y = y + 1;
            if(pk < 0)
                pk = pk + (2 * abs(dx));
            else
            {
                x = x + 1;
                pk = pk + (2 * abs(dx)) - (2 *abs(dy));
            }

            glBegin(GL_POINTS);
            glVertex2i(x,y);
            glEnd();    // display pixel at coordinate (x, y)
            // delay(10);
        }

        // delay(30);
    }

}
void bresenCircle(int xc,int yc,int r)
{
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
}
void display (void) 
{ 
   glClear(GL_COLOR_BUFFER_BIT); 
   bresenCircle(0,0,r);
    bresenCircle(50,0,r);
     bresenCircle(-50,0,r);
   bresenLine(0,r,0,200);
   bresenLine(-50,r,0,200);
   bresenLine1(50,r,0,200);
   glFlush(); 
} 

int main (int argc, char** argv) 
{ 
   //  printf("Enter the value of xc : ");
   // scanf("%d",&xc);
   // printf("Enter the value of yc : ");
   // scanf("%d",&yc);
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
   