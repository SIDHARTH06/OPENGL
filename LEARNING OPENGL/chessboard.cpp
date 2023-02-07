#include <iostream>
#include <vector>
#include <GL/glut.h>
#include <GL/gl.h>
const int WINDOW_SIZE = 500;
std::vector<std::pair<int, int>> points;
bool isDrawing = false;

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            isDrawing = true;
            points.clear();
            points.push_back(std::make_pair(x, WINDOW_SIZE - y));
        } else if (state == GLUT_UP) {
            isDrawing = false;
        }
    }
    glutPostRedisplay();
}

void motion(int x, int y) {
    if (isDrawing) {
        points.push_back(std::make_pair(x, WINDOW_SIZE - y));
        glutPostRedisplay();
    }
}

void display() {
    glClearColor(1, 1, 1, 1); // set background color to white
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0, 0, 0); // set color to black
    glBegin(GL_LINE_STRIP);
    for (auto p : points) {
        glVertex2i(p.first, p.second);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);
    glutCreateWindow("Stroke Plotting");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
    return 0;
}
