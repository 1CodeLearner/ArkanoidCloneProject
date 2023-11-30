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


void Ball::InverseX()
{
	direction.x *= -1.f;
}

void Ball::InverseY()
{
	direction.y *= -1.f;
}

void Ball::HandleOverlap(const Rect& otherRect, Sound& sound)
{
	if (GetRect().CheckOverlap(otherRect)) {
		//ball position changes only when the edges overlap.
		Rect ballRect = GetRect();
		if (ballRect.GetLeft() <= otherRect.GetLeft())
		{
			centerLoc.x += otherRect.GetLeft() - ballRect.GetLeft();
			InverseX();
			sound.Play();
		}
		if (ballRect.GetRight() > otherRect.GetRight())
		{
			centerLoc.x += otherRect.GetRight() - ballRect.GetRight();
			InverseX();
			sound.Play();
		}
		if (ballRect.GetTop() <= otherRect.GetTop())
		{
			centerLoc.y += otherRect.GetTop() - ballRect.GetTop();
			InverseY();
			sound.Play();
		}
		if (ballRect.GetBottom() > otherRect.GetBottom())
		{
			centerLoc.y += otherRect.GetBottom() - ballRect.GetBottom();
			InverseY();
			sound.Play();
		}
	}
}

Rect Ball::GetRect() const
{
	return Rect(centerLoc, radius );
}
