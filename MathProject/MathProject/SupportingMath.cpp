#include "stdafx.h"
#include "SupportingMath.h"
#include <cmath>

float SupportingMath::RadiansToDegrees(float rad)
{
	return rad * (180.f / PI);
}

float SupportingMath::DegreesToRadians(float degrees)
{
	return degrees * (PI / 180.f);
}
