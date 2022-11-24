#pragma once
#include "Scene.h"
#include "MainScene.h"
#include "RoundScene.h"
#include "MultiScene.h"


class TutorialScene : public Scene
{
public:
	float f_float = 0.0f;
	float temp = 0.0f, temp2 = 0.0f;
	int num = 0;

	float screenWidth, screenHeight, windowWidth, windowHeight;

	TutorialScene(GameWindow*);
	~TutorialScene();

	void render() override;
	void update() override;

	void setInput(unsigned char) override;
	void unsetInput(unsigned char) override;

	void checkInput() override;
	void addInput(int) override;

	GameWindow* window;
	void init();
	bool exitKey = false;

};

