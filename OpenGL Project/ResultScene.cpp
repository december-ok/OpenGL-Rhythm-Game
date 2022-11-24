#include "ResultScene.h"

ResultScene::ResultScene(GameWindow*)
{
	this->window = window;
	this->init();
}

ResultScene::ResultScene(GameWindow*, GameInfo p, GameInfo op, bool multi)
{
	this->multi = multi;
	this->p_Info = p;
	if (multi) {
		this->op_Info = op;
	}
	this->window = window;
	this->init();
}

ResultScene::~ResultScene()
{

}

void ResultScene::init()
{
	screenWidth = glutGet(GLUT_SCREEN_WIDTH) / 10;
	screenHeight = glutGet(GLUT_SCREEN_HEIGHT) / 10;
	windowWidth = glutGet(GLUT_WINDOW_WIDTH) / 10;
	windowHeight = glutGet(GLUT_WINDOW_HEIGHT)/10;
	printf("%f", screenHeight);
	//나중에 들어오는거보고 지울거
	this->p_Info = GameInfo();
	this->op_Info = GameInfo();
}


void ResultScene::render()
{
	if (!multi) {
		//싱글
		glColor3f(1, 1, 1);

		glBegin(GL_LINE_LOOP);
		glVertex2f(windowWidth/8, 90.f);
		glVertex2f(windowWidth/8, 10.f);
		glEnd();
		
		glBegin(GL_LINE_LOOP);
		glVertex2f(windowWidth / 8*7, 90.f);
		glVertex2f(windowWidth / 8*7, 10.f);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glVertex2f(windowWidth / 8*7, 10.f);
		glVertex2f(windowWidth / 8, 10.f);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glVertex2f(windowWidth / 8*7, 90.f);
		glVertex2f(windowWidth / 8, 90.f);
		glEnd();

		string content = "";

		// 로고
		content = "RESULT";
		glColor3f(1, 1, 1);
		glRasterPos2f(windowWidth/2-float(content.length())/2, 95.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
		}
		
		float xx = windowWidth /8 * 2;

		content = "HP : "+ to_string(int(p_Info.HP));
		glColor3f(1, 1, 1);
		glRasterPos2f(xx, 70.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		content = "SCORE : " + to_string(p_Info.score);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx, 60.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}
		content = "MAX COMBO : " + to_string(p_Info.max_combo);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx, 50.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		xx = windowWidth / 16 * 9;
		content = "PERFECT : " + to_string(p_Info.perfect);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx, 70.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		content = "GREAT : " + to_string(p_Info.great);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx, 60.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		content = "NORMAL : " + to_string(p_Info.normal);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx, 50.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		content = "BAD : " + to_string(p_Info.bad);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx, 40.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		content = "MISS : " + to_string(p_Info.miss);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx, 30.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}
	}
	else {
		//멀티
	}
}

void ResultScene::update()
{
	if (exitKey) {
		this->window->scene = new MainScene(this->window);
		free(this);
	}
}

void ResultScene::setInput(unsigned char input)
{
	if (input == 13) {
		exitKey = true;
	}
}

void ResultScene::unsetInput(unsigned char input)
{
}

void ResultScene::checkInput()
{
}

void ResultScene::addInput(int)
{
}

