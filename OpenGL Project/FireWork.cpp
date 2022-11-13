#include"FireWork.h"

void drawCircle(float x, float y, float radius) {
	float circle_points = 50;
	float angle;
	glLineWidth(1);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < circle_points; ++i) {
		angle = 2 * PI * i / circle_points;
		glVertex2d(x + cos(angle) * radius, y + sin(angle) * radius * 1.5);
	}
	glEnd();
}

Vector::Vector() {
	this->x = 0;
	this->y = 0;
}

Vector::Vector(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector::set(Vector* v)
{
	this->x = v->x;
	this->y = v->y;
}

void Vector::add(Vector* v)
{
	this->x += v->x;
	this->y += v->y;
}

Vector Vector::clone()
{
	return Vector(this->x, this->y);
}

Particle::Particle(Vector* pos, Vector* vel, float size, float life)
{
	this->position = pos;
	this->velocity = vel;
	this->after_length = 10;
	this->size = size;
	this->life = life;
	this->r = 1.0f;
	this->g = 1.0f;
	this->b = 1.0f;
	this->after = vector<Vector*>();
	this->after.reserve(100);
}

void Particle::render() {
	drawCircle(this->position->x, this->position->y, 2.f);
	
	for (int i = 0; i < this->after.size(); i++) {
		drawCircle(this->after[i]->x, this->after[i]->y, 2.f);
	}
}

void Particle::update() {
	this->after.push_back(this->position);
	this->position->add(this->velocity);
	
	while (true) {
		if (this->after.size() <= this->after_length) break;
		
		this->after.erase(this->after.begin());
	}
}

FireWork::FireWork(Vector* pos, float speed) {
	this->position = pos;
	this->speed = speed;

	this->elevator = new Particle(this->position, new Vector(0, this->speed), 2.f, 1.f);
	this->explosionList = vector<Particle*>();
	this->explosionList.reserve(50);
}

void FireWork::update() {
	if (this->elevateMode) this->elevateUpdate();
	else this->explodeRender();
}

void FireWork::elevateUpdate() {
	this->elevator->update();
	this->elevator->velocity->y += 0.01f;

	if (this->elevator->velocity->y > 0) {
		Vector* pos = this->elevator->position;
		for (int i = 0; i < this->EXPLOSION_COUNT;++i) {
			this->explosionList.push_back(
				new Particle(
					pos,
					new Vector(
						(float)(rand() % 150) / 100.f, (float)(rand() % 150) / 100.f
					),
					2.f,
					1.f
				)
			);

			this->elevateMode = false;
		}
	}
}

void FireWork::explodeUpdate() {
	for (int i = 0;i < this->EXPLOSION_COUNT;++i) {
		Particle* p = this->explosionList[i];
		p->velocity->y += 2;
		p->life -= 0.004f;
		p->update();
	}
}

void FireWork::render() {
	if (this->elevateMode)	this->elevateRender();
	else this->explodeRender();
}

void FireWork::elevateRender(){
	this->elevator->render(); 
}

void FireWork::explodeRender(){
	for (int i = 0;i < this->EXPLOSION_COUNT; ++i) {
		Particle* p = this->explosionList[i];
		p->render();
	}
}