#include <GL/gl.h>

/*OpenGL cannot create a window or handle events by itself.
So this code is not complete and cannot run alone.*/

/* Purpose is to show that GL only draws graphics*/

/* What GL does is that it interacts with gpu, 
draws shapes,
draws graphics.
 What it can not do is that it can not create a window,
 Handle Keyboard or Mouse,
 Run a main loop
*/

// OpenGL is the core rendering engine only
/* in terms of computer graphics, rendering is the process of generating graphics from data */

void drawTriangle()
{
    glClearColor(0, 0, 0, 1);   // Black background
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 0);        // Yellow color

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.5f, -0.5f);
        glVertex2f( 0.0f,  0.5f);
    glEnd();

    glFlush();
}

/* alii@penguin:~/Learning_C/Week_2$ g++ GL.cpp -lGL -o gl
/usr/bin/ld: /usr/lib/gcc/x86_64-linux-gnu/12/../../../x86_64-linux-gnu/Scrt1.o: in function `_start':
(.text+0x17): undefined reference to `main'
collect2: error: ld returned 1 exit status */