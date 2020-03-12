#include <stdio.h> 
#include <GL/glut.h> 
#include <math.h> 
#define pi 3.142857 
    
float scalf=1.0;

void drawStar(int x, int y)
{
  glPushMatrix();
  glScalef(scalf,scalf,0.0);
  glBegin(GL_TRIANGLES);
  // glColor3f(1.0, 0.0, 0.0);
  glVertex2i(x, y);
  glVertex2i(x-10, y-20);
  glVertex2i(x+10, y-20);
  
  glVertex2i(x, y-25);
  glVertex2i(x-10, y-5);
  glVertex2i(x+10, y-5);
  glEnd();
  glPopMatrix();
  glFlush();
}
void mouse(int button,int state,int x,int y)
{
  switch(button)
  {
  case GLUT_LEFT_BUTTON:
    if(state==GLUT_DOWN)
      {
        exit(0);
      }
    break;
  case GLUT_MIDDLE_BUTTON:
    if(state==GLUT_DOWN)
    {
      glutIdleFunc(NULL);
    }
    break;
  case GLUT_RIGHT_BUTTON:
    if(state==GLUT_DOWN)
      {
        int curx = x/scalf;
        int cury = y/scalf;
        drawStar(curx,cury);
      }
    break;
  default:
    break;
  }
}
void keyboard(unsigned char key, int x, int y)
{
  //-------- spin --------
  if(key=='s')
  {
     scalf+=0.1;
  }
  else if(key=='r')
  {
    scalf-=0.1;
  }
}

void myInit (void) 
{ 
   glClearColor(0.0, 0.0, 0.0, 1.0); 
   glColor3f(0.0, 1.0, 0.0); 
   glPointSize(1.0); 
   glMatrixMode(GL_PROJECTION); 
   glLoadIdentity(); 
   gluOrtho2D(0, 500, 500, 0); 
} 

void display (void) 
{ 
  glClear(GL_COLOR_BUFFER_BIT); 
  // drawStar(xc,yc);
  glFlush();
} 

int main (int argc, char** argv) 
{ 

   glutInit(&argc, argv); 
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
   
   // giving window size in X- and Y- direction 
   glutInitWindowSize(500, 500); 
   glutInitWindowPosition(100, 100);
   
   // Giving name to window 
   glutCreateWindow("Star"); 
   myInit(); 
   scalf=1.0;
   glutDisplayFunc(display); 
   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   glutMainLoop(); 
} 
