#pragma once

#define WIDTH 1270
#define HEIGHT 720
#define COLUMS 127
#define ROWS 108

#define FPS 60

#define LINES 4

#define PI 3.14159265358979323846
#define START_FRAME 5*FPS

enum MUSIC {
	CANON
};

enum JUDGEMENT {
	NONE,
	PERFECT,
	GREAT,
	NORMAL,
	BAD,
	MISS
};

enum UI_SELECTION {
	SINGLE_PLAY,
	ONLINE_PLAY,
	EXIT
};

enum JUDGEMENT_FRAME {
	PERFECT_FRAME = 5,
	GREAT_FRAME = 10,
	NORMAL_FRAME = 15,
	BAD_FRAME = 20,
	MISS_FRAME = 25

};