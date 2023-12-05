#pragma once
#include "Graphics.h"
#include "Rect.h"

class Border
{
public:
	Border(Color _color, float _borderPadding = 0.f);

public:
	void Draw(Graphics& gfx);
	Rect GetBorderRect() const;

private:
	Rect GetBorderRectPadded() const;

	Rect windowsBorder = Rect(0.f, 0.f, Graphics::ScreenWidth, Graphics::ScreenHeight);
	float borderPadding;
	Color color;
};