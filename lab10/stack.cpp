#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int top=-1;
int flag = -2;
string numb[10];
void init(void)
{
    glClearColor(0.0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300,300,-300,300);
}
void drawText(string str,float x,float y) 
{  
    glColor3f(1.0,0.0,0.0);
    glRasterPos2f(x, y);

    for (int i=0;str[i]!='\0'; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str[i]);
    }
}
// void drawNumbers(int t)
// {

// }
void drawStack()
{
   
   glColor3f(0.0,1.0,0.0);
     glBegin(GL_LINES);
     glVertex2i(0,0);
     glVertex2i(50,0);

      glVertex2i(50,0);
     glVertex2i(50,50);

     glVertex2i(50,50);
     glVertex2i(0,50);
     glVertex2i(0,50);
      glVertex2i(0,0);
   // glEnd();glBegin(GL_QUADS);
     glVertex2i(0,50);
     glVertex2i(50,50);
      glVertex2i(50,50);
     glVertex2i(50,100);
     glVertex2i(50,100);
     glVertex2i(0,100);
     glVertex2i(0,100);
      glVertex2i(0,50);
   // glEnd();glBegin(GL_QUADS);
     glVertex2i(0,100);
     glVertex2i(50,100);
     glVertex2i(50,100);
     glVertex2i(50,150);
         glVertex2i(50,150);
     glVertex2i(0,150);
      glVertex2i(0,150);
     glVertex2i(0,100);
   // glEnd();glBegin(GL_QUADS);
     glVertex2i(0,150);
     glVertex2i(50,150);
      glVertex2i(50,150);
     glVertex2i(50,200);
     glVertex2i(50,200);
     glVertex2i(0,200);
        glVertex2i(0,200);
     glVertex2i(0,150);
   // glEnd();glBegin(GL_QUADS);
     glVertex2i(0,200);
     glVertex2i(50,200);
     glVertex2i(50,200);
     glVertex2i(50,250);
      glVertex2i(50,250);
     glVertex2i(0,250);
        glVertex2i(0,250);
     glVertex2i(0,200);
   glEnd();
     // glBegin(GL_QUADS);
   //   glVertex2i(0,250);
   //   glVertex2i(50,250);
   //   glVertex2i(50,300);
   //   glVertex2i(0,300);
   //   glEnd();
        
   glFlush();
}

void mykey(unsigned char key,int x,int y)
{
    if(key=='i')
    {  
        if(top<5)
        {
          top++;
          cout<<"enter the num"<<endl;
          cin>>numb[top];
          //stack inserted
          flag=1;
          glutPostRedisplay();
        }
        else
        {
          flag=2;
          cout<<"stack full"<<endl;
        }
    }
    else if(key == 'd')
    {
        if(top>=0)
        {
          top--;
          //poped
          flag=-1;
          glutPostRedisplay();
        }
        else
        {
          flag=-2;
          cout<<"stack empty"<<endl;
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawStack();
    // drawNumbers();
    drawText("Stack empty",150.0,250.0);
    if(flag == 1)
    {
      drawText("Stack Inserted",150,250);
    }
    else if(flag == 2)
    {
      drawText("Stack Full",150,250);
    }
    else if(flag == -1)
    {
      drawText("Stack Deleted",150,250);
    }
    else if(flag == -2)
    {
      drawText("Stack empty",150.0,250.0);
    }

}


int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("tri");
    glutDisplayFunc(display);
    // glutKeyboardFunc(mykey);
    init();
    glutMainLoop();
    return 0;
}
