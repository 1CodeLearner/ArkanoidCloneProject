#include "Brick.h"

Brick::Brick(Vec2 _center, float _halfWidth, float _halfHeight, Color _color)
	: center(_center), halfWidth(_halfWidth), halfHeight(_halfHeight), color(_color)
{
}

bool Brick::HandleOverlap(Ball& ball, Sound& sound)
{
	if(!isOverlapped && GetRect().CheckOverlap(ball.GetRect()))
	{
		ball.InverseY();
		isOverlapped = true;
		sound.Play();
	}

	return isOverlapped;	
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
	return Rect::AtCenter(center, halfWidth, halfHeight);
}
