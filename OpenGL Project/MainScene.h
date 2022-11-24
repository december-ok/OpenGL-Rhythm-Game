#pragma once
#include "Scene.h"
#include "Render.h"
#include "Global.h"
#include "GameWindow.h"
#include <string>
#include "FireWork.h"
using namespace std;

class MainScene :public Scene
{
public:
	MainScene(GameWindow*);
	~MainScene();

	void render() override;
	void update() override;

	void setInput(unsigned char) override;
	void unsetInput(unsigned char) override;

	void checkInput() override;
	void addInput(int) override;

private:
	FireWork* fireWork[10];
	GameWindow* window;
	void init();

	void render_ui(void);

	void move_scene(void);

	bool KeyUp = false;
	bool KeyDown = false;
	bool KeyEnter = false;

	int fps = 0;
	
	UI_SELECTION selection = SINGLE_PLAY;
};
