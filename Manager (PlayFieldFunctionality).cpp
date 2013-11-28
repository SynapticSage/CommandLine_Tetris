
/*******************************************************************************

PLAYFIELD FUNCTIONALITY

********************************************************************************/

/************************************************************************
Filename: Manager (PlayFieldFuctionality).cpp
Description: Is used to keep the function implamentations
that handle pieces in Manager.h seperate from the general
fucntions that the Game uses.
************************************************************************/
#include "Manager.h"

/*Description: Clears the field, then updates the matrix that holds where the pieces are
  Assumptions: The correct argument is passed. The pieces in the container have the 
      correct rows, cols, and color.
  Post Condition: The matrix shows where the pieces are.
  Return: Void
*/
void Manager::updatePlayField(PiecesContainer* container)
{
	int rowOfBit, colOfBit;

	//Fill the field with zeros
	fillFieldWithEmpty();
	checkThatFieldEmpty();

	//Place pieces
	for(int numPiece = 0; numPiece < container->getNumPieces(); numPiece++)
	{
		for(int bitPiece = 0; bitPiece < 4; bitPiece++)
		{

			rowOfBit = ( ( (*container)[numPiece])[bitPiece].r_ );
			colOfBit = ( ((*container)[numPiece])[bitPiece].c_ );

			//Check if out of bounds, if so, deactivate piece - should only happen at very end, when piece can't make it into field
			if(rowOfBit < 0 || colOfBit < 0 || rowOfBit >= playField_.getRows() || colOfBit >= playField_.getColumns() )
			{
				((*container)[numPiece])[bitPiece].active_  = false;
			}

			if( ((*container)[numPiece])[bitPiece].active_ )
				playField_[rowOfBit][colOfBit] = (*container)[numPiece].getColor();
		}
	}
}

/*
Description:	Used to update the playField_ matrix with the row its about
				to delete highlighted
Preconditions:	The bits to be deleted MUST be deactivated before using this
				method
Postcondition:	The play field must be updated via the standard updatePlayField()
				immediatley after this and printed to the screen.

Musing:			It may be necessary when calling this method to use a wait after
				its been printed to give the user a slice of time to admire thier
				accomplishments.
*/
void Manager::displayDeletionUpdatePlayField(PiecesContainer* container)
{
	int rowOfBit, colOfBit;

	//Fill the field with zeros
	fillFieldWithEmpty();
	checkThatFieldEmpty();

	//Place pieces
	for(int numPiece = 0; numPiece < container->getNumPieces(); numPiece++)
	{
		for(int bitPiece = 0; bitPiece < 4; bitPiece++)
		{

			rowOfBit = ( ( (*container)[numPiece])[bitPiece].r_ );
			colOfBit = ( ((*container)[numPiece])[bitPiece].c_ );

			//Check if out of bounds, if so, deactivate piece - should only happen at very end, when piece can't make it into field
			if(rowOfBit < 0 || colOfBit < 0 || rowOfBit >= playField_.getRows() || colOfBit >= playField_.getColumns() )
			{
				((*container)[numPiece])[bitPiece].active_  = false;
			}

			if( ((*container)[numPiece])[bitPiece].active_ )
				playField_[rowOfBit][colOfBit] = (*container)[numPiece].getColor();
			else
				playField_[rowOfBit][colOfBit] = DELETION_COLOR;
		}
	}
}


/*Description: Destroys any rows that are filled, and updates the score and the level
  Assumptions: The container and playfield exist
  Post Condition: Filled rows are deleted. Pieces above that row are moved down.
      Speed, score, and number of lines destroyed have all been updated
  Return: Void
*/
void Manager::destroyRowCompletions()
{
	bool readyToDelete;
	int rowToDelete, rowsDeletedAtOnce = 0;

    //If any of the elements on the row are empty, it is not ready to delete
	for(int row = 0; row <= playField_.getRows()-1 ; row++)
	{
		readyToDelete = true;
		for(int col = 0; col < playField_.getColumns(); col++)
		{
			if(playField_[row][col] == EMPTY)
				readyToDelete = false;

		}

		//Delete Phase
		if(readyToDelete)
		{
			//Queue deletion sound
			PlaySound("laserfire3.wav",NULL, SND_FILENAME|SND_ASYNC|SND_NOSTOP);

			rowToDelete = row;
			
			//Delete the row and move pieces down
			checkAllOfContainerToRowDelete( container_ , rowToDelete );
			displayDeletionRows();
            movePiecesDown( container_ , rowToDelete );

			//Increment the number of lines destroyed
            statistic_.numberOfLinesDestroyed_++;
            
            //Speed up tetris
			int newSpeed = statistic_.numberOfLinesDestroyed_ / options_.numLinesSpeedUp_;
			if(newSpeed > options_.speedLevel_)
			{
				options_.speedLevel_++;
				options_.speedSetting_.speedUp();
				if(options_.colorChangeOnDelete_)
					colorChangeAllBlocks(1);
			}

            //Keep track of num. of rows deleted with one tetromino
            rowsDeletedAtOnce++;
		}
	}

    updateScore(rowsDeletedAtOnce);
}

/*Description: Updates the score
  Assumptions: The correct argument is passed. The Manager exists. Only four rows can be
      deleted at once (with the "I" piece)
  Post Condition: The score has been updated. The new score and number of lines destroyed
      has been displayed to the screen.
  Return: Void
*/
void Manager::updateScore(int rowsDeletedAtOnce)
{
    //Increase Score
    switch (rowsDeletedAtOnce)
    {
        case 1:  statistic_.score_ += 10 * (.5 * options_.speedLevel_ +1);
                 break;
        case 2:  statistic_.score_ += 30 * (.5 * options_.speedLevel_+1);
                 break;
        case 3:  statistic_.score_ += 50 * (.5 * options_.speedLevel_+1);
                 break;
        case 4:  statistic_.score_ += 70 * (.5 * options_.speedLevel_+1);
                 break;
        default: statistic_.score_ += 0 * (.5 * options_.speedLevel_+1);
    }

    //Print Score
    if (rowsDeletedAtOnce !=0)
    {
        plotHUD_.setColor(green);
        plotHUD_.move(67 + X_ADJUSTMENT_FACTOR ,7);
        cout << statistic_.score_ << endl;
        plotHUD_.move(75 + X_ADJUSTMENT_FACTOR , 8);
        cout << statistic_.numberOfLinesDestroyed_ << endl;
		plotHUD_.move(75 + X_ADJUSTMENT_FACTOR , 9);
        cout << options_.speedLevel_ << endl;
    }
}

/*Description: Deactivates bits that are in the filled row
  Assumptions: The correct arguments are passed. The manager and container exist.
  Post Condition: Active is set to false for the bits in the filled row
  Return: Void
*/
void Manager::checkAllOfContainerToRowDelete(PiecesContainer& container, const int rowToDelete)
{
	int rowOfBit;

    //Deactivate bits that are in the filled row
	for(int pieceNum = 0; pieceNum < container.getNumPieces(); pieceNum++)
	{
		for(int bitNum = 0; bitNum < 4;  bitNum++)
		{
		    rowOfBit = ( ( (container)[pieceNum])[bitNum].r_ );

			if(rowOfBit == rowToDelete)
				((container)[pieceNum])[bitNum].active_ = false;
		}
	}
}

/*Description: Moves the pieces above the filled row down
  Assumptions: The correct arguments are passed. The pieces in the container have the 
      correct rows, cols, and color. The manager and container exist
  Post Condition: The row of the pieces above the filled row are incremented
  Return: Void
*/
void Manager::movePiecesDown(PiecesContainer& container, const int rowToDelete)
{
	int rowOfBit;
	
	//Move all bits that are above the deleted row down
	for(int pieceNum = 0; pieceNum < container.getNumPieces(); pieceNum++)
	{
		for(int bitNum = 0; bitNum < 4;  bitNum++)
		{
		    rowOfBit = ( ( (container)[pieceNum])[bitNum].r_ );

			if(rowOfBit < rowToDelete)
				( (container)[pieceNum])[bitNum].r_  = rowOfBit + 1;
		}
	}
}

/*Description: Clears the field
  Assumptions: Manager and the playing field exist
  Post Condition: The elements of the field are set to zero
  Return: Void
*/
void Manager::fillFieldWithEmpty()
{
    //Clear the field
	for(int i = 0; i < FIELD_SIZE_Y; i++)
	{
		for(int j = 0; j < FIELD_SIZE_X; j++)
		{
			playField_[i][j] = EMPTY;
		}
	}
}

/*Description: Makes sure the field is empty
  Assumptions: The manager and playing field exist
  Post Condition: An exception is thrown if any of the elements on the field
      are not set to EMPTY
  Return: Void
*/
void Manager::checkThatFieldEmpty()
{
    //Make sure the field is cleared
	for(int i = 0; i < FIELD_SIZE_Y; i++)
	{
		for(int j = 0; j < FIELD_SIZE_X; j++)
		{
			if(playField_[i][j] != EMPTY)
				throw "FIELD NOT EMPTY";
		}
	}
}

/*Description: Draws the "Next Piece" on the screen
  Assumptions: The correct argument is passed. The next piece matrix exists. The box that
      the next piece is supposed to be drawn in is in the correct space
  Post Condition: The next piece is drawn in the box on the screen
  Return: Void
*/
void Manager::drawNextPiece (Piece* next)
{
    //Clear the "next piece" matrix
    for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			nextPiece_[i][j] = EMPTY;
		}
	}

    //Draw the next piece in the 4x4 matrix.
    switch(next->getType())
    {
        case 'I': nextPiece_.setElement(0,1,I_COLOR);
                  nextPiece_.setElement(1,1,I_COLOR);
                  nextPiece_.setElement(2,1,I_COLOR);
                  nextPiece_.setElement(3,1,I_COLOR);
                  break;
        case 'J': nextPiece_.setElement(0,1,J_COLOR);
                  nextPiece_.setElement(1,1,J_COLOR);
                  nextPiece_.setElement(2,1,J_COLOR);
                  nextPiece_.setElement(2,0,J_COLOR);
                  break;
        case 'L': nextPiece_.setElement(0,1,L_COLOR);
                  nextPiece_.setElement(1,1,L_COLOR);
                  nextPiece_.setElement(2,1,L_COLOR);
                  nextPiece_.setElement(2,2,L_COLOR);
                  break;
        case 'T': nextPiece_.setElement(1,0,T_COLOR);
                  nextPiece_.setElement(1,1,T_COLOR);
                  nextPiece_.setElement(1,2,T_COLOR);
                  nextPiece_.setElement(2,1,T_COLOR);
                  break;
        case 'O': nextPiece_.setElement(1,0,O_COLOR);
                  nextPiece_.setElement(1,1,O_COLOR);
                  nextPiece_.setElement(2,0,O_COLOR);
                  nextPiece_.setElement(2,1,O_COLOR);
                  break;
        case 'S': nextPiece_.setElement(1,1,S_COLOR);
                  nextPiece_.setElement(1,2,S_COLOR);
                  nextPiece_.setElement(2,0,S_COLOR);
                  nextPiece_.setElement(2,1,S_COLOR);
                  break;
        default:  nextPiece_.setElement(1,0,Z_COLOR);
                  nextPiece_.setElement(1,1,Z_COLOR);
                  nextPiece_.setElement(2,1,Z_COLOR);
                  nextPiece_.setElement(2,2,Z_COLOR);
    }
    
    //Draw the next piece
    plotNext_.draw(nextPiece_);
}

/*Description: Changes the color of all the blocks
  Assumptions: The correct argument is passed. The ints still represent colors
  Post Condition: The colors of all the blocks on the screen are changed
  Return: Void
*/
void Manager::colorChangeAllBlocks(int amount)
{
    //Change the colors of the bits
	for(int i = 0; i < container_.getNumPieces(); i++)
	{
		container_[i].changeColor(amount);
	}
}

void Manager::displayDeletionRows()
{
	displayDeletionUpdatePlayField(&container_);
	draw();
	wait(.7);

}