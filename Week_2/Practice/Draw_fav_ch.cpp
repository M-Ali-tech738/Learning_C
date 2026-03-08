#include <GL/freeglut.h>
#include <GL/glut.h>
#include <cmath>

// Function to draw text inside the window
void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    while (*text)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
        text++;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.2f, 0.2f, 0.2f, 1);

    /* ===== Character Head (Circle) ===== */
    glColor3f(1.0f, 0.8f, 0.6f);   // Skin color
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float angle = i * 3.1416f / 180;
        glVertex2f(0.0f + 0.2f * cos(angle),
                   0.2f + 0.2f * sin(angle));
    }
    glEnd();

    // Left eye
glColor3f(0, 0, 0);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++)
{
    float angle = i * 3.1416f / 180;
    glVertex2f(-0.07f + 0.02f * cos(angle),
                0.25f + 0.02f * sin(angle));
}
glEnd();

// Right eye
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++)
{
    float angle = i * 3.1416f / 180;
    glVertex2f(0.07f + 0.02f * cos(angle),
               0.25f + 0.02f * sin(angle));
}
glEnd();

    /* ===== Body ===== */
    glColor3f(0.0f, 0.0f, 1.0f); // Blue shirt
    glBegin(GL_QUADS);
        glVertex2f(-0.15f, 0.0f);
        glVertex2f( 0.15f, 0.0f);
        glVertex2f( 0.15f,-0.35f);
        glVertex2f(-0.15f,-0.35f);
    glEnd();

    /* ===== Text ===== */
    glColor3f(1, 1, 1);
    drawText(-0.9f, -0.7f, "Name: Your Name");
    drawText(-0.9f, -0.8f, "Seat No: AI-351-XXX");

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Favourite Game Character");

    glClearColor(0, 0, 0, 1); // Black background
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
