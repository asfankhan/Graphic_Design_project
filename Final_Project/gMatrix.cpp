#include "gMatrix.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor/Destructor (2pt)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
gMatrix::gMatrix(int square)
{
	data.resize(square);
	for (int i = 0; i < square; i++)
	{
		data[i] = gVector(square);
	}
}/// Creates a square matrix of size 'square'						(1pt)
gMatrix::gMatrix(int r, int c)
{
	data.resize(r);
	for (int i = 0; i < r; i++)
	{
		data[i] = gVector(c);
	}
}/// Creates a matrix with rows 'r' and columns 'c'					(1pt)
gMatrix::~gMatrix()
{
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getters/Setters (9pt)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int gMatrix::rows() const
{
	return data.size();
}/// returns:  the number of rows								(1pt)
int gMatrix::cols() const
{
	return data.max_size();
}/// returns:  the number of cols								(1pt)
bool gMatrix::isSquare() const
{
	if(data.size()==data[0].size())
	{
		return true;
	}
	return false;
}/// returns:  returns true if the matrix is square				(1pt)
double gMatrix::get(int r, int c) const
{
	return data[r][c];
}/// returns:  the cth value in the rth row.						(1pt)
gVector gMatrix::getRow(int r) const
{
	return data[r];
}/// returns:  a vector containing the 'r'th row values			(1pt)
gVector gMatrix::getCol(int c) const
{
	gVector temp = gVector(data.size());

	for (int i = 0; i < data.size(); i++)
	{
		temp[i] = data[i][c];
	}
	return temp;
}/// returns:  a vector containing the 'c'th column values		(1pt)
void gMatrix::set(int r, int c, double value)
{
	data[r][c] = value;
}/// sets the cell at (r, c) to value							(1pt)
gVector& gMatrix::operator[] (int r)
{
	return data[r];
}/// returns a reference to the 'r'th row (or column)			(1pt)
gVector gMatrix::operator[] (int r) const
{
	gVector temp = gVector(data[r].size());
	for (int i = 0; i < r; i++)
	{
		temp = data[r][i];
	}
	return temp;
}/// returns a copy of the 'r'th row (or column)					(1pt)


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Matrix Cell Operations (20pt)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
gMatrix gMatrix::transpose() const
{
	gMatrix temp = gMatrix(data[0].size(),data.size());
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			temp[j][i] = data[i][j];
		}
	}
	return temp;
}/// Returns the transpose of the current matrix		(4pt)
gMatrix gMatrix::inverse() const
{
	return NULL;
}/// Returns the inverse of the current matrix (if	(6pt)
//	its square and has 3 or less rows)
gMatrix gMatrix::subMatrix(int r1, int c1, int r2, int c2)
{
	return NULL;

}/// Returns a subMatrix with spans from cell		(4pt)
													//	(r1,c1) to cell (r2,c2) inclusive
double gMatrix::determinant() const
{
	return NULL;

}/// Returns the determinanet of the current matrix	(6pt)
													//	(if its square and his 3 or less rows)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Boolean Friend Functions (2pt)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool operator== (const gMatrix& m1, const gMatrix& m2)
{
	return NULL;

}/// m1[i][j] == m2[i][j]			(1pt)
bool operator!= (const gMatrix& m1, const gMatrix& m2)
{
	return NULL;

}/// m1[i][j] == m2[i][j]			(1pt)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Matrix Math Operations (13pt)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
gMatrix operator+ (const gMatrix& m1, const gMatrix& m2)
{
	return NULL;

}/// matrix addition: m1 + m2		(2pt)
gMatrix operator- (const gMatrix& m1, const gMatrix& m2)
{
	return NULL;

}/// matrix subtraction: m1 - m2		(2pt)
gMatrix operator* (const gMatrix& m1, const gMatrix& m2)
{
	gMatrix temp = gMatrix(4, 4);


	temp[0][0] = m1.getRow(0) * m2.getCol(0);
	temp[0][1] = m1.getRow(0) * m2.getCol(1);
	temp[0][2] = m1.getRow(0) * m2.getCol(2);

	temp[1][0] = m1.getRow(1) * m2.getCol(0);
	temp[1][1] = m1.getRow(1) * m2.getCol(1);
	temp[1][2] = m1.getRow(1) * m2.getCol(2);

	temp[2][0] = m1.getRow(2) * m2.getCol(0);
	temp[2][1] = m1.getRow(2) * m2.getCol(1);
	temp[2][2] = m1.getRow(2) * m2.getCol(2);

	temp[3][3] =1;

	return temp;

}/// dot product: m1 * m2			(2pt)
gVector operator* (const gVector& v, const gMatrix& m)
{
	gVector temp = gVector(0, 0, 0, 0);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < m[0].size(); j++)
		{
			temp[i] += v[j] * m[i][j];
		}
	}

	return temp;

}/// dot product: v * m				(2pt)
gVector operator* (const gMatrix& m, const gVector& v)
{
	gVector temp=gVector(0, 0, 0, 0);

	temp[0] = v * m.getCol(0);
	temp[1] = v * m.getCol(1);
	temp[2] = v * m.getCol(2);

	return temp;
}/// dot product: m * v				(2pt)
gMatrix operator* (const gMatrix& m, const double d)
{
	return NULL;

}/// scalar product: m * d			(1pt)
gMatrix operator* (const double d, const gMatrix& m)
{
	return NULL;

}/// scalar product: d * m			(1pt)
gMatrix operator/ (const gMatrix& m, const double d)
{
	return NULL;

}/// scalar division: m * d			(1pt)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Static Matrix Generating Functions (13pt)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
gMatrix gMatrix::rotationMatrix(double rotate2D)
{
	return NULL;

}/// Returns a 2-D HOMOGENEOUS		(4pt)
																	//  rotation matrix	
gMatrix gMatrix::rotationMatrix(const gVector& v, double rotate3D)
{
	return NULL;

}/// Returns a 3-D HOMOGENEOUS		(4pt)
																	//  rotation matrix	around an axis v
gMatrix gMatrix::scaleMatrix(const gVector& v)
{
	return NULL;

}/// Returns a nxn scale matrix		(4pt)
																	//  determined by v.  v is a vector 
																	//  of scale coefficients
gMatrix gMatrix::translationMatrix(const gVector& v)
{
	return NULL;

}/// Returns a nxn translation matrix(4pt)
																	//  determined by v					
gMatrix gMatrix::identityMatrix(int size)
{
	gMatrix temp = gMatrix(size,size);

	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			temp[0][0]=1;
		}
		if (i == 1)
		{
			temp[1][1] = 1;
		}
		if (i == 2)
		{
			temp[2][2] = 1;
		}
		if (i == 3)
		{
			temp[3][3] = 1;
		}
	}

	return temp;

}/// Returns a size x size identity	(2pt)
																	//  matrix
double radToDeg(double rad)
{
	return 0;
}
double degToRad(double deg)
{
	return 0;
}
