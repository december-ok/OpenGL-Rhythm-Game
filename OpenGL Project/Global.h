#pragma once

#define WIDTH 1270
#define HEIGHT 720
#define COLUMS 127
#define ROWS 108

#define FPS 60

#define LINES 4

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

#define START_FRAME 5*FPS