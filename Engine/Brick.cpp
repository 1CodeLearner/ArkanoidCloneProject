#include "Brick.h"
#include <cmath>
#include <assert.h>
Brick::Brick(Vec2 _center, float _halfWidth, float _halfHeight, Color _color)
	: center(_center), halfWidth(_halfWidth), halfHeight(_halfHeight), color(_color)
{
}

Brick::~Brick()
{
	delete pBrickToDestroy;
}

bool Brick::CheckOverlap(Ball& ball, Sound& sound)
{
	if (!IsDestroyed && GetRect().CheckOverlap(ball.GetRect()))
	{
		Rect ballRect = ball.GetRect();
		//Ball is hitting the sides of brick
		if (ball.GetRect().GetBottom() < GetRect().GetBottom()) {
			ball.InverseX();
		}
		else if (CheckCornerHit(ball))
		{
			//Ball is hitting corner within inside of brick. 
			if (std::signbit(ball.GetDirection().x) ==
				std::signbit(ball.GetCenterLocation().x - center.x))
			{
				ball.InverseY();
			}
			//Ball is hitting corner from outside of brick.
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
		IsDestroyed = true;
		sound.Play();
		return true;
	}
	return false;
}

void Brick::Draw(Graphics& gfx)
{
	if (!IsDestroyed) {
		Rect rect = GetRect();
		gfx.DrawRect(rect.GetLeft(), rect.GetTop(), rect.GetRight(), rect.GetBottom(), color);
	}
	

}

bool Brick::GetIsDestroyed() const
{
	return IsDestroyed;
}

void Brick::DetectOverlap(const Ball& ball)
{
	if ( !IsDestroyed && GetRect().CheckOverlap(ball.GetRect()) )
	{
		if(pBrickToDestroy == nullptr)
			pBrickToDestroy = this;
		else 
		{
			float storedBrickSq = (ball.GetCenterLocation() - pBrickToDestroy->center).GetLengthSq();
			float newBrickSq = (ball.GetCenterLocation() - this->center).GetLengthSq();

			if (newBrickSq < storedBrickSq)
			{
				pBrickToDestroy = this;
			}
		}
	}
}

bool Brick::ExecuteOverlap(Ball& ball, Sound& brickSound)
{
	bool hasCollided = false;
	if(pBrickToDestroy)
	{
		//Ball is hitting the sides of brick
		if (ball.GetRect().GetBottom() <
			pBrickToDestroy->GetRect().GetBottom()
		)
		{
			ball.InverseX();
		}
		else if (CheckCornerHit(ball))
		{
			//Ball is hitting corner within inside of brick. 
			if (std::signbit(ball.GetDirection().x) ==
				std::signbit(ball.GetCenterLocation().x - pBrickToDestroy->center.x)
			)
			{
				ball.InverseY();
			}
			//Ball is hitting corner from outside of brick.
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
		pBrickToDestroy->IsDestroyed = true;
		brickSound.Play();
		hasCollided = true;
	}
	else
	{
		hasCollided = false;
	}

	pBrickToDestroy = nullptr;
	return hasCollided;
}

bool Brick::CheckCornerHit(const Ball& ball)
{
	assert(pBrickToDestroy);

	Rect tempRect = pBrickToDestroy->GetRect();

	return ball.GetRect().GetRight() > tempRect.GetRight()
		&& ball.GetRect().GetLeft() > tempRect.GetLeft() ||
		ball.GetRect().GetLeft() < tempRect.GetLeft()
		&& ball.GetRect().GetRight() < tempRect.GetRight();;
}

Rect Brick::GetRect() const
{
	return Rect::CenterToRect(center, halfWidth, halfHeight);
}


Brick* Brick::pBrickToDestroy = nullptr;