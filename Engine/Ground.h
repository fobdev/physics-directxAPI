#pragma once
#include "Vector.h"
#include "Graphics.h"
#include "Rect.h"
#include "Keyboard.h"

class Ground
{
public:
	Ground() = default;
	Ground(Vector& position, float halfW, float halfH);
	void DrawGround(Graphics& gfx);
	void ChangeHeight(const Keyboard& kbd);
	Rect getRect();

public:
	Vector pos;
	
	Vector* pPos = &pos;
	float* chgPosY = &pPos->y;
	
	static constexpr Color groundColor = Colors::Red;
	float halfWidth;
	float halfHeight;
};