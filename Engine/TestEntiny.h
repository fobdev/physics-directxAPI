#pragma once
#include "Keyboard.h"
#include "Rect.h"
#include "Ground.h"
class Entity
{
public:
	Entity() = default;
	Entity(Vector& _pos, float _halfW, float _halfH);
	void DrawEntity(Graphics& gfx);
	void Update(Keyboard& kbd, float dt);
	Rect GetRect();
	void GroundCollision(Ground& ground);

private:
	void Gravity(float dt);
	float Falling(float dt);
	void ClampToScreen();
	float Speedometer(float dt);

public:
	// Center recticle
	void recta(Graphics& gfx);

private:
	Vector pos;
	float pEnergy = 1.0f;		 // Potential Energy that increases during fall
	float gravityAmount = 30.0f; // Gravity variable'
	float gravityLimit = 50.0f;	 // Gravity	variable
	float halfW;				 // Test Entity half width
	float halfH;				 // Test Entity half height
	float actSpeed = 2.3f;		 // Movement increaser
	bool alreadyPressed = false; // Jump cooldown based on keyboard hit
	bool onGround = false;		 // Jump cooldown based on ground collision
	bool Gforce = false;
	bool isFalling = false;		 
	float speed = 5.0f * 60.0f;
	static constexpr Color entityColor = Colors::White;

public:
	Vector* pPos = &pos;
	float* pYchg = &pPos->y;

};