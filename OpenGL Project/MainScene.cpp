#include "MainScene.h"
#include "RoundScene.h"

MainScene::MainScene(GameWindow* window)
{
	this->window = window;
	
	this->init();
}

MainScene::~MainScene()
{
}

void MainScene::init()
{
	
}

void MainScene::render()
{
	this->render_ui();
}

void MainScene::update()
{
	checkInput();

}

void MainScene::render_ui(void)
{
	float x = 0;
	float y = 0;
	float width = 30.f;
	float height = 10.f;
	string content = "";

	// ·Î°í
	content = "Rhythm Game";
	glColor3f(1, 1,	 1);
	glRasterPos2f(56.5f, 80.f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
	
	x = 49.f;
	y = 50.f;
	
	if (selection == SINGLE_PLAY) {
		glColor3f(0.7f, 0.7f, 0.7f);
	}
	else {
		glColor3f(0.2f, 0.2f, 0.2f);
	}
	glRectd(x, y, x + width, y + height);
	content = "Single Play";
	glColor3f(1, 1, 1);
	glRasterPos2f(59.5f, 54.f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}

	y = 35.f;
	if (selection == ONLINE_PLAY) {
		glColor3f(0.7f, 0.7f, 0.7f);
	}
	else {
		glColor3f(0.2f, 0.2f, 0.2f);
	}
	glRectd(x, y, x + width, y + height);
	content = "Online Play";
	glColor3f(1, 1, 1);
	glRasterPos2f(59.5f, 39.f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}

	y = 20.f;
	if (selection == EXIT) {
		glColor3f(0.7f, 0.7f, 0.7f);
	}
	else {
		glColor3f(0.2f, 0.2f, 0.2f);
	}
	glRectd(x, y, x + width, y + height);
	content = "Exit";
	glColor3f(1, 1, 1);
	glRasterPos2f(62.f, 24.f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}
}

void MainScene::move_scene(void) {
	if (this->selection == SINGLE_PLAY) {
		this->window->scene = new RoundScene(this->window, CANON);
		free(this);
	}
	else if (this->selection == ONLINE_PLAY)
	{
		
	}
	else if (this->selection == EXIT)
	{
		exit(0);
	}
}

void MainScene::setInput(unsigned char input) {
	if (input == GLUT_KEY_DOWN) {
		this->KeyDown = true;
	}
	else if (input == GLUT_KEY_UP) {
		this->KeyUp = true;
	}
	else if (input == 13) {
		this->KeyEnter = true;
	}
}

void MainScene::unsetInput(unsigned char input) {
	if (input == GLUT_KEY_DOWN) {
		this->KeyDown = false;
	}
	else if (input == GLUT_KEY_UP) {
		this->KeyUp = false;
	}
	else if (input == 13) {
		this->KeyEnter = false;
	}
}

void MainScene::checkInput()
{
	if (KeyUp) {
		selection = (UI_SELECTION)((selection + 2) % 3);
		KeyUp = false;
	}
	if (KeyDown) {
		selection = (UI_SELECTION)((selection + 1) % 3);
		KeyDown = false;
	}
	if (KeyEnter) {
		this->move_scene();
		KeyEnter = false;
	}
}

void MainScene::addInput(int)
{
	return;
}

