/*
 *
 * To be deleted and replaced by a real main at a later stage
 * simply used to test dependacies, and to check compile on other
 * classes to be included.
 *
 *
 */

#include <GL\freeglut.h> // Note that this is the GL folder found in the project solution, not the GL folder on C:
#include "Graphics.h"

int main(int argc, char** argv)
{
	int WindowStartX = 350, WindowStartY = 50;
	int WindowWidth = 720;
	int WindowHeight = 480;

	//Setup OpenGL
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA); 		

	//Setup main window
	glutInitWindowPosition(WindowStartX, WindowStartY);
	glutInitWindowSize(WindowWidth, WindowHeight);
	glutCreateWindow("Test");
	glutMainLoop();

	return 0;
}