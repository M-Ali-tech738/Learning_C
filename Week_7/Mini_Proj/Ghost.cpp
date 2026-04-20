#include <GL/glut.h>

void drawGhost()
{
    /* --- WHITE COLOR FOR BODY --- */
    glColor3f(1.0, 1.0, 1.0);

    /* HEAD - semicircle made of a polygon */
    /* these are hand-picked points along the top half of a circle */
    glBegin(GL_POLYGON);
        glVertex2f( 0.0,  0.5);   /* top center */
        glVertex2f(-0.1,  0.49);
        glVertex2f(-0.2,  0.46);
        glVertex2f(-0.27, 0.41);
        glVertex2f(-0.3,  0.3);   /* left side */
        glVertex2f(-0.3,  0.2);   /* bottom left of head */
        glVertex2f( 0.3,  0.2);   /* bottom right of head */
        glVertex2f( 0.3,  0.3);   /* right side */
        glVertex2f( 0.27, 0.41);
        glVertex2f( 0.2,  0.46);
        glVertex2f( 0.1,  0.49);
    glEnd();

    /* BODY - simple rectangle */
    glBegin(GL_POLYGON);
        glVertex2f(-0.3,  0.2);   /* top left */
        glVertex2f( 0.3,  0.2);   /* top right */
        glVertex2f( 0.3, -0.2);   /* bottom right */
        glVertex2f(-0.3, -0.2);   /* bottom left */
    glEnd();

    /* LEFT TENTACLE */
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.3,  -0.2);  /* top left */
        glVertex2f(-0.1,  -0.2);  /* top right */
        glVertex2f(-0.2,  -0.4);  /* bottom tip */
    glEnd();

    /* MIDDLE TENTACLE */
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.1,  -0.2);  /* top left */
        glVertex2f( 0.1,  -0.2);  /* top right */
        glVertex2f( 0.0,  -0.4);  /* bottom tip */
    glEnd();

    /* RIGHT TENTACLE */
    glBegin(GL_TRIANGLES);
        glVertex2f( 0.1,  -0.2);  /* top left */
        glVertex2f( 0.3,  -0.2);  /* top right */
        glVertex2f( 0.2,  -0.4);  /* bottom tip */
    glEnd();

    /* --- BLACK COLOR FOR FACE --- */
    glColor3f(0.0, 0.0, 0.0);

    /* LEFT EYE - small square */
    glBegin(GL_POLYGON);
        glVertex2f(-0.15, 0.38);
        glVertex2f(-0.05, 0.38);
        glVertex2f(-0.05, 0.28);
        glVertex2f(-0.15, 0.28);
    glEnd();

    /* RIGHT EYE - small square */
    glBegin(GL_POLYGON);
        glVertex2f( 0.05, 0.38);
        glVertex2f( 0.15, 0.38);
        glVertex2f( 0.15, 0.28);
        glVertex2f( 0.05, 0.28);
    glEnd();

    /* MOUTH - one horizontal line */
    glBegin(GL_LINES);
        glVertex2f(-0.1, 0.22);
        glVertex2f( 0.1, 0.22);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGhost();
    glFlush();
}

void init()
{
    glClearColor(0.1, 0.0, 0.2, 1.0);  /* dark purple background */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Ghost");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}