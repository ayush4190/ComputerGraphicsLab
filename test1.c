#include <GL/glut.h>
#include <stdio.h>
int x, y,dist=0,inc=1,max=50,ch;
float angle=0.0;
void myInit() {
 
  glClearColor(0.0, 0.0, 0.0, 1.0);
   glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0,1.0,1.0);
  gluOrtho2D(0, 500, 0, 500);
}
void draw_pixel(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}
void mark_points(int x, int y, int p,int q)
{
  draw_pixel(x+p,y+q);
  draw_pixel(x+p,y-q);
  draw_pixel(x+q,y+p);
  draw_pixel(x+q,y-p);
  draw_pixel(x-p,y+q);
  draw_pixel(x-p,y-q);
  draw_pixel(x-q,y+p);
  draw_pixel(x-q,y-p);
}
void draw_circle(int x, int y, int r) {
  int d=3-2*r;
  int p=0;
  int q=r;
  draw_pixel(x+r,y);
  draw_pixel(x,y+r);
  draw_pixel(x-r,y);
  draw_pixel(x,y+r);
  while(p<q)
  {
      p++;
      if(d<=0)
          d=d+4*p+6;
      else
      {
          q--;
          d=d+4*(p-q)+10;
      }
      mark_points(x,y,p,q);
  }
}
void draw_semi(int x, int y, int r) {
  int d=3-2*r;
  int p=0;
  int q=r;
  draw_pixel(x+r,y);
  draw_pixel(x,y+r);
  draw_pixel(x-r,y);
  draw_pixel(x,y+r);
  while(p<q)
  {
      p++;
      if(d<=0)
          d=d+4*p+6;
      else
      {
          q--;
          d=d+4*(p-q)+10;
      }
      draw_pixel(x+p,y+q);
      draw_pixel(x+q,y+p);
      draw_pixel(x-p,y+q);
      draw_pixel(x-q,y+p);
  }
}
void draw_line(int x1, int x2, int y1, int y2) {
  int dx, dy, i, e;
  int incx, incy, inc1, inc2;
  int x,y;
  dx = x2-x1;
  dy = y2-y1;
  if (dx < 0) dx = -dx;
  if (dy < 0) dy = -dy;
  incx = 1;
  if (x2 < x1) incx = -1;
  incy = 1;
  if (y2 < y1) incy = -1;
  x = x1; y = y1;
  if (dx > dy) {
      draw_pixel(x, y);
      e = 2 * dy-dx;
      inc1 = 2*(dy-dx);
      inc2 = 2*dy;
      for (i=0; i<dx; i++) {
          if (e >= 0) {
              y += incy;
              e += inc1;
          }
          else
              e += inc2;
          x += incx;
          draw_pixel(x, y);
      }
  } else {
      draw_pixel(x, y);
      e = 2*dx-dy;
      inc1 = 2*(dx-dy);
      inc2 = 2*dx;
      for (i=0; i<dy; i++) {
          if (e >= 0) {
              x += incx;
              e += inc1;
          }
          else
              e += inc2;
          y += incy;
          draw_pixel(x, y);
      }
  }
}
int cx=200,cy=200;
int r =50;
int g = r/10;
int rec = r*2;
int leg = r/5;
int leg_height = r;
void myDisplay()
{   glPushMatrix();
   draw_semi(cx,cy,r);
   draw_line(cx-r,cx+r,cy,cy);
   draw_line(cx-r,cx+r,cy-g,cy-g);
   draw_line(cx-r,cx-r,cy-g,cy-rec);
   draw_line(cx+r,cx+r,cy-g,cy-rec);
   draw_line(cx-r,cx+r,cy-rec,cy-rec);
   draw_line(cx-r+leg,cx-r+leg,cy-rec,cy-rec-leg_height);
   draw_line(cx-r+leg+leg,cx-r+leg+leg,cy-rec,cy-rec-leg_height);
   draw_line(cx+r-leg,cx+r-leg,cy-rec,cy-rec-leg_height);
   draw_line(cx+r-leg-leg,cx+r-leg-leg,cy-rec,cy-rec-leg_height);
   draw_line(cx+r-leg-leg,cx+r-leg-leg,cy-rec,cy-rec-leg_height);
   draw_line(cx+r-leg,cx+r-leg-leg,cy-rec-leg_height,cy-rec-leg_height);
   draw_line(cx-r+leg,cx-r+leg+leg,cy-rec-leg_height,cy-rec-leg_height);
  
   //eyes
   draw_circle(cx-g-2*leg,cx+5*g,r/10);
   draw_circle(cx+g+2*leg,cx+5*g,r/10);
   //ANTEENA

   
  
   //handleft
   glPushMatrix();
   if(ch == 1)
   {
   angle = angle + 2.0;

   	glRotatef(angle,1,0,0);
   }

 
   draw_line(cx-r-g-leg,cx-r-g,cy-g,cy-g);
   draw_line(cx-r-g-leg,cx-r-g,cy-rec,cy-rec);
   draw_line(cx-r-g,cx-r-g,cy-g,cy-rec);
   draw_line(cx-r-g-leg,cx-r-g-leg,cy-g,cy-rec);
   //handright
   draw_line(cx+r+g+leg,cx+r+g,cy-g,cy-g);
   draw_line(cx+r+g+leg,cx+r+g,cy-rec,cy-rec);
   draw_line(cx+r+g,cx+r+g,cy-g,cy-rec);
   draw_line(cx+r+g+leg,cx+r+g+leg,cy-g,cy-rec);
   glPopMatrix();
 
   glPopMatrix();
   glutPostRedisplay();
   glFlush();
}
int scale = 0.1;
 
void keyboard(unsigned char key, int x, int y)
// x and y givethe mouse pos
{
   printf("%c",key);
    if(key =='t'){
       glTranslatef(dist,0,0);
   }
   if(key =='e'){
       exit(0);
   }
   if(key == 'h'){
       glTranslatef(-dist,0,0);
   }
   if(key =='c'){
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       glLoadIdentity(); // Reset The Projection Matrix
   }
   if(key == 'i'){
       r=r+1;
   }
   if(key == 'd'){
       if(r>=0)
       r=r-1;
   }
   if(key=='r'){
       ch=1;
       
   }
   if(key=='s'){
      ch=0 ;
      angle =0.0;
   }
 
  
}
 
 
 
void StepRot(int n)
{
  angle-=inc;
  dist+=inc;
  if(dist>=max)
  {
      inc=-1;
      angle=0;
  }
  else if(dist<=-max)
  {
      inc=1;
      angle=0;
  }
  glClear(GL_COLOR_BUFFER_BIT);
  glutPostRedisplay();
  glutTimerFunc(50,StepRot,0);
}
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(1000, 1000);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Car");
  myInit();
  glutDisplayFunc(myDisplay);
  glutTimerFunc(50,StepRot,0);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
 
