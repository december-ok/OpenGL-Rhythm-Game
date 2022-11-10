#pragma once
#include<vector>
#include<string>
#include<queue>
#include "Global.h"
#include "Note.h"
#include "Input.h"
#include <bass.h>
#include"GameInfo.h"

using namespace std;
static unsigned int frame = 0;

class Round
{
	MUSIC id;
	string name = "";
	string artist = "";
	string musicFile = "";
	HSTREAM stream = NULL;

	//unsigned int frame = 0;
	unsigned int score = 0;
	vector<Note*> notes[LINES];
	int line_input[LINES]; // 각 라인 별 입력 횟수 저장 - list로 할 때


	bool key[LINES] = { false, false, false, false };
	bool renderKey[LINES] = { false, false, false, false };
	queue<Input*> InputQueue;
	
	GameInfo* gameInfo;
	unsigned int reinforce = 0;
	int endFrame = 0;
public:
	
	Round(MUSIC);
	~Round();
	
	void init();
	
	void render();
	void update();
	void addTime();

	//int getNoteDelay(int line);	// 노트의 딜레이 반환
	int getNoteDelay(int line, unsigned int i_frame);	// 노트의 딜레이 반환
	void deleteNote(int line, int n_frame);
	void deleteMissNote();		// 입력 못한 노트 제거
	int getLineInput(int line);
	void setLineInput(int line);

	void setInput(unsigned char);
	void unsetInput(unsigned char);

	// InputQueue 확인
	void checkInputQueue();
	void addInputQueue(int line);

	//okt
	bool pause = false;
	void receiveJudgement(int judge,Note* nott);
	void calcScore(int judge);
	void pauseSound(bool pause);

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
