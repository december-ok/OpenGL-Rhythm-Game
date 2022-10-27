#pragma once
#include<vector>
#include<string>
#include "Global.h"

using namespace std;

class Round
{
	string id;
	unsigned int frame = 0;
	unsigned int score = 0;
	vector<bool> notes[LINES];

	bool key[LINES] = { false, false, false, false };
	bool renderKey[LINES] = { false, false, false, false };

public:
	Round(string);
	~Round();
	
	void init();
	
	void render();
	void addTime();

	void setInput(unsigned char);
	void unsetInput(unsigned char);
private:
	void renderGrid();
	void renderNotes();
	void renderInputEffect();
};
