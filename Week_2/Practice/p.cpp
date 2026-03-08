#include <GL/glut.h>

void display(){
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,1);
glBegin(GL_POLYGON);

glVertex2f(-0.5f,0.0f);
glVertex2f(0.5f,0.0f);
glVertex2f(0.0f,0.5f);


glEnd();
}

int main(int argc, char** argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(640, 480);
glutCreateWindow("Hello");
glutDisplayFunc(display);
glutMainLoop();
}