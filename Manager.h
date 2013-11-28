#ifndef TETRIS_GAME_MANAGER
#define TETRIS_GAME_MANAGER

//INCLUSIONS
#include "PiecesContainer.h"
#include "Plotter.h"
#include "PlotterTetris.h"



class Manager
{

public:

	Manager();

	/*****Basic Game Functionality*****/
	bool step();
	void draw();
	bool move(int);
	void setSpeed(const int& amount)
	{
			options_.speedLevel_ = amount;
			options_.speedSetting_.handleSpeedSettings(amount);
	}


	/*****Used to Communicate with Game.h*******/
	GameStat& returnGameStat();

	//Set up screen functions
	void setUpScreen();
		void readySetGo();
		void drawTetrisLarge(int x, int y);
		void justWait(double seconds);
		void drawOutline (int xStart, int xEnd, int yStart, int yEnd);
	void gameOver();

	
	/******Game Options(see HeaderStuff.h)******/ //(It's here so game can mess with it, but not user)
	Options options_;

private:

	/********The Guts*********/
	PlotterTetris plotHUD_;
	Plotter plotPlayField_, plotNext_;
	Matrix playField_, nextPiece_;
		//Pieces Contained for Game
		PiecesContainer container_;

	/******The Pieces Immediatley concerned with the Game*****/
	Piece* pInAction_, *pNextAction_;

	/*******Flags**********/
	bool pieceHitRockBottom_;

	bool moveDown();
	
	/******Game Statistics(see HeaderStuff.h)******/
	GameStat statistic_;
	void updateScore(int);

	/*******Private Helper Functions******/

		//used in step() --instantiating new piece
		Piece* giveNewRandomPiece();
		//used in step() --move active piece into playField or impossible
		bool moveActiveToPlayField(Piece &p);

	/*Piece Fuctions for Move()*/
		void flip();
		void moveRight();
		void moveLeft();
		bool gravity();

	/*playField handling functions*/
		void updatePlayField(PiecesContainer*);
		void displayDeletionRows(void);
			void displayDeletionUpdatePlayField(PiecesContainer*);
		void fillFieldWithEmpty(void);
		void destroyRowCompletions(void);
			void checkAllOfContainerToRowDelete( PiecesContainer&, const int );
			void movePiecesDown (PiecesContainer&, const int);
		void checkThatFieldEmpty();

		void drawNextPiece (Piece*);
		void colorChangeAllBlocks(int amount = 1);

	/*Helper Function for Move Actions in General*/
	bool isAPartOfActive(int, int);

	/*Tme Helper Function*/
	void wait( double);

	/*KeyLogging Helper*/
	void checkKeyLog( int& );


};

#endif
