#include "StdAfx.h"
#include "Vector2D.h"

void Vector2D::Set(float x, float y)
{
	x = x;
	y = y;
}

void Vector2D::Normalize()
{
	x = x / Length(); y = y / Length();
}

float Vector2D::Length()
{
	return glm::vec2(x,y).length();
}

float Vector2D::Dot(Vector2D& other)
{
	return ((x * other.x) + (y * other.y));
}

bool Vector2D::IsZero()
{
	return (x == 0 && y == 0);
}

Vector2D& Vector2D::operator=(const Vector2D& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

Vector2D& Vector2D::operator+(const Vector2D& other) const
{
	Vector2D result = *this;
	result.x += other.x;
	result.y += other.y;
	return result;
}

Vector2D& Vector2D::operator+=(const Vector2D& other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

Vector2D& Vector2D::operator-(const Vector2D& other) const
{
	Vector2D result = *this;
	result.x -= other.x;
	result.y -= other.y;
	return result;
}

Vector2D& Vector2D::operator-=(const Vector2D& other)
{
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

Vector2D& Vector2D::operator*(const float value) const
{
	Vector2D result = *this;
	result.x *= value;
	result.y *= value;
	return result;
}

Vector2D& Vector2D::operator*=(const float value)
{
	this->x *= value;
	this->y *= value;

	return *this;
}