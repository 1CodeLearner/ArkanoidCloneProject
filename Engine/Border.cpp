#include "Border.h"
#include <assert.h>

Border::Border(float _borderPadding)
	: borderPadding(_borderPadding)
{

}

void Border::Draw(Graphics& gfx)
{

}

Rect Border::GetBorderRect()
{
	assert(windowsBorder.GetLeft() + borderPadding >= 0);
	assert(windowsBorder.GetRight() - borderPadding <= Graphics::ScreenWidth);
	assert(windowsBorder.GetTop() + borderPadding >= 0);
	assert(windowsBorder.GetBottom() - borderPadding <= Graphics::ScreenHeight);

	return windowsBorder.GetPadded(-borderPadding);
}
