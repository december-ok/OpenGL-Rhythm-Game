#pragma once

#define WIDTH 1270
#define HEIGHT 720
#define COLUMS 127
#define ROWS 108
#define JUDGE_HEIGHT 5

#define FPS 60

#define INF 214748364	// 일부러 마지막 자리 뺌

#define LINES 4

#define PI 3.14159265358979323846
#define START_FRAME 5*FPS

#define ITEM_COUNT 5
#define ITEM_NUMBER 6

// ITEM BLINK
#define BLINK_DURATION 400
#define BLINK_DELAY 20

// ITEM ACCEL
#define ACCEL_DURATION 400
#define ACCEL_INIT_VELOCITY 0
#define ACCEL_CONSTANT 0.0097087		// 수정 X: 수정하면 판정선과 노트가 맞지 않음

// ITEM SLOWDOWN
#define SLOW_DOWN_DURATION 400
#define SLOW_DOWN_INIT_VELOCITY 1.5
#define SLOW_DOWN_CONSTANT  -0.004854	// 수정 X: 수정하면 판정선과 노트가 맞지 않음

// LieNote
#define LIE_DURATION 400


enum MUSIC {
	CANON,
	BIRTHDAY_CAKE
};

enum JUDGEMENT {
	NONE,
	PERFECT,
	GREAT,
	NORMAL,
	BAD,
	MISS
};

enum ITEMTYPE {
	HPUP,
	REINFORCE,
	SWITCHLINE,
	BLINK,
	ACCELERATE,
	SLOWDOWN,
	LIENOTE
};

enum UI_SELECTION {
	SINGLE_PLAY,
	ONLINE_PLAY,
	TUTORIAL,
	EXIT
};

enum JUDGEMENT_FRAME {
	PERFECT_FRAME = 5,
	GREAT_FRAME = 10,
	NORMAL_FRAME = 15,
	BAD_FRAME = 20,
	MISS_FRAME = 25

};