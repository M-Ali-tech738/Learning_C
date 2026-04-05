// Q1 - Week 10 Assignment
// Name: Muhammad Ali | Seat No: B25110206026
// All 3 functions display text, differences are explained in comments below

#include <iostream>
#include <GL/glut.h>   // OpenGL/GLUT for bitmap rendering
using namespace std;

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// FUNCTION 1: renderBitmapScreen
// Uses GLUT's glutBitmapCharacter to render each character
// at a floating-point (x, y) position on screen.
// Iterates through the string character by character.
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void renderBitmapScreen(float x, float y, void* font, char* string) {
    // Move the raster position to (x, y) in window coordinates
    glRasterPos2f(x, y);

    // Loop through every character in the string
    char* c;
    for (c = string; *c != '\0'; c++) {
        // Render one bitmap character using GLUT
        glutBitmapCharacter(font, *c);
        // After each character, raster position advances automatically
    }
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// FUNCTION 2: print
// Uses integer (x, y) coordinates (pixel-level control).
// Calls glutBitmapCharacter just like renderBitmapScreen
// but accepts int coordinates and font as last parameter.
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void print(int x, int y, char* string, void* font) {
    // Set raster position using integer coordinates
    glRasterPos2i(x, y);

    // Loop through each character and render it
    char* c;
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// FUNCTION 3: drawString
// Simplest version - no position or font parameters.
// Uses a fixed hardcoded raster position.
// Only accepts the string itself.
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void drawString(const char* string) {
    // Fixed position hardcoded at (10, 10)
    glRasterPos2i(10, 10);

    // Loop through each character and render with a default font
    const char* c;
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// Display callback - called by GLUT to draw the window
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen

    // Set drawing color to white
    glColor3f(1.0f, 1.0f, 1.0f);

    // --- Call Function 1 ---
    char text1[] = "Humera Tariq";
    renderBitmapScreen(50.0f, 250.0f, GLUT_BITMAP_HELVETICA_18, text1);

    // --- Call Function 2 ---
    char text2[] = "Programming Fundamentals";
    print(50, 200, text2, GLUT_BITMAP_HELVETICA_18);

    // --- Call Function 3 ---
    drawString("Week 10 Assignment");

    glutSwapBuffers();  // Display the rendered frame
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// main - sets up GLUT window and enters event loop
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 300);
    glutCreateWindow("Q1 - Three Text Functions");

    // Set background color to dark blue
    glClearColor(0.1f, 0.1f, 0.3f, 1.0f);

    // Set up a 2D orthographic projection matching window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 300);  // (left, right, bottom, top)

    glutDisplayFunc(display);  // Register display callback
    glutMainLoop();            // Enter GLUT event loop
    return 0;
}

/*
  ############################################################
  DIFFERENCE BETWEEN THE 3 FUNCTIONS:
  ############################################################
 
  renderBitmapScreen(float x, float y, void* font, char* string)
    - Takes FLOAT coordinates -> sub-pixel precision positioning
    - Font is passed as a parameter (flexible)
    - Uses glRasterPos2f() for float-based positioning
 
  print(int x, int y, char* string, void* font)
    - Takes INT coordinates -> pixel-level positioning only
    - Font is passed as last parameter (different order)
    - Uses glRasterPos2i() for integer-based positioning
 
  drawString(const char* string)
    - NO position parameters -> always draws at a fixed location
    - NO font parameter -> uses a hardcoded default font
    - Least flexible but simplest to call
 
  All 3 achieve the same visual result: drawing text on screen.
  The difference is in how much CONTROL they give the caller.
  ============================================================
 */
