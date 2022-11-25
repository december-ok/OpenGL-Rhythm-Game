#include "GameWindow.h"
#include <ctime>


int main(void) {
	srand((unsigned int)time(NULL));
	GameWindow* window = new GameWindow();
	return 0;
} 