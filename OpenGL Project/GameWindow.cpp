#include "GameWindow.h"
#include "MainScene.h"
#include "RoundScene.h"
#include <iostream>

GameWindow* window;
using namespace std;

GameWindow::GameWindow()
{
	window = this;
//	this->scene = new RoundScene(this, CANON);
	this->scene = new MainScene(this);
	
	this->windowInit(0,NULL);
}

GameWindow::~GameWindow()
{
	
}

void GameWindow::windowInit(int argc, char** argv)
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Rhythm Game");

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glShadeModel(GL_SMOOTH);
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);


	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshapeFunction);
	glutKeyboardFunc(set_keyboard_callback);
	glutKeyboardUpFunc(unset_keyboard_callback);
	glutSpecialFunc(set_special_keyboard_callback);
	glutSpecialUpFunc(unset_special_keyboard_callback);
	glutTimerFunc(0, timer_callback, 0);
	init();
	glutMainLoop();
}

void GameWindow::init() {
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
	window->scene->update();
	glClear(GL_COLOR_BUFFER_BIT);
	window->scene->render();
	glutSwapBuffers();
}

void timer_callback(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer_callback, 0);
}

void set_keyboard_callback(unsigned char key, int x, int y)
{
	if (key == 'd' || key == 'D') {
		window->scene->setInput('d');
		window->scene->addInput(0);
	}
	else if (key == 'f' || key == 'F') {
		window->scene->setInput('f');
		window->scene->addInput(1);
	}
	else if (key == 'j' || key == 'J') {
		window->scene->setInput('j');
		window->scene->addInput(2);
	}
	else if (key == 'k' || key == 'K') {
		window->scene->setInput('k');
		window->scene->addInput(3);
	}
	else if (key == 'p' || key == 'P') {
		window->scene->setInput('p');
	}
	else if (key == '[' || key == '{') {
		window->scene->setInput('[');
	}
	else if (key == ']' || key == '}') {
		window->scene->setInput(']');
	}
	else if (key == ',' || key == '<') {
		window->scene->setInput(',');
	}
	else if (key == '.' || key == '>') {
		window->scene->setInput('.');
	}
	else if (key == 13) {
		window->scene->setInput(13);
	}
	else if (key == 27) {
		window->scene->setInput(27);
	}
}

void set_special_keyboard_callback(int key, int x, int y)
{
	if (key == GLUT_KEY_DOWN) {
		window->scene->setInput(GLUT_KEY_DOWN);
	}
	else if (key == GLUT_KEY_UP) {
		window->scene->setInput(GLUT_KEY_UP);
	}
}

void unset_keyboard_callback(unsigned char key, int x, int y)
{
	if (key == 'd' || key == 'D') {
		window->scene->unsetInput('d');
	}
	else if (key == 'f' || key == 'F') {
		window->scene->unsetInput('f');
	}
	else if (key == 'j' || key == 'J') {
		window->scene->unsetInput('j');
	}
	else if (key == 'k' || key == 'K') {
		window->scene->unsetInput('k');
	}
	// q: Blink Test용
	else if (key == 'q' || key == 'Q') {
		window->scene->setInput('q');
	}
	// w: Accel Test용
	else if (key == 'w' || key == 'W') {
		window->scene->setInput('w');
	}
	// w: Slow down Test 용
	else if (key == 'e' || key == 'E') {
		window->scene->setInput('e');
	}
	// r: LieNote Test 용
	else if (key == 'r' || key == 'R') {
		window->scene->setInput('r');
	}
	// t: LieNote Test 용
	else if (key == 't' || key == 'T') {
		window->scene->setInput('t');
	}
	else if (key == 13) {	
		window->scene->unsetInput(13);
	}
}

void unset_special_keyboard_callback(int key, int x, int y)
{
	if (key == GLUT_KEY_DOWN) {
		window->scene->unsetInput(GLUT_KEY_DOWN);
	}
	else if (key == GLUT_KEY_UP) {
		window->scene->unsetInput(GLUT_KEY_UP);
	}
}