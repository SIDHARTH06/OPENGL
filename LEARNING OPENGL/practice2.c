#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <GL/glut.h>

using namespace std;

struct Point {
    float x, y, z;
};

vector<Point> vertices;

void readFromFile(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    while (!feof(fp)) {
        Point p;
        if (fscanf(fp, "%f%f%f", &p.x, &p.y, &p.z) == 3) {
            vertices.push_back(p);
        }
    }
    fclose(fp);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    for (int i = 0; i < vertices.size(); i++) {
        glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    readFromFile("rectangular_strip.txt");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rectangular Strip Plot");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
