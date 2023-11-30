#include "Border.h"

Border::Border(float _borderPadding)
	: borderPadding(_borderPadding)
{

}

void Border::Draw(Graphics& gfx)
{
}

Rect Border::GetBorderRect()
{
	return Rect();
}
