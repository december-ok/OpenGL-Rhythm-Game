#include "MainScene.h"
#include "RoundScene.h"
#include "MultiScene.h"
#include "TutorialScene.h"
#include "ResultScene.h"
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
//	this->fireWork = new FireWork(new Vector(50, 0), 1.3f);
}

void MainScene::render()
{
	for (auto f : this->fireWork) {
		if (f) {
			f->render();
		}
	}
	this->render_ui();
}

void MainScene::update()
{
	for (auto f : this->fireWork) {
		if (f) {
			f->update();
		}
	}

	if(this->fps % (FPS/2) == 0){
		int i = (this->fps % (5 * FPS)) / (FPS / 2);
		if (this->fireWork[i]) {
			free(this->fireWork[i]);
		}
		this->fireWork[i] = new FireWork(new Vector(getRandRage(0, 127), 0), getRandRage(0.9f, 1.3f));
	}
	
	if (KeyUp) {
		selection = (UI_SELECTION)((selection + 3) % 4);
		KeyUp = false;
	}
	if (KeyDown) {
		selection = (UI_SELECTION)((selection + 1) % 4);
		KeyDown = false;
	}
	if (KeyEnter) {
		this->move_scene();
		KeyEnter = false;
	}
	
	++this->fps;
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
	glRasterPos2f(56.5f, 90.f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
	
	x = 49.f;
	y = 60.f;
	
	if (selection == SINGLE_PLAY) {
		glColor3f(0.7f, 0.7f, 0.7f);
	}
	else {
		glColor3f(0.2f, 0.2f, 0.2f);
	}
	glRectd(x, y, x + width, y + height);
	content = "Single Play";
	glColor3f(1, 1, 1);
	glRasterPos2f(59.5f, 64.f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}

	y = 45.f;
	if (selection == ONLINE_PLAY) {
		glColor3f(0.7f, 0.7f, 0.7f);
	}
	else {
		glColor3f(0.2f, 0.2f, 0.2f);
	}
	glRectd(x, y, x + width, y + height);
	content = "Online Play";
	glColor3f(1, 1, 1);
	glRasterPos2f(59.5f, 49.f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}
	y = 30.f;
	if (selection == TUTORIAL) {
		glColor3f(0.7f, 0.7f, 0.7f);
	}
	else {
		glColor3f(0.2f, 0.2f, 0.2f);
	}
	glRectd(x, y, x + width, y + height);
	content = "How to Play";
	glColor3f(1, 1, 1);
	glRasterPos2f(59.f, 34.f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}


	y = 15.f;
	if (selection == EXIT) {
		glColor3f(0.7f, 0.7f, 0.7f);
	}
	else {
		glColor3f(0.2f, 0.2f, 0.2f);
	}
	glRectd(x, y, x + width, y + height);
	content = "Exit";
	glColor3f(1, 1, 1);
	glRasterPos2f(62.f, 19.f);
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
		this->window->scene = new MultiScene(this->window, CANON);
		free(this);
	}
	else if (this->selection == TUTORIAL){
		
		this->window->scene = new TutorialScene(this->window);
		free(this);
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

