#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "TestEntiny.h"
#include "Ground.h"
#include "FrameTimer.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();

private:
	void ComposeFrame();
	void UpdateModel();

private:
	FrameTimer ft;
	MainWindow& wnd;
	Graphics gfx;
	Entity entity;
	Ground ground;

private:
	static constexpr float sqrSz = 15.0f;


};