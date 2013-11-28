/*************************************************************************************

FileName:		Bit.h

Descrition:		Contains all the most basically used elements of the matrix class
				including exceptions it uses to throw and the basic struct Bit,
				the essential building block of tetronimoes.

FutureNeeds:

**************************************************************************************/

#ifndef TETRIS_BITS_COMPONENTS
#define TETRIS_BITS_COMPONENTS


//INCLUSIONS
#include <exception>
#include <cstdlib>
#include <memory>
#include <windows.h>
#include <MMsystem.h>

#include "HeaderStuff.h"

//NAMESPACE
using namespace std;


/*********************************************
			The BIT (direction vectors)

They are the components of all the tetronimoes

PossibleChanges:	If setting a Bit to NULL
					does not work to keep it
					unactive, then we might
					need each Bit to contain
					the member varibale active

**********************************************/
struct Bit
{
	//Stores a location for each bit
	int r_, c_;
	bool active_;

	//Stores a color for each block
	int color_;

	//Simplified Bit Constructor
	Bit(int r = 0, int c = 0, bool active = true)
	{
		r_ = r;
		c_ = c;
		color_ = 0;
		active_ = active;
	}

	const Bit operator + (const Bit& other) const
	{
		Bit newBit;

		newBit.r_ = this->r_ + other.r_;
		newBit.c_ = this->c_ + other.c_;

		return newBit;
	}

	const Bit operator * (int num) const
	{
		Bit newBit;

		newBit.r_ = this->r_ * num;
		newBit.c_ = this->c_ * num;

		return newBit;
	}

	bool operator == (const Bit& other) const
	{
		bool equals = true;
		if(r_ != other.r_)
			equals = false;
		if(c_ != other.c_)
			equals = false;

		//Return
		return equals;
	}

};



#endif
