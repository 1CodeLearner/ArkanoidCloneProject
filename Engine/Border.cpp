#include "Border.h"
#include <assert.h>

Border::Border(Color _color, float _borderPadding)
	: color(_color), borderPadding(_borderPadding)
{
	assert(windowsBorder.GetLeft() + borderPadding >= 0);
	assert(windowsBorder.GetRight() - borderPadding <= Graphics::ScreenWidth);
	assert(windowsBorder.GetTop() + borderPadding >= 0);
	assert(windowsBorder.GetBottom() - borderPadding <= Graphics::ScreenHeight);
}

void Border::Draw(Graphics& gfx)
{
	Rect padded = GetBorderRectPadded();
	for (int i = 0; i < Graphics::ScreenHeight; i++) 
	{
		for (int j = 0; j < Graphics::ScreenWidth; j++)
		{
			if (!padded.CheckOverlap(Vec2((float)j, (float)i)) &&
				i < padded.GetBottom()
			)
			{

				gfx.PutPixel(j, i, color);
			}
		}
	}
}

Rect Border::GetBorderRect() const
{
	return GetBorderRectPadded();
}

Rect Border::GetBorderRectPadded() const
{
	return windowsBorder.GetPadded(-borderPadding);
}