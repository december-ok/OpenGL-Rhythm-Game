#include "Window.h"
#include "include/GL/glut.h"
#include <iostream>

Window* window;

Window::Window()
{
	window = this;
	this->round = new Round("TEST");
	
	this->windowInit(0,NULL);
}

Window::~Window()
{
	
}

void Window::windowInit(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Rhythm Game");

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glShadeModel(GL_SMOOTH);

	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshapeFunction);
	glutTimerFunc(0, timer_callback, 0);
	init();
	glutMainLoop();
}

void Window::init() {
	glClearColor(0.0, 0.0, 0.0, 0.5f);
}

void reshapeFunction(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, COLUMS, 0, ROWS, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display_callback() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	// 1. 렌더링
	window->round->render();

	// 2. 입력 받음

	// 3. 기타 계산
	glutSwapBuffers();
}

void timer_callback(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer_callback, 0);
}

void Window::keyboard_callback(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		break;
	case GLUT_KEY_DOWN:
		break;
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		break;
	}
}