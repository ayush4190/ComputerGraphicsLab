#include<GL/glut.h>
#include<iostream>
using namespace std;

int v1[2],v2[2],v3[2],v4[2];
int n;
 int a1[2],b1[2],c1[2],d1[2];
void initGL(){
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    gluOrtho2D(0,400,0,400);
}
void show(int a[2]){
    cout<<"display: "<<a[0]<<" "<<a[1]<<endl;
}
void draw_square(int a[2],int b[2], int c[2], int d[2]){
    
       
        glColor3f(0.0f,1.0f,0.0f);
        glVertex2f(a[0],a[1]);
        glVertex2f(b[0],b[1]);
        glVertex2f(c[0],c[1]);
        glVertex2f(d[0],d[1]);
       
       
        a1[0]=(2*a[0]+d[0])/3;
        a1[1]=(2*a[1]+b[1])/3;
        b1[0]=(2*b[0]+c[0])/3;
        b1[1]=(2*b[1]+a[1])/3;
        c1[0]=(2*c[0]+b[0])/3;
        c1[1]=(2*c[1]+d[1])/3;
        d1[0]=(2*d[0]+a[0])/3;
        d1[1]=(2*d[1]+c[1])/3;

        show(a1); show(b1); show(c1); show(d1);
        
        glColor3f(0.0f,0.0f,1.0f);
        glVertex2f(a1[0],a1[1]);
        glVertex2f(b1[0],b1[1]);
        glVertex2f(c1[0],c1[1]);
        glVertex2f(d1[0],d1[1]);
        
        cout<<"hi"<<endl;
}
void divide_square(int a[2],int b[2], int c[2], int d[2], int m){
    int v0[2], v1[2], v2[2],v3[2],j;
    show(a);show(b);show(c);show(d);
    if(m>0){
        v0[0]=a[0];
        v0[1]=(a[1]+2*b[1])/3;
        v1[0]=b[0];
        v1[1]=b[1];
        v2[0]=(c[0]+2*b[0])/3;
        v2[1]=b[1];
        v3[0]=v2[0];
        v3[1]=v0[1];

        draw_square(v0,v1,v2,v3);

        int a1[2],b1[2],c1[2],d1[2];
        a1[0]=a[0];a1[1]=a[1];
        b1[0]=a[0];
        b1[1]=(a[1]+v0[1])/2;

        int temp[2];
        temp[0]=d[0];
        temp[1]=(c[1]+2*d[1])/3;

        c1[0]=(temp[0]+2*b1[0])/3;
        c1[1]=b1[1];
        d1[0]=c1[0];
        d1[1]=a[1];

        divide_square(a1,b1,c1,d1,m-1);
    }
    else
    return;
}
void gasket(){
    glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_QUADS);
        draw_square(v1,v2,v3,v4);
        divide_square(v1,v2,v3,v4,n-1);
     glEnd();
    glFlush();
}
int main(int argc, char **argv){

    cout<<"Enter no. of recursive steps: ";cin>>n;
    // cout<<"Enter vertices of triangle: (x,y)"<<endl;
    // cout<<"point 1:"<<endl;
    // cin>>v1[0]>>v1[1];
    // cout<<"point 2:"<<endl;
    // cin>>v2[0]>>v2[1];
    // cout<<"point 3:"<<endl;
    // cin>>v3[0]>>v3[1];
    v1[0]=10;v1[1]=10;v2[0]=10;v2[1]=310;v3[0]=310;v3[1]=310;v4[0]=310;v4[1]=10;
    
    //show(v1);show(v2);show(v3);show(v4);
    glutInit(&argc,argv);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Sierpinski Gasket Hollow Square");
    initGL();
    glutDisplayFunc(gasket);
    glutMainLoop();
    return 0;
}