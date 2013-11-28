#ifndef SPECIAL_PIECES
#define SPECIAL_PIECES
#include "Matrix.h"
#include "Pieces.h"

/*

FileName:		"SpecialPieces.h"

Description:	THESE are all the inherited base classes of Piece. For information on any of their function, one should
				consult the Pieces class. There are 7 different permuted configurations all of which are contructed
				using the same concept for developing a construction algorithm

FutureNeeds:	A way to increment its color that is used in contructor. The Tetris will eventually change all the colors
				on the playing field for completing rows. The constructor will need to recognize this color change and
				accordingly create all its pieces thus henceforth.
*/


/***********************************************
T tetris block config
***********************************************/
class T: public Piece
{
public:
	T():Piece()
	{
		type_ = 'T';
		color_ = T_COLOR;
	
		//All pieces now with their randomly selected direction build theirself
		
		Bit startLocation(START_Y_PIECE, START_X_PIECE);
		
		pieceBuilder(direction_, startLocation);
	}

	T(Bit direction, Bit startLocation)
	{
		type_ = 'T';
		color_ = T_COLOR;
		
		direction_ = direction;
	
		pieceBuilder(direction, startLocation);
	}
	
	void pieceBuilder(Bit direction, Bit startLocation)
	{
		FlipMatrix flipMatrix;
		
/*		Create initial sequence of 3 bits
		
		[][][]
		
*/
		for(int i = 0; i < 3; i++)
		{
			//typedef  flipOperation;
			bits_[i] = startLocation + (flipMatrix * (direction * i));
		}

/*		Top it off
		
		  []
		[][][]
		
*/
		bits_[3] = bits_[1] + ( (flipMatrix * flipMatrix) * direction );
	}
};

/***********************************************
I tetris block config
***********************************************/
class I: public Piece
{
	public:
	
	
	I():Piece()
	{
		type_ = 'I';
		color_ = I_COLOR;
	
		//All pieces now with their randomly selected direction build theirself
		
		Bit startLocation(START_Y_PIECE, START_X_PIECE);
		
		pieceBuilder(direction_, startLocation);
	}

	I(Bit direction, Bit startLocation)
	{
		type_ = 'I';
		color_ = I_COLOR;
		
		direction_ = direction;
	
		pieceBuilder(direction, startLocation);
	}
	
/*		Create sequence of 4 heading down a singular axis
		
		[]
		[]
		[]
		[]
		
*/
	void pieceBuilder(const Bit& direction, Bit startLocation)
	{
		FlipMatrix flipMatrix;
		
		for(int i = 0; i < 4; i++)
		{
			bits_[i] = startLocation + (direction * i);
		}
	}
};

/***********************************************
J tetris block config
***********************************************/
class J: public Piece
{
	public:
	
	J():Piece()
	{
		type_ = 'J';
		color_ = J_COLOR;
		
		//All pieces now with their randomly selected direction build theirself
		
		Bit startLocation(START_Y_PIECE, START_X_PIECE);
		
		pieceBuilder(direction_, startLocation);
	}

	J(Bit direction, Bit startLocation):Piece()
	{
		type_ = 'J';
		color_ = J_COLOR;
		
		direction_ = direction;
	
		pieceBuilder(direction, startLocation);
	}
	
	void pieceBuilder(const Bit& direction, Bit startLocation)
	{
		FlipMatrix flipMatrix;
		
/*		Create initial sequence of 3 bits
		
		[]
		[]
		[]

*/
		for(int i = 0; i < 3; i++)
		{
			bits_[i] = startLocation + (direction * i);
		}

/*		the last bit is on the left in relation to the chain of 3
		
		  []
		  []
		[][]
*/
		//typedef ((flipMatrix*flipMatrix*flipMatrix)*direction) directionChange3Time;
		bits_[3] = bits_[2] + ((flipMatrix*flipMatrix*flipMatrix)*direction);
	}
};

/***********************************************
L tetris block config
***********************************************/
class L: public Piece
{

public:

	L():Piece()
	{
		type_ = 'L';
		color_ = L_COLOR;
	
		//All pieces now with their randomly selected direction build theirself
		
		Bit startLocation(START_Y_PIECE, START_X_PIECE);
		
		pieceBuilder(direction_, startLocation);
	}

	L(Bit direction, Bit startLocation)
	{
		type_ = 'L';
		color_ = L_COLOR;
		
		direction_ = direction;
	
		pieceBuilder(direction, startLocation);
	}

	void pieceBuilder(const Bit& direction, Bit startLocation)
	{
		FlipMatrix flipMatrix;
		
		/*		Create initial sequence of 3 bits
		
		[]
		[]
		[]

*/
		for(int i = 0; i < 3; i++)
		{
			bits_[i] = startLocation + (direction * i);
		}

/*		the last bit is on the right in relation to the chain of 3
		
		[]
		[]
		[][]
*/
		//typedef (flipMatrix * direction) directionChange1Time;
		bits_[3] = bits_[2] + (flipMatrix * direction);

	}
};

/***********************************************
O tetris block config
***********************************************/
class O: public Piece
{

public:

	O():Piece()
	{
	
		type_ = 'O';
		color_ = O_COLOR;
		
		//All pieces now with their randomly selected direction build theirself
		
		Bit startLocation(START_Y_PIECE, START_X_PIECE);
		
		pieceBuilder(direction_, startLocation);
	}

	O(Bit direction, Bit startLocation)
	{
		
		direction_ = direction;
	
		pieceBuilder(direction, startLocation);
	}

	void pieceBuilder(const Bit& direction, Bit startLocation)
	{
		Bit onlyConstructDirection(1,0);

		FlipMatrix flipMatrix;
		
/*		initial 2 bits
		[]
		[]
*/
		for(int i = 0; i < 2; i++)
		{ 
			bits_[i] = startLocation + (onlyConstructDirection * i);
		}
/*		Change this functions copy of startLocation and
		finish off the O-block

		[][]
		[][]
		
*/
		startLocation = startLocation + (flipMatrix * onlyConstructDirection);
		for(int i = 2; i < 4; i++)
		{
			bits_[i] = startLocation + (onlyConstructDirection * (i-2));
		}
	}
};

/***********************************************
Z tetris block config
***********************************************/
class Z: public Piece
{

public:

	Z():Piece()
	{
		type_ = 'Z';
		color_ = Z_COLOR;
	
		//All pieces now with their randomly selected direction build theirself
		
		Bit startLocation(START_Y_PIECE, START_X_PIECE);
		
		pieceBuilder(direction_, startLocation);
	}

	Z(Bit direction, Bit startLocation)
	{
	
		type_ = 'Z';
		color_ = Z_COLOR;
		
		direction_ = direction;
	
		pieceBuilder(direction, startLocation);
	}

	void pieceBuilder(Bit direction, Bit startLocation)
	{
		FlipMatrix flipMatrix;
		
/*
			Create initial [][] in direction*flipMatrix
*/
		//typedef (flipMatrix * direction) flipVectorOneTime;

		for(int i = 0; i < 2; i++)
		{
			bits_[i] = startLocation + ((flipMatrix * direction) * i);
		}

/*
		Drop the startLocation down one into the direction fed to
		the function and finish off the bloc

		[][]
		  [][]
*/
		startLocation = bits_[1] + direction;

		for(int i = 2; i < 4; i++)
		{
			bits_[i] = startLocation + (flipMatrix * direction * (i-2));
		}
	}
};

/***********************************************
S tetris block config
***********************************************/
class S: public Piece
{

public:

	S():Piece()
	{
	
		type_ = 'S';
		color_ = S_COLOR;
		
		//All pieces now with their randomly selected direction build theirself
		
		Bit startLocation(START_Y_PIECE, START_X_PIECE);
		
		pieceBuilder(direction_, startLocation);
	}

	S(Bit direction, Bit startLocation)
	{
		type_ = 'S';
		color_ = S_COLOR;
		
		direction_ = direction;
	
		pieceBuilder(direction, startLocation);
	}
	
	void pieceBuilder(Bit direction, Bit startLocation)
	{
		FlipMatrix flipMatrix;
		
/*
			Create initial [][] in direction*flipMatrix
*/
		//typedef (flipMatrix * direction) flipVectorOneTime

		for(int i = 0; i < 2; i++)
		{
			bits_[i] = startLocation + ((flipMatrix * direction) * i);
		}

/*
		Drop the startLocation up one into the direction fed to
		the function and finish off the bloc

		  [][]
		[][]
*/
		//typedef (flipMatrix * flipMatrix * direction) flipVectorTwoTimes
		startLocation = bits_[1] + (flipMatrix * flipMatrix * direction);

		for(int i = 2; i < 4; i++)
		{
			bits_[i] = startLocation + ( (flipMatrix * direction) * (i-2));
		}
	}
};

#endif
