#pragma once

struct Vector2D
{
public:
	Vector2D(void) { x = 0; y = 0; };
	Vector2D(float x, float y) { this->x = x; this->y = y; }
	Vector2D(glm::vec3 vect) { this->x = vect.x; this->y = vect.z; }

	void Set(float x, float y);

	float GetX() const { return x; }
	float GetY() const { return y; }

	void Normalize();

	float Length();

	float Dot(Vector2D& other);

	bool IsZero();

	glm::vec3 ToGLM() { return glm::vec3(x, 0, y); } 

	Vector2D& operator=(const Vector2D& other);

	Vector2D& operator+(const Vector2D& other) const;
	Vector2D& operator+=(const Vector2D& other);

	Vector2D& operator -(const Vector2D& other) const;
	Vector2D& operator -=(const Vector2D& other);
	
	Vector2D& operator *(const float value) const;
	Vector2D& operator *=(const float value);

	float x;
	float y;
};

