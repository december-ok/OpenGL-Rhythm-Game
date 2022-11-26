#pragma once
#include "Global.h"
#include <vector>
#include "GameWindow.h"
#include "Render.h"
#include "Scene.h"
#include "Note.h"
#include <bass.h>
#include "GameInfo.h"
#include <string>
#define P1_COLUMN 12
#define P2_COLUMN 78

using namespace std;

enum MultiSceneState
{
	CONNECTION_ERR,
	CONNECTING_SERVER,
	FINDING_PLAYER,
	PLAYING,
	FINISH
};

class MultiScene: public Scene
{
	MUSIC id;
	string name = "";
	string artist = "";
	string musicFile = "";
	HSTREAM stream = NULL;
	

	//unsigned int frame = 0;
	unsigned int score = 0;
	vector<Note*> notes[LINES];
	int line_input[LINES]; // �� ���� �� �Է� Ƚ�� ���� - list�� �� ��


	GameInfo* myGameInfo;
	GameWindow* window;
	unsigned int reinforce = 0;
	int endFrame = 0;
	int frame = 0;

	int comma = 0;
	
	public:
		GameInfo* opponentGameInfo;
		bool key[LINES] = { false, false, false, false };
		bool renderKey[LINES] = { false, false, false, false };
		bool opponentRenderKey[LINES] = { false, false, false, false };

		int section_input[LINES] = { 0, 0, 0, 0 };		// �ճ�Ʈ �Է� �ð�
		int section_delay[LINES] = { 0, 0, 0, 0 };		// �Է� ������ ���� delay - �ٵ� �̰� �Ⱦ��� �� ������..?
		int section_judgement[LINES] = { -1, -1, -1, -1 };	// �ճ�Ʈ ���� ����
		
		MultiScene(GameWindow*, MUSIC);
		~MultiScene();

		void render() override;
		void update() override;

		void setInput(unsigned char) override;
		void unsetInput(unsigned char) override;

		void checkInput() override;
		void addInput(int) override;
		
		MultiSceneState state = CONNECTING_SERVER;
	private:
		void init(void);

		void renderInfo(void);
		void renderGame(void);
		void renderInputEffect();
		void renderGrid(void);
		void renderNotes(void);
		void renderCombo();
		void renderJudgement();
		void renderScoreAndInfo();

		void loadMusic();
		void playSound();

		void playEffectSound();
};
