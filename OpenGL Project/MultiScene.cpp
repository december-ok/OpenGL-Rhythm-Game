#include "MultiScene.h"
#include "NetworkSocket.h"

NetworkSocket* gameSocket;

MultiScene::MultiScene(GameWindow* window, MUSIC id)
{
	this->window = window;

	this->id = id;
	for (int i = 0; i < LINES; i++) {
		line_input[i] = 0;
	}
	switch (this->id)
	{
	case CANON:
		this->name = "Cannon Variation";
		this->artist = "Johan Pachelbel";
		this->musicFile = "./Canon.mp3";
		break;
	default:
		break;
	}
	
	this->init();
}

MultiScene::~MultiScene()
{
}

void MultiScene::init(void)
{
	gameSocket = new NetworkSocket(this);
	this->myGameInfo = new GameInfo();
	this->opponentGameInfo = new GameInfo();
//	U_Config = new UserConfig();
	BASS_Init(-1, 44100, 0, 0, NULL);

	this->loadMusic();

	int s;
	float t;

	switch (this->id)
	{
	case CANON:
		// 노드 수작업 부분
		// 오류 확인용 여러 케이스
		s = 1020;
		t = 11.25f;

		//this->notes[1].push_back((Note*)new NoramlNote(300));
		this->notes[1].push_back((Note*)new SectionNote(300, 350));


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

void MultiScene::loadMusic() {
	this->stream = BASS_StreamCreateFile(FALSE, this->musicFile.c_str(), 0, 0, 0);
	BASS_ChannelPlay(this->stream, FALSE);
//	setMVol(U_Config->M_Vol);
	BASS_ChannelPause(this->stream);

	//끝나는 시점 계산
	QWORD len = BASS_ChannelGetLength(stream, BASS_POS_BYTE);
	double time = BASS_ChannelBytes2Seconds(stream, len);
	endFrame = START_FRAME + (time * FPS);
}

void MultiScene::playEffectSound() {
	HSTREAM effect = BASS_StreamCreateFile(FALSE, "./hit_sound.mp3", 0, 0, 0);
//	BASS_ChannelSetAttribute(effect, BASS_ATTRIB_VOL, U_Config->E_Vol);
	BASS_ChannelPlay(effect, FALSE);
}

void MultiScene::playSound() {
	if (this->stream) {
		BASS_ChannelPlay(this->stream, FALSE);
	}
}

void MultiScene::render()
{
	if (this->state == PLAYING) {
		this->renderGame();
	}
	else {
		this->renderInfo();
	}
}

void MultiScene::renderInfo(void)
{
	string content = "";
	
	switch (this->state)
	{
	case CONNECTION_ERR:
		content = "Connection Error!";
		break;
	case CONNECTING_SERVER:
		content = "Connecting Server...";
		break;
	case FINDING_PLAYER:
		content = "Finding Player...";
		break;
	default:
		break;
	}

	glColor3f(1, 1, 1);
	glRasterPos2f(50.f, 50.f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
}


void MultiScene::renderGame()
{
	this->renderNotes();
	this->renderGrid();
	this->renderInputEffect();

	this->renderCombo();
	this->renderJudgement();
	this->renderScoreAndInfo();
}

void MultiScene::renderCombo() {
	if (this->myGameInfo->combo == 0) {
		return;
	}

	float x = 20;
	float y = 50;

	string content = to_string(this->myGameInfo->combo) + " COMBO";

	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(0.04, 0.06, 1);
	glColor4f(1, 0.8f, 0, 0.5f);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.15f, y, 0);
	glColor4f(0, 0.65f, 1, 0.5f);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.3f, y, 0);
	glColor4f(0.19f, 0.65f, 0.32f, 0.5f);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.45f, y, 0);
	glColor4f(0.9f, 1, 0.15f, 0.5f);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();

	x = 85;

	content = to_string(this->opponentGameInfo->combo) + " COMBO";

	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(0.04, 0.06, 1);
	glColor4f(1, 0.8f, 0, 0.5f);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.15f, y, 0);
	glColor4f(0, 0.65f, 1, 0.5f);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.3f, y, 0);
	glColor4f(0.19f, 0.65f, 0.32f, 0.5f);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.45f, y, 0);
	glColor4f(0.9f, 1, 0.15f, 0.5f);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
}

void MultiScene::renderJudgement() {
	if (this->myGameInfo->recentJudgement == NONE) {
		return;
	}

	float x = 20;
	float y = 36;

	string content = "";
	switch (this->myGameInfo->recentJudgement) {
	case PERFECT:
		glColor4f(0.64f, 0.05f, 0.6f, 0.5f);
		content = "PERFECT";
		break;
	case GREAT:
		glColor4f(0.9f, 0.55f, 0.15f, 0.5f);
		content = " GREAT ";
		break;
	case NORMAL:
		glColor4f(0.1f, 0.75f, 0.15f, 0.5f);
		content = " NORMAL";
		break;
	case BAD:
		glColor4f(0.3f, 0.75f, 0.74f, 0.5f);
		content = "  BAD  ";
		break;
	case MISS:
		glColor4f(0.4f, 0.4f, 0.4f, 0.5f);
		content = "  MISS  ";
		break;
	}


	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.15f, y, 0);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.3f, y, 0);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.45f, y, 0);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();

	x = 85;
	content = "";
	switch (this->opponentGameInfo->recentJudgement) {
	case PERFECT:
		glColor4f(0.64f, 0.05f, 0.6f, 0.5f);
		content = "PERFECT";
		break;
	case GREAT:
		glColor4f(0.9f, 0.55f, 0.15f, 0.5f);
		content = " GREAT ";
		break;
	case NORMAL:
		glColor4f(0.1f, 0.75f, 0.15f, 0.5f);
		content = " NORMAL";
		break;
	case BAD:
		glColor4f(0.3f, 0.75f, 0.74f, 0.5f);
		content = "  BAD  ";
		break;
	case MISS:
		glColor4f(0.4f, 0.4f, 0.4f, 0.5f);
		content = "  MISS  ";
		break;
	}


	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.15f, y, 0);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.3f, y, 0);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.45f, y, 0);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
}

void MultiScene::renderScoreAndInfo() {
	float x = 0;
	float y = 105;

	string content = "Score: " + to_string(this->myGameInfo->score);
	glColor4f(1, 1, 1, 1);
	glRasterPos2f(x, y);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	x = 65;
	content = "Score: " + to_string(this->opponentGameInfo->score);
	glColor4f(1, 1, 1, 1);
	glRasterPos2f(x, y);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
}

void MultiScene::renderNotes() {
	if (frame + 120 > 10000) return;
	int input_count = 0;
	for (int line = 0; line < LINES; ++line) {
		for (int scope = 0; scope < this->notes[line].size(); ++scope) {
			if (this->notes[line][scope] == nullptr)
				break;
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

				// 바닥으로부터 노트(바닥)까지의 거리
				int height = this->notes[line][scope]->GetHeight(frame);
				int noteLength = this->notes[line][scope]->getNoteLength();

				// 롱노트에 대하여
				if (this->notes[line][scope]->type == 1) {
					int bottom = 0;
					// 롱노트가 현재 입력 대기중인 노트이고, 그 노트가 입력중일 때
					if (scope == line_input[line] && section_judgement[line] != -1) {
						bottom = JUDGE_HEIGHT;
					}

					// 일부 롱노트가 화면 아래에 있음
					if (height < 2) {
						glRectd(P1_COLUMN + ((float)line * 4), bottom, (P1_COLUMN + 4) + ((float)line * 4), height + noteLength);
						glRectd(P2_COLUMN + ((float)line * 4), bottom, (P2_COLUMN + 4) + ((float)line * 4), height + noteLength);
					}
					else {
						glRectd(P1_COLUMN + ((float)line * 4), height, (P1_COLUMN + 4) + ((float)line * 4), height + noteLength);
						glRectd(P2_COLUMN + ((float)line * 4), height, (P2_COLUMN + 4) + ((float)line * 4), height + noteLength);
					}
				}
				else {
					glRectd(P1_COLUMN + ((float)line * 4), height, (P1_COLUMN + 4) + ((float)line * 4), height + noteLength);
					glRectd(P2_COLUMN + ((float)line * 4), height, (P2_COLUMN + 4) + ((float)line * 4), height + noteLength);
				}

				//}
				//cout << frame << " | " << line << ":" << height << "\n";

				if (line == 0 && (0 <= height && height <= 10)) {
					//	cout << line << ":" << height << "\n";
				}
			}
		}
	}
}

void MultiScene::renderInputEffect() {
	for (int i = 0;i < LINES;i++) {
		if (!this->renderKey[i]) continue;
		
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glVertex2f(P1_COLUMN + (i * 4), 5);
		glColor4f(0, 0, 0, 0);
		glVertex2f(P1_COLUMN + (i * 4), 40.f);
		glColor4f(0, 0, 0, 0);
		glVertex2f(P1_COLUMN + 4 + (i * 4), 40.f);
		glColor3f(1, 1, 1);
		glVertex2f(P1_COLUMN + 4 + (i * 4), 5);
		glEnd();
	}

	for (int i = 0;i < LINES;i++) {
		if (!this->opponentRenderKey[i]) continue;

		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glVertex2f(P2_COLUMN + (i * 4), 5);
		glColor4f(0, 0, 0, 0);
		glVertex2f(P2_COLUMN + (i * 4), 40.f);
		glColor4f(0, 0, 0, 0);
		glVertex2f(P2_COLUMN + 4 + (i * 4), 40.f);
		glColor3f(1, 1, 1);
		glVertex2f(P2_COLUMN + 4 + (i * 4), 5);
		glEnd();
	}
}

void MultiScene::renderGrid()
{
	glLineWidth(1);
	glColor3f(1, 1, 1);

	// 내 그리드
	for (int i = 0; i < LINES + 1; ++i) {
		glBegin(GL_LINE_LOOP);
		glVertex2f(P1_COLUMN + (i * 4), 0);
		glVertex2f(P1_COLUMN + (i * 4), ROWS);
		glEnd();
	}
	

	// 상대 그리드
	for (int i = 0; i < LINES + 1; ++i) {
		glBegin(GL_LINE_LOOP);
		glVertex2f(P2_COLUMN + (i * 4), 0);
		glVertex2f(P2_COLUMN + (i * 4), ROWS);
		glEnd();
	}

	glColor3f(1, 1, 1);
	glRectd(P1_COLUMN, 5, P1_COLUMN + (4 * LINES), 6);
	glRectd(P2_COLUMN, 5, P2_COLUMN + (4 * LINES), 6);
	
	// 가운데 대결모양
	// HSV 색 모델 이용
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(63.5f, -30);
	glVertex2f(61, 58);
	glVertex2f(63.5f, 55);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(63.5f, ROWS+30);
	glVertex2f(66, 50);
	glVertex2f(63.5f, 53);
	glEnd();
}

void MultiScene::update()
{
	if (this->state == PLAYING){
		if (this->frame == START_FRAME) {
			this->playSound();
		}
		
		++this->frame;
	}
}

void MultiScene::setInput(unsigned char key)
{
	if (key == 'd') {
		this->key[0] = true;
		this->renderKey[0] = true;
//		this->playEffectSound();
		
		gameSocket->sendInput(0);
	}
	else if (key == 'f') {
		this->key[1] = true;
		this->renderKey[1] = true;
//		this->playEffectSound();

		gameSocket->sendInput(1);
	}
	else if (key == 'j') {
		this->key[2] = true;
		this->renderKey[2] = true;
//		this->playEffectSound();

		gameSocket->sendInput(2);
	}
	else if (key == 'k') {
		this->key[3] = true;
		this->renderKey[3] = true;
//		this->playEffectSound();

		gameSocket->sendInput(3);
	}
}

void MultiScene::unsetInput(unsigned char key)
{
	if (key == 'd') {
		this->key[0] = false;
		this->renderKey[0] = false;

		gameSocket->sendUnput(0);
	}
	else if (key == 'f') {
		this->key[1] = false;
		this->renderKey[1] = false;

		gameSocket->sendUnput(1);
	}
	else if (key == 'j') {
		this->key[2] = false;
		this->renderKey[2] = false;

		gameSocket->sendUnput(2);
	}
	else if (key == 'k') {
		this->key[3] = false;
		this->renderKey[3] = false;

		gameSocket->sendUnput(3);
	}
}

void MultiScene::checkInput()
{
}

void MultiScene::addInput(int key)
{
}