#pragma once
#include "Scene.h"
#include "Render.h"
#include "Global.h"
#include "GameWindow.h"
#include <string>
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

private:
	GameWindow* window;
	void init();

	void render_ui(void);

	void move_scene(void);

	bool KeyUp = false;
	bool KeyDown = false;
	bool KeyEnter = false;
	
	UI_SELECTION selection = SINGLE_PLAY;
};
