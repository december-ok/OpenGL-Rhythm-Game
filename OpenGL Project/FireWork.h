#pragma once
#include "Render.h"
#include "Global.h"
#include "Global.h"
#include <math.h>
#include <vector>
#include <stdlib.h>
using namespace std;


class Vector {
public:
	Vector(float x, float y);

	float x;
	float y;
	
	void set(float x, float y);
	void add(float x, float y);
	Vector* clone();
};

class RGBClass {
public:
	RGBClass(float r, float g, float b, float a);
	float r;
	float g;
	float b;
	float a;
	void setAlpha(float a);
	RGBClass* copyAlpha(float a);
};

class Particle {
public:
	Particle(Vector* pos, Vector* vel, RGBClass* rgb);
	~Particle();

	Vector* pos;
	Vector* vel;
	int after_length;
	float size;
	float life;
	RGBClass* rgb;
	vector<Vector*> after;

	void update();
	void render();
};

class FireWork {
public:
	FireWork(Vector* pos, float speed);
	~FireWork();

	Vector* pos;
	float speed;
	RGBClass* color;
	int EXPLOSION_COUNT = 75;
	bool elevateMode = true;
	
	Particle* elevator;
	vector<Particle*> explosionList;
	

	void update();
	void elevateUpdate();
	void explodeUpdate();
	
	void render();
	void elevateRender();
	void explodeRender();
};

void drawCircle(float x, float y, float radius, RGBClass* rgb);
float getRandRage(float min, float max);
int getRandPlusMinus();