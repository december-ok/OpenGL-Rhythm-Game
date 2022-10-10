#include "include/GL/glut.h"
#include "Round.h"
#include<vector>
#include<iostream>
#include <random>

using namespace std;


Round::Round(string id)
{
	this->id = id;

	this->init();
	// id를 통해 노래 정보등을 가져오기
}

Round::~Round()
{
	
}

void Round::init() {
	for (int line = 0; line < LINES; ++line) {
		this->notes[line] = vector<bool>(10000, false);
		for (int i = 100; i < 150; i++) {
			this->notes[line][rand()%10000] = true;
			//this->notes[line][i] = true;
		}
	}
}

void Round::setInput(unsigned char key) {
	if (key == 'd') {
		this->key[0] = true;
		this->renderKey[0] = true;
	}
	else if (key == 'f') {
		this->key[1] = true;
		this->renderKey[1] = true;
	}
	else if (key == 'j') {
		this->key[2] = true;
		this->renderKey[2] = true;
	}
	else if (key == 'k') {
		this->key[3] = true;
		this->renderKey[3] = true;
	}
}
void Round::unsetInput(unsigned char key) {
	if (key == 'd') {
		this->key[0] = false;
		this->renderKey[0] = false;
	}
	else if (key == 'f') {
		this->key[1] = false;
		this->renderKey[1] = false;
	}
	else if (key == 'j') {
		this->key[2] = false;
		this->renderKey[2] = false;
	}
	else if (key == 'k') {
		this->key[3] = false;
		this->renderKey[3] = false;
	}
}

void Round::renderGrid() {
	glLineWidth(1);
	glColor3f(1, 1, 1);

	//glBegin(GL_LINE_LOOP);
	//glVertex2f(x, y);
	//glVertex2f(x + 1, y);
	//glVertex2f(x + 1, y + 1);
	//glVertex2f(x, y + 1);
	//glEnd();

	for (int i = 0; i < LINES+1; ++i) {
		glBegin(GL_LINE_LOOP);
		glVertex2f(20 + (i * 4), 0);
		glVertex2f(20 + (i * 4), ROWS);
		glEnd();
	}

	glColor3f(1,1,1);
	glRectd(20, 5, 36, 6);
}

void Round::render() {
	this->renderNotes();
	this->renderGrid();
	this->renderInputEffect();
	this->addTime();
}

void Round::renderNotes() {
	if (this->frame + 120> 10000) return;
	for (int line = 0; line < LINES; ++line) {
		for (int scope = this->frame; scope < this->frame + ROWS+1; ++scope) {
			if (this->notes[line][scope]) {
				// 노트의 색 지정
				switch (line)
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

				int height = ROWS - ((this->frame) - (scope - ROWS));
				glRectd(20.f + ((float)line * 4), height, 24.f + ((float)line * 4), height + 1);
				
				if (line == 0 && (0<=height && height<=10 ) ) {
					cout << line << ":" << height << "\n";
				}
			}
		}
	}
}

void Round::renderInputEffect() {
	for (int i = 0;i < LINES;i++) {
		if (!this->renderKey[i]) continue;
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glVertex2f(20 + (i * 4), 5);
		glColor4f(0, 0, 0, 0); 
		glVertex2f(20 + (i * 4), 40.f);
		glColor4f(0, 0, 0, 0);
		glVertex2f(24 + (i * 4), 40.f);
		glColor3f(1, 1, 1);
		glVertex2f(24 + (i * 4), 5);
		glEnd();
	}
}

void Round::addTime() {
	this->frame += 1;
}