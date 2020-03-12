#include<iostream>
#include <GL/glut.h>
#include<math.h>
using namespace std;
void display();
int N;
float xt1 , yt1 , xt2 , yt2 , xt3 , yt3 , xt4 ,yt4 ;
void myinit()
{
glClearColor(0.0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300,300,-300,300);

}

void drawsquare(float x1 , float y1 , float x2 , float y2 , float x3 , float y3 , float x4 , float y4)
{
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_QUADS);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glVertex2i(x3,y3);
    glVertex2i(x4,y4);
    glEnd();
    glFlush();
}
void serpenski(float x1 , float y1 , float x2 , float y2 , float x3 , float y3 , float x4 , float y4 ,int n)
{

    if(n<=0)
    {

        drawsquare(x1,y1,x2,y2,x3,y3 , x4 ,y4);
        return ;
    }
     n--;
    
  float d = (x2-x1)/3;
  serpenski(x1,y1,x1+d,y1,x1+d,y1+d,x1,y1+d,n);
  serpenski(x1+d,y1,x1+2*d,y1,x1+2*d,y1+d,x1+d,y1+d,n);
  serpenski(x1+2*d,y1,x2,y2,x2,y1+d,x1+2*d,y1+d,n);

  serpenski(x1,y1+d,x1+d,y1+d,x1+d,y1+2*d,x1,y1+2*d,n);
  serpenski(x1+2*d,y1+d,x2,y1+d,x2,y1+2*d,x1+2*d,y1+2*d,n);

  serpenski(x1,y1+2*d,x1+d,y1+2*d,x1+d,y4,x4,y4,n);
  serpenski(x1+d,y1+2*d,x1+2*d,y1+2*d,x1+2*d,y4,x1+d,y4,n);
  serpenski(x1+2*d,y1+2*d,x2,y2+2*d,x3,y3,x1+2*d,y3,n);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    serpenski(xt1 , yt1 , xt2 , yt2 , xt3 , yt3 , xt4 , yt4, N);

}

int main(int argc , char **argv)
{
    
    printf("serpensiki square literal matlab nahi pata hai muhje par algo samaj aa gaya to likh diya \n");
    printf("enter the initial coordinates of the square\n");
    printf("x1 y1 \n");
    cin >> xt1 >> yt1 ;
    cout<<"x2 y2 \n";
    cin >> xt2 >> yt2 ;
    cout<< "x3 y3 \n";
    cin>> xt3 >> yt3 ;
    cout<<" x4 y4 \n";
    cin >> xt4 >> yt4 ;

    cout<<"enter the value of N \n";
    cin>>N;
    glutInit(&argc , argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
   glutInitWindowSize(1000, 1000); 
   glutInitWindowPosition(0, 0); 
   glutCreateWindow("serpenski square bolte hai isse"); 
glutDisplayFunc(display);   

   myinit();
  
   glutMainLoop(); 


}

