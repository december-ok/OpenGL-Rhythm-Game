#pragma once
#include "Scene.h"
#include "MainScene.h"
#include "RoundScene.h"
#include "MultiScene.h"
#include "GameInfo.h"

class ResultScene : public Scene
{
public:
	float f_float = 0.0f;
	float temp = 0.0f, temp2 = 0.0f;
	bool multi = 0;
	float screenWidth, screenHeight, windowWidth, windowHeight;

	GameInfo p_Info, op_Info;
	ResultScene(GameWindow*);
	ResultScene(GameWindow*, GameInfo* p,GameInfo* op, bool multi);

	~ResultScene();

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

