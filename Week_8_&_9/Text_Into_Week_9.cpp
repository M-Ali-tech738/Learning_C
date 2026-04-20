#include <GL/glut.h>

void drawText(float x, float y, char text[])
{
    int i;
    glRasterPos2f(x, y);
    for(i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0.0);
    drawText(-0.4,  0.3, "WELCOME TO MY PROGRAM");

    glColor3f(1.0, 1.0, 1.0);
    drawText(-0.3,  0.0, "Press any key to start");

    glColor3f(0.5, 0.5, 0.5);
    drawText(-0.15, -0.3, "Version 1.0");

    glFlush();
}

void myInit()
{
    glClearColor(0.0, 0.0, 0.2, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Intro Screen");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}