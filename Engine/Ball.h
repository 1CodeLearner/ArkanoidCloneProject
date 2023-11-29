#pragma once
#include "Vec2.h"
#include "Rect.h"
#include "Graphics.h"
#include "Sound.h"
class Ball
{
public:
	Ball(Vec2 _centerLoc, float _radius, float _speed);

public:
	void Draw(Graphics& gfx);
	void Update(float deltaTime);
	void HandleOverlap(const Rect& otherRect, Sound& sound);

private:
	Rect GetRect() const;
	bool IsOverlapping(const Rect& otherRect);
	void InverseX();
	void InverseY();
private:
	Vec2 centerLoc;
	float radius;
	float speed;
	Vec2 direction;
};