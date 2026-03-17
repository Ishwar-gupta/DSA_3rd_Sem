/*
2.) WAP to draw a Triangle using OpenGL library function
*/
#include <GL/freeglut.h>

GLsizei wh = 500;
GLsizei ww = 500;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(8.0);

    glBegin(GL_TRIANGLES);
        glVertex2i(100,100);
        glVertex2i(400,100);
        glVertex2i(250,400);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(0.0,0.0,0.0,0.0);   // black background
    glColor3f(1.0,1.0,1.0);          // white point

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   // important in Windows
    glutInitWindowSize(ww, wh);
    glutInitWindowPosition(100,100);

    glutCreateWindow("Display a Triangle");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}