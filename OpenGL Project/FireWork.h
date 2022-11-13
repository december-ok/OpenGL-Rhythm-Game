#pragma once
#include "Render.h"
#include "Global.h"
#include "Global.h"
#include <math.h>
#include <vector>
using namespace std;

void drawCircle(float x, float y, float radius);

class Vector {
public:
	Vector();
	Vector(float x, float y);

	float x;
	float y;
	
	void set(Vector* v);
	void add(Vector* v);
	Vector clone();
};

class Particle {
public:
	Particle(Vector* pos, Vector* vel, float size, float life);

	Vector* position;
	Vector* velocity;
	int after_length;
	float size;
	float life;
	float r;
	float g;
	float b;
	vector<Vector*> after;

	void update();
	void render();
};

class FireWork {
public:
	FireWork(Vector* pos, float speed);

	Vector* position;
	Vector* velocity;
	float speed;
	int EXPLOSION_COUNT = 20;
	bool elevateMode = true;
	
	Particle* elevator;
	vector<Particle*> explosionList;

	vector<Particle*> particles;

	void update();
	void elevateUpdate();
	void explodeUpdate();
	
	void render();
	void elevateRender();
	void explodeRender();
};
