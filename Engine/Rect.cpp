#include "Rect.h"

Rect::Rect(Vec2 center, float radius)
	: Rect(Vec2(center.x - radius, center.y - radius),
		radius + radius, radius + radius)
{}

Rect::Rect(Vec2 _loc, float _width, float _height)
	: Rect(_loc.x, _loc.y, _loc.x + _width, _loc.y + _height)
{
	
}

Rect::Rect(float left, float top, float right, float bottom)
	: left(left), top(top), right(right), bottom(bottom)
{
}

Rect Rect::CenterToRect(Vec2 center, float halfWidth, float halfHeight)
{
	Vec2 half = { halfWidth, halfHeight };
	return Rect(center - half, halfWidth*2, halfHeight*2);
}

Rect Rect::GetPadded(float padding) const
{

	return Rect(left - padding, top - padding, right + padding, bottom + padding);
}

bool Rect::CheckOverlap(const Rect& other) const
{
	//right > other.left || left < other.right ||
	//	top < other.bottom || bottom > other.top;
	return right > other.left && left < other.right
		&& bottom > other.top && top < other.bottom;
}

bool Rect::CheckOverlap(const Vec2 other) const
{
	return other.x >= left && other.x <= right &&
		other.y >= top && other.y <= bottom;
}

float Rect::GetLeft() const
{
	return left;
}

float Rect::GetTop() const
{
	return top;
}

float Rect::GetRight() const
{
	return right;
}

float Rect::GetBottom() const
{
	return bottom;
}
