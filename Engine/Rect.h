#pragma once
#include "Vec2.h"

class Rect
{
public:
	Rect() = default; 
	Rect(Vec2 center, float radius);
	Rect(Vec2 _loc, float _width, float _height);
	Rect(float left, float top, float right, float bottom);
public:
	bool CheckOverlap(const Rect& other);
	float GetLeft() const;
	float GetTop() const;
	float GetRight() const;
	float GetBottom() const;
private:
	float left; 
	float top; 
	float right; 
	float bottom;
};