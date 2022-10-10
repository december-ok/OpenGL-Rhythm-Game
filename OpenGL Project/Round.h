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
	vector<bool> notes[5];
public:
	Round(string);
	~Round();
	
	void init();
	
	void render();
	void addTime();
private:
	
	void renderGrid();
	void renderNotes();
	void renderInputEffect(int);
};
