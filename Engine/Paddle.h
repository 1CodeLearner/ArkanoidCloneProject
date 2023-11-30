#pragma once
#include "Vec2.h"
#include "Ball.h"
#include "Sound.h"
#include "Graphics.h"
#include "Keyboard.h"


class Paddle
{
public:
	Paddle(Vec2 _center, float _halfWidth, float _halfHeight, Color _color);
	
	void Update( Keyboard& kbd , float deltaTime);
	void HandleOverlap(Ball& ball, Sound& sound);

	void Draw(Graphics& gfx);

private:
	Rect GetRect() const;
	void ClampToScreen();
private:
	Vec2 center;
	float halfWidth; 
	float halfHeight; 
	
	Vec2 moveDir;
	float speed;

	Color color; 

};