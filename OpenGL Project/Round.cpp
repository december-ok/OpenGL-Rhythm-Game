#include "Render.h"
#include "Round.h"
#include <vector>
#include <iostream>
#include <random>
#include <bass.h>
#include <stdlib.h>

using namespace std;


Round::Round(MUSIC id)
{
	this->id = id;
	/*노트 판정에 따른 값 수정 필요!!*/
	for (int i = 0; i < LINES; i++) {
		line_input[i] = 0;
	}
	
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
	BASS_Free();
}

void Round::init() {

	this->gameInfo = GameInfo();

	this->loadSound();

	int s;
	float t;

	switch (this->id)
	{
	case WE_WERE_YONG:
		// 노드 수작업 부분
		// 오류 확인용 여러 케이스
		s = 1020;
		t = 11.25f;

		this->notes[1].push_back((Note*)new NoramlNote(300));
		this->notes[3].push_back((Note*)new NoramlNote(390));
		this->notes[2].push_back((Note*)new NoramlNote(435));
		this->notes[1].push_back((Note*)new NoramlNote(480));
		this->notes[3].push_back((Note*)new NoramlNote(570));
		this->notes[2].push_back((Note*)new NoramlNote(615));
		this->notes[1].push_back((Note*)new NoramlNote(660));
		this->notes[0].push_back((Note*)new NoramlNote(750));
		this->notes[2].push_back((Note*)new NoramlNote(795));
		this->notes[1].push_back((Note*)new NoramlNote(840));

		this->notes[0].push_back((Note*)new NoramlNote(930));
		this->notes[1].push_back((Note*)new NoramlNote(935));
		this->notes[0].push_back((Note*)new NoramlNote(940));
		this->notes[1].push_back((Note*)new NoramlNote(945));
		this->notes[0].push_back((Note*)new NoramlNote(950));
		this->notes[1].push_back((Note*)new NoramlNote(955));
		this->notes[0].push_back((Note*)new NoramlNote(960));
		this->notes[1].push_back((Note*)new NoramlNote(965));
		this->notes[2].push_back((Note*)new NoramlNote(970));
		this->notes[3].push_back((Note*)new NoramlNote(975));
		this->notes[2].push_back((Note*)new NoramlNote(980));
		this->notes[3].push_back((Note*)new NoramlNote(985));
		this->notes[1].push_back((Note*)new NoramlNote(990));
		this->notes[3].push_back((Note*)new NoramlNote(995));
		this->notes[1].push_back((Note*)new NoramlNote(1000));
		this->notes[3].push_back((Note*)new NoramlNote(1005));

		this->notes[1].push_back((Note*)new NoramlNote(s));
		this->notes[3].push_back((Note*)new NoramlNote(s + 1 * t));
		this->notes[2].push_back((Note*)new NoramlNote(s + 2 * t));
		this->notes[3].push_back((Note*)new NoramlNote(s + 3 * t));
		this->notes[1].push_back((Note*)new NoramlNote(s + 4 * t));
		this->notes[3].push_back((Note*)new NoramlNote(s + 5 * t));
		this->notes[2].push_back((Note*)new NoramlNote(s + 6 * t));
		this->notes[3].push_back((Note*)new NoramlNote(s + 7 * t));

		for (int i = 0; i < 8; i++)
		{
			s += 90;
			this->notes[0].push_back((Note*)new NoramlNote(s));
			this->notes[2].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 7 * t));

			s += 90;
			this->notes[1].push_back((Note*)new NoramlNote(s));
			this->notes[2].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 7 * t));

			s += 90;
			this->notes[2].push_back((Note*)new NoramlNote(s));
			this->notes[3].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 7 * t));

			s += 90;
			this->notes[3].push_back((Note*)new NoramlNote(s));
			this->notes[0].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 7 * t));

			s += 90;
			this->notes[1].push_back((Note*)new NoramlNote(s));
			this->notes[2].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 7 * t));

			s += 90;
			this->notes[1].push_back((Note*)new NoramlNote(s));
			this->notes[3].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 7 * t));

			s += 90;
			this->notes[1].push_back((Note*)new NoramlNote(s));
			this->notes[3].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 7 * t));

			s += 90;
			this->notes[1].push_back((Note*)new NoramlNote(s));
			this->notes[2].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 7 * t));

			s += 90;
			this->notes[1].push_back((Note*)new NoramlNote(s));
			this->notes[2].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 7 * t));
		}

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

	//끝나는 시점 계산
	QWORD len = BASS_ChannelGetLength(stream, BASS_POS_BYTE);
	double time = BASS_ChannelBytes2Seconds(stream, len);
	endFrame = START_FRAME + (time * FPS);
}

void Round::playSound() {
	if (this->stream){
		BASS_ChannelPlay(this->stream, FALSE);
	}
}

void Round::pauseSound(bool pause)
{

	if (pause) BASS_ChannelPause(this->stream);
	else {
		if (frame >= START_FRAME) {
			this->playSound();
		}
	}
}

void Round::receiveJudgement(int judge,Note* nott)
{
	//판정 ( 1:perfect, 2:great, 3:good? 4:bad 5:miss(침))
	// 안치면 타입정보 안줌

	
	int type = 0;
	if(nott != NULL) type = nott->type;

	if (type == 3) {
		printf("Item\n");
		ItemNote* tmpNott = (ItemNote*)nott;
		unsigned char itemType = tmpNott->itemType;

		if (itemType == 1) {
			printf("1111111\n");
			gameInfo.HP += 30;
			if (gameInfo.HP > 100)
				gameInfo.HP = 100;
		}
		else if (itemType == 2) {
			printf("222222\n");
			reinforce += 1000;
		}
	}

	//판정 up 아이템 적용
	//miss 와 퍼펙트 아닌 부분에서 판정을 하나씩 올림
	if (reinforce > 0 && judge > 1 && judge <5){
		judge--;
	}


	//lie노드면 처리, 못치면 타입 중요한거 없음
	if (type == 2) {
		printf("lie\n");
		gameInfo.HP -= 30;
	}
	else if (judge == 1) {
		gameInfo.HP += 2;
		gameInfo.combo++;
		gameInfo.perfect++;
		calcScore(judge);
	}
	else if (judge == 2) {
		gameInfo.HP += 1;
		gameInfo.combo++;
		gameInfo.great++;
		calcScore(judge);
	}
	else if (judge == 3) {
		gameInfo.combo++;
		gameInfo.normal++;
		calcScore(judge);
	}
	else if (judge == 4) {
		gameInfo.HP -= 5;
		gameInfo.combo = 0;
		gameInfo.bad++;
		calcScore(judge);
	}
	else if (judge == 5) {
		gameInfo.HP -= 10;
		gameInfo.combo = 0;
		gameInfo.miss++;
	}

	if (gameInfo.HP > 100)
		gameInfo.HP = 100;
	if (gameInfo.HP <= 0) {
		//gameover()
		printf("사망\n");
		exit(0);
	}
}

void Round::calcScore(int judge)
{
	//perfect 1 great 2 normal 3 bad 4 miss : 점수 계산 없음
	//노트 점수 : 기본점수 * 콤보 보너스(100combo당 10% 증가) * 판정 점수(1.3 1.1 1.0 0.5 0)
	int base = 100;
	int interval = gameInfo.combo / 100;
	float calc = 0;

	switch (judge) {
	case 1:
		calc = base * (1 + (interval * 0.1)) * 1.3;
		break;
	case 2:
		calc = base * (1 + (interval * 0.1)) * 1.1;
		break;
	case 3:
		calc = base * (1 + (interval * 0.1)) * 1;
		break;
	case 4:
		calc = base * 0.5;
		break;
	}

	int tmp = calc;
	gameInfo.score += tmp;
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
	else if (key == 'p') {
		pause = !(pause);
		pauseSound(pause);
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
	this->deleteMissNode();	// 여기가 맞나..?
	if (frame == START_FRAME) {
		this->playSound();	// 5초 뒤 음악 실행
	}
	if (reinforce > 0) reinforce--;
}

void Round::render() {
	this->renderNotes();
	this->renderGrid();
	this->renderInputEffect();
	

	
	//tr->renderText("Hello!", 0, 0, 10, 10);

	char* c;
	string ss = to_string(frame);	// 노래 시작과 프레임 맞추기. 근데 왜 글자 깨짐...?

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
	int input_count = 0;
	for (int line = 0; line < LINES; ++line) {
		for (int scope = 0; scope < this->notes[line].size(); ++scope) {
			if (this->notes[line][scope] == nullptr) break;
			//cout << "fps: " << frame << " | ";
			if (this->notes[line][scope]->IsActive(frame) && this->notes[line][scope]->isAlive) {
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

				int height = this->notes[line][scope]->GetHeight(frame);
				glRectd(20.f + ((float)line * 4), height, 24.f + ((float)line * 4), height + 1);
				//cout << frame << " | " << line << ":" << height << "\n";

				if (line == 0 && (0 <= height && height <= 10)) {
				//	cout << line << ":" << height << "\n";
				}
			}
			else if(this->notes[line][scope]->IsMissNote(frame)) {
				this->deleteNote(line, scope);
				
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
	if (frame == endFrame) {
		//gameclear()
		exit(0);
	}
}

///*입력 당시의 프레임을 줌. START_FRAME때문에 코드가 조금 더러움*/
//int Round::getFrame()
//{
//	if (frame - START_FRAME < 0) {	// 노래 시작 전 Frame
//		return -100;	// 우선 임시로 음수값을 줌. 왜냐하면, 노래 시작할 때 출력되는 노트와 '충돌'하면 안됨
//	}
//	else {
//		return frame - START_FRAME;
//	}
//}

/*사용자의 입력과 노트 프레임 간의 차이를 계산하는 함수*/
int Round::getNoteDelay(int line)
{
	// 가장 가까운 노트
	int n_frame = this->line_input[line];

	// 입력과 노트 프레임 사이의 차이
	int n_delay = this->notes[line][n_frame]->GetHeight(frame);
	int noteType = this->notes[line][n_frame]->type;

	Note* nott = this->notes[line][n_frame];

	// 일정 범위 내에 노트가 존재함
	if (n_delay <= 50) {
		// 노트 지움
		this->deleteNote(line, n_frame);
		this->setLineInput(line);
		printf("%d: Delay\n", n_delay);
		if (abs(n_delay) <= 10) {
			receiveJudgement(1,nott);
			return 1;
		}
		else if (abs(n_delay) <= 20) {
			receiveJudgement(2, nott);
			return 2;
		}
		else if (abs(n_delay) <= 30) {
			receiveJudgement(3, nott);
			return 3;
		}
		else if (abs(n_delay) <= 40) {
			receiveJudgement(4, nott);
			return 4;
		}
		else {
			receiveJudgement(5, nott);
		}
	}
	else {
	}
}

/*입력된 노트를 삭제하는 함수. 이후 판정선을 넘어간 노트도 지워야 함*/
void Round::deleteNote(int line, int n_frame)
{
	if (this->notes[line][n_frame] != nullptr) {
		this->notes[line][n_frame]->killNote();
		printf("%d번 note 삭제\n", n_frame);
	}

}

int Round::getLineInput(int line) {
	return this->line_input[line];
}

void Round::setLineInput(int line) {
	this->line_input[line]++;
}

void Round::deleteMissNode() {
	// 1 -> LINES로 바꿔야 함.
	for (int i = 0; i < 1; i++) {
		// 입력 못한 노트 제거
		if (this->notes[i][line_input[i]]->IsMissNote(frame)) {
			receiveJudgement(5, NULL);
			printf("%d Miss Note 제거\n", line_input[i]);
			this->notes[i][line_input[i]]->killNote();
			this->setLineInput(i);
		}
	}
}

///*놓치는 노트들을 Miss 처리하는 함수 - 판정을 다른 곳으로 보내주어야 함.*/
//void Round::deleteMissNote() 
//{
//	if (frame >= 50) {
//		if (this->notes[0][frame - 50]) {
//			printf("miss\n");
//			deleteNote(0, frame - 50);
//		}
//
//	}
//}
