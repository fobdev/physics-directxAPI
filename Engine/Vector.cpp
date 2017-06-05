#include "Vector.h"
#include <cmath>
Vector::Vector(float _x, float _y)
	:
	x(_x),
	y(_y)
{
}

Vector Vector::operator+(const Vector & rh)  const
{
	return Vector(x + rh.x, y + rh.y);
}

Vector & Vector::operator+=(const Vector & rh)
{
	return *this = *this + rh;
}

Vector Vector::operator*(float rh) const
{
	return Vector(x * rh, y * rh);
}

Vector & Vector::operator*=(float rh)
{
	return *this = *this * rh;
}

Vector Vector::operator-(const Vector & rh) const
{
	return Vector(x - rh.x, y - rh.y);
}

Vector & Vector::operator-=(const Vector & rh)
{
	return *this = *this - rh;
}

Vector Vector::operator/(const Vector & rh) const
{
	return Vector(x / rh.x, y / rh.y);
}

Vector & Vector::operator/=(const Vector & rh)
{
	return *this = *this / rh;
}

Vector & Vector::Normalize()
{
	return *this = getNormalized();
}

Vector Vector::getNormalized() const
{
	const float lenght = getSize();
	if (lenght != 0.0f)
	{
		return *this * (1.0f / lenght);
	}
	return *this;
}

float Vector::getSizeSqrt() const
{
	return std::sqrt(getSize());
}

float Vector::getSize() const
{
	return x * x + y * y;
}

