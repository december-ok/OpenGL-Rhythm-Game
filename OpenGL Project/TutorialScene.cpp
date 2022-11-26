#include "TutorialScene.h"

TutorialScene::TutorialScene(GameWindow* window)
{
	this->window = window;

	this->init();
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::init()
{
	screenWidth = glutGet(GLUT_SCREEN_WIDTH) / 10;
	screenHeight = glutGet(GLUT_SCREEN_HEIGHT) / 10;
	windowWidth = glutGet(GLUT_WINDOW_WIDTH) / 10;
	windowHeight = glutGet(GLUT_WINDOW_HEIGHT) / 10;
	printf("%f", windowWidth);
}


void TutorialScene::render()
{
	float x = 0;
	float y = 0;
	float width = 30.f;
	float height = 10.f;
	string content = "";

	// ·Î°í
	content = "Rhythm Game";
	glColor3f(1, 1, 1);
	glRasterPos2f(56.5f, 100.f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	content = "EXIT : ESC";
	glColor3f(1, 1, 1);
	glRasterPos2f(110.0f, 100.f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	content = "Controls";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 * 2 + 16, 90.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	content = "Line 1 : \"D\"";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 * 2 + 16, 83.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	content = "Line 2 : \"F\"";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 * 2 + 16, 76.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	content = "Line 3 : \"J\"";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 * 2 + 16, 69.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	content = "Line 4 : \"K\"";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 * 2 + 16, 62.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	content = "PAUSE(SINGLE) : \"P\"";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 * 2 + 16, 55.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}


	content = "BGM Volume up : \"]\"";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 * 2 + 16, 48.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	content = "BGM Volume down : \"[\"";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 * 2 + 16, 41.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	content = "Effect Volume up : \".\"";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 * 2 + 16, 34.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	content = "Effect Volume down : \",\"";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 * 2 + 16, 27.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
	content = "Items";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 - 14, 90.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	content = "HP up";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 - 14, 83.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
	content = "Recovery 30 HP";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 - 2, 83.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
	content = "Reinforce";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 - 14, 76.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
	content = "Reinforce input judgment";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 - 2, 76.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
	content = "Blink";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 - 14, 69.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	content = "blinks note after several times";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 - 2, 69.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
	content = "Accel";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 - 14, 62.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
	content = "gradually increasing note speed";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 - 2, 62.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
	content = "Slow down";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 - 14, 55.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	content = "gradually decreasing note speed";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 - 2, 55.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
	content = "Lie Note";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 - 14, 48.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	content = "Do not touch 'Lie Note'.";
	glColor3f(1, 1, 1);
	glRasterPos2f(windowWidth / 3 - 2, 48.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
	content = ":";
	for (int i = 0; i < 6; i++) {
		glRasterPos2f(windowWidth / 3 - 3, 83.0f - 7.0f*float(i));
		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
		}
	}
	content = "Notes";
	glColor3f(1, 1, 1);
	glRasterPos2f(1.0f, 90.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	switch (num / 60)
	{
	case 0:
		glColor3f(1, 0.8f, 0);
		break;
	case 1:
		glColor3f(0, 0.65f, 1);
		break;
	case 2:
		glColor3f(0.19f, 0.65f, 0.32f);
		break;
	case 3:
		glColor3f(0.9f, 1, 0.15f);
	default:
		break;
	}

	glRectd(1.0f, 85.0f, 5.0f, 86.0f);

	glRectd(1.0f, 55.0f, 5.0f, 75.0f);

	content = ": Normal Note";
	glColor3f(1, 1, 1);
	glRasterPos2f(6.0f, 85.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	content = ": Long Note";
	glColor3f(1, 1, 1);
	glRasterPos2f(6.0f, 57.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	glColor3f(temp, temp2, 0);
	glRectd(1.0f, 44.0f, 5.0f, 45.0f);

	content = ": Highlight Note";
	glColor3f(1, 1, 1);
	glRasterPos2f(6.0f, 44.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	glColor3f(1, 1, 1);
	glRectd(1.0f, 34.0f, 5.0f, 35.0f);

	content = ": Lie Note";
	glColor3f(1, 1, 1);
	glRasterPos2f(6.0f, 34.0f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	glBegin(GL_LINE_LOOP);
	glVertex2f(0, 95.0f);
	glVertex2f(windowWidth, 95.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(windowWidth / 3 - 15, 0);
	glVertex2f(windowWidth / 3 - 15, 95.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(windowWidth / 3 * 2 + 15, 0);
	glVertex2f(windowWidth / 3 * 2 + 15, 95.0f);
	glEnd();



}

void TutorialScene::update()
{
	f_float = f_float + 1;
	temp = (sin(f_float / 5) + 1) / 8 + 0.75;
	temp2 = (cos(f_float / 5) + 1) / 8 + 0.75;


	if (exitKey) {
		this->window->scene = new MainScene(this->window);
		free(this);
	}

	this->num = (this->num + 1) % 240;
}


void TutorialScene::setInput(unsigned char input) {

	if (input == 27) {
		exitKey = true;
	}
}

void TutorialScene::unsetInput(unsigned char input) {

}

void TutorialScene::checkInput()
{
}

void TutorialScene::addInput(int)
{
}



