#include "Manager.h"
#include "Flipper.h"
#include <ctime>

/*Description: Manager constructor
  Assumptions: The constants are correct, so that the matrices will draw in the
      correct places.
  Post Condition: The manager has been created. The statistics are set to zero, 
      the matrices are made correctly, the field is cleared, and a piece is ready 
      to drop
  Return: NA
*/
Manager::Manager()
{
	statistic_.numberOfMoves_ = 0;
	statistic_.score_ = 0;
	statistic_.numberOfLinesDestroyed_ = 0;

	pieceHitRockBottom_ = true;
	srand(time(0));


	//CREATE THE PLAYFIELD
	Matrix field(FIELD_SIZE_Y,FIELD_SIZE_X);
	playField_ = field;

    Matrix next(4,4);
	nextPiece_ = next;

	fillFieldWithEmpty();
	checkThatFieldEmpty();

	plotPlayField_.setStartPoint(START_X,START_Y);
    plotNext_.setStartPoint(66 + X_ADJUSTMENT_FACTOR,13);

	//GIVE nInAction_ a piece to handle
	pNextAction_ = giveNewRandomPiece();
}

/*Description: Moves the playing pieces  
  Assumptions: The manager exists.
  Post Condition: A piece has been moved, or a new piece has been created and 
      moved into the field
  Return: bool representing whether the function can still be performed (i.e. the game
      is not over).
*/
bool Manager::step()
{
	bool impossibleToStep = false;

	if(pieceHitRockBottom_)
	{
		//Add next piece to container
		container_.addPiece(pNextAction_);

		//Set in action pointe to next
		pInAction_ = pNextAction_;

		//Create a new next piece
		pNextAction_ = giveNewRandomPiece();

		//Inquire about the impossibility of stepage
		impossibleToStep = moveActiveToPlayField( (*pInAction_) );

		//Reset flag
		pieceHitRockBottom_ = false;

		//Update
		updatePlayField(&container_);

		drawNextPiece(pNextAction_);
	}
	else //MAIN MOVE--which determines if it hits rock bottom
	{
		//WAIT + KEYLOG + CHILDREN MOVE FUNCTIONS
        wait(options_.speedSetting_.forced_drop_pause_);


        //Move and if hit rock bottom, flag to create new
		pieceHitRockBottom_ = moveDown();

	}



	//Return ability to continue step
	return impossibleToStep;


}


/*Description: Clears the field, then updates the matrix that holds where the pieces are
  Assumptions:  The manager and container exist
  Post Condition: The piece has been moved down. If rows were completed, they were destroyed.
      The playing field has been updated.
  Return: A bool representing whether the piece has hit the bottom
*/
bool Manager::moveDown()
{
	bool hitRockBottom = false;

	hitRockBottom = gravity();

	updatePlayField(&container_);

	if(hitRockBottom)
	{
		destroyRowCompletions();
		updatePlayField(&container_);
	}

	//update number of moves
	statistic_.numberOfMoves_++;

	return hitRockBottom;
}



/*

NOTES ABOUT move() ALGORITHM:

The algorithm when it updates will not check to make sure each block doesnt share,
it will simply move a block down until it forsees the spot it wants (downward) is occupied,
then it will return true...meaning it hit rock bottom. The move algorithm will not
complain if the space it wants due to user commands of left and right or flip are
occupied...it will simply deny the user the ability to complete that command.

EXITING CONDITIONS FOR step()
To first understand its exit condition, one must first observe the Piece creation
process. When a piece is created, it is created completley outside of the playing
field, negative integers and such... when step makes its new piece active, it simply
moves that piece down until its totally in the playing field or if it strikes another
piece. If it strikes another piece before it is graciously accepted into the playing
field step bitches a false...which should tell the Game (the class that will eventually
contain this class) that it needs to cessate play .. and inform our player that he failed
miserably..possibly a great instance to hurl some insults and disses in our misfortunate
player's face.


*/

/*Description: Moves the pieces according to which arrow has been pressed
  Assumptions: The correct argument is passed. The waits are long enough that the pieces
     don't move too quickly, but short enough so that the pieces move fast enough to be
     where the user wants them
  Post Condition: The piece has been moved according to the arrows pressed, and the 
      play field has been updated.
  Return: A bool representing whether the piece has hit the bottom
*/
bool Manager::move(int keyLogged)
{
	bool hitRockBottom = false;

	//Keylog--UP--flip()
	if (keyLogged == 1)
	{
		flip();
		justWait(options_.speedSetting_.flip_speed_);
	}
	//Keylog--RIGHT--moveRight()
	if (keyLogged == 2)
	{
		moveRight();
		justWait(options_.speedSetting_.move_horizontal_speed_);
	}
	//Keylog--LEFT-moveLeft()
	if (keyLogged == 3)
	{
		moveLeft();
		justWait(options_.speedSetting_.move_horizontal_speed_);
	}
	//Keylog--DOWNRIGHT-moveLeft()
	if (keyLogged == 5)
	{
		hitRockBottom = gravity();
		moveRight();
		justWait(options_.speedSetting_.move_vertical_speed_);
	}
	//Keylog--DOWNRIGHT-moveLeft()
	if (keyLogged == 6)
	{
		hitRockBottom = gravity();
		moveLeft();
		justWait(options_.speedSetting_.move_vertical_speed_);
	}
	//Keylog--DOWN-moveDown()
	if(keyLogged == 4)
	{
		hitRockBottom = gravity();
		justWait(options_.speedSetting_.move_vertical_speed_);
	}
	//KeyLog--INSTADOWN--moveDown until rock bottom
	if(keyLogged == 7)
	{
		while(!hitRockBottom)
			hitRockBottom = gravity();
		justWait(options_.speedSetting_.move_horizontal_speed_);
	}


	if (keyLogged >=1 && keyLogged <= 6)
	{
		if(options_.disco_mode_)
			colorChangeAllBlocks(1);

	    updatePlayField(&container_);
	    draw();
	}

	//update number of moves
	statistic_.numberOfMoves_++;

	return hitRockBottom;
}

/*Description:Returns the game statistics
  Assumptions: The Manager exists
  Return: Game Statistics
*/
GameStat& Manager::returnGameStat()
{
	return statistic_;
}


/*Description: Creates a new random piece
  Assumptions:  The manager exists
  Post Condition: A new piece of a random type has been created
  Return: A pointer to the created piece
*/
Piece* Manager::giveNewRandomPiece()
{
	Piece* p;
	int randomInteger = rand() % 7;
	switch(randomInteger)
	{
	case 1:
		p = new Z;
		break;
	case 2:
		p = new S;
		break;
	case 3:
		p = new T;
		break;
	case 4:
		p = new L;
		break;
	case 5:
		p = new J;
		break;
	case 6:
		p = new O;
		break;
	default:
		p = new I;
	}

	return p;
}


/*Description: Ends the game
  Assumptions:  The manager and container exist
  Post Condition: "Game Over" is printed to the middle of the playing field.
      The statistics and playing field have been reset, and a new piece is ready
      to move into the field for the next game.
  Return: Void
*/
void Manager::gameOver()
{
	PlaySound("godHatesyou.wav", NULL, SND_FILENAME);


    //Store the coordinates of the middle of the matrix
    int averageX = START_X+(END_X-START_X)/2,
        averageY = START_Y+(END_Y-START_Y)/2;

    //Print "Game Over"
    plotHUD_.setColor(white);
    plotHUD_.move(averageX-4,averageY);
    cout << "GAME OVER" << endl;
    
    plotHUD_.move(2,24);
    system("PAUSE");
    
    container_.deleteContainer();
	
	//Reset Statistics
	statistic_.numberOfMoves_ = 0;
	statistic_.score_ = 0;
	statistic_.numberOfLinesDestroyed_ = 0;  
	  
    //GIVE nInAction_ a piece to handle
	pNextAction_ = giveNewRandomPiece();
	
	pieceHitRockBottom_ = true;
	fillFieldWithEmpty();

	//Reset the speed
	options_.speedLevel_ = 0;
	options_.speedSetting_.handleSpeedSettings(options_.speedLevel_);
    
}



/***************************************************************************************************

DRAW FUNCTIONALITY

***************************************************************************************************/

/*Description: Draws the playing field
  Assumptions:  The manager and playing field exist
  Post Condition: The matrix showing where the pieces are is drawn
  Return: Void
*/
void Manager::draw()
{
	plotPlayField_.draw(playField_);
}


/***************************************************************************************************

TIME FUNCTIONALITY

*****************************************************************************************************/

/*Description: Waits before the piece is dropped. Checks to see if arrows are pressed during that time
  Assumptions: The correct argument is passed. The manager exists
  Post Condition: A certain amount of time has passed. The piece has been moved according to the 
      pressed keys
  Return: Void
*/
void Manager::wait(double seconds)
{
    clock_t endwait;
    endwait = clock () + seconds * CLK_TCK ;
    while (clock() < endwait)
    {
        int keyLogged = 0;
        checkKeyLog(keyLogged);
        move(keyLogged);

    }
}


/*Description: Checks to see if a key has been pressed
  Assumptions: The correct argument is passed. 
  Post Condition: The int passed by reference tells which key has been pressed
  Return: Void
*/
void Manager::checkKeyLog(int &keyLogged)
	{
		if(keyLogged == 0)
		{
			//Keylog--UP
			if (GetKeyState(VK_UP) & 0x80)
				keyLogged = 1;
			//Keylog--RIGHT
			if (GetKeyState(VK_RIGHT) & 0x80)
				keyLogged = 2;
			//Keylog--LEFT
			if (GetKeyState(VK_LEFT) & 0x80)
				keyLogged = 3;
			//Keylog--DOWN-moveDown()
			if (GetKeyState(VK_DOWN) & 0x80)
				keyLogged = 4;
			if ( (GetKeyState(VK_RIGHT) && GetKeyState(VK_DOWN)) & 0x80)
				keyLogged = 5;
			if ( (GetKeyState(VK_LEFT) && GetKeyState(VK_DOWN)) & 0x80)
				keyLogged = 6;
			if( GetKeyState(VK_SPACE) & 0x80 )
				keyLogged = 7;
		}

	}