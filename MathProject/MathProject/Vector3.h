#pragma once

class Vector3 
{
public:
	Vector3(float x, float y, float z);
	~Vector3();

	Vector3& operator*(float scalar);
	Vector3& operator*=(float scalar);
	Vector3& operator/(float scalar);
	Vector3& operator/=(float scalar);
	Vector3& operator+(const Vector3 a);
	Vector3& operator+=(const Vector3 a);
	Vector3& operator-(const Vector3 a);
	Vector3& operator-=(const Vector3 a);
	//Negation of vector
	Vector3& operator-();
	float GetMagnitude();
	float GetSquaredMagnitude();
	Vector3 GetProjectionOfVectorOntoSelf(Vector3 v);
	Vector3 GetPerpendiculatOfVectorOntoSelf(Vector3 v);

	static float GetDotProduct(Vector3 a, Vector3 b);
	static float GetAngleBetweenVectors(Vector3 a, Vector3 b);

public:
	float x = 0.f;
	float y = 0.f;
	float z = 0.f;

};