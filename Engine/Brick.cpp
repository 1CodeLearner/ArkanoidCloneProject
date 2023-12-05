#include "Brick.h"
#include <cmath>

Brick::Brick(Vec2 _center, float _halfWidth, float _halfHeight, Color _color)
	: center(_center), halfWidth(_halfWidth), halfHeight(_halfHeight), color(_color)
{
}

bool Brick::CheckOverlap(Ball& ball, Sound& sound)
{
	if (!IsDestroyed && GetRect().CheckOverlap(ball.GetRect()))
	{
		Rect ballRect = ball.GetRect();
		//Ball is hitting the sides of brick
		if (ball.GetRect().GetBottom() < GetRect().GetBottom()) {
			ball.InverseX();
		}
		else if (CheckCornerHit(ball))
		{
			//Ball is hitting corner within inside of brick. 
			if (std::signbit(ball.GetDirection().x) ==
				std::signbit(ball.GetCenterLocation().x - center.x))
			{
				ball.InverseY();
			}
			//Ball is hitting corner from outside of brick.
			else
			{
				ball.InverseX();
				ball.InverseY();

			}
		}
		else
		{
			ball.InverseY();
		}
		IsDestroyed = true;
		sound.Play();
		return true;
	}
	return false;
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

bool Brick::CheckCornerHit(const Ball& ball) const
{
	return ball.GetRect().GetRight() > GetRect().GetRight()
		&& ball.GetRect().GetLeft() > GetRect().GetLeft() ||
		ball.GetRect().GetLeft() < GetRect().GetLeft()
		&& ball.GetRect().GetRight() < GetRect().GetRight();;
}

Rect Brick::GetRect() const
{
	return Rect::CenterToRect(center, halfWidth, halfHeight);
}
