#pragma once
#include "Vector3D.h"




	class [[nodiscard]] Matrix3X3
	{
		friend class Vector3D;
	public:
		constexpr Matrix3X3(const Vector3D& col1, const Vector3D& col2, const Vector3D& col3) noexcept;

		Matrix3X3 operator+(const Matrix3X3& other) const;
		Matrix3X3 operator-(const Matrix3X3& other) const;
		Matrix3X3 operator*(const Matrix3X3& other) const;
		Matrix3X3& operator+=(const Matrix3X3& other);
		Matrix3X3& operator-=(const Matrix3X3& other);
		Matrix3X3& operator*=(const Matrix3X3& other);
		Matrix3X3 operator*(float scalar) const;
		Matrix3X3& operator*=(float scalar);
		Vector3D operator*(const Vector3D& vector) const; /*	a1 b1 c1  v1
																a2 b2 c2  v2 -shaped multiplication.
																a3 b3 c3  v3
															*/
		float GetElementAt(int row, int column) const;
		void SetElementAt(int row, int column, float value);
		Vector3D GetColumn(int i) const;
		Vector3D GetRow(int i) const;
		/* TODO :
		float Determinant()const;
		Matrix3X3 GetInverseMatrix()const;
		*/



	private:
		Vector3D mColumns[3];
	
	public:
		static Matrix3X3 GetRotationMatrix(float dRadian);
	};


	std::ostream& operator<<(std::ostream& os, const Matrix3X3& m);
