#include <gl/glut.h>
#include <gl/gl.h>

/* display() called when window contents need to be refreshed */
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0); /* red */
	glVertex2f(-1.0, -1.0); /* lower left corner */
	glColor3f(0.0, 1.0, 0.0); /* green */
	glVertex2f(-1.0, 1.0); /* upper left corner */
	glColor3f(0.0, 0.0, 1.0); /* blue */
	glVertex2f(1.0, -1.0); /* lower right corner */
	glEnd();
	glFlush(); /* OpenGL is pipelined, and sometimes waits
			   for a full buffer to execute */
}

/* reshape(w, h) called when window changes size
called with width w and height h of new window size */
void reshape(int w, int h)
{
	glViewport(0, 0, w, h); /* establish viewing area to cover entire window */
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv); /* setup GLUT */
	glutCreateWindow(argv[0]); /* open a window */
	glutDisplayFunc(display); /* tell GLUT how to fill window */
	glutReshapeFunc(reshape); /* update shape of window */
	glutMainLoop(); /* let glut manage i / o processing */
	return 0; /* ANSI C requires main to return int */
}