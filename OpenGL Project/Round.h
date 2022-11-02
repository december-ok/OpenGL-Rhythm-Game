#pragma once
#include<vector>
#include<string>
#include "Global.h"
#include <bass.h>

using namespace std;


class Round
{
	MUSIC id;
	string name = "";
	string artist = "";
	string musicFile = "";
	HSTREAM stream = NULL;

	//unsigned int frame = 0;
	unsigned int score = 0;
	vector<bool> notes[LINES];

	bool key[LINES] = { false, false, false, false };
	bool renderKey[LINES] = { false, false, false, false };
	

public:
	static unsigned int frame;
	Round(MUSIC);
	~Round();
	
	void init();
	
	void render();
	void update();
	void addTime();

	int getFrame();	
	int getNoteDelay(int line, int n_frame);	// 노트의 딜레이 반환
	void deleteNote(int line, int n_frame);
	void deleteMissNote();

	void setInput(unsigned char);
	void unsetInput(unsigned char);
private:
	void renderGrid();
	void renderNotes();
	void renderInputEffect();

	void loadSound();
	void playSound();
};
