#pragma once
#include "Vector.h"
#include "Graphics.h"

class Rect
{
public:
	Rect() = default;

	// Draw 
	Rect(float _left, float _right, float _top, float _bottom);
	Rect(const Vector& topLeft, const Vector& bottomRight);
	Rect(const Vector& topLeft, float width, float height);

	// Config
	static Rect fromCenter(const Vector& center, float halfW, float halfH);
	bool isOverlappingWith(const Rect& other);
	bool isContainedBy(const Rect& other);
	Vector getCenter() const;

public:
	float left;
	float right;
	float top;
	float bottom;
};