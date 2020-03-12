// 8*8 chess board


#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

float xa,ya,xb,yb;
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

void DDA(float X1,float Y1,float X2,float Y2)
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

void display (void) 
{ 
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_LINES);
   glVertex2f(xa, ya); 
   glVertex2f(xb, yb);
   glEnd();
   glBegin(GL_LINES);
   glColor3f(1.0,0.0,0.0);
   glVertex2f(xa, ya); 
   glVertex2f(xb*s, yb*s);
   glEnd();
   glFlush();

} 

int main (int argc, char** argv) 
{ 

    printf("Enter x1,y1\n");
    scanf("%f %f",&xa,&ya);
    printf("Enter x2,y2\n");
    scanf("%f %f",&xb,&yb);
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
