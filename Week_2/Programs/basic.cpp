#include<GL/glut.h>

void  display_triangle(){
glClear(GL_COLOR_BUFFER_BIT); //Clears all colors which were being displayed 

glColor3f(1,1,0); // Sets color to yellow, uses RGB combination

// Two Triangles
glBegin(GL_TRIANGLES); // Tells rendering engine that three vertices will form a triangle
glVertex2f(-0.5f,0.0f); // Coordinates of Vertices
glVertex2f(0.5f,0.0f);
glVertex2f(0.0f,0.5f);
glEnd(); 

glBegin(GL_TRIANGLES);
glVertex2f(-0.5f,-0.1f);
glVertex2f(0.5f,-0.1f);
glVertex2f(0.0f,-0.5f);
glEnd(); 

// My name 
glBegin(GL_TRIANGLES);
glVertex2f(0.5f,0.5f);
glVertex2f(0.5f,0.49f);
glVertex2f(0.51f,0.49f);
glEnd(); // M

glBegin(GL_TRIANGLES);
glVertex2f(0.51f,0.49f);
glVertex2f(0.52f,0.49f);
glVertex2f(0.52f,0.5f);
glEnd(); // M
    
glBegin(GL_TRIANGLES);
glVertex2f(0.5f,0.49f);
glVertex2f(0.502f,0.48f);
glVertex2f(0.5f,0.47f);
glEnd(); // M

glBegin(GL_TRIANGLES);
glVertex2f(0.52f,0.5f);
glVertex2f(0.503f,0.49f);
glVertex2f(0.52f,0.47f);
glEnd(); // M

glBegin(GL_TRIANGLES);
glVertex2f(0.54f,0.5f);
glVertex2f(0.54f,0.47f);
glVertex2f(0.545f,0.47f);
glEnd(); // U
    
glBegin(GL_TRIANGLES);
glVertex2f(0.545f,0.47f);
glVertex2f(0.56f,0.5f);
glVertex2f(0.56f,0.47f);
glEnd(); // U

glBegin(GL_TRIANGLES);
glVertex2f(0.5875f,0.485f);
glVertex2f(0.58f,0.5f);
glVertex2f(0.58f,0.47f);
glEnd(); // H

glBegin(GL_TRIANGLES);
glVertex2f(0.5875f,0.485f);
glVertex2f(0.5955f,0.5f);
glVertex2f(0.5955f,0.47f);
glEnd(); // H

glBegin(GL_TRIANGLES);
glVertex2f(0.618f,0.482f);
glVertex2f(0.61f,0.5f);
glVertex2f(0.61f,0.47f);
glEnd(); // A

glBegin(GL_TRIANGLES);
glVertex2f(0.618f,0.482f);
glVertex2f(0.6255f,0.5f);
glVertex2f(0.6255,0.47f);
glEnd(); // A    

glBegin(GL_TRIANGLES);
glVertex2f(0.618f,0.489f);
glVertex2f(0.61f,0.5f);
glVertex2f(0.6255,0.5f);
glEnd(); // A

glBegin(GL_TRIANGLES);
glVertex2f(0.6355f,0.5f); 
glVertex2f(0.6355f,0.488f);
glVertex2f(0.645f,0.488f); 
glEnd(); // M

glBegin(GL_TRIANGLES);
glVertex2f(0.645f,0.488f); 
glVertex2f(0.656f,0.488f); 
glVertex2f(0.656f,0.5f); 
glEnd(); // M
    
glBegin(GL_TRIANGLES);
glVertex2f(0.6355f,0.488f);
glVertex2f(0.6355f,0.47f);
glVertex2f(0.6371f,0.479f);
glEnd(); // M

glBegin(GL_TRIANGLES);
glVertex2f(0.656f,0.488f);
glVertex2f(0.656f,0.47f);
glVertex2f(0.6399f,0.488f);
glEnd(); // M


glBegin(GL_TRIANGLES);
glVertex2f(0.67f,0.5f); 
glVertex2f(0.67f,0.488f);  
glVertex2f(0.678f,0.488f); 
glEnd(); // M

glBegin(GL_TRIANGLES);
glVertex2f(0.6865f,0.5f); 
glVertex2f(0.6865f,0.488f); 
glVertex2f(0.678f,0.488f);  
glEnd(); // M
    
glBegin(GL_TRIANGLES);
glVertex2f(0.67f,0.488f);
glVertex2f(0.67f,0.47f);
glVertex2f(0.673f,0.479f);
glEnd(); // M

glBegin(GL_TRIANGLES);
glVertex2f(0.6865f,0.488f);
glVertex2f(0.6865f,0.47f);
glVertex2f(0.67f,0.488f);
glEnd(); // M

glBegin(GL_TRIANGLES);
glVertex2f(0.708f,0.482f);
glVertex2f(0.70f,0.5f);
glVertex2f(0.70,0.47f);
glEnd(); // A

glBegin(GL_TRIANGLES);
glVertex2f(0.708f,0.482f);
glVertex2f(0.7155f,0.5f);
glVertex2f(0.7155f,0.47f);
glEnd(); // A

glBegin(GL_TRIANGLES);
glVertex2f(0.708f,0.489f);
glVertex2f(0.7155f,0.5f);
glVertex2f(0.7,0.5f);
glEnd(); // A

glBegin(GL_TRIANGLES);
glVertex2f(0.73f,0.5f);
glVertex2f(0.73f,0.485f);
glVertex2f(0.738f,0.5f);
glEnd(); // D

glBegin(GL_TRIANGLES);
glVertex2f(0.73f,0.485f);
glVertex2f(0.73f,0.47f);
glVertex2f(0.738f,0.47f);
glEnd(); // D

glBegin(GL_TRIANGLES);
glVertex2f(0.738f,0.5f);
glVertex2f(0.7478f,0.485f);
glVertex2f(0.738f,0.47f);
glEnd(); // D
//
glBegin(GL_TRIANGLES);
glVertex2f(0.77f,0.5f);
glVertex2f(0.77f,0.47f);
glVertex2f(0.7775f,0.485f);
glEnd(); // A

glBegin(GL_TRIANGLES);
glVertex2f(0.785f,0.5f);
glVertex2f(0.785f,0.47f);
glVertex2f(0.7775f,0.485f);
glEnd(); // A

glBegin(GL_TRIANGLES);
glVertex2f(0.77f,0.5f);
glVertex2f(0.785f,0.5f);
glVertex2f(0.7775f,0.4875f);
glEnd(); // A

glBegin(GL_TRIANGLES);
glVertex2f(0.8f,0.5f);
glVertex2f(0.8f,0.47f);
glVertex2f(0.805f,0.479f);
glEnd(); // L

glBegin(GL_TRIANGLES);
glVertex2f(0.815f,0.47f);
glVertex2f(0.805,0.479f);
glVertex2f(0.8f,0.47f);
glEnd(); // L

glBegin(GL_TRIANGLES);
glVertex2f(0.825f,0.505f);
glVertex2f(0.829f,0.479f);
glVertex2f(0.825f,0.47f);
glEnd(); // I
    
glFlush(); // Forces OpenGL to display everything
}

int main(int argc, char** argv){
glutInit(&argc, argv); // Initializing Glut 

glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Setting Display Mode
glutInitWindowSize(640, 480); // Setting Window size

glutCreateWindow("GL + GLU + GLUT Example"); // Sets window title bar

glutDisplayFunc(display_triangle); // passes our display function as a parameter, tells glut what grpahics will appear on the windows as we initialized it before

glutMainLoop(); // a constant loop, till we forcefully stop it by closing the window 

return 0; // Practically has nothing to return 
}

