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
	Brick(Vec2 _origin, float _width, float _height, Color _color);
	bool HandleOverlap(Ball& ball, Sound& sound);
	void Draw(Graphics& gfx);
	bool GetIsOverlapped() const;
private:
	Rect GetRect() const;
private:
	Vec2 origin; 
	float width; 
	float height; 
	Color color;
	bool isOverlapped = false;
};