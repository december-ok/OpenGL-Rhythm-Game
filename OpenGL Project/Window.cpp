#include "Window.h"
#include "Render.h"
#include <iostream>

Window* window;
unsigned int Round::frame;

Window::Window()
{
	window = this;
	for (int i = 0; i < LINES; i++) {
		line_input[i] = 0;
	}
	this->round = new Round(WE_WERE_YONG);
	
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
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);


	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshapeFunction);
	glutKeyboardFunc(set_keyboard_callback);
	glutKeyboardUpFunc(unset_keyboard_callback);
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
	window->round->update();
	
	glClear(GL_COLOR_BUFFER_BIT);
	window->round->render();
	
	glutSwapBuffers();
}

void timer_callback(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer_callback, 0);
}

/*수정한 부분: D 입력*/
void set_keyboard_callback(unsigned char key, int x, int y)
{
	if (key == 'd' || key == 'D') {
		window->round->setInput('d');
		int d_frame = window->round->getFrame();
		int d_delay = window->round->getNoteDelay(0, d_frame);
		if (d_delay != 200) {
			// 입력이 존재함
			d_delay -= 5;
			printf("%d\n", d_delay);

			// 판정 출력 - 전달해주어야 함
			if (abs(d_delay) <= 10) {
				printf("Perfect!!\n");
			}
			else if (abs(d_delay) <= 20) {
				printf("Great!\n");
			}
			else if (abs(d_delay) <= 30) {
				printf("Good\n");
			}
			else if (abs(d_delay <= 40)) {
				printf("Bad\n");
			}
			else {
				printf("Miss\n");
			}

			// 판정 입력한 노트 제거
			window->round->deleteNote(0, (d_delay + 5) + d_frame);

		}
	}
	else if (key == 'f' || key == 'F') {
		window->round->setInput('f');
	}
	else if (key == 'j' || key == 'J') {
		window->round->setInput('j');
	}
	else if (key == 'k' || key == 'K') {
		window->round->setInput('k');
	}
}

void unset_keyboard_callback(unsigned char key, int x, int y)
{
	if (key == 'd' || key == 'D') {
		window->round->unsetInput('d');
	}
	else if (key == 'f' || key == 'F') {
		window->round->unsetInput('f');
	}
	else if (key == 'j' || key == 'J') {
		window->round->unsetInput('j');
	}
	else if (key == 'k' || key == 'K') {
		window->round->unsetInput('k');
	}
}