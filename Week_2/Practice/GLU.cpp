#include <GL/gl.h>
#include <GL/glu.h>

/* Complex math (camera, perspective, aka pov) is hard in pure OpenGL 
   so the purpose of GLU is to simplify OpenGL */

/* GLU adds:
Camera control (gluLookAt)
Perspective (gluPerspective)
Complex shapes */

// GLU is a helper library built on OpenGL (provides helper functions)
// The program is still incomplete

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // GLU makes perspective EASY
    gluPerspective(60, 1, 1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Camera positioning using GLU
    gluLookAt(0,0,5,  0,0,0,  0,1,0);

    glColor3f(0, 1, 0);

    glBegin(GL_TRIANGLES);
        glVertex3f(-1, -1, 0);
        glVertex3f( 1, -1, 0);
        glVertex3f( 0,  1, 0);
    glEnd();

    glFlush();
}

/* alii@penguin:~/Learning_C/Week_2$ g++ GLU.cpp -lGL -lGLU -o glu
/usr/bin/ld: /usr/lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/Scrt1.o: in function `_start':
(.text+0x17): undefined reference to `main'
collect2: error: ld returned 1 exit status*/