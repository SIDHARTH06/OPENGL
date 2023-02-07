#include<GL/freeglut.h>
#include<GL/gl.h>
GLfloat r=0.0,g=0.0,b=0.0,a=0.0;
void renderFunction()
{
	glClearColor(r,g,b,a);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	glPointSize(5);
	glFlush();
}
void myKeyboardFunction(unsigned char key, int x,int y)
{
	switch(key)
	{
		case 'r':
		{
			r=1.0;
			b=0.0;
			g=0.0;
			glClearColor(r,g,b,a);	
			glClear(GL_COLOR_BUFFER_BIT);
			glFlush();
			break;
		}
		case 'g':
		{
			r=0.0;
			b=0.0;
			g=1.0;
			glClearColor(r,g,b,a);	
			glClear(GL_COLOR_BUFFER_BIT);
			glFlush();
			break;
		}
		case 'b':
		{
			r=0.0;
			b=1.0;
			g=0.0;
			glClearColor(r,g,b,a);	
			glClear(GL_COLOR_BUFFER_BIT);
			glFlush();
			break;
		}
		default:break;
	}
}

int main(int argc,char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Practice Question 1");
	glutKeyboardFunc(myKeyboardFunction);
	glutDisplayFunc(renderFunction);
	glutMainLoop();
	return 0;
}

