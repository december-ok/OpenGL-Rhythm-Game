#include "ResultScene.h"

ResultScene::ResultScene(GameWindow* window)
{
	this->window = window;
	this->init();
}

ResultScene::ResultScene(GameWindow* window, GameInfo* p, GameInfo* op, bool multi)
{
	
	this->multi = multi;
	this->p_Info = *p;
	if (multi) {
		this->op_Info = *op;
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
}


void ResultScene::render()
{
	if (!multi) {
		//½Ì±Û
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

		// ·Î°í
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

		content = "PRESS ENTER TO CONTINUE!";
		glColor3f(1, 1, 1);
		glRasterPos2f(windowWidth / 8 * 6, 100.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}
	}
	else {
		//¸ÖÆ¼
		glColor3f(1, 1, 1);
		string content = "";
		if (p_Info.score < op_Info.score) {
			// ·Î°í
			content = "YOU LOSE";
			glColor3f(1, 1, 1);
			glRasterPos2f(windowWidth / 2 - float(content.length()) / 2, 95.f);

			for (auto c : content)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
			}
		}
		else if (p_Info.score == op_Info.score) {
			//ºñ±è

			content = "DRAW";
			glColor3f(1, 1, 1);
			glRasterPos2f(windowWidth / 2 - float(content.length()) / 2, 95.f);

			for (auto c : content)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
			}
		}
		else {
			//ÀÌ±è

			content = "YOU WIN";
			glColor3f(1, 1, 1);
			glRasterPos2f(windowWidth / 2 - float(content.length()) / 2, 95.f);

			for (auto c : content)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
			}
		}

		glBegin(GL_LINE_LOOP);
		glVertex2f(windowWidth / 8, 80.f);
		glVertex2f(windowWidth / 8, 7.f);
		glEnd();
		
		glBegin(GL_LINE_LOOP);
		glVertex2f(windowWidth / 8 * 3, 80.f);
		glVertex2f(windowWidth / 8 * 3, 7.f);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glVertex2f(windowWidth / 8 * 3, 7.f);
		glVertex2f(windowWidth / 8, 7.f);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glVertex2f(windowWidth / 8 * 3, 80.f);
		glVertex2f(windowWidth / 8, 80.f);
		glEnd();



		glBegin(GL_LINE_LOOP);
		glVertex2f(windowWidth / 8*7, 80.f);
		glVertex2f(windowWidth / 8*7, 7.f);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glVertex2f(windowWidth / 8 * 5, 80.f);
		glVertex2f(windowWidth / 8 * 5, 7.f);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glVertex2f(windowWidth / 8 * 5, 7.f);
		glVertex2f(windowWidth / 8*7, 7.f);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glVertex2f(windowWidth / 8 * 5, 80.f);
		glVertex2f(windowWidth / 8*7, 80.f);
		glEnd();

		content = "YOU";
		glColor3f(1, 1, 1);
		glRasterPos2f(windowWidth / 4 - float(content.length()/2)-0.5f, 83.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
		}



		content = "RIVAL";
		glColor3f(1, 1, 1);
		glRasterPos2f(windowWidth / 4*3 - float(content.length() / 2) - 0.5f, 83.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
		}

		float xx = windowWidth / 4;

		content = "SCORE : " + to_string(p_Info.score);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx - float(content.length() / 2) - 0.5f, 73.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}
		content = "MAX COMBO : " + to_string(p_Info.max_combo);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx - float(content.length() / 2) - 0.5f, 63.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		content = "PERFECT : " + to_string(p_Info.perfect);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx - float(content.length() / 2) - 0.5f, 53.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		content = "GREAT : " + to_string(p_Info.great);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx - float(content.length() / 2) - 0.5f, 43.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		content = "NORMAL : " + to_string(p_Info.normal);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx - float(content.length() / 2) - 0.5f, 33.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		content = "BAD : " + to_string(p_Info.bad);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx - float(content.length() / 2) - 0.5f, 23.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		content = "MISS : " + to_string(p_Info.miss);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx - float(content.length() / 2), 13.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		xx = windowWidth / 4*3;

		content = "SCORE : " + to_string(op_Info.score);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx - float(content.length() / 2) - 0.5f, 73.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}
		content = "MAX COMBO : " + to_string(op_Info.max_combo);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx - float(content.length() / 2) - 0.5f, 63.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		content = "PERFECT : " + to_string(op_Info.perfect);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx - float(content.length() / 2) - 0.5f, 53.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		content = "GREAT : " + to_string(op_Info.great);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx - float(content.length() / 2) - 0.5f, 43.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		content = "NORMAL : " + to_string(op_Info.normal);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx - float(content.length() / 2) - 0.5f, 33.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		content = "BAD : " + to_string(op_Info.bad);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx - float(content.length() / 2) - 0.5f, 23.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		content = "MISS : " + to_string(op_Info.miss);
		glColor3f(1, 1, 1);
		glRasterPos2f(xx - float(content.length() / 2), 13.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		content = "PRESS ENTER TO CONTINUE!";
		glColor3f(1, 1, 1);
		glRasterPos2f(windowWidth / 8 * 6, 100.f);

		for (auto c : content)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}
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

