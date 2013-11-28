#include "Pieces.h"
#include <cstdlib>
#include <ctime>

/*
	description:	This deletes one of the bits
					from the tetronimoes
	precondition:	A bit exists
	postcondition:	Deletes bit, throws bad_index if
					n is out of bounds
	return:			If the bit is already deleted
*/
Piece::Piece()
{
	//INITIALIZE TYPE
	type_ = 'P';
	color_ = 0;


	srand( time(NULL) );
	int randomInteger = rand() % 4;

	//PICK WHICH DIRECTION VECTOR TO FEED CONSTRUCTION MECHANISM
	Bit constructDirection;
	switch(randomInteger)
	{
		case 1:
			constructDirection = rightUnitVector;
			break;
		case 2:
			constructDirection = downUnitVector;
			break;
		case 3:
			constructDirection = leftUnitVector;
			break;
		default:
			constructDirection = upUnitVector;
		//note that default case covers the zero integer case that I want to occur
	}

	//Set the pieces stored directon
	direction_ = constructDirection;

}


/*
Description:	changes the color of the pieced
Assumptions:	a piece exists
Postcondition:	the color is changed
*/
void Piece::changeColor(const int amount)
{
	//Adds color but wraps back to zero when it hits 200
	color_ += amount;
	if(color_ > 199)
		color_ -= 200;
}

/*
Description:	CopyConstructor
Assumptions:	A piece exits
Postcondition:	This piece is a perfect copy
				of the other piece.
*/
Piece::Piece(const Piece& p)
{
	//Copy Guts
	for(int i = 0; i < 4; i++)
	{
		bits_[i] = p.bits_[i];
	}

	type_ = p.type_;
}


/*
Description:	defines the [] operator
				to give users access to
				the individual bits of the
				tetronimoe.
Assumption	:	a piece (tetronimoe) exists
Postcondition:	SEE Return: , else it
				throws a bad_index for a
				bad n value
Return:			retuns a reference to
				the bit specified by n
*/
Bit& Piece::operator [] (int n)
{
	if(n < 0 || n > 3)
		throw ("Index is Bad");

	return bits_[n];
}

/*
Description:	lets two pieces use the equals
				operator to set themselves equal
				to eachother
Assumption	:	a piece to be immatated is not itself
Postcondition:	a piece becomes a perfect immatation
				of another piece.
Return:			retuns itself
*/
Piece& Piece::operator = (const Piece& p)
{
	//Copy Guts
	for(int i = 0; i < 4; i++)
	{
		bits_[i] = p.bits_[i];
}

	type_ = p.type_;
	color_ = p.color_;

	//Return
	return *this;
}

/*
Description:	returns a pieces color
Assumption	:	a piece exists
Postcondition:	the object is unchanged
Return:			retuns its color
*/
int Piece::getColor() const
{
	return color_;
}

/*
Description:	deletes a bit
Assumption	:	a bit is pointed to and not
				already deleted
Postcondition:	deletes bits_'s bit at n
Return:			a bool whether its already
				been deleted or not
*/
bool Piece::deleteBit(int n)
{
	bool alreadyDeleted = false;

	if(n < 0 || n > 3)
		throw ("Index is Bad");

	if(bits_[n] == 0)
		alreadyDeleted = true;

	bits_[n] = 0;

	return alreadyDeleted;
}

/*
Description:	Serves a requirement for
				all pieces who inherit from
				the Piece class. it is what single
				handedly builds the tetronimoe with
				unit vectors and a location
Assumption	:	a piece exists
Postcondition:	the Piece is contructed at startLocation
				with direction_ direction.
*/
void Piece::pieceBuilder(Bit direction, Bit startLocation)
{
}

