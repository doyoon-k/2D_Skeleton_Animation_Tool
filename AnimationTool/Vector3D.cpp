#include <cassert>
#include "Matrix3X3.h"
#include "Vector3D.h"
#include <cfloat>
#include <cmath>
#include <QTextStream>


//just a cheat to make it look clean
#define x xyz[0]
#define y xyz[1]
#define z xyz[2]



	using namespace std;



    bool Vector3D::operator==(const Vector3D& other) const
	{
        return  (fabs(x - other.x) <= FLT_EPSILON) &&
            (fabs(y - other.y) <= FLT_EPSILON) &&
            (fabs(z - other.z) <= FLT_EPSILON);
	}

	float& Vector3D::operator[](int index)
	{
		assert(index > -1 && index < 3);
		return xyz[index];
	}

	float Vector3D::operator[](int index) const
	{
		assert(index > -1 && index < 3);
		return xyz[index];
	}

	Vector3D Vector3D::GetNormal() const
	{
		float length = GetLength();
		return Vector3D(x / length, y / length, z / length);
	}

	float Vector3D::GetLength() const
	{
        return sqrt(x * x + y * y + z * z);
	}

	void Vector3D::Normalize()
	{
		float length = GetLength();
		x /= length;
		y /= length;
		z /= length;
	}


    QTextStream &operator>>(QTextStream &stream, Vector3D &vector)
    {
        char rest;
        stream>>vector.xyz[0];
        stream>>rest;
        stream>>vector.xyz[1];
        stream>>rest;
        stream>>vector.xyz[2];
        return stream;
    }

    QTextStream &operator<<(QTextStream &stream, Vector3D &vector)
    {
        stream<<vector.xyz[0]<<',';
        stream<<vector.xyz[1]<<',';
        stream<<vector.xyz[2];
        return stream;
    }
