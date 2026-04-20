#include <GL/glut.h>
#include <iostream>
using namespace std;

float xPos = -0.8;   // global position for animation

void display()
{
    // 8. Called by GLUT every time window needs redrawing
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(xPos,        0.1);
        glVertex2f(xPos + 0.1,  0.1);
        glVertex2f(xPos + 0.1, -0.1);
        glVertex2f(xPos,       -0.1);
    glEnd();

    glFlush();
}

void myTimer(int value)
{
    // 7. Fires every 33ms, moves box, requests redraw
    xPos += 0.01;
    if(xPos > 1.0)
        xPos = -0.8;   // reset to left when off screen

    cout << "myTimer fired at value = " << value << endl;

    glutPostRedisplay();
    glutTimerFunc(33, myTimer, value + 1);   // re-register timer
}

void myInit()
{
    // 5. Called once to set up OpenGL state
    glClearColor(0.0, 0.0, 0.2, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    cout << "myInit() called" << endl;
}

int main(int argc, char** argv)
{
    // 1. glutInit
    glutInit(&argc, argv);
    cout << "1. glutInit done" << endl;

    // 2. glutInitWindowSize
    glutInitWindowSize(600, 600);
    cout << "2. Window size set" << endl;

    // 3. glutCreateWindow
    glutCreateWindow("Timer Demo");
    cout << "3. Window created" << endl;

    // 4. myInit
    myInit();
    cout << "4. myInit done" << endl;

    // 5. glutDisplayFunc
    glutDisplayFunc(display);
    cout << "5. Display callback registered" << endl;

    // 6. glutTimerFunc - first registration
    glutTimerFunc(33, myTimer, 0);
    cout << "6. Timer registered" << endl;

    // 7. glutMainLoop - infinite loop starts here
    cout << "7. Entering main loop" << endl;
    glutMainLoop();

    return 0;
}