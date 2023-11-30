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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball(Vec2(100.f, 100.f), 7.f, 500.f),
	brick(Vec2(500.f, 500.f), 100, 40, Colors::Gray),
	sound(L"Sounds\\arkpad.wav")
{
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
	//Ball will always be overlapping with windowsBorder.
	Rect windowsBorder = Rect(0.f, 0.f, Graphics::ScreenWidth, Graphics::ScreenHeight);
	ball.HandleOverlap(windowsBorder, sound);
	//brick.HandleOverlap(ball, sound);
}

void Game::ComposeFrame()
{
	if(!brick.GetIsOverlapped())
	{
		brick.Draw(gfx);
	}
	ball.Draw(gfx);
}
