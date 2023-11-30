#include "Brick.h"

Brick::Brick(Vec2 _center, float _halfWidth, float _halfHeight, Color _color)
	: center(_center), halfWidth(_halfWidth), halfHeight(_halfHeight), color(_color)
{
}

void Brick::HandleOverlap(Ball& ball, Sound& sound)
{
	if (!IsDestroyed && GetRect().CheckOverlap(ball.GetRect()))
	{
		ball.InverseY();
		this->IsDestroyed = true;
		sound.Play();
	}
}

void Brick::Draw(Graphics& gfx)
{
	if (!IsDestroyed) {
		Rect rect = GetRect();
		gfx.DrawRect(rect.GetLeft(), rect.GetTop(), rect.GetRight(), rect.GetBottom(), color);
	}
	

}

bool Brick::GetIsDestroyed() const
{
	return IsDestroyed;
}

Rect Brick::GetRect() const
{
	return Rect::AtCenter(center, halfWidth, halfHeight);
}
