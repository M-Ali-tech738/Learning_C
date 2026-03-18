#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

// Window size
int W = 800, H = 600;
float timer = 0;

struct Star { float x, y; };
Star stars[100];

void initStars() {
    for (int i = 0; i < 100; i++) {
        stars[i].x = rand() % W;
        stars[i].y = rand() % H;
    }
}

void drawCircle(float x, float y, float r) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 50; i++) {
        float a = 2 * 3.14 * i / 50;
        glVertex2f(x + r*cos(a), y + r*sin(a));
    }
    glEnd();
}

void background() {
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.3);
    glVertex2f(0, 0);
    glVertex2f(W, 0);
    glColor3f(0.0, 0.0, 0.1);
    glVertex2f(W, H);
    glVertex2f(0, H);
    glEnd();
}

void drawStars() {
    for (int i = 0; i < 100; i++) {
        float glow = 0.5 + 0.5*sin(timer);
        glColor3f(glow, glow, glow);
        drawCircle(stars[i].x, stars[i].y, 2);
    }
}

void drawMoon() {
    glColor3f(1, 1, 0.5);
    drawCircle(600, 450, 40);

    glColor3f(0.1, 0.1, 0.3);
    drawCircle(615, 460, 35);
}

void drawMosque() {
    glColor3f(0.6, 0.4, 0.2);

    // Base
    glBegin(GL_QUADS);
    glVertex2f(200, 0);
    glVertex2f(600, 0);
    glVertex2f(600, 150);
    glVertex2f(200, 150);
    glEnd();

    // Dome
    drawCircle(400, 200, 60);

    // Minarets
    glBegin(GL_QUADS);
    glVertex2f(220, 0);
    glVertex2f(260, 0);
    glVertex2f(260, 200);
    glVertex2f(220, 200);

    glVertex2f(540, 0);
    glVertex2f(580, 0);
    glVertex2f(580, 200);
    glVertex2f(540, 200);
    glEnd();
}

void text() {
    glColor3f(1, 1, 1);
    glRasterPos2f(300, 300);
    char msg[] = "EID MUBARAK";

    for (int i = 0; msg[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg[i]);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    background();
    drawStars();
    drawMoon();
    drawMosque();
    text();

    glutSwapBuffers();
}

void update(int) {
    timer += 0.05;
    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(W, H);
    glutCreateWindow("Eid Card");

    initStars();

    gluOrtho2D(0, W, 0, H);

    glutDisplayFunc(display);
    glutTimerFunc(30, update, 0);
    glutMainLoop();
}
