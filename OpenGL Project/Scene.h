#pragma once

class Scene {
public:
	virtual void render() = 0;
	virtual void update() = 0;

	virtual void setInput(unsigned char) = 0;
	virtual void unsetInput(unsigned char) = 0;

	virtual void checkInput() = 0;
	virtual void addInput(int) = 0;
};
