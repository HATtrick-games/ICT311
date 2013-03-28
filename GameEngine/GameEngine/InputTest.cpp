#include <GL/freeglut.h>
#include <iostream>
#include "Input.h"

/*
Input* gameInput;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	gameInput->GetKeyboard()->DefineKey("attack", OGLKeys::KEY_A);

	if(gameInput->GetKeyboard()->IsKeyDown("attack"))
	{
		std::cout << "A PRESSED" << std::endl;
	}

	if(gameInput->GetMouse()->IsButtonDown(OGLButton::MOUSE_LEFT))
	{
		std::cout << "LMB Down" << std::endl;
	}

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(200,200);
	glutCreateWindow("Input Test");

	glutIdleFunc(display);

	gameInput = new Input("OPENGL");

	glutMainLoop();

	return 0;
}*/