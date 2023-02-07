//opengl for reading rgba from input file and displaying background in that color
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<stdio.h>
#include<stdlib.h>
GLfloat r=0.0,g=0.0,b=0.0,a=0.0;
//render function
void renderFunction()
{
	glClearColor(r,g,b,a);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
//get rgba from input file
void getRGBA()
{
	FILE *fp;
	fp=fopen("input.txt","r");
	fscanf(fp,"%f %f %f %f",&r,&g,&b,&a);
	fclose(fp);
}
int main(int argc,char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Practice Question 1");
    
	glutDisplayFunc(renderFunction);
	glutMainLoop();
	return 0;
}

