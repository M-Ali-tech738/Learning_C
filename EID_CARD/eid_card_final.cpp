#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include "RGBA.h"

const int   WIN_W  = 800;
const int   WIN_H  = 600;
const float PI     = 3.14159f;
float       gTimer = 0.0f;

RGBApixmap pix[1];

struct Star { float x, y, r, phase; };
const int N_STARS = 110;
Star      stars[N_STARS];

void initStars() {
    srand(7);
    for (int i = 0; i < N_STARS; i++) {
        stars[i].x     = 40  + rand() % (WIN_W - 80);
        stars[i].y     = 200 + rand() % (WIN_H - 250);
        stars[i].r     = 0.7f + (rand() % 18) / 10.0f;
        stars[i].phase = (rand() % 628) / 100.0f;
    }
}

void drawCircle(float cx, float cy, float r, int seg = 80) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= seg; i++) {
        float a = 2.0f * PI * i / seg;
        glVertex2f(cx + r * cosf(a), cy + r * sinf(a));
    }
    glEnd();
}

void drawRing(float cx, float cy, float r1, float r2, int seg = 80) {
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= seg; i++) {
        float a = 2.0f * PI * i / seg;
        glVertex2f(cx + r1 * cosf(a), cy + r1 * sinf(a));
        glVertex2f(cx + r2 * cosf(a), cy + r2 * sinf(a));
    }
    glEnd();
}

void drawStar5(float cx, float cy, float outer, float inner) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 10; i++) {
        float a = PI / 2.0f + i * PI / 5.0f;
        float r = (i % 2 == 0) ? outer : inner;
        glVertex2f(cx + r * cosf(a), cy + r * sinf(a));
    }
    glEnd();
}

void drawRect(float x1, float y1, float x2, float y2) {
    glBegin(GL_QUADS);
    glVertex2f(x1, y1); glVertex2f(x2, y1);
    glVertex2f(x2, y2); glVertex2f(x1, y2);
    glEnd();
}

void drawDomeUp(float cx, float baseY, float rw, float rh, int seg = 60) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, baseY);
    for (int i = 0; i <= seg; i++) {
        float a = PI * i / seg;
        glVertex2f(cx + rw * cosf(a), baseY + rh * sinf(a));
    }
    glEnd();
}

void drawBackground() {
    glBegin(GL_QUADS);
    glColor3f(0.50f, 0.27f, 0.08f);  glVertex2f(0,     0);
    glColor3f(0.50f, 0.27f, 0.08f);  glVertex2f(WIN_W, 0);
    glColor3f(0.12f, 0.07f, 0.25f);  glVertex2f(WIN_W, WIN_H);
    glColor3f(0.12f, 0.07f, 0.25f);  glVertex2f(0,     WIN_H);
    glEnd();
}

void drawStars() {
    for (int i = 0; i < N_STARS; i++) {
        float b = 0.30f + 0.70f * sinf(gTimer * 1.3f + stars[i].phase);
        glColor4f(1.0f, 0.96f, 0.78f, b);
        drawCircle(stars[i].x, stars[i].y, stars[i].r);
    }
}

void drawMoon(float cx, float cy) {
    glColor4f(1.0f, 0.88f, 0.28f, 0.07f);  drawCircle(cx, cy, 82);
    glColor4f(1.0f, 0.88f, 0.28f, 0.13f);  drawCircle(cx, cy, 64);
    glColor3f(1.0f, 0.88f, 0.20f);          drawCircle(cx, cy, 50);
    glColor3f(0.12f, 0.07f, 0.25f);         drawCircle(cx + 20, cy + 8, 40);
    glColor3f(1.0f, 0.88f, 0.20f);          drawStar5(cx + 63, cy + 24, 13, 5);
}

void drawGlassDome(float cx, float baseY, float rw, float rh) {
    float col[6][3] = {
        {0.85f, 0.15f, 0.15f}, {0.15f, 0.35f, 0.85f},
        {0.10f, 0.65f, 0.30f}, {0.75f, 0.20f, 0.70f},
        {0.90f, 0.55f, 0.05f}, {0.10f, 0.60f, 0.65f},
    };
    int petals = 8;
    glColor4f(0.08f, 0.04f, 0.18f, 0.9f);
    drawDomeUp(cx, baseY, rw, rh);
    for (int p = 0; p < petals; p++) {
        float a1 = PI * p / petals;
        float a2 = PI * (p + 1) / petals;
        float* c = col[p % 6];
        glColor4f(c[0], c[1], c[2], 0.55f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, baseY);
        int steps = 12;
        for (int i = 0; i <= steps; i++) {
            float a = a1 + (a2 - a1) * i / steps;
            glVertex2f(cx + rw * cosf(a), baseY + rh * sinf(a));
        }
        glEnd();
        glColor4f(c[0]*1.2f, c[1]*1.2f, c[2]*1.2f, 0.30f);
        glBegin(GL_TRIANGLE_FAN);
        float am = (a1 + a2) / 2.0f;
        glVertex2f(cx + rw*0.5f*cosf(am), baseY + rh*0.5f*sinf(am));
        for (int i = 0; i <= steps; i++) {
            float a = a1 + (a2 - a1) * i / steps;
            glVertex2f(cx + rw*0.85f*cosf(a), baseY + rh*0.85f*sinf(a));
        }
        glEnd();
    }
    glColor4f(0.10f, 0.06f, 0.02f, 1.0f); glLineWidth(1.8f);
    for (int p = 0; p <= petals; p++) {
        float a = PI * p / petals;
        glBegin(GL_LINES);
        glVertex2f(cx, baseY);
        glVertex2f(cx + rw*cosf(a), baseY + rh*sinf(a));
        glEnd();
    }
    glColor4f(1.0f,1.0f,1.0f,0.30f); glLineWidth(3.5f);
    glBegin(GL_LINE_STRIP);
    for (int i = 8; i <= 35; i++) {
        float a = PI * i / 60.0f;
        glVertex2f(cx + rw*0.82f*cosf(a), baseY + rh*0.82f*sinf(a));
    }
    glEnd();
    glColor4f(1.0f,1.0f,1.0f,0.12f); glLineWidth(8.0f);
    glBegin(GL_LINE_STRIP);
    for (int i = 10; i <= 30; i++) {
        float a = PI * i / 60.0f;
        glVertex2f(cx + rw*0.75f*cosf(a), baseY + rh*0.75f*sinf(a));
    }
    glEnd();
    glColor3f(1.0f,0.80f,0.18f); glLineWidth(2.5f);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 60; i++) {
        float a = PI * i / 60.0f;
        glVertex2f(cx + rw*cosf(a), baseY + rh*sinf(a));
    }
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(cx-rw, baseY); glVertex2f(cx+rw, baseY);
    glEnd();
}

void drawMosque() {
    float bR=0.70f,bG=0.45f,bB=0.20f;
    float oR=1.00f,oG=0.80f,oB=0.18f;
    glColor3f(bR,bG,bB); drawRect(0,0,WIN_W,60);
    glColor3f(oR,oG,oB); glLineWidth(3.0f);
    glBegin(GL_LINES); glVertex2f(0,60); glVertex2f(WIN_W,60); glEnd();
    glColor3f(bR,bG,bB); drawRect(368,60,432,170);
    glColor3f(oR,oG,oB); glLineWidth(1.8f);
    for (float lx=378; lx<=422; lx+=11) {
        glBegin(GL_LINES); glVertex2f(lx,60); glVertex2f(lx,170); glEnd();
    }
    drawGlassDome(400,170,125,115);
    glColor3f(bR,bG,bB); drawRect(190,60,248,135);
    glColor3f(oR,oG,oB); glLineWidth(1.4f);
    glBegin(GL_LINES);
    glVertex2f(204,60); glVertex2f(204,135);
    glVertex2f(219,60); glVertex2f(219,135);
    glVertex2f(234,60); glVertex2f(234,135);
    glEnd();
    drawGlassDome(219,135,68,62);
    glColor3f(bR,bG,bB); drawRect(552,60,610,135);
    glColor3f(oR,oG,oB); glLineWidth(1.4f);
    glBegin(GL_LINES);
    glVertex2f(566,60); glVertex2f(566,135);
    glVertex2f(581,60); glVertex2f(581,135);
    glVertex2f(596,60); glVertex2f(596,135);
    glEnd();
    drawGlassDome(581,135,68,62);
    glColor3f(bR,bG,bB);
    drawRect(55,0,80,125); drawRect(48,112,87,127);
    glBegin(GL_TRIANGLES);
    glVertex2f(55,127); glVertex2f(80,127); glVertex2f(67,165);
    glEnd();
    glColor3f(oR,oG,oB); glLineWidth(1.5f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(55,0); glVertex2f(80,0);
    glVertex2f(80,127); glVertex2f(67,165); glVertex2f(55,127);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(48,112); glVertex2f(87,112);
    glVertex2f(48,127); glVertex2f(87,127);
    glEnd();
    glColor3f(bR,bG,bB);
    drawRect(720,0,745,125); drawRect(713,112,752,127);
    glBegin(GL_TRIANGLES);
    glVertex2f(720,127); glVertex2f(745,127); glVertex2f(732,165);
    glEnd();
    glColor3f(oR,oG,oB); glLineWidth(1.5f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(720,0); glVertex2f(745,0);
    glVertex2f(745,127); glVertex2f(732,165); glVertex2f(720,127);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(713,112); glVertex2f(752,112);
    glVertex2f(713,127); glVertex2f(752,127);
    glEnd();
    glColor3f(oR,oG,oB);
    drawCircle(400,285,9); drawCircle(219,197,7);
    drawCircle(581,197,7); drawCircle(67,165,6); drawCircle(732,165,6);
}

void drawLantern(float x, float y, float sc, float r, float g, float b) {
    float flicker = 0.78f + 0.22f * sinf(gTimer * 4.5f + x * 0.05f);
    glColor4f(r,g*0.55f,0.04f,0.09f); drawCircle(x,y,sc*54);
    glColor4f(r,g*0.65f,0.07f,0.15f); drawCircle(x,y,sc*37);
    glColor3f(0.85f,0.68f,0.12f); glLineWidth(2.0f);
    glBegin(GL_LINES); glVertex2f(x,y+sc*44); glVertex2f(x,y+sc*58); glEnd();
    glColor3f(0.85f,0.65f,0.10f);
    glBegin(GL_QUADS);
    glVertex2f(x-sc*16,y+sc*30); glVertex2f(x+sc*16,y+sc*30);
    glVertex2f(x+sc*11,y+sc*44); glVertex2f(x-sc*11,y+sc*44);
    glEnd();
    glColor3f(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f(x-sc*19,y-sc*28); glVertex2f(x+sc*19,y-sc*28);
    glVertex2f(x+sc*16,y+sc*30); glVertex2f(x-sc*16,y+sc*30);
    glEnd();
    glColor4f(1.0f,1.0f,0.55f,0.32f); glLineWidth(1.2f);
    for (int i=-1; i<=1; i++) {
        glBegin(GL_LINES);
        glVertex2f(x+i*sc*6.5f,y-sc*28); glVertex2f(x+i*sc*6.5f,y+sc*30);
        glEnd();
    }
    glColor3f(0.85f,0.65f,0.10f);
    glBegin(GL_QUADS);
    glVertex2f(x-sc*19,y-sc*28); glVertex2f(x+sc*19,y-sc*28);
    glVertex2f(x+sc*14,y-sc*38); glVertex2f(x-sc*14,y-sc*38);
    glEnd();
    glColor4f(1.0f,0.92f*flicker,0.18f*flicker,1.0f);
    drawCircle(x,y,sc*7.5f*flicker);
    glColor4f(1.0f,1.0f,0.90f,0.95f); drawCircle(x,y,sc*3.0f);
}

void drawText() {
    glViewport(0, 0, WIN_W, WIN_H);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIN_W, 0, WIN_H);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRasterPos2f(150, 150);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_EQUAL, 1.0f);
    pix[0].mDraw();
    glDisable(GL_ALPHA_TEST);


    const char* dedication = "To Ms. Humaira Tariq";
    float dw = glutBitmapLength(GLUT_BITMAP_HELVETICA_18,
                                (const unsigned char*)dedication);
    glColor3f(1.0f, 0.88f, 0.22f);
    glRasterPos2f(320, 330);
    for (int i = 0; dedication[i]; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, dedication[i]);


    const char* name = "Name: Muhammad Ali";
    const char* seat = "Seat No: B25110206026";
    float nw = glutBitmapLength(GLUT_BITMAP_HELVETICA_12,
                                (const unsigned char*)name);
    float sw = glutBitmapLength(GLUT_BITMAP_HELVETICA_12,
                                (const unsigned char*)seat);
    glColor3f(0.95f, 0.88f, 0.70f);
    glRasterPos2f(550, 45);
    for (int i = 0; name[i]; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, name[i]);
    glRasterPos2f(550, 30);
    for (int i = 0; seat[i]; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, seat[i]);
}

void drawBorder() {
    glColor3f(0.95f,0.75f,0.12f); glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(14,14); glVertex2f(WIN_W-14,14);
    glVertex2f(WIN_W-14,WIN_H-14); glVertex2f(14,WIN_H-14);
    glEnd();
    glColor3f(0.72f,0.50f,0.08f); glLineWidth(1.5f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(22,22); glVertex2f(WIN_W-22,22);
    glVertex2f(WIN_W-22,WIN_H-22); glVertex2f(22,WIN_H-22);
    glEnd();
    glColor3f(1.0f,0.85f,0.20f);
    drawStar5(36,36,13,5); drawStar5(WIN_W-36,36,13,5);
    drawStar5(36,WIN_H-36,13,5); drawStar5(WIN_W-36,WIN_H-36,13,5);
    glColor3f(0.90f,0.70f,0.12f);
    for (int i=1; i<=15; i++) {
        float x=14+i*(WIN_W-28)/16.0f;
        drawCircle(x,14,2.5f); drawCircle(x,WIN_H-14,2.5f);
    }
    for (int i=1; i<=11; i++) {
        float y=14+i*(WIN_H-28)/12.0f;
        drawCircle(14,y,2.5f); drawCircle(WIN_W-14,y,2.5f);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    drawBackground();
    drawStars();
    drawMosque();
    drawMoon(600, 490);
    drawLantern(118, 320, 1.00f, 0.85f, 0.22f, 0.08f);
    drawLantern(682, 320, 1.00f, 0.15f, 0.42f, 0.85f);
    drawLantern(65,  445, 0.62f, 0.25f, 0.72f, 0.22f);
    drawLantern(735, 445, 0.62f, 0.70f, 0.22f, 0.65f);
    drawText();
    drawBorder();
    glDisable(GL_BLEND);
    glutSwapBuffers();
}

void update(int) {
    gTimer += 0.025f;
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIN_W, 0, WIN_H);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    initStars();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(WIN_W, WIN_H);
    glutCreateWindow("Eid Mubarak");
    pix[0].readBMPFile("eid_logo.bmp", 1);
    pix[0].setChromaKey(0, 0, 0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}
