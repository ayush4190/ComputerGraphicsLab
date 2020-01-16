#include <GL/glut.h>
#include <stdio.h>

int x1, y_1, x2, y2;

void init() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1000,1000,-1000,1000);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int x2, int y_1, int y2) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y_1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y_1) incy = -1;
	x = x1; y = y_1;
	x = x1; y = y_1;
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

void display() {
	draw_line(-100, 0, 0, 100);
	draw_line(0, 100, 100, 0);
	draw_line(100, 0, 0, -100);
	draw_line(0, -100, -100, 0);
	draw_line(-100, -100, -100, 100);
draw_line(100, 100, -100, 100);
draw_line(-100, 100, 100, 100);
draw_line(-100, 100, -100, -100);
draw_line(-50, -50, -50, 50);
draw_line(50, 50, -50, 50);
draw_line(-50, 50, 50, 50);
draw_line(-50, 50, -50, -50);
	glFlush();
}

void main(int argc, char **argv) {

	

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(5000, 5000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Drawing");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
