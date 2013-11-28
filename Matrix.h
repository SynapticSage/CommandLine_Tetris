//Program 2 - "Matrix Class" - Header file
//Implement the Matrix class
//Due: January 28, 2007
//Created: January 26, 2007
//Last Modified: January 28, 2007

#ifndef MATRIX_
#define MATRIX_
#include "Bit.h"

class Matrix
{
    protected:
        int rows, cols;
        int **element;
        static int matrixCount;

    public:

        /*Data Abstraction: A new 2D integer array (or matrix), which
               element points to.
          Input: Two ints are passed by value.
          Process/Implentation: Rows and cols are initialized to the two
               arguments that were passed, as long as those arguments are
               greater than 0. If the argument is less than zero, then that
               variable is set to zero. Element is made to point to a
               matrix with the size given by the values of rows and cols,
               and each element is initialized to 0. matrixCount
               is incremented.
          Output: NA
          Assumptions: Arguments were passed with the correct data type.
        */
        Matrix(int r=0, int c = 0);

        /*Data Abstraction: A new 2D integer array (or matrix), which
               element points to.
          Input: A matrix is passed by reference
          Process/Implentation: Rows and cols are initialized to the rows
               and cols of the matrix that was passed. Element is made to
               point to a matrix, and each element is initialized to the
               value in the corresponding element of the passed matrix.
               matrixCount is incremented.
          Output: NA
          Assumptions: A matrix is passed
        */
        Matrix(const Matrix& m);

        /*Process/Implementation: The 2D array that element points to is
               deleted. matrixCount is decremented.
        */
        ~Matrix();

        /*Data Abstraction: A new 2D integer array (or matrix), which
               element points to.
          Input: A matrix is passed by reference
          Process/Implentation: The 2D array the matrix originally pointed to
               is deleted. Rows and cols are initialized to the rows
               and cols of the matrix that was passed. Element is made to
               point to a matrix, and each element is initialized to the
               value in the corresponding element of the passed matrix.
          Output: A matrix is returned.
          Assumptions: A Matrix is passed.
        */
        Matrix operator= (Matrix);

        /*Input: An int is passed by value
          Output: The int pointer element[n] points to is returned.
          Assumptions: An int was passed. The user will not use the returned
               pointer to change memory not allocated to the matrix.
        */
        int* operator[] (int);

        /*Output: An int whose value is the number of rows is returned.
        */
        int getRows() const;

        /*Output: An int whose value is the number of columns is returned.
        */
        int getColumns() const;

        /*Input: Two ints, r and c, are passed by value
          Process/Implentation: If r or c is less than zero, that variable
               is assigned zero. If r is greater than rows, r is assigned
               rows-1. If c is greater than cols, c is assigned cols-1.
          Output: An int, element[r][c], is returned.
          Assumptions: Two ints were passed.
        */
        int getElement(int r, int c) const;

        /*Input: Three ints, r, c, and v, are passed by value.
          Process/Implentation: If both r and c are greater than zero, r is
               less than rows, and c is less than cols, element[r][c] is
               set to v. Otherwise, nothing happens.
        */
        void setElement (int r, int c, int v);

        /*Data Abstraction: A matrix class, called sum.
          Input: A matrix (m) is passed by reference
          Process/Implentation: Sum's rows and cols variables are set to
               the original matrix's rows and cols.  Sum's element pointer
               is made to point to a matrix, and each element is
               initialized to the sum of the corresponding element of the
               original matrix and the corresponding element of the
               passed matrix.
          Output: The sum matrix is returned.
          Assumptions: A Matrix is passed with the same rows and cols values
               as the original matrix.
        */
        Matrix add (const Matrix& m) const;

        /*Data Abstraction: A matrix class, called difference.
          Input: A matrix (m) is passed by reference
          Process/Implentation: Difference's rows and cols variables are set
               to the original matrix's rows and cols.  Difference's element
               pointer is made to point to a matrix, and each element is
               initialized to the difference of the corresponding element of
               the original matrix and the corresponding element of the
               passed matrix.
          Output: The difference matrix is returned.
          Assumptions: A Matrix is passed with the same rows and cols values
               as the original matrix.
        */
        Matrix subtract (const Matrix& m) const;

        /*Data Abstraction: A matrix class, called product.
          Input: A matrix (m) is passed by reference
          Process/Implentation: Product's rows and cols variables are set
               to the original matrix's rows and m's cols.  Product's element
               pointer is made to point to a matrix, and each element is
               initialized to the sum of the products of the corresponding
               elements in m and the original matrix.
          Output: The product is returned.
          Assumptions: A Matrix is passed whose number of rows is equal to
               the original matrix's cols.
        */
        Matrix operator * (const Matrix& m) const;

        /*Output: A int whose value is matrixCount is returned.
        */
        static int get_matrixCount ();

		//Written specially for the Pieces.h
		Bit operator * (const Bit& bit) const;


};

class FlipMatrix: public Matrix
{
	public:
		FlipMatrix():Matrix(2,2)
		{
			setElement(0 , 0 , 0 ); 
			setElement(0 , 1 , -1 );
			setElement( 1 , 0 , 1 ); 
			setElement( 1 , 1 , 0 );
		}
};


#endif //MATRIX_
