#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include "Rect.h"
#include "Ball.h"
#include "Sound.h"

class Brick
{
public: 
	Brick() = default; 
	Brick(Vec2 _center, float _halfWidth, float _halfHeight, Color _color);
	bool CheckOverlap(Ball& ball, Sound& sound);
	void Draw(Graphics& gfx);
	bool GetIsDestroyed() const;
	bool CheckCornerHit(const Ball& ball) const;
private:
	Rect GetRect() const;
private:
	Vec2 center = {0.f,0.f};
	float halfWidth = 0.f; 
	float halfHeight = 0,f; 
	Color color;
	bool IsDestroyed = false;
};