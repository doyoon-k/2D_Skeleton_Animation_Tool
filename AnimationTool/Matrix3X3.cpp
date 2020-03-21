#include <cassert>
#include "Matrix3X3.h"



	using namespace std;

	constexpr Matrix3X3::Matrix3X3(const Vector3D& col1, const Vector3D& col2, const Vector3D& col3) noexcept
		:mColumns{ col1,col2,col3 }
	{}


	Matrix3X3 Matrix3X3::operator+(const Matrix3X3& other) const
	{
		return Matrix3X3(mColumns[0] + other.mColumns[0], mColumns[1] + other.mColumns[1], mColumns[2] + other.mColumns[2]);
	}

	Matrix3X3 Matrix3X3::operator-(const Matrix3X3& other) const
	{
		return Matrix3X3(mColumns[0] - other.mColumns[0], mColumns[1] - other.mColumns[1], mColumns[2] - other.mColumns[2]);
	}

	Matrix3X3 Matrix3X3::operator*(const Matrix3X3& other) const
	{
		return Matrix3X3((*this) * other.mColumns[0], (*this) * other.mColumns[1], (*this) * other.mColumns[2]);
	}

	Matrix3X3& Matrix3X3::operator+=(const Matrix3X3& other)
	{
		mColumns[0] += other.mColumns[0];
		mColumns[1] += other.mColumns[1];
		mColumns[2] += other.mColumns[2];
		return *this;
	}

	Matrix3X3& Matrix3X3::operator-=(const Matrix3X3& other)
	{
		mColumns[0] -= other.mColumns[0];
		mColumns[1] -= other.mColumns[1];
		mColumns[2] -= other.mColumns[2];
		return *this;
	}

	Matrix3X3& Matrix3X3::operator*=(const Matrix3X3& other)
	{
		Vector3D&& newCol1 = (*this) * other.mColumns[0];
		Vector3D&& newCol2 = (*this) * other.mColumns[1];
		Vector3D&& newCol3 = (*this) * other.mColumns[2];
		mColumns[0] = newCol1;
		mColumns[1] = newCol2;
		mColumns[2] = newCol3;
		return *this;
	}

	Matrix3X3 Matrix3X3::operator*(float scalar) const
	{
		return Matrix3X3(mColumns[0] * scalar, mColumns[1] * scalar, mColumns[2] * scalar);
	}

	Matrix3X3& Matrix3X3::operator*=(float scalar)
	{
		mColumns[0] *= scalar;
		mColumns[1] *= scalar;
		mColumns[2] *= scalar;
		return *this;
	}

	Vector3D Matrix3X3::operator*(const Vector3D& vector) const
	{
		return Vector3D(GetRow(0).DotProduct(vector), GetRow(1).DotProduct(vector), GetRow(2).DotProduct(vector));
	}

	float Matrix3X3::GetElementAt(int row, int column) const
	{
		return mColumns[column].xyz[row];
	}

	void Matrix3X3::SetElementAt(int row, int column, float value)
	{
		mColumns[column].xyz[row] = value;
	}

	Vector3D Matrix3X3::GetColumn(int i) const
	{
		assert(i > -1 && i < 3);
		return Vector3D(mColumns[i]);
	}

	Vector3D Matrix3X3::GetRow(int i) const
	{
		assert(i > -1 && i < 3);
		return Vector3D(mColumns[0][i], mColumns[1][i], mColumns[2][i]);
	}

	Matrix3X3 Matrix3X3::GetRotationMatrix(float dRadian)
	{
        return Matrix3X3(Vector3D(std::cos(dRadian),-std::sin(dRadian),0.f),
                         Vector3D(std::sin(dRadian),std::cos(dRadian),0.f),
                         Vector3D(0.f,0.f,1.f));
	}

	ostream& operator<<(ostream& os, const Matrix3X3& m)
	{
		cout << m.GetRow(0) << endl;
		cout << m.GetRow(1) << endl;
		cout << m.GetRow(2);
		return os;
	}

