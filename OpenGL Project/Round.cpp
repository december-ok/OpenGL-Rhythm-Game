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
		for (int i = 0; i < 50; i++) {
			this->notes[line][rand()%10000] = true;
			//this->notes[line][i] = true;
		}
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

	glLineWidth(6);
	glBegin(GL_LINE_LOOP);
	glVertex2f(20, 5);
	glVertex2f(20 + (LINES * 4), 5);
	glEnd();
}

void Round::render() {
	this->renderNotes();
	this->renderGrid();
	this->renderInputEffect(0);
	this->addTime();
}

void Round::renderNotes() {
	if (this->frame + 120 == 10000) return;
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
			}
		}
	}
}

void Round::renderInputEffect(int input) {
	float i = (float)input;
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1); // make this vertex purple
	glVertex2f(20 + (i * 4), 5);
	glColor4f(0, 0, 0, 0); // make this vertex red
	glVertex2f(20 + (i * 4), 40.f);
	glColor4f(0, 0, 0, 0); // make this vertex green
	glVertex2f(24 + (i * 4), 40.f);
	glColor3f(1, 1, 1); // make this vertex yellow
	glVertex2f(24 + (i * 4), 5);
	glEnd();
}

void Round::addTime() {
	this->frame += 1;
}