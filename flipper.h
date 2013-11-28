/************************************************************

FileName: "Flipper.h"

Description: Holds the flipper function that is a friend to all
pieces.

************************************************************/

#include "specialPieces.h"

/*
	
	Desription: produces a pointer to a flipped version of
				the passed piece.
	Assumptions:The piece exists
	Postconditions:	Creates a pointer to the flipped piece
					and returns with the original piece
					unchanged

*/
Piece* giveFlipped(const Piece &p)
{
	FlipMatrix flipMatrix;
/*
	Draw out the least square bounds that piece exists in 
	
														  *------*
														  |		 |
														  |		 |
														  *------*
	
	Wherever zero bit is, reconstruct it in the next corner
	where next corner is chose in counter-clockwise manner
*/
	
	//Come about rowMax and rowMin
	int rowMin = p.bits_[0].r_, rowMax = p.bits_[0].r_;
	for(int i = 0; i < 4; i++)
	{
		if(rowMin > p.bits_[i].r_)
			rowMin = p.bits_[i].r_;

		if(rowMax < p.bits_[i].r_)
			rowMax = p.bits_[i].r_;
	}
	
	//Come about colMax and colMin
	int colMin = p.bits_[0].c_, colMax = p.bits_[0].c_;
	for(int i = 0; i < 4; i++)
	{
		if(colMin > p.bits_[i].c_)
			colMin = p.bits_[i].c_;

		if(colMax < p.bits_[i].c_)
			colMax = p.bits_[i].c_;
	}

	//setCorners constants
	const Bit lowerLeft(rowMin, colMin);
	const Bit upperLeft(rowMax, colMin);
	const Bit upperRight(rowMax, colMax);
	const Bit lowerRight(rowMin, colMax);

	//Grab startLocation -- the p.bits_[0] -- to be changed
	Bit newStartLocation = p.bits_[0];

	//Assign the newStartLocation an integer data type
	int integerSwitch = 0;
	if(newStartLocation == upperLeft)
		integerSwitch = 1;
	if(newStartLocation == upperRight)
		integerSwitch = 2;
	if(newStartLocation == lowerRight)
		integerSwitch = 3;
	if(newStartLocation == lowerLeft)
		integerSwitch = 4;

	//Which ever corner, flip that
	switch(integerSwitch)
	{
	case 1:
		newStartLocation = upperRight;
		break;
	case 2:
		newStartLocation = lowerRight;
		break;
	case 3:
		newStartLocation = lowerLeft;
		break;
	case 4:
		newStartLocation = upperLeft;
	}

	//get new pieces direction
	Bit newPieceDirection = flipMatrix * p.direction_;


//Create new piece with the informations -- CAN I REFERENCE DERIVED CLASS THINGS WITH THE SUPER CLASS FUCNTION???

Piece* piece;

switch(p.type_)
{
case 'T':
		  piece = new T(newPieceDirection, newStartLocation);
		  break;
case 'L':
		  piece = new L(newPieceDirection, newStartLocation);
		  break;
case 'J':
		  piece = new J(newPieceDirection, newStartLocation);
		  break;
case 'I':
		  piece = new I(newPieceDirection, newStartLocation);
		  break;
case 'Z':
		  piece = new Z(newPieceDirection, newStartLocation);
		  break;
case 'S':
		  piece = new S(newPieceDirection, newStartLocation);
		  break;
default:
		  piece = new O(newPieceDirection, newStartLocation);
}

	return (piece);

/*

	 CHANGE
	 flip will return a the flipped version of itelf in its place, the super class will have to
	 check its ability to occupy its realestate. if its occuied then dont change the actual object,
	 else set it equal to the returned flipped piece.
*/

}

