#include<GL/glut.h>
#include<iostream>
using namespace std;

void initGL(){
   glClearColor(0.0f,0.0f,0.0f,1.0f);
}
void display(){
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
      glTranslatef(-0.5f, -0.5f, 0.0f);
      glRotatef(180.f, 0.0f, 0.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 1.0f);
      glBegin(GL_LINE_LOOP);
      {
         glVertex2f(0.0f,  - 10.0f);
         glVertex2f( 8.0f, 10.0f);
         glVertex2f(0.0f, 5.0f);
         glVertex2f( - 8.0f, 10.0f);
         glVertex2f(0.0f, - 10.0f);
      }
      glEnd();
      glPopMatrix();

   glFlush();
}
int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Shapes and Translations");
   glutInitWindowSize(400,400);
   glutInitWindowPosition(50,50);
   glutDisplayFunc(display);
   initGL();
   glutMainLoop();
   return 0;
}