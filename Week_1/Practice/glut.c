#include <GL/glut.h>

/* Function to render graphics */
void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the screen

    glBegin(GL_TRIANGLES);          // Start drawing a triangle
        glVertex3f(-0.5f, -0.5f, 0.0f);
        glVertex3f( 0.5f, -0.5f, 0.0f);
        glVertex3f( 0.0f,  0.5f, 0.0f);
    glEnd();                        // End drawing

    glFlush();                      // Force rendering
}

/* Main function */
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                          // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Display mode
    glutInitWindowPosition(100, 100);               // Window position
    glutInitWindowSize(400, 400);                   // Window size
    glutCreateWindow("GLUT Triangle Program");      // Create window

    glutDisplayFunc(renderScene);                   // Register display callback
    glutMainLoop();                                 // Enter event loop

    return 0;
}
