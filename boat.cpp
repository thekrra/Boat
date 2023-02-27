
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <iostream>
using namespace std;


float shift = 0; // variable that moves the boat

void init(void)
{ /* here I prepare the window for displaying on it */
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 100, 0.0, 50);
}
void moving_boat() {
    // we want to draw moving boat

    
    // sea
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.3, 1);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(0, 18);
    glVertex2f(150, 18);
    glVertex2f(150, 0);

    glEnd();


    // boat
    glColor3f(0.5, 0.0, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(45 + shift, 20);
    glVertex2f(5 + shift, 20);
    glVertex2f(15 + shift, 10);
    glVertex2f(35 + shift, 10);

    glEnd();


    // flag
    glColor3f(0.5, 0.4, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(25 + shift, 30);
    glVertex2f(25 + shift, 25);
    glVertex2f(17.943 + shift, 25.019);

    glEnd();

    
    // the flag holder
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(25 + shift, 25.0);
    glVertex2f(25 + shift, 20);
    glVertex2f(23 + shift, 20);
    glVertex2f(23 + shift, 25);

    glEnd();

    glutSwapBuffers();
}



void keyStroke(int key, int x, int y) {
    switch (key)
    {
    case GLUT_KEY_LEFT:
        shift--;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        shift++;
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        
       
    }



}


int main(int argc, char** argv)
{
    cout << "moving the boat with left and right arrows" << endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(1000, 600); //sets the initial window size
    glutCreateWindow("Boat Program"); // creates the window with name line
    init();
    glutDisplayFunc(moving_boat);
    glutSpecialFunc(keyStroke);
    glutMainLoop(); // enters the GLUT event processing loop
    
    return 0;
}
