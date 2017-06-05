#include "Ground.h"
Ground::Ground(Vector& position, float halfW, float halfH)
	:
	pos(position),
	halfWidth(halfW),
	halfHeight(halfH)
{
}
void Ground::DrawGround(Graphics & gfx)
{
	Rect rect = getRect();
	gfx.DrawRect(rect, groundColor);
}

void Ground::ChangeHeight(const Keyboard & kbd)
{
	if (kbd.KeyIsPressed('W'))
	{
		pos.y -= 5;
	}
	if (kbd.KeyIsPressed('S'))
	{
		pos.y += 5;
	}

	Rect rect = getRect();
	if (rect.top < 0)
	{
		pos.y -= rect.top;
	}
	else if (rect.bottom >= Graphics::ScreenHeight)
	{
		pos.y += Graphics::ScreenHeight - rect.bottom;
	}
}

Rect Ground::getRect()
{
	return Rect::fromCenter(pos, halfWidth, halfHeight);
}
