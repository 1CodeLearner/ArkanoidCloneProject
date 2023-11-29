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

void Ball::HandleOverlap(const Rect& otherRect)
{
}

Rect Ball::GetRect() const
{
	return Rect(centerLoc, radius );
}
