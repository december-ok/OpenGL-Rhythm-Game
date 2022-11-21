#include "MultiScene.h"
#include "NetworkSocket.h"

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
	new NetworkSocket(this);
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
	this->renderGrid();
	this->renderInputEffect();
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

}

void MultiScene::setInput(unsigned char key)
{
	printf("asdf");
	if (key == 'd') {
		this->key[0] = true;
		this->renderKey[0] = true;
//		this->playEffectSound();
	}
	else if (key == 'f') {
		this->key[1] = true;
		this->renderKey[1] = true;
//		this->playEffectSound();
	}
	else if (key == 'j') {
		this->key[2] = true;
		this->renderKey[2] = true;
//		this->playEffectSound();
	}
	else if (key == 'k') {
		this->key[3] = true;
		this->renderKey[3] = true;
//		this->playEffectSound();
	}
}

void MultiScene::unsetInput(unsigned char key)
{
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

void MultiScene::checkInput()
{
}

void MultiScene::addInput(int key)
{
}