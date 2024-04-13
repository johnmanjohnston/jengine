#pragma once
class Vector2 {
public:
	float x, y;
	Vector2(float _x = 0.f, float _y = 0.f) { x = _x; y = _y; };

	Vector2 operator+ (const Vector2& other) 
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator- (const Vector2& other)
	{
		return Vector2(x - other.x, y - other.y);
	}
};