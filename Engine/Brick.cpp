#include "Brick.h"

Brick::Brick(Vec2 _origin, float _width, float _height, Color _color)
	: origin(_origin), width(_width), height(_height), color(_color)
{
}

bool Brick::HandleOverlap(Ball& ball, Sound& sound)
{
	//if(GetRect().CheckOverlap(ball.GetRect()))
	//{
	//	if 
	//}

	return false;
}

void Brick::Draw(Graphics& gfx)
{
	Rect rect = GetRect();
	gfx.DrawRect(rect.GetLeft(), rect.GetTop(), rect.GetRight(), rect.GetBottom(), color);
}

bool Brick::GetIsOverlapped() const
{
	return isOverlapped;
}

Rect Brick::GetRect() const
{
	return Rect(origin, width, height);
}
