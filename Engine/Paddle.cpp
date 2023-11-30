#include "Paddle.h"

Paddle::Paddle(Vec2 _center, float _halfWidth, float _halfHeight, Color _color)
	: center(_center), halfWidth(_halfWidth), halfHeight(_halfHeight), color(_color)
{
	moveDir = { 0.f, 0.f };
	speed = 250.f;
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
	if ( ball.GetRect().CheckOverlap(GetRect()))
	{
		Rect ballRect = ball.GetRect();
		if (ballRect.GetBottom() > GetRect().GetTop())
		{
			ball.InverseY();
		}
		sound.Play();
	}
}

void Paddle::Draw(Graphics& gfx)
{
	Rect rect = GetRect();
	gfx.DrawRect(rect.GetLeft(), rect.GetTop(), rect.GetRight(), rect.GetBottom(), color);
}

Rect Paddle::GetRect() const
{
	return Rect::AtCenter(center, halfWidth, halfHeight);
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
