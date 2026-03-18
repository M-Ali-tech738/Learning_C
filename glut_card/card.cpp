#include<iostream>
#include<cmath>
#include<GL/glut.h>

const int w=400;
const int h=300;

void drawRandomGlassWindow(float x, float y, float width, float height, int rows, int cols) {
    float dx = width / cols;
    float dy = height / rows;
    float points[rows + 1][cols + 1][2];

    for (int r = 0; r <= rows; r++) {
        for (int c = 0; c <= cols; c++) {
            float offsetX = 0, offsetY = 0;
            if (r > 0 && r < rows && c > 0 && c < cols) {
                offsetX = ((float)rand() / RAND_MAX - 0.5f) * (dx * 0.8f);
                offsetY = ((float)rand() / RAND_MAX - 0.5f) * (dy * 0.8f);
            }
            points[r][c][0] = x + (c * dx) + offsetX;
            points[r][c][1] = y + (r * dy) + offsetY;
        }
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            float p1[2] = {points[r][c][0], points[r][c][1]};
            float p2[2] = {points[r][c+1][0], points[r][c+1][1]};
            float p3[2] = {points[r+1][c+1][0], points[r+1][c+1][1]};
            float p4[2] = {points[r+1][c][0], points[r+1][c][1]};

            // Glass Panes with Alpha (0.6f)
            glBegin(GL_TRIANGLES);
                glColor4f((float)rand()/RAND_MAX, (float)rand()/RAND_MAX, (float)rand()/RAND_MAX, 0.6f);
                glVertex2fv(p1); glVertex2fv(p2); glVertex2fv(p3);

                glColor4f((float)rand()/RAND_MAX, (float)rand()/RAND_MAX, (float)rand()/RAND_MAX, 0.6f);
                glVertex2fv(p1); glVertex2fv(p3); glVertex2fv(p4);
            glEnd();

            // Solid Black Outlines
            glColor4f(0.0, 0.0, 0.0, 1.0f);
            glLineWidth(2.0);
            glBegin(GL_LINE_LOOP);
                glVertex2fv(p1); glVertex2fv(p2); glVertex2fv(p3);
            glEnd();
            glBegin(GL_LINE_LOOP);
                glVertex2fv(p1); glVertex2fv(p3); glVertex2fv(p4);
            glEnd();
        }
    }
}

void drawcircle(float xc, float yc, float rad, float seg){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc,yc);
    for(int i=0; i<=seg; i++){
        glVertex2f(xc+rad*cos(i), yc+rad*sin(i));
    }
    glEnd();
}

// 1. Function to set up transparency
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glEnable(GL_BLEND);
    glBlendFunc(GL_SOURCE0_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_MODELVIEW);
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Positioned in the middle of your 800x600 canvas
    drawRandomGlassWindow(0, 0, 100, 600, 5, 3);
    drawcircle(w, h, 100, 1000);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // Use RGBA for alpha
    glutInitWindowSize(800, 600);
    glutCreateWindow("Stained Glass Window");

    init(); // Setup blending

    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
