#pragma once
#include<vector>
#include<string>
#include"Global.h"
#include"Note.h"
#include<bass.h>
#include<queue>
#include"GameInfo.h"
#include"Scene.h"
#include"GameWindow.h"
#include"Input.h"
#include"UserConfig.h"
#include "FireWork.h"
#include<time.h>
#include<stdlib.h>
using namespace std;

class RoundScene:public Scene
{
	
	MUSIC id;
	string name = "";
	string artist = "";
	string musicFile = "";
	HSTREAM stream = NULL;

	unsigned int frame = 0;
	unsigned int score = 0;
	vector<Note*> notes[LINES];
	int line_input[LINES]; // �� ���� �� �Է� Ƚ�� ����

	int section_input[LINES] = { 0, 0, 0, 0 };		// �ճ�Ʈ �Է� �ð�
	int section_delay[LINES] = { 0, 0, 0, 0 };		// �Է� ������ ���� delay - �ٵ� �̰� �Ⱦ��� �� ������..?
	int section_judgement[LINES] = { -1, -1, -1, -1 };	// �ճ�Ʈ ���� ����

	bool key[LINES] = { false, false, false, false };
	bool renderKey[LINES] = { false, false, false, false };

	bool isEnd = false;

	queue<Input*> InputQueue;
	
	GameInfo* gameInfo;
	UserConfig* U_Config;

	// Timer ����
	clock_t init_timer;
	clock_t start_timer;
	clock_t end_timer;

	int timer_count = 0;
	clock_t clock_delay = 0;
	bool adjust_on = false;

	// Item Blink
	int blink_count = 0;
	bool blink_on = false;

	// LieNote
	bool lie_on = false;
	int lie_count = 0;
	vector<Note*> lie_notes[LINES];		// ��¥ ��Ʈ ����
	int lie_input[LINES];				// ���� ��Ʈ �Է� Ƚ�� ����

	// Auto Mode
	bool auto_on = true;
	int auto_input[LINES];

	GameWindow* window;
	unsigned int reinforce = 0;
	int endFrame = 0;
	FireWork* fireWork[10];
	
public:
	RoundScene(GameWindow*, MUSIC);
	~RoundScene();
	
	void init();
	
	void render() override;
	void update() override;
	void addTime();

	void getNoteDelay(int line, unsigned int i_frame);
	void deleteNote(int line, int n_frame);
	void deleteMissNode();
	int getLineInput(int line);
	void setLineInput(int line);

	void setInput(unsigned char) override;
	void unsetInput(unsigned char) override;

	void checkSectionNote();	// �ճ�Ʈ �Է� �˻�

	void checkInput() override;
	void addInput(int line) override;

	// Timer
	void showTimer();
	void timeCheck();
	void calcTimer();

	// Item - Blink
	void blink();
	void blinkOff();
	void blinkCountUp();

	// Item - Accelerate
	void setAccelNote(int _frame);
	double calcAccelNoteDist(int _time);

	// Item + Slow Down
	void setSlowNote(int _frame);
	double calcSlowNoteDist(int _time);

	// Item - LieNote
	int getNearNote(int line, int current_frame);	// Note Binary Search
	void makeLieNoteData(int current_frame);
	void renderLieNotes();
	void setLieInput(int line);
	void lieNoteOn();
	void lieNoteOff();
	void lieTimerCheck();
	void clearLieNoteVector();

	// Auto mode
	void autoMode();
	void setTempLineInput();
	void unsetAutoMode();


	//okt
	bool pause = false;
	void receiveJudgement(int judge, Note* nott);
	void calcInfo(int judge, int highlight);
	void calcSectionInfo(int judge);
	void pauseSound(bool pause);
	void setMVol(float volume);
	

private:
	void renderGrid();
	void renderNotes();
	void renderInputEffect();
	void renderCombo();
	void renderJudgement();
	void renderScoreAndInfo();

	void loadMusic();
	void playSound();

	void playEffectSound();
};
