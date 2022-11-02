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
	/*노트 판정에 따른 값 수정 필요!!*/
	
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
	// id를 통해 노래 정보등을 가져오기
}

Round::~Round()
{
	
}

void Round::init() {
	this->loadSound();
	for (int line = 0; line < LINES; ++line) {
		this->notes[line] = vector<bool>(10000, false);
		for (int i = 100; i < 150; i++) {
			// 최대 9000 FPS까지
			this->notes[line][START_FRAME] = true;
			this->notes[line][rand()%9000 + START_FRAME] = true;
			//this->notes[line][i] = true;
		}
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
	if (this->frame == START_FRAME) {
		this->playSound();	// 5초 뒤 음악 실행
	}
}

void Round::render() {
	this->renderNotes();
	this->renderGrid();
	this->renderInputEffect();

	
	//tr->renderText("Hello!", 0, 0, 10, 10);

	char* c;
	string ss = to_string(this->frame);	// 노래 시작과 프레임 맞추기. 근데 왜 글자 깨짐...?

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

			// 우선 계속 돌아가는 부분에 넣음
			
		}
	}
	deleteMissNote();
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

/*입력 당시의 프레임을 줌. START_FRAME때문에 코드가 조금 더러움*/
int Round::getFrame()
{
	if (this->frame - START_FRAME < 0) {	// 노래 시작 전 Frame
		return -100;	// 우선 임시로 음수값을 줌. 왜냐하면, 노래 시작할 때 출력되는 노트와 '충돌'하면 안됨
	}
	else {
		return this->frame - START_FRAME;
	}
}

/*사용자의 입력과 노트 프레임 간의 차이를 계산하는 함수*/
int Round::getNoteDelay(int line, int n_frame)
{
	// 50: 임싯값
	for (int i = n_frame - 50; i <= n_frame + 50; i++) {
		if (i >= 0) {
			if (this->notes[line][i + START_FRAME]) {
				return i - n_frame;	// 빠르면 양수, 느리면 음수
			}
		}
		else if(i >= -50) {
			if (this->notes[line][START_FRAME]) {
				return -n_frame;	
			}
		}

	}
	
	return 200;	// 입력 초과
}

/*입력된 노트를 삭제하는 함수. 이후 판정선을 넘어간 노트도 지워야 함
또한, 노트의 구조가 바뀌면 이 또한 바뀌어야 함*/
void Round::deleteNote(int line, int n_frame)
{
	this->notes[line][n_frame + START_FRAME] = false;

}

/*놓치는 노트들을 Miss 처리하는 함수 - 판정을 다른 곳으로 보내주어야 함.*/
void Round::deleteMissNote() 
{
	if (frame >= 50) {
		if (this->notes[0][frame - 50]) {
			printf("miss\n");
			deleteNote(0, frame - 50);
		}

	}
}
