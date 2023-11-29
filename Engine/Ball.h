#pragma once
#include "Vec2.h"
#include "Rect.h"
#include "Graphics.h"
class Ball
{
public:
	Ball(Vec2 _centerLoc, float _radius, float _speed);

public:
	void Draw(Graphics& gfx);
	void Update(float deltaTime);
	bool IsOverlapping(const Rect& otherRect);
	void HandleOverlap(const Rect& otherRect);

private:
	Rect GetRect() const;

private:
	Vec2 centerLoc;
	float radius;
	float speed;
	Vec2 direction;
};