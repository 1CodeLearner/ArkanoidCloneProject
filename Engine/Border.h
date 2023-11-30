#pragma once
#include "Graphics.h"
#include "Rect.h"

class Border
{
public:
	Border(float _borderPadding = 0.f);
	void Draw(Graphics& gfx);
	Rect GetBorderRect();
private:
	Rect windowsBorder = Rect(0.f, 0.f, Graphics::ScreenWidth, Graphics::ScreenHeight);
	float borderPadding;
};