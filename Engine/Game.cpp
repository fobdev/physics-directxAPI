#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	entity(Vector(200.0f, 250.0f), sqrSz, sqrSz),
	ground(Vector(400.0f, 500.0f), int(Graphics::ScreenWidth / 2), 2.0f)
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
	const float dt = ft.Mark();

	if (wnd.kbd.KeyIsPressed('E'))
	{
		*ground.chgPosY = 700.0f;
	}

	if (wnd.kbd.KeyIsPressed('R'))
	{
		*entity.pYchg = 30.0f;
	}

	entity.Update(wnd.kbd, dt);
	entity.GroundCollision(ground);
	ground.ChangeHeight(wnd.kbd);
}

void Game::ComposeFrame()
{
	entity.DrawEntity(gfx);
	ground.DrawGround(gfx);
}
