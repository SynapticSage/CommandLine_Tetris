
/******************************************************************************************

PIECE FUNCTIONALITY

******************************************************************************************/

/************************************************************************
Filename: Manager (PieceFuctionality).cpp
Description: Is used to keep the function implamentations
that handle pieces in Manager.h seperate from the general
fucntions that the Game uses.
************************************************************************/

#include "Manager.h"
#include <mmsystem.h>


/*
Description:	Flips the tetronimoe data wise
Assumption:		The piece exists.
PostCondition:	Flips if it can within the contstaints
				of the field and other pieces surrounding
				it
*/
void Manager::flip()
{
	//For each bit check if interfere
	bool isEmpty = false;
	int rowToCheck, colToCheck;

	Piece* flipped = 0;

	//Get flipped of active
	if( pInAction_->getType() != 'O' )
	{
		flipped = giveFlipped(*pInAction_);
		isEmpty = true;
	}

	for(int i = 0; i < 4 && isEmpty; i++)
	{
		rowToCheck = (*flipped)[i].r_;
		colToCheck = (*flipped)[i].c_;

		if( rowToCheck < 0 || rowToCheck >= playField_.getRows() )
			isEmpty = false;

		if( colToCheck < 0 || colToCheck >= playField_.getColumns() )
			isEmpty = false;

		if( isEmpty && playField_[rowToCheck][colToCheck] != EMPTY)
			isEmpty = isAPartOfActive(rowToCheck, colToCheck);
	}

	//If isEmpty is true, set the *pInAction_ to its flipped
	if(isEmpty)
	{
		delete pInAction_;

		//Reset inAction piece
		pInAction_ = flipped;

		//Reset container's pointer to inAction piece
		int numAction = container_.getNumPieces()-1;

		//HHOOOOOOLLLYYYY SHIIIIIIIIIIT!!!!!!!!!!!!!
		container_.setPointerAt(numAction, pInAction_);
	}
}


/*
Description:	moves the piece right if can
Assumption:		The piece exists.
PostCondition:	Moves the piece right within the contstaints
				of the field and other pieces surrounding
				it
*/
void Manager::moveRight()
{
	//For each bit check if interfere
	bool isEmpty = true;
	int rowToCheck, colToCheck;

	for(int i = 0; i < 4; i++)
	{

		rowToCheck = (((*pInAction_)[i].r_));
		colToCheck = (((*pInAction_)[i].c_)+1);

		if( rowToCheck < 0 || rowToCheck >= playField_.getRows() )
			isEmpty = false;

		if( colToCheck < 0 || colToCheck >= playField_.getColumns() )
			isEmpty = false;

		if( isEmpty && playField_[rowToCheck][colToCheck] != EMPTY )
			isEmpty = isAPartOfActive(rowToCheck, colToCheck);
	}

	//If isEmpty is true, set the *pInAction_ to its flipped
	if(isEmpty)
	{
		for(int i = 0; i < 4; i++)
		{
			rowToCheck = (((*pInAction_)[i].r_));
			colToCheck = (((*pInAction_)[i].c_)+1);

 			(*pInAction_)[i].r_ = rowToCheck;
			(*pInAction_)[i].c_ = colToCheck;
		}
	}
}


/*
Description:	moves the piece right if can
Assumption:		The piece exists.
PostCondition:	Moves the piece right within the contstaints
				of the field and other pieces surrounding
				it
*/
void Manager::moveLeft()
{
	//For each bit check if interfere
	bool isEmpty = true;
	int rowToCheck, colToCheck;

	for(int i = 0; i < 4; i++)
	{

		rowToCheck = (((*pInAction_)[i].r_));
		colToCheck = (((*pInAction_)[i].c_)-1);

		if( rowToCheck < 0 || rowToCheck >= playField_.getRows() )
			isEmpty = false;

		if( colToCheck < 0 || colToCheck >= playField_.getColumns() )
			isEmpty = false;

		if( isEmpty && playField_[rowToCheck][colToCheck] != EMPTY )
			isEmpty = isAPartOfActive(rowToCheck, colToCheck);
	}

	//If isEmpty is true, set the *pInAction_ to its flipped
	if(isEmpty)
	{
		for(int i = 0; i < 4; i++)
		{
			rowToCheck = (((*pInAction_)[i].r_));
			colToCheck = (((*pInAction_)[i].c_)-1);

			(*pInAction_)[i].r_ = rowToCheck;
			(*pInAction_)[i].c_ = colToCheck;
		}
	}
}

/*
Description:	moves the piece down
Assumption:		The piece exists.
PostCondition:	Moves the piece right within the contstaints
				of the field and other pieces surrounding
				it
Returns:		true if it can't move down (hitRockBottom)
*/
bool Manager::gravity()
{
	//For each bit check if interfere
	bool isEmpty = true;
	int rowToCheck, colToCheck;

	//Occupied?
	for(int i = 0; i < 4 && isEmpty; i++)
	{

		rowToCheck = (((*pInAction_)[i].r_)+1);
		colToCheck = (((*pInAction_)[i].c_));
		
		//In row bounds?
		if( rowToCheck < 0 || rowToCheck >= playField_.getRows() )
			isEmpty = false;

		//In col bounds?
		if( colToCheck < 0 || colToCheck >= playField_.getColumns() )
			isEmpty = false;

		if( isEmpty && playField_[rowToCheck][colToCheck] != EMPTY )
			isEmpty = isAPartOfActive(rowToCheck, colToCheck);
	}

	//If isEmpty is true, set the *pInAction_ to its dropped
	if(isEmpty)
	{
		for(int i = 0; i < 4; i++)
		{
			rowToCheck = (((*pInAction_)[i].r_)+1);

			(*pInAction_)[i].r_ = rowToCheck;
		}
	}

	//Return is empty
	return !isEmpty;
}

/*
Description:	checks to see if the particular coordinate
				is a part of the active piece in motion. This
				is to combat the glitching behavior that cause
				a pieces components to not want to move into
				itself.
Assumption:		The piece exists.
PostCondition:	Moves the piece right within the contstaints
				of the field and other pieces surrounding
				it
Returns:		true if it can't move down (hitRockBottom)
*/
bool Manager::isAPartOfActive(int row, int col)
{
	bool isAPartOfMe = false;
	for(int bitNum = 0; bitNum < 4; bitNum++)
	{
		if( (*pInAction_)[bitNum].r_ == row && (*pInAction_)[bitNum].c_ == col)
			isAPartOfMe = true;
	}

	return isAPartOfMe;
}


/*
Purpose:		Is used to shift Pieces that are
				moving into activity into the
				play field. If they can move in
				due to realestate conflicts, then
				alert whomever called me.

Assumptions:	The Piece must be created such that
				all of its bits are in negative rows
				above the center of the playField.

Resultant:		The tetronimoe is ready to be moved

Output:			Returns the condition of
				cannotMoveToField
*/
bool Manager::moveActiveToPlayField(Piece &p)
{
	//Bool conditions
	bool isEmpty = true;
	bool inPlayField = true;

	//contants
	int zeroBitRowPlusOne, oneBitRowPlusOne,twoBitRowPlusOne, threeBitRowPlusOne;

	//Check Ints
	int rowToCheck, colToCheck;


	//In playField?
	for(int i = 0; i < 4; i++)
	{
		if( p[i].r_ < 0 || p[i].r_ >= playField_.getRows() || p[i].c_ < 0 || p[i].c_ >= playField_.getColumns() )
				inPlayField = false;
	}

	//Occupied?
	for(int i = 0; i < 4 && isEmpty; i++)
	{

		rowToCheck = (((*pInAction_)[i].r_)+1);
		colToCheck = (((*pInAction_)[i].c_));


		if(rowToCheck >= 0 && rowToCheck>= 0 && playField_[rowToCheck][colToCheck] != EMPTY )
			isEmpty = isAPartOfActive(rowToCheck, colToCheck);
	}

	while( !(inPlayField) && (isEmpty) )
	{
		//Occupied?
		for(int i = 0; i < 4 && isEmpty; i++)
		{

			rowToCheck = (((*pInAction_)[i].r_)+1);
			colToCheck = (((*pInAction_)[i].c_));


			if(rowToCheck >= 0 && rowToCheck>= 0 && playField_[rowToCheck][colToCheck] != EMPTY )
				isEmpty = isAPartOfActive(rowToCheck, colToCheck);
		}



		//Get next locations
		zeroBitRowPlusOne = (p[0].r_)+1;
		oneBitRowPlusOne = (p[1].r_)+1;
		twoBitRowPlusOne = (p[2].r_)+1;
		threeBitRowPlusOne = (p[3].r_)+1;

		//If empty then move
		if(isEmpty)
		{
			p[0].r_ = zeroBitRowPlusOne;
			p[1].r_ = oneBitRowPlusOne;
			p[2].r_ = twoBitRowPlusOne;
			p[3].r_ = threeBitRowPlusOne;
		}

		//In playField?
		inPlayField = true;
		for(int i = 0; i < 4; i++)
		{
			if( p[i].r_ < 0 || p[i].r_ >= playField_.getRows() || p[i].c_ < 0 || p[i].c_ >= playField_.getColumns() )
					inPlayField = false;
		}
	}

	//Return (cannotMoveToField)
	return !isEmpty;
}
