#ifndef JIM_BOB
#define JIM_BOB

#include "Manager.h"

class Tetris
{
	public:

	Tetris(int speedMode)
	{
		//Bounds Checking
		if(numOfMovesAllowed > 10)
			numOfMovesAllowed = 10;

		//Set speed
		
	}

	void startTetris()
	{
		manager_.setUpScreen();
		//manager_.readySetGo();

		int keyLogged = 0;
		int numMoves = 0;
		bool endGame = false;

		//Guts of Game
		while(!endGame)
		{
			endGame = manager_.step();
            manager_.draw();

			//Reset numMoves taken
			numMoves = 0;
		}

		manager_.gameOver();

		char dummy;
		cin.get(dummy);


	}

	private:

	Manager manager_;
	int numOfMovesAllowed_;
};

#endif