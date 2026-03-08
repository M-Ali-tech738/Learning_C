#include <GL/glut.h>
#include <cmath>

// Function to draw the sin(x) curve
void drawSinCurve() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw X and Y axes
    glColor3f(1.0, 1.0, 1.0); // White color
    glBegin(GL_LINES);
        // X-axis
        glVertex2f(-3.2, 0.0);
        glVertex2f(3.2, 0.0);

        // Y-axis
        glVertex2f(0.0, -1.2);
        glVertex2f(0.0, 1.2);
    glEnd();

    // Draw sin(x) curve
    glColor3f(0.0, 1.0, 0.0); // Green color
    glBegin(GL_LINE_STRIP);

    for (float x = -3.14; x <= 3.14; x += 0.01) {
        glVertex2f(x, sin(x));
        glVertex2f(0,0);        
    }

    glEnd();
  
    glFlush();
}

// OpenGL initialization
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-3.2, 3.2, -1.2, 1.2); // Coordinate system
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("sin(x) Graph using OpenGL");

    init();
    glutDisplayFunc(drawSinCurve);
    glutMainLoop();

    return 0;
}
