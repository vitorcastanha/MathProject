#include "stdafx.h"
#include "Vector3.h"
#include <cmath>
#include "SupportingMath.h"

Vector3::Vector3()
{
	this->x = 0.f;
	this->y = 0.f;
	this->z = 0.f;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{
}

Vector3 & Vector3::operator*(float scalar)
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 & Vector3::operator*=(float scalar)
{
	*this = *this * scalar;
	return *this;
}

Vector3 & Vector3::operator/(float scalar)
{
	return Vector3(x/scalar, y/scalar, z/scalar);
}

Vector3 & Vector3::operator/=(float scalar)
{
	*this = *this / scalar;
	return *this;
}

Vector3 & Vector3::operator+(const Vector3 a)
{
	return Vector3(x + a.x, y + a.y, z + a.z);
}

Vector3 & Vector3::operator+=(const Vector3 a)
{
	*this = *this + a;
	return *this;
}

Vector3 & Vector3::operator-(const Vector3 a)
{
	return Vector3(x - a.x, y - a.y, z - a.z);
}

Vector3 & Vector3::operator-=(const Vector3 a)
{
	*this = *this - a;
	return *this;
}

Vector3 & Vector3::operator-()
{
	return Vector3(-x, -y, -z);
}

float Vector3::GetMagnitude()
{
	return sqrt(GetSquaredMagnitude());
}

float Vector3::GetSquaredMagnitude()
{
	return pow(x, 2.f) + pow(y, 2.f) + pow(z, 2.f);
}

Vector3 Vector3::GetProjectionOfVectorOntoSelf(Vector3 v)
{
	//(P.Q/||Q||2) * Q
	return *this * GetDotProduct(*this, v)/sqrt(this->GetMagnitude());
}

Vector3 Vector3::GetPerpendiculatOfVectorOntoSelf(Vector3 v)
{
	return v - this->GetProjectionOfVectorOntoSelf(v);
}

Vector3 Vector3::Normalized()
{
	return Vector3::NormalizeVector(*this);
}

float Vector3::GetAngleBetweenVectors(Vector3 a, Vector3 b)
{
	//cos@ = P.Q / ||P|| * ||Q||
	float planarAngle = GetDotProduct(a, b) / (a.GetMagnitude() * b.GetMagnitude());
	return SupportingMath::RadiansToDegrees(acos(planarAngle));
}

Vector3 Vector3::GetCrossProduct(Vector3 a, Vector3 b)
{
	return Vector3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x-b.y - a.y*b.x);
}

Vector3 Vector3::GetVectorProduct(Vector3 a, Vector3 b)
{
	return Vector3::GetCrossProduct(a, b);
}

Vector3 Vector3::NormalizeVector(Vector3 v)
{
	return v * (1/v.GetMagnitude());
}

float Vector3::GetDotProduct(Vector3 a, Vector3 b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}