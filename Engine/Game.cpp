/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(100.f, 100.f), 7.f, 500.f),
	paddle(Vec2(300.f, 500.f), 100, 25, Colors::Green),
	sound(L"Sounds\\arkpad.wav")
{
	for (int i = 0; i < brickRow; i++)
	{
		for (int j = 0; j < brickColumn; j++)
		{
			int index = i * brickColumn + j;
			float x = bricksStartPos.x + (2 * brickHalfWidth) * j;
			float y = bricksStartPos.y + (2 * brickHalfHeight) * i;
			Vec2 newStartPos = Vec2(x, y);
			Vec2 newCenter = Vec2(newStartPos.x + brickHalfWidth, 
				newStartPos.y + brickHalfHeight);
			bricks[index] = Brick(newCenter, brickHalfWidth, brickHalfHeight, Colors::Blue);
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float deltaTime = frameTimer.Mark();

	ball.Update(deltaTime);
	paddle.Update(wnd.kbd, deltaTime);
	//Ball will always be overlapping with windowsBorder.
	ball.HandleOverlap(windowsBorder, sound);
	for (Brick brick : bricks)
	{
		brick.HandleOverlap(ball, sound);
	}
	paddle.HandleOverlap(ball, sound);
}

void Game::ComposeFrame()
{
	for (Brick brick : bricks)
	{
		brick.Draw(gfx);
	}
	ball.Draw(gfx);
	paddle.Draw(gfx);
}
