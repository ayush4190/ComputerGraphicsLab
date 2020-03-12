#include<iostream>
#include <math.h>
#include <GL/glut.h> 
void display();
using namespace std;
int N ;
float xt1,yt1,xt2,yt2,xt3, yt3 ;
void myinit()
{
glClearColor(0.0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300,300,-300,300);

}

void drawtriangle( float x1 , float y1 , float x2 , float y2 , float x3 , float y3 )
{

     glColor3f(1.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glVertex2i(x3,y3);
    glEnd();
    glFlush();

}

void serpenski(float x1 , float y1 , float x2 , float y2 , float x3 , float y3 , int n)
{

    if(n<=0)
    {
        drawtriangle(x1,y1,x2,y2,x3,y3);
        return ;
    }

    n--;
    serpenski(x1,y1,((x1+x2)/2),y1,((3*x1+x2)/4),((y1+y3)/2),n);
    serpenski(((x1+x2)/2),y1,x2,y2,((3*x2+x1)/4),((y2+y3)/2),n);
    serpenski(((3*x1+x2)/4),((y1+y3)/2),((3*x2+x1)/4),((y2+y3)/2),x3,y3,n);

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    serpenski(xt1 , yt1 , xt2 , yt2 , xt3 , yt3, N);

}

int main(int argc , char **argv)
{
    
    printf("serpensiki triangle literal matlab nahi pata hai muhje par algo samaj aa gaya to likh diya \n");
    printf("enter the initial coordinates of the triangle\n");
    printf("x1 y1 \n");
    cin >> xt1 >> yt1 ;
    cout<<"x2 y2 \n";
    cin >> xt2 >> yt2 ;
    cout<< "x3 y3 \n";
    cin>> xt3 >> yt3 ;
    cout<<"enter the value of N \n";
    cin>>N;
    glutInit(&argc , argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
   glutInitWindowSize(1000, 1000); 
   glutInitWindowPosition(0, 0); 
   glutCreateWindow("serpenski triangle bolte hai isse"); 
glutDisplayFunc(display);   

   myinit();
  
   glutMainLoop(); 


}