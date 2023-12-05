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
	bool CheckOverlap(const Rect& otherRect, Sound& sound, bool& isGameOver);
	Rect GetRect() const;
	const Vec2 GetCenterLocation() const;
	void InverseX();
	void InverseY();
	const Vec2 GetDirection() const;
private:
	Vec2 centerLoc;
	float radius;
	float speed;
	Vec2 direction;
};