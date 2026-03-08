#include <GL/glut.h>
#include <iostream>
#include <cstring>
using namespace std;

void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    for (int i = 0; i < strlen(text); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}
void display()
{

glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0);

glBegin(GL_TRIANGLES);

glVertex2f(0,0);
glVertex2f(0,-0.8);
glVertex2f(0.2,0.2);// under right

glVertex2f(0,0);
glVertex2f(0,-0.8);
glVertex2f(-0.2,0.2);// under left

glVertex2f(0,-0.8);
glVertex2f(0.3,-0.6);
glVertex2f(0.2,0.5); // outer right

glVertex2f(0,-0.8);
glVertex2f(-0.3,-0.6);
glVertex2f(-0.2,0.5); //outer left

glVertex2f(0,0);
glVertex2f(0.2,0.2);
glVertex2f(0,0.1); // right hat

glVertex2f(0,0);
glVertex2f(-0.2,0.2);
glVertex2f(0,0.1);  // left hat

glColor3f(0,0,0);

    
glVertex2f(0.05,-0.15);
glVertex2f(0.2,0);
glVertex2f(0.18,-0.12); // right eye

glVertex2f(-0.05,-0.15);
glVertex2f(-0.2,0);
glVertex2f(-0.18,-0.12); // left eye

glVertex2f(0,-0.32);
glVertex2f(0.2,-0.2);
glVertex2f(0.2,-0.5); // right cheek

glVertex2f(0,-0.32);
glVertex2f(-0.2,-0.2);
glVertex2f(-0.2,-0.5); // left cheek

glVertex2f(0,-0.32);
glVertex2f(0.2,-0.5);
glVertex2f(-0.2,-0.5); //  cheek connector

glVertex2f(0,-0.7);
glVertex2f(0.2,-0.5);
glVertex2f(-0.2,-0.5); // jaw


    
glEnd();

glColor3f(1,0,0);    
    
glColor3f(1, 1, 1);
drawText(0.5, 0.8, "Muhammad Ali");
    
glFlush();
}

int main(int argc, char** argv)
{

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1280, 800);
glutCreateWindow("Display");
glutDisplayFunc(display);
glutMainLoop();

return 0;
}