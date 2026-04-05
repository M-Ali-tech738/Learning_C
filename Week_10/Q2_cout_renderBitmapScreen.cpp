// Q2 - Week 10 Assignment
// Name: Muhammad Ali | Seat No: B25110206026
// Adding cout OUTSIDE and INSIDE the loop in renderBitmapScreen
// in order to print addresses and characters at each address

#include <iostream>
#include <GL/glut.h>
using namespace std;

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// renderBitmapScreen WITH cout statements added
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void renderBitmapScreen(float x, float y, void* font, char* string) {

    // ---- cout OUTSIDE the loop ----
    // Print the starting address of the entire string
    cout << "=== renderBitmapScreen called ===" << endl;
    cout << "Address of string pointer (string itself): " << (void*)string << endl;
    cout << "Value at that address (first char): " << *string << endl;
    cout << "----------------------------------" << endl;

    glRasterPos2f(x, y);

    char* c;
    for (c = string; *c != '\0'; c++) {

        // ---- cout INSIDE the loop ----
        // Print the address of the current character and the character itself
        cout << "Address: " << (void*)c
             << "  |  Character: " << *c << endl;

        glutBitmapCharacter(font, *c);
    }

    // ---- cout OUTSIDE the loop (after) ----
    cout << "=== End of string reached ===" << endl << endl;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);

    char name[] = "Muhammad Ali";  
    renderBitmapScreen(50.0f, 150.0f, GLUT_BITMAP_HELVETICA_18, name);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 300);
    glutCreateWindow("Q2 - cout Inside renderBitmapScreen");

    glClearColor(0.1f, 0.1f, 0.3f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 300);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

