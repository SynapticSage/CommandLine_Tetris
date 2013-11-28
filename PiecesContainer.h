#ifndef TETRIS_GAME_MANAGER_PIECESCONTAINER
#define	TETRIS_GAME_MANAGER_PIECESCONTAINER

//INCLUSIONS
#include "Pieces.h"
#include "SpecialPieces.h"

using namespace std;

/***************************************


ClassName:	PiecesContainer

Purpose:	Holds all the piecs being used
			by the tetris game

Abilities:	Allows the game to run through
			and handle each tetronimoe and
			move it in accordance with other
			obstacles (including the wall)

ReWritten:	It was re implemented to, instead of
			stuffing copies of pieces that are created...to stuff
			pointers to the actual copies that are made. This way,
			less memory is stolen and when i move a piece in action
			i dont have to worry about its counterpart in the container
			not moving.

FutureNeeds:Destuctor must be written lest a huge amount of memory be lost


***************************************/

class PiecesContainer
{


private:
	//THE CONTAINER
	Piece** container_;

	//Properties of the container
	int capacity_;
	int numPieces_;

	//Helper Functions
	void PiecesContainer::grow()
	{
		//Alloc
		capacity_ = capacity_ * 2;
		Piece** temp = new Piece*[capacity_];

		//Copy into
		for(int i = 0; i < numPieces_; i++)
			temp[i] = container_[i];

		//Destroy member variables previous stuff and then set it to temp
		delete [] container_;
		container_ = temp;
	}

public:

	/*
		Description:	Gets the container ready to be stuffed
		Assumptions:	Nothing
		Postcondition:	Its ready to be stuffed
	*/
	PiecesContainer(void)
	{
		capacity_ = 10;
		numPieces_ = 0;
		
		container_ = new Piece*[capacity_];
	}

	
	/*
		Description:	Gets the size
		Assumptions:	Nothing
		Postcondition:	object is unchanged
		Returns:		The number of pieces
	*/
	int getNumPieces()
	{
		return numPieces_;
	}

	
	/*
		Description:	Deletes the containers contents and
						makes it so that it is ready to go.
		Assumtions:		The container has stuff
		Postcond:		all container contents are deleted
						and ready to go for the next game
	*/
	void deleteContainer()
	{
	    delete []container_;
	    
	    capacity_ = 10;
	    numPieces_ = 0;
	    container_ = new Piece*[capacity_];
	 }

	/**********************************
	Description:	Adds a piece to the container
					assuming the container exists
	Precondition:	The object exists
	Postcondition:	A piece is added, the numPieces is
					incremented.
	Return:			Returns whether we have additional memory to
					deal with.
	***********************************/
	bool addPiece(Piece* p)
	{
		Piece* newPiece = p;

		bool outOfMemory = false;
		
		try
		{
			if(numPieces_ >= capacity_)
				grow();
		}
		catch(bad_alloc)
		{
			outOfMemory = true;
		}

		container_[numPieces_] = newPiece;
		numPieces_++;

		//Return
		return outOfMemory;
	}


	/*******************************
	description:	Let's game use operator
					[] to call any piece from
					container
	precondition:	the container exists
	postcondition:	returns a piece and throws
					a bad_index if index is given out of
					bounds
	return:			returns the piece aske for by reference
	********************************/
	Piece& operator [] (int num)
	{
		if(num < 0 || num >= numPieces_)
			throw ("Index is Bad");
		
		//Return
		return (*container_[num]);
	}
	
	/*
		Description:	Instead of setting the
						piece at a certain point numm, (**)
						it sets a single derefrenced point
						to its pointer.
		Assumptions:	Nothing
		Postcondition:	container_ stores the pointer at num
		Returns:		nada
	*/
	void setPointerAt(int num, Piece* p)
	{
		if(num < 0 || num >= numPieces_)
			throw ("Index is Bad");
		
		container_[num] = p;
	}


};


#endif
