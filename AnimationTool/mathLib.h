#pragma once
#include "Matrix3X3.h"


	namespace constants
	{
		constexpr float PI = 3.141592653589793238462643384727f;
		constexpr float TWO_PI = 6.283185307179586476925286769454f;

		constexpr float E = 2.718281828459045235360287471352662497757247093f;
	}



    template<typename T>
    constexpr T clamp(T x, T lowerLimit, T upperLimit) noexcept
    {
        return x < lowerLimit ? lowerLimit : x > upperLimit ? upperLimit : x;
    }

    template<typename T>
    constexpr T lerp(T start, T end, float alpha, bool bClamp = true) noexcept
    {
        if (bClamp)
        {
            if (alpha < 0.f)
            {
                return start;
            }
            if (alpha > 1.f)
            {
                return end;
            }
        }

        return start + alpha * (end - start);
    }


    inline Vector3D Get_Rotated_Vector_Around_Given_Axis(Vector3D src, Vector3D axis, float dRadian)
	{
        Vector3D&& diff = src - axis;
        Matrix3X3&& rotationMatrix = Matrix3X3::GetRotationMatrix(dRadian);
        Vector3D&& rotatedDiff = rotationMatrix * diff;
		return axis + rotatedDiff;
	}

    inline float GetRadBetweenTwoVectors(Vector3D v1, Vector3D v2)
	{
		_ASSERT(abs(v1.GetLengthSqr() - v2.GetLengthSqr()) < FLT_EPSILON);
		float v1Length = v1.GetLength();
		float v2Length = v2.GetLength();
		float cosTheta = v1.DotProduct(v2) / (v1Length * v2Length);

        return acos(cosTheta);
	}

    inline float GetRadOffset(Vector3D p1, Vector3D p2)//+ - > ccw
	{
		_ASSERT(abs(p1.GetLengthSqr() - p2.GetLengthSqr()) < FLT_EPSILON);
		float rad = GetRadBetweenTwoVectors(p1, p2);
		float rotatedDirection = (p1.CrossProduct(p2)[2] >= 0.f) ? 1.f : -1.f;
		return rad * rotatedDirection;
	}

    inline Vector3D slerp(Vector3D p1, Vector3D p2,float t)
	{
		_ASSERT(abs(p1.GetLengthSqr() - p2.GetLengthSqr()) < FLT_EPSILON);
		float radOffset = GetRadOffset(p1, p2);
        const Matrix3X3& rotationMatrix = Matrix3X3::GetRotationMatrix(radOffset * t);
        return Vector3D(rotationMatrix * p1);
	}
