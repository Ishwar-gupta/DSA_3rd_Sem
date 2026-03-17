/*
Draw a regular polygon (filled) using OpenGL (freeglut)
*/
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

GLsizei wh = 500, ww = 500;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    int n = 6;               // number of sides (change to 5, 7, 8...)
    float cx = 250, cy = 250;
    float r  = 150;

    glBegin(GL_POLYGON);     // use GL_LINE_LOOP for outline only
    for (int i = 0; i < n; i++)
    {
        float ang = (2.0f * (float)M_PI * i) / n;
        float x = cx + r * cosf(ang);
        float y = cy + r * sinf(ang);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 0);
    glColor3f(1, 1, 1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(ww, wh);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Display a Polygon");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
