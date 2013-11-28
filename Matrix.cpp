//Program 2 - "Matrix Class" - Class functions
//Implement the Matrix class
//Due: January 28, 2007
//Created: January 26, 2007
//Last Modified: January 28, 2007

#include "Matrix.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int Matrix::matrixCount = 0;

Matrix::Matrix(int r, int c)
{
    if (r > 0)
    {
        rows = r;
    }
    else
    {
        rows = 0;
    }
    if (c > 0)
    {
        cols = c;
    }
    else
    {
        cols = 0;
    }

    element = new int* [rows];

    for (int i=0; i<rows; i++)
    {
        element[i] = new int[cols];
        for (int n = 0; n<cols; n++)
        {
            element[i][n] = 0;
        }
    }

    matrixCount++;
}

Matrix::Matrix(const Matrix& m)
{

    rows = m.rows;
    cols = m.cols;

    element = new int* [rows];

    for (int i=0; i<rows; i++)
    {
        element[i] = new int[cols];
        for (int n = 0; n<cols; n++)
        {
            element[i][n] = m.element[i][n];
        }
    }
    matrixCount++;
}

Matrix::~Matrix()
{
    if (element !=NULL)
    {
        for (int i=0; i<rows; i++)
        {
            if (element[i] != NULL)
                delete []element[i];
        }

        delete []element;
    }

    matrixCount--;
}


Matrix Matrix::operator=(Matrix m)
{

    if (element !=NULL)
    {
        for (int i=0; i<rows; i++)
        {
            if (element[i] != NULL)
                delete []element[i];
        }

        delete []element;
    }

    rows = m.rows;
    cols = m.cols;

    element = new int* [rows];

    for (int i=0; i<rows; i++)
    {
        element[i] = new int[cols];
        for (int n = 0; n<cols; n++)
        {
            element[i][n] = m.element[i][n];
        }
    }

    return *this;
}

int* Matrix::operator[] (int n)
{
    return element[n];
}

int Matrix::getRows() const
{
    return rows;
}

int Matrix::getColumns() const
{
    return cols;
}

int Matrix::getElement(int r, int c) const
{
    if (r<0)
        r = 0;
    else if (r>=rows)
        r = rows-1;
    if (c<0)
        c = 0;
    else if (c>=cols)
        c = cols-1;
    return element[r][c];
}


void Matrix::setElement (int r, int c, int v)
{
    if (r>=0 && r<=rows && c>=0 && c<=cols)
        element[r][c] = v;
}

Matrix Matrix::add (const Matrix& m) const
{
    Matrix sum;

    sum.rows = rows;
    sum.cols = cols;

    sum.element = new int* [rows];

    for (int i=0; i<rows; i++)
    {
        sum.element[i] = new int[cols];
        for (int n = 0; n<cols; n++)
        {
            sum.element[i][n] = element[i][n]+ m.element[i][n];
        }
    }

    return sum;
}

Matrix Matrix::subtract (const Matrix& m) const
{
    Matrix difference;

    difference.rows = rows;
    difference.cols = cols;

    difference.element = new int* [rows];

    for (int i=0; i<rows; i++)
    {
        difference.element[i] = new int[cols];
        for (int n = 0; n<cols; n++)
        {
            difference.element[i][n] = element[i][n]- m.element[i][n];
        }
    }

    return difference;
}

Matrix Matrix::operator * (const Matrix& m) const
{
    Matrix product;

    product.rows = rows;
    product.cols = m.cols;

    product.element = new int* [rows];

    for (int i=0; i<product.rows; i++)
    {
        product.element[i] = new int[m.cols];

        for (int n = 0; n<product.cols; n++)
        {
            product.element[i][n] = 0;
            for (int r=0; r<cols; r++)
            {
                product.element[i][n] += element[i][r] * m.element[r][n];
            }
        }
    }

    return product;
}

Bit Matrix::operator * (const Bit& bit) const
{
	//When multiplying a by a bit if there are more than 2 rows, throw bad_index
	//if more than 2 cols the vectos wont fit in the Bit struct, throw bad_index
	if(rows != 2 || cols != 2)
		throw ("Index is Bad");

	//New R comp
	int rComp = ( element[0][0] * bit.r_ ) + ( element[0][1] * bit.c_ );
	
	//New C comp
	int cComp = ( element[1][0] * bit.r_ ) + ( element[1][1] * bit.c_ );

	//Creating the new Bit to be filled
	Bit flipBit(rComp, cComp);

	//Return
	return flipBit;
}

int Matrix::get_matrixCount()
{
    return matrixCount;
}
