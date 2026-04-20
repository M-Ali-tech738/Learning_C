#include <GL/glut.h>

void drawTriangle()
{
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2f( 0.0,  0.5);
        glVertex2f(-0.5, -0.5);
        glVertex2f( 0.5, -0.5);
    glEnd();
}

void drawSquare()
{
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.4, -0.4);
        glVertex2f( 0.4, -0.4);
        glVertex2f( 0.4,  0.4);
        glVertex2f(-0.4,  0.4);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // VIEWPORT 1 - left half
    // glViewport(x, y, width, height)
    glViewport(0, 0, 300, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);   // camera 1
    drawTriangle();

    // VIEWPORT 2 - right half
    glViewport(300, 0, 300, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);   // camera 2
    drawSquare();

    glFlush();
}

void myInit()
{
    glClearColor(0.1, 0.1, 0.1, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Multiple Viewports");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
