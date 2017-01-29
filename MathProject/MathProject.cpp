// MathProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector3.h"

int main()
{
	Vector3 a = Vector3(0.f, 0.f, 0.f);
	Vector3 b = Vector3(1.f, 2.f, 3.f);

	Vector3 c = a + b;
	c += b;
	c = -c;

	Vector3 d = Vector3(1.f, 0.f, 0.f);
	Vector3 e = Vector3(0.f, 1.f, 0.f);

	float angleBetweenDnE = Vector3::GetAngleBetweenVectors(d, e);

	int i = 0;

    return 0;
}

