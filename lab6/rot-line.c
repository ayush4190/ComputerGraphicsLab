// 8*8 chess board


#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

int xa,ya,xb,yb,xr,yr;
float angle;

void myInit (void) 
{ 
   glClearColor(0.0, 0.0, 0.0, 1.0); 
   glColor3f(0.0, 1.0, 0.0); 
   glPointSize(1.0); 
   glMatrixMode(GL_PROJECTION); 
   glLoadIdentity(); 
   gluOrtho2D(-780, 780, -420, 420); 
} 


void rotateArnd(int pxa, int pya,int pxb,int pyb, int cx, int cy,float theta) 
{ 
  
    // glClear(GL_COLOR_BUFFER_BIT); 
    int xfa, yfa,xfb,yfb; 

    // check overflow 
    if (theta >= (2.0 * 3.14159)) 
      theta = theta - (2.0 * 3.14159); 

    // actual calculations.. 
    xfa = cx + (int)((float)(pxa - cx) * cos(theta)) 
      - ((float)(pya - cy) * sin(theta)); 
    yfa = cy + (int)((float)(pxa - cx) * sin(theta)) 
      + ((float)(pya - cy) * cos(theta)); 

    xfb = cx + (int)((float)(pxb - cx) * cos(theta)) 
      - ((float)(pyb - cy) * sin(theta)); 
    yfb = cy + (int)((float)(pxb - cx) * sin(theta)) 
      + ((float)(pyb - cy) * cos(theta)); 

    glBegin(GL_LINES);
   glVertex2f(xfa, yfa); 
   glVertex2f(xfb, yfb);  
   glEnd();

    glFlush(); 
} 


void display (void) 
{ 
   glClear(GL_COLOR_BUFFER_BIT); 
   glBegin(GL_LINES);
   glVertex2f(xa, ya); 
   glVertex2f(xb, yb);  
   glEnd();
   rotateArnd(xa,ya,xb,yb,xr,yr,angle);
   glFlush();

} 

int main (int argc, char** argv) 
{ 

    printf("Enter x1,y1\n");
    scanf("%d %d",&xa,&ya);
    printf("Enter x2,y2\n");
    scanf("%d %d",&xb,&yb);
    printf("Enter angle\n");
    scanf("%f",&angle);
    printf("Enter rot axis x,y\n");
    scanf("%d %d",&xr,&yr);
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
  