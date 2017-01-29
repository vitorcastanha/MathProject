#pragma once

class Vector3 
{
public:
	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	//TODO - REFACTOR to allow symetric calculations

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
	Vector3 Normalized();

	static float GetDotProduct(Vector3 a, Vector3 b);
	static float GetAngleBetweenVectors(Vector3 a, Vector3 b);
	/*
	Cross Product enforces the Right Hand Rule. Meaning that if 'a' is the pointer finger and 'b' is the middle finger,
	then the thumb position would point the direction of the cross product. Therefore, inverting the order of the vectors,
	negates the resulting vector.
	*/
	static Vector3 GetCrossProduct(Vector3 a, Vector3 b);
	static Vector3 GetVectorProduct(Vector3 a, Vector3 b);
	static Vector3 NormalizeVector(Vector3 v);

	//TODO - Create a function to orthogonize a set of Vectors

public:
	float x = 0.f;
	float y = 0.f;
	float z = 0.f;

};