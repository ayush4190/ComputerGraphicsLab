// 8*8 chess board


#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

// float X1,Y1,X2,Y2;

void myInit (void) 
{ 
   glClearColor(0.0, 0.0, 1.0, 1.0); 
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

 	
             int i,  k = 0,j;
            float cbvalue;  

            for(i=0;i<9;i++)
            {
                DDA(0,k,400,k);
                DDA(k,0,k,400);
                k+=50;
            }

            cbvalue = 1.0;

            int row=-50;
            for(i=0; i<8; i++)
            {
                int col = -50; row +=50;
                for(j=0; j<8; j++)
                {
                    glColor3f(cbvalue, cbvalue,cbvalue);
                    int r;
                    for(r=0; r<50; r++)
                        DDA(50 + col,row+r,100 + col,row+r);
                    col = col+50;
                    if (j<7)
                        if (cbvalue == 1.0)
                                cbvalue =0.0;
                        else
                                cbvalue =1.0;
                }
             }
            glFlush();

} 

int main (int argc, char** argv) 
{ 

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
