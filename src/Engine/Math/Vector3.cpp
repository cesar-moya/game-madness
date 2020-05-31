#include "Vector3.h"
#include <math.h>

//TODO: Study the Dot product
float Vector3::Dot(const Vector3& a, const Vector3& b) {
	//multiply the x's, then multiply the y's, then add them together
	return a.x * b.x + a.y * b.y;
}

//study how to calculate the projection of one [vector] onto another?
//EP 5, 1:08:02
Vector3 Vector3::Project(const Vector3& a, const Vector3& b){
	//projects a onto b
	return Vector3(
		(Vector3::Dot(a, b) / ((float)pow(b.x, 2) + (float)pow(b.y, 2))) * b.x, //x
		(Vector3::Dot(a, b) / ((float)pow(b.x, 2) + (float)pow(b.y, 2))) * b.y, //y
		0); //z
}


Vector3::Vector3(){
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(const Vector3& other) {
	x = other.x;
	y = other.y;
	z = other.z;
}

Vector3::Vector3(float _x) {
	x = _x;
	y = _x;
	z = _x;
}

Vector3::Vector3(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
}

Vector3& Vector3::operator=(const Vector3& other) {
	x = other.x;
	y = other.y;
	z = other.z;
	
	return *this;
}

Vector3 Vector3::operator+(const Vector3& other) {
	Vector3 ret;
	ret.x = x + other.x;
	ret.y = y + other.y;
	ret.z = z + other.z;
	return ret;
}

Vector3 Vector3::operator-(const Vector3& other) {
	Vector3 ret;
	ret.x = x - other.x;
	ret.y = y - other.y;
	ret.z = z - other.z;
	return ret;
}

Vector3 Vector3::operator*(const Vector3& other) {
	Vector3 ret;
	ret.x = x * other.x;
	ret.y = y * other.y;
	ret.z = z * other.z;
	return ret;
}

Vector3 Vector3::operator*(float _x) {
	Vector3 ret;
	ret.x = x * _x;
	ret.y = y * _x;
	ret.z = z * _x;
	return ret;
}

bool Vector3::operator==(const Vector3& other) {
	return (x == other.x && y == other.y && z == other.z);
}

bool Vector3::operator!=(const Vector3& other) {
	return ! operator==(other);
}