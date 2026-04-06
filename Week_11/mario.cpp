
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "RGBA.h"



const int WIN_W = 640;
const int WIN_H = 480;

enum LevelType { INTRO, LEVEL1, LEVEL2 };
LevelType level;

float WL, WR, WB, WT;
int worldWidth  = 50;
int worldHeight = 50;

enum ModeType  { STAY, RUN, JUMP, DEAD };
enum StateType { STANDING, RUNNING1, RUNNING2, RUNNING3, JUMPING, DYING };

ModeType  marioMode  = STAY;
StateType marioState = STANDING;

float marioX = 0.0f;
float marioY = 0.0f;

#define NUM_IMAGES 6          // FIX: was 5, needs 6 for background
RGBApixmap pix[NUM_IMAGES];


void loadMarioImages() {
    pix[0].readBMPFile("MarioStanding.bmp", 1);
    pix[1].readBMPFile("MarioRun1.bmp",     1);
    pix[2].readBMPFile("MarioRun2.bmp",     1);
    pix[3].readBMPFile("MarioRun3.bmp",     1); 
    pix[4].readBMPFile("MarioJump.bmp",     1);
    pix[5].readBMPFile("bg.bmp",            1);  

    for (int i = 0; i < 5; i++)
        pix[i].setChromaKey(192, 192, 192);
}


void changePosition(float dx, float dy) {
    marioX += dx;
    marioY += dy;
}

void setPosition(float x, float y) {
    marioX = x;
    marioY = y;
}


void changeMode(ModeType m) {
    if (marioMode == m) return;

    switch (m) {
        case STAY:  marioState = STANDING; break;
        case RUN:   marioState = RUNNING1; break;
        case JUMP:  marioState = JUMPING;  break;
        case DEAD:  marioState = DYING;    break;
    }
    marioMode = m;
}

void runAnimation() {
    switch (marioState) {
        case RUNNING1: marioState = RUNNING2; break;
        case RUNNING2: marioState = RUNNING3; break;
        case RUNNING3: marioState = RUNNING1; break;
        default:       marioState = RUNNING1; break;
    }
    glRasterPos2f(marioX, marioY);
    pix[marioState].mDraw();
}

void renderMario() {
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_EQUAL, 1.0f);

    switch (marioMode) {
        case STAY:
            glRasterPos2f(marioX, marioY);
            pix[0].mDraw();
            break;
        case RUN:
            runAnimation();
            break;
        case JUMP:
            glRasterPos2f(marioX, marioY);
            pix[4].mDraw();
            break;
        case DEAD:
            break;
    }

    glDisable(GL_ALPHA_TEST);
}

void renderBitmapString(float x, float y, void* font, const char* string) {
    const char* c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
}

void introScreen() {
    char buf[100] = {0};

    glColor3f(1.0f, 0.85f, 0.2f);
    sprintf(buf, "MARIO  GAME");
    renderBitmapString(-70, 20, GLUT_BITMAP_TIMES_ROMAN_24, buf);

    glColor3f(1.0f, 1.0f, 1.0f);
    sprintf(buf, "By: Muhammad Ali");
    renderBitmapString(-55, 5, GLUT_BITMAP_HELVETICA_18, buf);

    glColor3f(0.8f, 0.8f, 0.8f);
    sprintf(buf, "Use Arrow Keys to move");
    renderBitmapString(-65, -15, GLUT_BITMAP_HELVETICA_12, buf);

    sprintf(buf, "Press S to start");
    renderBitmapString(-50, -25, GLUT_BITMAP_HELVETICA_12, buf);
}

void renderBitmap(float x, float y, int imgId) {
    glRasterPos2f(x, y);
    pix[imgId].mDraw();
}

void myInit() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glViewport(0, 0, WIN_W, WIN_H);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(WL, WR, WB, WT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    switch (level) {

        case INTRO:
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(WL, WR, WB, WT);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            introScreen();
            break;

        case LEVEL1: {
            
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(WL, WR, WB, WT);  
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();

            glClearColor(0.5f, 0.8f, 1.0f, 1.0f);  // sky blue

            glEnable(GL_ALPHA_TEST);
            glAlphaFunc(GL_EQUAL, 1.0f);

           
            renderBitmap(WL, WB, 5);

            renderMario();

            glDisable(GL_ALPHA_TEST);
            break;
        }

        case LEVEL2:
            break;
    }

    glutSwapBuffers();
}


void pressKeySpecial(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            changePosition(-5, 0);
            changeMode(RUN);
            break;
        case GLUT_KEY_RIGHT:
            changePosition(5, 0);
            changeMode(RUN);
            break;
        case GLUT_KEY_UP:
            if (marioY < 20)
                changePosition(0, 10);
            changeMode(JUMP);
            break;
        case GLUT_KEY_DOWN:
            break;
    }
    glutPostRedisplay();
}


void releaseKeySpecial(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
        case GLUT_KEY_RIGHT:
            changeMode(STAY);
            break;
        case GLUT_KEY_UP:
            if (marioY != 0)
                setPosition(marioX, 0);
            changeMode(STAY);
            break;
        case GLUT_KEY_DOWN:
            break;
    }
    glutPostRedisplay();
}


void keyboardHandler(unsigned char key, int x, int y) {
    switch (key) {
        case 's':
        case 'S':
            level = LEVEL1;
            
            marioX = WL + 10;
            marioY = WB + 5;
            changeMode(STAY);
            break;
        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
}

void update(int value) {
    if (marioMode == RUN)
        glutPostRedisplay();

    glutTimerFunc(100, update, 0);
}

int main(int argc, char** argv) {

    level = INTRO;
    
    WL = -100; WR = 100;   
    WB = -50;  WT =  50;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(WIN_W, WIN_H);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("Mario Game");

    loadMarioImages();

    glutDisplayFunc(display);
    glutSpecialFunc(pressKeySpecial);
    glutSpecialUpFunc(releaseKeySpecial);
    glutKeyboardFunc(keyboardHandler);

    glutTimerFunc(100, update, 0);

    myInit();
    glutMainLoop();
    return 0;
}
