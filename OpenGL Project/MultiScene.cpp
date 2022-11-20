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

void MultiScene::update()
{

}

void MultiScene::setInput(unsigned char key)
{
}

void MultiScene::unsetInput(unsigned char key)
{
}

void MultiScene::checkInput()
{
}

void MultiScene::addInput(int key)
{
}