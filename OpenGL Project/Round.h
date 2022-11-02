#pragma once
#include<vector>
#include<string>
#include "Global.h"
#include "Note.h"
#include <bass.h>

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
	

public:
	
	Round(MUSIC);
	~Round();
	
	void init();
	
	void render();
	void update();
	void addTime();

	//int getFrame();	
	int getNoteDelay(int line);	// 노트의 딜레이 반환
	void deleteNote(int line, int n_frame);
	void deleteMissNode();
	int getLineInput(int line);
	void setLineInput(int line);
	//void deleteMissNote();

	void setInput(unsigned char);
	void unsetInput(unsigned char);
private:
	void renderGrid();
	void renderNotes();
	void renderInputEffect();

	void loadSound();
	void playSound();
};
