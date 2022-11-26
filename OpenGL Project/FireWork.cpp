#include"FireWork.h"
#include <cmath>
using namespace std;

void drawCircle(float x, float y, float radius, RGBClass* rgb) {
	float circle_points = 4;
	float angle;
	glColor4f(rgb->r, rgb->g, rgb->b, rgb->a);
	glLineWidth(1);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < circle_points; ++i) {
		angle = 2 * PI * i / circle_points;
		glVertex2d(x + cos(angle) * radius, y + sin(angle) * radius * 1.5);
	}
	glEnd();
}

float getRandRage(float min, float max) {
	return (rand() * (max - min) / RAND_MAX) + min;
}

int getRandPlusMinus() {
	return (rand() % 2) * 2 - 1;
}

Vector::Vector(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector::set(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector::add(float x, float y)
{
	this->x += x;
	this->y += y;
}

Vector* Vector::clone()
{
	return new Vector(this->x, this->y);
}

RGBClass::RGBClass(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

void RGBClass::setAlpha(float a)
{
	this->a = a;
}

RGBClass* RGBClass::copyAlpha(float a)
{
	return new RGBClass(this->r, this->g, this->b, a);
}

Particle::Particle(Vector* pos, Vector* vel, RGBClass* rgb)
{
	this->pos = pos;
	this->vel = vel;
	this->after_length = 25;
	this->life = 1;
	this->rgb = rgb;
	this->after = vector<Vector*>();
	this->after.reserve(this->after_length);
	
	this->size = 0.3f;
}
Particle ::~Particle()
{
	free(this->pos);
	free(this->vel);
	free(this->rgb);
	for (auto v : this->after) {
		free(v);
	}
}

void Particle::render() {
	drawCircle(this->pos->x, this->pos->y, this->size, this->rgb);
	
	for (int i = 0; i < this->after.size(); i++) {
		RGBClass* tempColor = this->rgb->copyAlpha(i / (float)this->after_length - 1 + this->life);
		drawCircle(this->after[i]->x, this->after[i]->y, this->size, tempColor);
		free(tempColor);
	}
}

void Particle::update() {
	this->rgb->setAlpha(this->life);
		
	this->after.push_back(this->pos->clone());
	this->pos->add(this->vel->x, this->vel->y);
	
	while (true) {
		if (this->after.size() <= this->after_length) break;
		
		this->after.erase(this->after.begin());
	}
}

FireWork::FireWork(Vector* pos, float speed) {
	this->pos = pos;
	this->speed = speed;

	this->color = new RGBClass(getRandRage(0,1), getRandRage(0, 1), getRandRage(0, 1), 1);

	this->elevator = new Particle(pos, new Vector(0, this->speed), this->color);
	this->explosionList = vector<Particle*>();
	this->explosionList.reserve(this->EXPLOSION_COUNT);
}

FireWork::~FireWork() {
	free(this->pos);
	free(this->color);
	free(this->elevator);
	for (auto p : this->explosionList) {
		free(p);
	}
}

void FireWork::update() {
	if (this->elevateMode) this->elevateUpdate();
	else this->explodeUpdate();
}

void FireWork::elevateUpdate() {
	this->elevator->update();
	this->elevator->vel->add(0, -0.02f);

	float speed = 0.5f;
	
	if (this->elevator->vel->y <= 0) {
		this->elevateMode = false;
		Vector* pos = this->elevator->pos;
		for (int i = 0; i < this->EXPLOSION_COUNT; i++) {
			float randX = getRandRage(-speed, speed);
			float maxRandY = sqrt((speed * speed) + 0.001f - (randX * randX));
			float randY = getRandRage(-1 * maxRandY, maxRandY) * 1.5;
			this->explosionList.push_back(
				new Particle(pos->clone(), new Vector(randX, randY), this->color)
			);
		}
	}
}

void FireWork::explodeUpdate() {
	for (auto p : this->explosionList) {
		p->vel->y -= 0.006f;
		p->life -= 0.008f;
		p->update();
	}
}

void FireWork::render() {
	if (this->elevateMode) this->elevateRender();
	else this->explodeRender();
}

void FireWork::elevateRender(){
	this->elevator->render();
}

void FireWork::explodeRender(){
	for (auto p : this->explosionList) {
		if(p->life > 0) p->render();
	}
}