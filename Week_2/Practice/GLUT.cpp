#include <GL/freeglut.h>

/* 
Glut solves for:
Window creation
Input handling
Main loop
*/

// GLUT completes OpenGL programming

/*
GLUT adds:
Window creation
Keyboard & mouse input
Event handling
Main loop
*/

// not only does it make OpenGL usable but also beginner-friendly

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 0);

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.5f, -0.5f);
        glVertex2f( 0.0f,  0.5f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    // Window & display handled by GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);

    glutCreateWindow("GL + GLU + GLUT Example");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
