#include <GL/glut.h>
#include <math.h>

void drawCircle(float cx, float cy, float r)
{
    int i;
    float angle, x, y;
    glBegin(GL_POINTS);
    for(i = 0; i <= 360; i++)
    {
        angle = i * 3.14159 / 180.0;
        x = cx + r * cos(angle);
        y = cy + r * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawHeptagon(float cx, float cy, float r)
{
    int i;
    float angle, x, y;
    glBegin(GL_LINE_LOOP);
    for(i = 0; i < 7; i++)
    {
        angle = i * 2 * 3.14159 / 7.0;
        x = cx + r * cos(angle);
        y = cy + r * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawText(float x, float y, const char* text)
{
    int i;
    glRasterPos2f(x, y);
    for(i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    /* Mosque base */
    glBegin(GL_POLYGON);
        glVertex2f(-0.6, -0.5);
        glVertex2f( 0.6, -0.5);
        glVertex2f( 0.6,  0.0);
        glVertex2f(-0.6,  0.0);
    glEnd();

    /* Three domes */
    drawCircle( 0.0,  0.05, 0.25);
    drawCircle(-0.35, 0.05, 0.15);
    drawCircle( 0.35, 0.05, 0.15);

    /* Crescent moon */
    drawCircle(-0.7, 0.6,  0.15);
    drawCircle(-0.65, 0.6, 0.12);

    /* Stars */
    glBegin(GL_LINES);
        glVertex2f(0.6,   0.6);   glVertex2f(0.6,   0.65);
        glVertex2f(0.575, 0.625); glVertex2f(0.625, 0.625);
        glVertex2f(0.75,  0.55);  glVertex2f(0.75,  0.6);
        glVertex2f(0.725, 0.575); glVertex2f(0.775, 0.575);
    glEnd();

    /* Heptagon */
    drawHeptagon(0.75, -0.3, 0.15);

    /* Text */
    drawText(-0.35, -0.75, "RAMADAN MUBARAK");
    drawText(-0.25, -0.85, "Dr Humera Tariq");

    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Ramadan Mubarak");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}