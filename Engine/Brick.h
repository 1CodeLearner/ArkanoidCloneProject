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
	bool HandleOverlap(Ball& ball, Sound& sound);
	void Draw(Graphics& gfx);
	bool GetIsOverlapped() const;
private:
	Rect GetRect() const;
private:
	Vec2 center; 
	float halfWidth; 
	float halfHeight; 
	Color color;
	bool isOverlapped = false;
};