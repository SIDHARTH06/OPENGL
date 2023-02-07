#include<GL/freeglut.h>
#include<GL/gl.h>

void renderFunction()
{
	glClearColor(0.0,1.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.2,0.75,0.0);

	//primitive definition
	glBegin(GL_TRIANGLES);
		glVertex2f(0.0,-1.0);
		glColor3f(1.0,0.8,1.0);
		glVertex2f(-0.5,0.5);
		glColor3f(0.0,0.75,1.0);
		glVertex2f(0.5,0.5);
		glColor3f(1.0,0.8,1.0);
		glVertex2f(0.5,-0.5);
	glEnd();
	
	glFlush();
}
int main(int argc,char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("OpenGL -Creating Window");
	glutDisplayFunc(renderFunction);
	glutMainLoop();
	return 0;
}
