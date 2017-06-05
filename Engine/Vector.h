#pragma once
class Vector
{
public:
	Vector() = default;
	Vector(float _x, float _y);

	// --- Vectorial operations --- \\
	
	// Addition 
	Vector operator+(const Vector& rh) const;
	Vector& operator+=(const Vector& rh);

	// Multiplication (scalar on right hand side)
	Vector operator*(float rh) const;
	Vector& operator*=(float rh);

	// Subtraction
	Vector operator-(const Vector& rh) const;
	Vector& operator-=(const Vector& rh);

	// Division
	Vector operator/(const Vector& rh) const;
	Vector& operator/=(const Vector& rh);

	// --- Vectorial configurations --- \\

	// Vector sizing
	float getSizeSqrt() const;
	float getSize() const;

	//  Normalization
	Vector getNormalized() const;
	Vector& Normalize();

public:
	float x;
	float y;
};