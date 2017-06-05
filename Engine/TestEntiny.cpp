#include "TestEntiny.h"
Entity::Entity(Vector & _pos, float _halfW, float _halfH)
	:
	pos(_pos),
	halfW(_halfW),
	halfH(_halfH)
{
}

void Entity::DrawEntity(Graphics & gfx)
{
	Rect rect = GetRect();
	gfx.DrawRect(rect, entityColor);
	recta(gfx);
}

void Entity::Update(Keyboard & kbd, float dt)
{
	Gravity(dt);
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		actSpeed += 0.2f;
		pos.x += Speedometer(dt);
		if (actSpeed > 10.0f)
		{
			actSpeed = 10.0f;
		}
	}

	if (kbd.KeyIsPressed(VK_LEFT))
	{
		actSpeed += 0.2f;
		pos.x -= Speedometer(dt);
		if (actSpeed > 10.0f)
		{
			actSpeed = 10.0f;
		}
	}

	if (!kbd.KeyIsPressed(VK_RIGHT) && !kbd.KeyIsPressed(VK_LEFT))
	{
		actSpeed = 1.0f;
	}

	if (!alreadyPressed && kbd.KeyIsPressed(VK_SPACE) || onGround && kbd.KeyIsPressed(VK_SPACE))
	{
		pos.y -= speed * dt * gravityAmount;
		alreadyPressed = true;
		Gforce = true;
	}
	else
	{
		Gforce = false;
	}

	if (!onGround)
	{
		// Gravity increaser during time - when hits the ground resets increaser.

		float fixedGrav = 10.0f;
		float pEnergy = 15.0f;
		for (float i = 0.0f; i < fixedGrav; i += 0.4f)
		{
			pEnergy += (i * 0.05f) * dt;
		}
		Falling(pEnergy, dt);
		fixedGrav = 10.0f;
	}
	ClampToScreen();
}


float Entity::Falling(float pEnergy, float dt)
{
	return  pos.y -= dt * pEnergy;
}

float Entity::Speedometer(float dt)
{
	return actSpeed += dt;
}

void Entity::Gravity(float dt)
{
	if (!Gforce)
	{
		pos.y += (dt * speed) / 2.0f;
	}
	else if (gravityAmount > gravityLimit)
	{
		pos.y -= dt * speed / 2.0f;
	}
}

void Entity::ClampToScreen()
{
	Rect rect = GetRect();
	if (rect.left < 0)
	{
		pos.x -= rect.left;
	}
	else if (rect.right >= Graphics::ScreenWidth)
	{
		pos.x += Graphics::ScreenWidth - rect.right;
	}

	if (rect.top < 0)
	{
		pos.y -= rect.top;
	}
	else if (rect.bottom >= Graphics::ScreenHeight)
	{
		pos.y += Graphics::ScreenHeight - rect.bottom;
	}
}

void Entity::recta(Graphics& gfx)
{
	Color rectColor = Colors::Red;
	float _rS = halfW / 4.0f;
	float _rT = 0.5f;
	Rect b = b.fromCenter(pos, _rS, _rT);
	Rect a = a.fromCenter(pos, _rT, _rS);
	gfx.DrawRect(a, rectColor);
	gfx.DrawRect(b, rectColor);
}

void Entity::GroundCollision(Ground & ground)
{
	Rect rect = GetRect();
	if (rect.bottom >= ground.pos.y)
	{
		pos.y = ground.pos.y - halfH;
		onGround = true;
		Gforce = false;
		isFalling = false;
	}
	else
	{
		isFalling = true;
		onGround = false;
	}
}

Rect Entity::GetRect()
{
	return Rect::fromCenter(pos, halfW, halfH);
}