#include "Paddle.h"

Paddle::Paddle(Vec2 _center, float _halfWidth, float _halfHeight, Color _color)
	: center(_center), halfWidth(_halfWidth), halfHeight(_halfHeight), color(_color)
{
	moveDir = { 0.f, 0.f };
	speed = 350.f;
	speedUp = 500.f;
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
	
	float finalSpeed = speed;
	if (kbd.KeyIsPressed(VK_SHIFT))
	{
		finalSpeed = speedUp;
	}
	center += moveDir * finalSpeed * deltaTime;
	moveDir = { 0.f,0.f };

	ClampToScreen();
}

void Paddle::HandleOverlap(Ball& ball, Sound& sound)
{
	if ( ball.GetRect().CheckOverlap(GetRect()))
	{
		Rect ballRect = ball.GetRect();
		if (ball.GetRect().GetTop() > GetRect().GetTop()) {
			ball.InverseX();
		}
		else if (
			ball.GetRect().GetRight() > GetRect().GetRight() 
			&& ball.GetRect().GetLeft() > GetRect().GetLeft() ||
			ball.GetRect().GetLeft() < GetRect().GetLeft() 
			&& ball.GetRect().GetRight() < GetRect().GetRight()
		)
		{
			ball.InverseX();
			ball.InverseY();
		}
		else 
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
