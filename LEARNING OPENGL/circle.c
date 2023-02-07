#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

const int WINDOW_SIZE = 500;
const int RADIUS = 100;
const int CIRCLE_X = WINDOW_SIZE / 2;
const int CIRCLE_Y = WINDOW_SIZE / 2;
const int LINE_WIDTH = 5;

void display() {
    glClearColor(0, 0, 0, 1); // set background color to black
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, WINDOW_SIZE, WINDOW_SIZE);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, WINDOW_SIZE, 0, WINDOW_SIZE);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glScalef(1, -1, 1);
glTranslatef(0, -WINDOW_SIZE, 0);

    glColor3f(1, 1, 1); // set color to white
    glLineWidth(LINE_WIDTH);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(CIRCLE_X + RADIUS * cos(degInRad), CIRCLE_Y + RADIUS * sin(degInRad));
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);
    glutCreateWindow("Ring");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
