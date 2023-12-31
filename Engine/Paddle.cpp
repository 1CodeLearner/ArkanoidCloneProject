#include "Paddle.h"
#include <cmath>
Paddle::Paddle(Vec2 _center, float _halfWidth, float _halfHeight, Color _color)
	: center(_center), halfWidth(_halfWidth), halfHeight(_halfHeight), color(_color)
{
	moveDir = { 0.f, 0.f };
	speed = 450.f;
}

void Paddle::Update(Keyboard& kbd, float deltaTime)
{
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		moveDir = { 1.f, 0 };
	}
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		moveDir = { -1.f, 0 };
	}
	center += moveDir * speed * deltaTime;
	moveDir = { 0.f,0.f };

	ClampToScreen();
}

void Paddle::HandleOverlap(Ball& ball, Sound& sound)
{
	if (!HasCollided && ball.GetRect().CheckOverlap(GetRect()))
	{
		Rect ballRect = ball.GetRect();
		//Ball is hitting the sides of paddle
		if (ball.GetRect().GetTop() > GetRect().GetTop()) {
			ball.InverseX();
		}
		else if (CheckCornerHit(ball))
		{
			//Ball is hitting corner within bounds of paddle. 
			if (std::signbit(ball.GetDirection().x) == 
				std::signbit(ball.GetCenterLocation().x - center.x ) )
			{
				ball.InverseY();
			}
			//Ball is hitting corner from outside of paddle.
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
		HasCollided = true;
		sound.Play();
	}
}

void Paddle::Draw(Graphics& gfx)
{
	Rect rect = GetRect();
	gfx.DrawRect((int)rect.GetLeft(), (int)rect.GetTop(), (int)rect.GetRight(), (int)rect.GetBottom(), color);
}

void Paddle::ResetHasCollided()
{
	HasCollided = false;
}

Rect Paddle::GetRect() const
{
	return Rect::CenterToRect(center, halfWidth, halfHeight);
}

void Paddle::ClampToScreen()
{
	Rect rect = GetRect();
	if (rect.GetLeft() < 0.f)
	{
		center.x += 0.f - rect.GetLeft();
	}
	else if (rect.GetRight() >= Graphics::ScreenWidth)
	{
		center.x += Graphics::ScreenWidth - rect.GetRight();
	}
}

bool Paddle::CheckCornerHit(const Ball& ball) const
{
	return ball.GetRect().GetRight() > GetRect().GetRight()
		&& ball.GetRect().GetLeft() > GetRect().GetLeft() ||
		ball.GetRect().GetLeft() < GetRect().GetLeft()
		&& ball.GetRect().GetRight() < GetRect().GetRight();
}
