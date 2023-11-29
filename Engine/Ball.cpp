#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(Vec2 _centerLoc, float _radius, float _speed)
	: centerLoc(_centerLoc), radius(_radius), speed(_speed)
{
	direction = Vec2(1.f, 1.f);
}

void Ball::Draw(Graphics& gfx)
{
	SpriteCodex::DrawBall(centerLoc, gfx);
}

void Ball::Update(float deltaTime)
{
	centerLoc += direction.GetNormalized() * speed* deltaTime;
}

bool Ball::IsOverlapping(const Rect& otherRect)
{
	Rect ballRect = GetRect();
	return ballRect.CheckOverlap(otherRect);
}

void Ball::InverseX()
{
	direction.x *= -1.f;
}

void Ball::InverseY()
{
	direction.y *= -1.f;
}

void Ball::HandleOverlap(const Rect& otherRect)
{
	if (IsOverlapping(otherRect))
	{
		//HandleOverlap will change ball position only when edges of rect overlap.
		Rect ballRect = GetRect();
		if (ballRect.GetLeft() <= otherRect.GetLeft())
		{
			centerLoc.x += otherRect.GetLeft() - ballRect.GetLeft();
			InverseX();
		}
		if (ballRect.GetRight() > otherRect.GetRight())
		{
			centerLoc.x += otherRect.GetRight() - ballRect.GetRight();
			InverseX();
		}
		if (ballRect.GetTop() <= otherRect.GetTop())
		{
			centerLoc.y += otherRect.GetTop() - ballRect.GetTop();
			InverseY();
		}
		if (ballRect.GetBottom() > otherRect.GetBottom())
		{
			centerLoc.y += otherRect.GetBottom() - ballRect.GetBottom();
			InverseY();
		}
	}
}

Rect Ball::GetRect() const
{
	return Rect(centerLoc, radius );
}
