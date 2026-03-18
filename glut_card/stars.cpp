#include <GL/glut.h>
#include <cmath>
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846 // Define M_PI if not available
#endif

// --- Global Variables for Progression ---
int current_component = -1; // -1: Nothing drawn yet, 0: Center, 1-11: Progressive vertices
float cx = 0.0f, cy = 0.0f; // Star center coordinates
float outerR = 0.5f;        // Outer radius (star spikes)
float innerR = 0.2f;        // Inner radius (star valleys)
int display_window_width = 800;
int display_window_height = 800;

// --- Timer Callback Function ---
void timerFunc(int value) {
    // There are 12 steps total: center vertex (1) + edge vertices (11)
    if (current_component < 11) {
        current_component++;
        std::cout << "Drawing component: " << current_component << std::endl;

        // Request an update to the display based on the new current_component
        glutPostRedisplay();

        // Schedule the next component to draw in 5000 milliseconds (5 seconds)
        glutTimerFunc(5000, timerFunc, current_component);
    }
}

// --- Modified progressive drawStar Function ---
void drawStarProgressive(float cx, float cy, float outerR, float innerR) {
    // Define the color for the star
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow Star

    // Start drawing the GL_TRIANGLE_FAN primitive
    glBegin(GL_TRIANGLE_FAN);

    // 1. Center Vertex (always drawn if we are past stage -1)
    if (current_component >= 0) {
        glVertex2f(cx, cy);
    }

    // 2. Progressive Edge Vertices (0 through current_component-1)
    for (int i = 0; i < current_component; i++) {
        // We only draw up to the 11th vertex (index 10) to complete the 10-point star
        if (i < 11) {
            // Calculate angle: 90 degrees offset + 36 degrees per step
            float angle = i * M_PI / 2.0f;

            // Alternate radius: even index -> outer, odd index -> inner
            float r = (i % 2 == 0) ? outerR : innerR;

            // Generate the progressive vertex
            glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
        }
    }

    // Finish drawing the primitive
    glEnd();
}

// --- Display Function ---
void display() {
    // 1. Clear the screen to a deep blue color
    glClearColor(0.0f, 0.0f, 0.3f, 1.0f); // Deep blue background
    glClear(GL_COLOR_BUFFER_BIT);

    // 2. Call our progressive star function with the parameters
    drawStarProgressive(cx, cy, outerR, innerR);

    // 3. Force all OpenGL commands to execute
    glFlush();
}

// --- Initialization Function ---
void init() {
    // Set up the projection (2D coordinate system from -1 to 1)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Define the view volume
    glMatrixMode(GL_MODELVIEW);
}

// --- Main Function ---
int main(int argc, char** argv) {
    // 1. Initialize GLUT and set display mode
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // 2. Create and position the window
    glutInitWindowSize(display_window_width, display_window_height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Progressive OpenGL Star Assembly (5 sec/vertex)");

    // 3. Register callback functions
    glutDisplayFunc(display);
    init(); // Run custom initialization

    // 4. Start the progressive drawing by triggering the first timer event
    //    We start current_component at 0 immediately.
    std::cout << "Star assembly beginning (5-second intervals)..." << std::endl;
    current_component = -1; // Reset to the initial state
    glutTimerFunc(0, timerFunc, 0); // Start timer immediately

    // 5. Enter the GLUT event processing loop
    glutMainLoop();

    return 0;
}
