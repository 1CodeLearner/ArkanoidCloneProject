#pragma once
#include "Vec2.h"
#include "Graphics.h"

struct SpriteDim
{
public:
	SpriteDim(Vec2 _topLeft, int _width, int _height)
	{
		topLeft = _topLeft; 
		width = _width; 
		height = _height;
	}
	Vec2 topLeft;
	int width = 0;
	int height = 0;
};


class MySprites
{
public:
	static void DrawGameOver(Graphics& gfx);
};