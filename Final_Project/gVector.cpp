#include "gVector.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor/Destructor (4pt)
/////////////////////////////////////////////////////////////////////////////////////////////////////////

gVector::gVector(int size)
{
	data.resize(size);
}/// Creates gVectors of a specified size(1pt)
gVector::gVector(double d1, double d2)
{
	data = { d1,d2 };
}/// Creates gVectors of size 2			(1pt)
gVector::gVector(double d1, double d2, double d3)
{
	data = { d1,d2,d3 };
}	/// Creates gVectors of size 3			(1pt)
gVector::gVector(double d1, double d2, double d3, double d4)
{
	data = { d1,d2,d3,d4 };

}	/// Creates gVectors of size 4			(1pt)

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getters/Setters (7pt)
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int gVector::size() const {
	return data.size();
}/// Returns the number of elements in the vector	(1pt)

double gVector::length() const {
	return data.max_size();
}/// Calculates the length of the vector				(2pt)
double gVector::get(int index) const {
	return data[index];
}/// Returns the value at the index of the vector	(1pt)
void gVector::set(int index, double value) {
	data[index]=value;
}/// Sets the specified index in the vector to value	(1pt)
double& gVector::operator[] (int index) {
	return data[index];
}/// Returns a reference to the specified index.		(1pt)
double gVector::operator[] (int index) const {
	return data[index];
}/// Returns the value at the specified index.		(1pt)

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Boolean friends functions (5pt)
//  Use the equality testing algorithms discussed in the reading/lecture						(3pt)
/////////////////////////////////////////////////////////////////////////////////////////////////////////
 bool operator== (const gVector& v1, const gVector& v2) {
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] != v2[i])
		{
			return false;
		}
	}
	return true;
}/// Tests v1[i] == v2[i]	(1pt)
bool operator!= (const gVector& v1, const gVector& v2) {
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] == v2[i])
		{
			return false;
		}
	}
	return true;
}	/// Tests v1[i] != v2[i]	(1pt)

/// /////////////////////////////////////////////////////////////////////////////////////////////////////
// Vector math functions (13pt)
/////////////////////////////////////////////////////////////////////////////////////////////////////////
gVector operator+ (const gVector& v1, const gVector& v2) {
	gVector temp = gVector(v1.size());

	for (int i = 0; i < v1.size(); i++) {
		temp[i] = v1[i] + v2[i];
	}
	return temp;
}	/// Vector Addition			(2pt)
gVector operator- (const gVector& v1, const gVector& v2) {
	gVector temp = gVector(v1.size());

	for (int i = 0; i < v1.size(); i++) {
		temp[i] = v1[i] - v2[i];
	}
	return temp;
}	/// Vector Subtraction		(2pt)
double  operator* (const gVector& v1, const gVector& v2) {
	double temp = 0;

	for (int i = 0; i < v1.size(); i++) {
		temp += v1[i] * v2[i];
	}

	return temp;
}	/// Dot Product				(2pt)
gVector operator* (const gVector& v, const double d) {
	gVector temp = gVector(v.length());

	for (int i = 0; i < v.size(); i++) {
		temp[i] = v[i] * d;
	}
	return temp;
}/// Scalar Multiplication	(1pt)
gVector operator* (const double d, const gVector& v)
{
	gVector temp = gVector(v.length());

	for (int i = 0; i < v.size(); i++) {
		temp[i] = v[i] * d;
	}
	return temp;
}/// Scalar Multiplication	(1pt)
gVector operator/ (const gVector& v, const double d) {
	gVector temp = gVector(v.size());

	for (int i = 0; i < v.size(); i++) {
		temp[i] = v[i] / d;
	}
	return temp;
}/// Scalar Division			(1pt)
gVector operator^ (const gVector& v1, const gVector& v2) {
	gVector temp = gVector(v1.size());
	vec3 temp1;
	if (v1.size() == 2)
	{
		 temp1 = vec3(0.0, 0.0, v1[1] * v2[2] - v2[1] * v1[2]);
	}
	if (v1.size() == 3)
	{
		temp1 = vec3(v1[2] * v2[3] - v1[3] * v2[2],
			 v1[3] * v2[1] - v1[1] * v2[3],
			 v1[1] * v2[2] - v1[2] * v2[1]);
	}
	temp.set(0, temp1[0]);
	temp.set(1 ,temp1[1]);
	temp.set(2, temp1[2]);
	return temp;
}	/// Cross Product			(4pt)
