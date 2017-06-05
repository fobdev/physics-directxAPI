#include "Rect.h"

Rect::Rect(float _left, float _right, float _top, float _bottom)
	:
	left(_left),
	right(_right),
	top(_top),
	bottom(_bottom)
{
}

Rect::Rect(const Vector & topLeft, const Vector & bottomRight)
	:
	Rect(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
{
}

Rect::Rect(const Vector & topLeft, float width, float height)
	:
	Rect(topLeft, topLeft + Vector(width, height))
{
}

Rect Rect::fromCenter(const Vector & center, float halfW, float halfH)
{
	const Vector half(halfW, halfH);
	return Rect(center - half, center + half);
}

bool Rect::isOverlappingWith(const Rect & other)
{
	// Rectangles overlap possibilities 
	return right > other.left && left < other.right && 
		bottom > other.top && top < other.bottom;
}

bool Rect::isContainedBy(const Rect & other)
{
	// Possibilities where a rectangle can be overwrited by other rectangle
	return left >= other.left && right <= other.right &&
		top >= other.top && bottom <= other.bottom;
}

Vector Rect::getCenter() const
{
	return Vector((left + right) / 2, (top + bottom) / 2);
}
