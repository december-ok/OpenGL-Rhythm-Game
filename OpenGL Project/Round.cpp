#include "Render.h"
#include "Round.h"
#include <vector>
#include <iostream>
#include <random>
#include <bass.h>

using namespace std;


Round::Round(MUSIC id)
{
	this->id = id;
	
	switch (this->id)
	{
	case WE_WERE_YONG:
		this->name = "We Were Young";
		this->artist = "Sad Puppy";
		this->musicFile = "./WE_WERE_YOUNG.mp3";
		break;
	default:
		break;
	}

	this->init();
	// id�� ���� �뷡 �������� ��������
}

Round::~Round()
{
	
}

void Round::init() {
	this->loadSound();
	for (int line = 0; line < LINES; ++line) {
		this->notes[line] = vector<Note*>();
	}

	switch (this->id)
	{
	case WE_WERE_YONG:
		// ��� ���۾� �κ�
		this->notes[0].push_back((Note*)new NoramlNote(300));
		break;
	default:
		break;
	}
}

void Round::loadSound() {
	BASS_Init(-1, 44100, 0, 0, NULL);
	this->stream = BASS_StreamCreateFile(FALSE, this->musicFile.c_str(), 0, 0, 0);
	BASS_ChannelPlay(this->stream, FALSE);
	BASS_ChannelPause(this->stream);
}

void Round::playSound() {
	if (this->stream){
		BASS_ChannelPlay(this->stream, FALSE);
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

void Round::update() {
	this->addTime();
	if (frame == START_FRAME) {
		this->playSound();
	}
}

void Round::render() {
	this->renderNotes();
	this->renderGrid();
	this->renderInputEffect();

	
	//tr->renderText("Hello!", 0, 0, 10, 10);
	// ���ڷ������ϴºκ��Դϴ� ��������
	char* c;
	string ss = to_string(frame / 60);
	glPushMatrix();
	glTranslatef(100, 100, 0);
	glScalef(0.04, 0.06, 1);
	glColor4f(1, 0.8f, 0,0.5f);
	glLineWidth(5);
	for (auto c:ss)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(100.15f, 100, 0);
	glColor4f(0, 0.65f, 1,0.5f);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : ss)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(100.3f, 100, 0);
	glColor4f(0.19f, 0.65f, 0.32f,0.5f);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : ss)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(100.45f, 100, 0);
	glColor4f(0.9f, 1, 0.15f,0.5f);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : ss)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
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


void Round::renderNotes() {
	if (frame + 120 > 10000) return;
	for (int line = 0; line < LINES; ++line) {
		for (int scope = 0; scope < this->notes[line].size(); ++scope) {
			if (this->notes[line][scope] == nullptr) break;
			cout << "fps: " << frame << " | ";
			if (this->notes[line][scope]->IsActive(frame)) {
				// ��Ʈ�� �� ����
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

				int height = this->notes[line][scope]->GetHeight(frame);
				glRectd(20.f + ((float)line * 4), height, 24.f + ((float)line * 4), height + 1);
				cout << frame << " | " << line << ":" << height << "\n";

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
	frame += 1;
}