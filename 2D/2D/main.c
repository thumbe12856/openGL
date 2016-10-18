#include <stdio.h>
#include <gl/glut.h>
#include <gl/glu.h>
#include <gl/gl.h>

int windowHeight = 500;
int windowWidth = 1000;
float mouseX, mouseY;

// display() called when window contents need to be refreshed
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPointSize(5.0f);
	glBegin(GL_POINTS);// starts drawing of points
	glVertex2f(mouseX, mouseY);
	glColor3f(((double)rand() / (RAND_MAX)), ((double)rand() / (RAND_MAX)), ((double)rand() / (RAND_MAX)));

	glEnd();
	glFlush();// OpenGL is pipelined, and sometimes waits for a full buffer to execute
	return;
}

// when mouse event is triggered
void mouse(int button, int stat, int x, int y) 
{
	if (button == 0)// left click
	{
		mouseX = (float)(x - windowWidth / 2) / ((float)windowWidth / 2);
		mouseY = (float)(windowHeight / 2 - y) / ((float)windowHeight / 2);
	}
	return;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow(argv[0]);

	glutMouseFunc(mouse);
	glutDisplayFunc(display);// tell GLUT how to fill window
	
	glutMainLoop();// let glut manage i / o processing
	return 0;
}