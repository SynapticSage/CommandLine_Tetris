/*
FileName: HeaderStuff.h
*/

#ifndef _HEADER_STUFFF_
#define _HEADER_STUFFF_

/***THE FIELD DIMENSIONS***/
const int FIELD_SIZE_Y = 22;
const int FIELD_SIZE_X = 10;

//PIECE BEGIN POINT
const int START_Y_PIECE = 0;
const int START_X_PIECE = FIELD_SIZE_X/2;
/**************************/

//Used to fix the issue of play size needing to be changed
//this is a bandage for the drawing of all things so that
//i do not ruin all the artwork drawn thus far which was
//drawn for a playField of x_width 22
const int X_ADJUSTMENT_FACTOR = (FIELD_SIZE_X + (-20));


//Matrix dimensions in overall coordinate system
const int START_X = 20, END_X = FIELD_SIZE_X+ START_X,
          START_Y = 1,  END_Y = FIELD_SIZE_Y + START_Y;

/***FIELD CONSTANTS     ***/
const int EMPTY = 0;
const char BLOCK = -79;
/**************************/


//Colors of the tetrominos
const int I_COLOR = 2;
const int J_COLOR = 3;
const int L_COLOR = 4;
const int O_COLOR = 5;
const int Z_COLOR = 6;
const int S_COLOR = 7;
const int T_COLOR = 14;
const int DELETION_COLOR = 95;

/*********************************************

StructName:		GameBoard Size Settings

StructPurpose:	Stores the size factors and
				numbers involved in the game
				board size

*********************************************/
struct GameBoardSize
{
	
};

/*********************************************

StructName:		Speed Settings

StructPurpose: Speed settings can be kept 
               together.

*********************************************/
struct SpeedSettings
{
	double forced_drop_pause_;
	double move_horizontal_speed_;
	double move_vertical_speed_;
	double flip_speed_;

	SpeedSettings();
	void handleSpeedSettings(const int& speedLevel = 1);
	void speedUp();
};

/*********************************************

StructName:		Options

StructPurpose: Game statistics can be
			   kept seperate from other variables
			   in the managaer.

*********************************************/
struct Options
{
	//SPEED
	int speedLevel_;
	int numLinesSpeedUp_;
	SpeedSettings speedSetting_;
	bool colorChangeOnDelete_;
	bool disco_mode_;
	
	Options(int numLinesSpeedUp = 3, bool colorChangeOnDelete = true);
};

/*********************************************

StructName:		GameStat`

StructPurpose: Game statistics can be
			   kept seperate from other variables
			   in the managaer.

*********************************************/
struct GameStat
{
	int score_;
	int numberOfMoves_;
	int numberOfLinesDestroyed_;
	
	int colorAddInteger_;
	
	
	GameStat();

};

/*********************************************

StructName:		HiScore`

StructPurpose: The high scores can be easily 
               written to files and sorted

*********************************************/
struct HiScore
{
    int nameLength;
    char name[30];
    double score;
};

/*******************************************
ClassName:	BadIndex
Purpose:	The used exception through out
			all of the Tetris Heirchy of
			classes for bad indexes
NoteThat:	A global exception object is declared
			at the end of this class declaration
********************************************/

#ifdef BAD_INDEX_FUN
class BadIndex
{
	const char* what()
	{
		return "A Wrong Index is Referenced";
	}

} bad_index;


#endif //BAD_INDEX_FUN

//Exception class in case there is an error with the file.
class FILE_ERROR{};

#endif//_HEADER_STUFFF_