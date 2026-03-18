#include <GL/glut.h>
#include <cmath>

// ─── Draw a filled circle ───────────────────────────────────────────────────
void drawCircle(float x, float y, float r) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);                          // center point
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100;
        glVertex2f(x + r * cos(angle), y + r * sin(angle));
    }
    glEnd();
}

// Drawing Star
void drawstar(float x, float y, ){
    for(int i=0; i<=10; i++){

    }
}

// ─── Draw the sky (background) ──────────────────────────────────────────────
void drawSky() {
    glColor3f(0.1f, 0.0f, 0.3f);              // dark purple color
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(800, 0);
    glVertex2f(800, 600);
    glVertex2f(0, 600);
    glEnd();
}

// ─── Draw a simple star ─────────────────────────────────────────────────────
void drawStar(float x, float y) {
    glColor3f(1.0f, 1.0f, 0.8f);              // pale yellow
    drawCircle(x, y, 4);                       // just a small dot
}

// ─── Draw the crescent moon ─────────────────────────────────────────────────
void drawMoon() {
    // Step 1: draw a full yellow circle
    glColor3f(1.0f, 0.9f, 0.2f);
    drawCircle(400, 450, 70);

    // Step 2: draw a smaller circle on top in background color
    // This "cuts" into the yellow circle, making it look like a crescent
    glColor3f(0.1f, 0.0f, 0.3f);
    drawCircle(430, 460, 58);
}

// ─── Draw a simple lantern ──────────────────────────────────────────────────
void drawLantern(float x, float y) {
    // String (line from top)
    glColor3f(1.0f, 0.8f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(x, y + 60);
    glVertex2f(x, y + 40);
    glEnd();

    // Lantern body (rectangle)
    glColor3f(0.9f, 0.2f, 0.1f);             // red color
    glBegin(GL_QUADS);
    glVertex2f(x - 20, y - 30);
    glVertex2f(x + 20, y - 30);
    glVertex2f(x + 20, y + 40);
    glVertex2f(x - 20, y + 40);
    glEnd();

    // Light glow inside
    glColor3f(1.0f, 0.9f, 0.3f);
    drawCircle(x, y, 10);
}

// ─── Draw the greeting text ─────────────────────────────────────────────────
void drawText() {
    // "Eid Mubarak" - big text
    glColor3f(1.0f, 0.85f, 0.2f);
    glRasterPos2f(330, 280);
    const char* msg = "Eid Mubarak!";
    for (int i = 0; msg[i]; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg[i]);

    // smaller subtitle
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(280, 240);
    const char* sub = "Wishing you joy, peace and blessings.";
    for (int i = 0; sub[i]; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, sub[i]);
}

// ─── Draw a simple border ───────────────────────────────────────────────────
void drawBorder() {
    glColor3f(1.0f, 0.8f, 0.0f);             // gold color
    glLineWidth(4.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(20, 20);
    glVertex2f(780, 20);
    glVertex2f(780, 580);
    glVertex2f(20, 580);
    glEnd();
}

// ─── Main display function (called every frame) ─────────────────────────────
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawSky();                                 // 1. background

    // 2. a few stars
    drawStar(100, 500);
    drawStar(200, 540);
    drawStar(600, 520);
    drawStar(700, 490);
    drawStar(150, 420);
    drawStar(650, 430);
    drawStar(300, 550);
    drawStar(500, 545);

    drawMoon();                                // 3. crescent moon

    drawLantern(150, 320);                     // 4. left lantern
    drawLantern(650, 320);                     // 5. right lantern

    drawText();                                // 6. greeting
    drawBorder();                              // 7. border

    glutSwapBuffers();
}

// ─── Setup the 2D coordinate system ────────────────────────────────────────
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);              // x: 0-800, y: 0-600
    glMatrixMode(GL_MODELVIEW);
}

// ─── Entry point ────────────────────────────────────────────────────────────
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Eid Mubarak Card");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
