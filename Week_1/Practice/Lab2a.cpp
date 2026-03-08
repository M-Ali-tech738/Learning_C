#include <iostream>
#include <fstream>
#include <GL/glut.h>

using namespace std;

// #pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

// void myDisplay1(void)
// {
// 	glClearColor(1.0f, 0.0f, 0.0f, 0.0);
// 	glClear(GL_COLOR_BUFFER_BIT);
// 	glColor3f(1, 1, 1);
// 	glFlush();
// }

void myDisplay(void)
{
	// Clear the screen with a black background
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Set the current color to yellow (R=1, G=1, B=0)
	glColor3f(1.0f, 1.0f, 0.0f);

	// Begin drawing a triangle
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, -0.5f); // Bottom-left
	glVertex2f(0.5f, -0.5f);  // Bottom-right
	glVertex2f(0.0f, 0.5f);	  // Top-center
	glEnd();

	// Flush the OpenGL commands to the screen
	glFlush();
}

int screenWidth = 640;
int screenHeight = 480;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(10, 10);

	glutCreateWindow("My first Game Window - AI-351");

	glutDisplayFunc(myDisplay);

	// glClearColor(1.0f, 0.0f, 0.0f, 0.0);

	glutMainLoop();

	return 0;
}
