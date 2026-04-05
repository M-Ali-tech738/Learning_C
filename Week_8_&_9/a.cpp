#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include <stdio.h>      // printf, sprintf
#include <iostream>     // cout, endl
#include <stdlib.h>     // exit()
#include <cmath>        // cos(), sin(), used in drawPolygon()
#include <ctime>        // time(), ctime(), time_t
#include <GL/freeglut.h>
#ifdef _WIN32
    #include <Windows.h>
    #include "wav.h"
#endif
#include "RGBA.h"

using namespace std;

const int WIN_W = 640;
const int WIN_H = 480;
#define NUM_IMAGES 3
RGBApixmap pix[NUM_IMAGES];
int animFrame = 0;

void renderBitmapString(float x, float y, void* font, const char* string)
{
    const char* c;                   // pointer that walks through the string
    glRasterPos2f(x, y);             // move pen to world position (x, y)
    for (c = string; *c != '\0'; c++) // loop until end-of-string marker
        glutBitmapCharacter(font, *c); // draw one character, pen moves right
}

void drawPolygon(int n, float radius, float cx, float cy, float startAngle)
{
    float angle    = startAngle;          // current angle, starts at startAngle
    float angleInc = 2.0f * 3.14159f / n; // how many radians between corners

    glBegin(GL_LINE_LOOP); // start recording vertices for a connected loop
    for (int i = 0; i < n; i++)
    {
        // Calculate this corner's x and y using trigonometry
        float px = cx + radius * cos(angle); // x = centre + radius * cos(angle)
        float py = cy + radius * sin(angle); // y = centre + radius * sin(angle)
        glVertex2f(px, py);                  // add this corner to the polygon
        angle += angleInc;                   // advance to the next corner
    }
    glEnd(); // stop recording — polygon is now ready to be drawn
}


void introScreen()
{
    char buf[100] = {0}; // character buffer — {0} zeroes all 100 bytes

    // ── Title line ──────────────────────────────────────────
    glColor3f(1.0f, 1.0f, 1.0f); // white
    sprintf(buf, ":::::::::::: Lab 05 :::::::::::::");
    renderBitmapString(-80, 40, GLUT_BITMAP_TIMES_ROMAN_24, buf);

    // ── Decorative line ─────────────────────────────────────
    sprintf(buf, "::::::::::::::::::::::::::::::::::::::::");
    renderBitmapString(-80, 35, GLUT_BITMAP_TIMES_ROMAN_24, buf);

    // ── Author name ─────────────────────────────────────────
    glColor3f(0.4f, 0.9f, 1.0f); // light blue
    sprintf(buf, ":::  By: Dr. Humera Tariq  :::");
    renderBitmapString(-60, 20, GLUT_BITMAP_HELVETICA_18, buf);

    // ── Instructions ────────────────────────────────────────
    glColor3f(0.8f, 0.8f, 0.8f); // light grey
    sprintf(buf, "Use Arrow Keys to move");
    renderBitmapString(-55, 5, GLUT_BITMAP_HELVETICA_18, buf);

    glColor3f(0.6f, 1.0f, 0.6f); // light green
    sprintf(buf, "press S to start");
    renderBitmapString(-45, -10, GLUT_BITMAP_HELVETICA_18, buf);
}

void myInit()
{
    // Background colour: black (R=0, G=0, B=0, Alpha=1 fully opaque)
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Alpha test: only draw pixels that are fully opaque (alpha == 1.0)
    // This makes chroma-keyed transparent pixels invisible
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_EQUAL, 1.0f);

    // Viewport: use the entire 640×480 window
    // (x=0, y=0) = bottom-left corner, width=640, height=480
    glViewport(0, 0, WIN_W, WIN_H);

    // Set up the camera (projection matrix)
    // gluOrtho2D(left, right, bottom, top)
    // Maps world coordinates 0..640 (x) and 0..480 (y)
    // directly to the window pixels — 1 unit = 1 pixel
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIN_W, 0, WIN_H);

    // Switch back to model-view matrix (required after setting projection)
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // ── Background music ─────────────────────────────────────
    // Uncomment this line (and ensure backmusic.wav is in the folder)
    // to play looping background audio:
    // PlayBackgroundSound("backmusic.wav");
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // black background
    glViewport(0, 0, WIN_W / 2, WIN_H / 2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIN_W, 0, WIN_H);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0f, 0.0f, 0.0f);

    drawPolygon(5, 150.0f, 100.0f, 120.0f, 0.0f);
    glViewport(WIN_W / 2, 0, WIN_W / 2, WIN_H / 2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIN_W, 0, WIN_H);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRasterPos2f(0.0f, 0.0f);
    pix[0].mDraw(); // pix[0] = bg.bmp
    glRasterPos2f(300.0f, 0.0f);
    pix[2].mDraw(); // pix[2] = ladder.bmp

    glFlush();
}

void myTimer(int t)
{
    animFrame++;               // increment frame counter (for future animation use)
    glutPostRedisplay();       // ask GLUT to call display() soon
    glutTimerFunc(500, myTimer, t); // reschedule: fire again after 500ms
}
int main(int argc, char** argv)
{
    time_t lastTime = time(nullptr);
    cout << "Epoch seconds: " << lastTime << endl;

    cout << "Readable time: " << ctime(&lastTime);
    glutInit(&argc, argv);  // initialise the GLUT library
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);

    glutInitWindowSize(WIN_W, WIN_H);      // window size in pixels: 640 × 480
    glutInitWindowPosition(100, 10);       // top-left corner position on monitor
    glutCreateWindow("Lab 05 - Text, Sound and Images");  // window title
    pix[0].setChromaKey(0, 0, 0);          // black (0,0,0) = transparent
    pix[0].readBMPFile("bg.bmp", 1);       // load background (1 = flip vertically)

    // Mario and ladder have grey chroma key (set inside RGBA.h default)
    pix[1].readBMPFile("mariostanding.bmp", 1); // Mario sprite
    pix[2].readBMPFile("ladder.bmp", 1);         // Ladder sprite

    glutDisplayFunc(display);   // GLUT calls display() when window needs redrawing

    myInit();

    glutTimerFunc(500, myTimer, 1);

    glutMainLoop();

    return 0; // never reached, but required by C++ for int main()
}