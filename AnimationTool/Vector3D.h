#pragma once
#include <cfloat>
#include <iostream>
#include "cmath"



	class Vector3D
	{
		friend class Matrix3X3;
	public:
		template<typename Number>
		constexpr Vector3D(Number X, Number Y, Number Z = 0.f) noexcept;
		constexpr Vector3D operator+(const Vector3D& other) const noexcept;
		constexpr Vector3D operator-(const Vector3D& other) const noexcept;
		constexpr Vector3D operator/(float scalar) const noexcept;
		constexpr Vector3D operator*(float scalar) const noexcept;
		constexpr Vector3D& operator+=(const Vector3D& other) noexcept;
		constexpr Vector3D& operator-=(const Vector3D& other) noexcept;
		constexpr Vector3D& operator/=(float scalar) noexcept;
		constexpr Vector3D& operator*=(float scalar) noexcept;
		bool operator==(const Vector3D& other) const;
		float& operator[](int index);
		float operator[](int index) const;

		[[nodiscard]] constexpr Vector3D CrossProduct(const Vector3D& other) const noexcept;

		[[nodiscard]] Vector3D GetNormal() const;

		[[nodiscard]] constexpr float DotProduct(const Vector3D& other) const noexcept;

		[[nodiscard]] float GetLength() const;

		[[nodiscard]] constexpr float GetLengthSqr() const noexcept;
		void Normalize();



	private:
		float xyz[3] = { 0.f,0.f,0.f };  //reason it's an array is because for the usage in Matrix3X3. ex) getElementAt(xyz[0],xyz[1])
	};


	std::ostream& operator<<(std::ostream& os, const Vector3D& v);


	template<typename Number>
	constexpr Vector3D::Vector3D(Number X, Number Y, Number Z) noexcept
	{
		xyz[0] = static_cast<float>(X);
		xyz[1] = static_cast<float>(Y);
		xyz[2] = static_cast<float>(Z);
	}

	constexpr Vector3D Vector3D::operator+(const Vector3D& other) const noexcept
	{
		return Vector3D(xyz[0] + other.xyz[0], xyz[1] + other.xyz[1], xyz[2] + other.xyz[2]);
	}

	constexpr Vector3D Vector3D::operator-(const Vector3D& other) const noexcept
	{
		return Vector3D(xyz[0] - other.xyz[0], xyz[1] - other.xyz[1], xyz[2] - other.xyz[2]);
	}

	constexpr Vector3D Vector3D::operator/(float scalar) const noexcept
	{
		return Vector3D(xyz[0] / scalar, xyz[1] / scalar, xyz[2] / scalar);
	}

	constexpr Vector3D Vector3D::operator*(float scalar) const noexcept
	{
		return Vector3D(xyz[0] * scalar, xyz[1] * scalar, xyz[2] * scalar);
	}


	constexpr Vector3D& Vector3D::operator+=(const Vector3D& other) noexcept
	{
		xyz[0] += other.xyz[0];
		xyz[1] += other.xyz[1];
		xyz[2] += other.xyz[2];
		return *this;
	}

	constexpr Vector3D& Vector3D::operator-=(const Vector3D& other) noexcept
	{
		xyz[0] -= other.xyz[0];
		xyz[1] -= other.xyz[1];
		xyz[2] -= other.xyz[2];
		return *this;
	}

	constexpr Vector3D& Vector3D::operator/=(float scalar) noexcept
	{
		xyz[0] /= scalar;
		xyz[1] /= scalar;
		xyz[2] /= scalar;
		return *this;
	}

	constexpr Vector3D& Vector3D::operator*=(float scalar) noexcept
	{
		xyz[0] *= scalar;
		xyz[1] *= scalar;
		xyz[2] *= scalar;
		return *this;
	}

	constexpr float Vector3D::DotProduct(const Vector3D& other) const noexcept
	{
		return xyz[0] * other.xyz[0] + xyz[1] * other.xyz[1] + xyz[2] * other.xyz[2];
	}

	constexpr Vector3D Vector3D::CrossProduct(const Vector3D& other) const noexcept
	{
		return Vector3D(xyz[1] * other.xyz[2] - xyz[2] * other.xyz[1],
						xyz[2] * other.xyz[0] - xyz[0] * other.xyz[2],
						xyz[0] * other.xyz[1] - xyz[1] * other.xyz[0]);
	}

	constexpr float Vector3D::GetLengthSqr() const noexcept
	{
		return xyz[0] * xyz[0] + xyz[1] * xyz[1] + xyz[2] * xyz[2];
	}

