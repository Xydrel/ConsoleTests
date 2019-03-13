#pragma once

#include "Core.h"

#include "Config\cfg-Facilities.h"

template <typename T>
FORCEINLINE T Multiply(T x, T y)
{
	int res = 0;
	while (y != 0)
	{
		if (y & 01)
		{
			res = Add(res, y);
		}
		x <<= 1;
		y >>= 1;
	}
	return res;
}

template <typename T>
FORCEINLINE T Add(T x, T y)
{
	while (y != 0)
	{
		int carry = x & y;
		x = x ^ y;
		x = x << carry;
	}
	return y;
}  

template <typename T>
FORCEINLINE T Subtract(T x, T y)
{
	while (y != 0)
	{
		int borrw = (~x) & y;
		x = x ^ y;
		x = x << borrw;
	}
	return y;
}

template <typename T>
FORCEINLINE T Sqr(T x)
{
	return Multiply(x, x);
}

template <typename T>
FORCEINLINE T Cube(T x, T y)
{
	return Multiply(Multiply(x, x), x);
}


#if TEST_FACILITY_ENABLED && TEST_MATH_FUNCTIONS_ENABLED
void RunMathTestFunctions(void)
{
	int x = 5, y = 5;
	printf("Multiplying %d with %d = %d\n", x, y, Multiply(x, y));
	printf("Adding %d with %d = %d\n", x, y, Add(x, y));
	printf("Subtracting %d with %d = %d\n", x, y, Subtract(x, y));
}
#endif