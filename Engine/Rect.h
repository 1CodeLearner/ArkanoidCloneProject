#pragma once
#include "Vec2.h"

class Rect
{
public:
	Rect() = default; 
	Rect(Vec2 center, float radius);
	Rect(Vec2 _loc, float _width, float _height);
	Rect(float left, float top, float right, float bottom);
	static Rect AtCenter(Vec2 center, float halfWidth, float halfHeight);
public:
	Rect GetPadded(float padding) const;
	bool CheckOverlap(const Rect& other) const;
	bool CheckOverlap(const Vec2 other) const;
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