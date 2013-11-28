#ifndef JIM_BOB
#define JIM_BOB

#include "Manager.h"

class Tetris
{
	public:

	/////////////////////////////////////////////////////////////////////////////
	
	//TETRIS.CPP
	
	/*Description: Outlines the overall game play
      Assumptions: The tetris game exists. The correct argument has been passed. Score 
          is originally set to zero
      Post Condition: The screen has been set up, the game has been played, and 
          afterwards the game has been reset
      Return: A char representing the users choice
	  */
	void startTetris();

	private:

	Manager manager_;

	/*
	  Description: Outlines the overall game play
      Assumptions: The tetris game exists. The correct argument has been passed. Score 
          is originally set to zero
      Post Condition: The screen has been set up, the game has been played, and 
          afterwards the game has been reset
      Return: A char representing the users choice
    */
	void playGame(int& score, int& speed);
		
	/*Description: Allows the speed to be changed
	Assumptions: The tetris game exists. The correct arguments are passed
	 Post Condition: The speed of the game has been changed
	Return: Void
    */
	void setSpeedOption(const int& speedLevel = 1);

	//Screens
	/*Description: Displays the welcome screen and the user inputs their choice
      Assumptions: The tetris game exists
      Post Condition: The user has inputed their choice of what to do next
      Return: A char representing the users choice
    */
    char welcomeScreen();
	/*Description: The instructions, about, or high score screen is displayed.
      Assumptions: The tetris game exists
      Return: Void
    */
    void instructionScreen();
    void aboutScreen();
    void OptionScreen(int& speed);
    void OptionsGameSpeed(int& speed);


    //////////////////////////////////////////////////////////////////////////////

    //HISCORESTUFF.CPP

    /*Purpose: This function checks to see if the user has earned a high score.
          If the user has earned a high score, then that score replaces the
          lowest high score, and the scores are sorted so that they are in order
          from highest to lowest. The names and scores are then stored in files.
      Data Abstraction: ***********
      Input: Names and scores are read from the overall high score file. If the
          user has received a high score, he or she inputs his name. If not, he
          or she presses enter as a dummy character.
      Process/Implementation: If the binary scores file does not exist, the file
          is created with 10 dummy scores. Names are read from the binary file
          into a HiScore array. If the user's score is lower than the lowest
          high score, his or her name and score replaces the lowest high score.
          The array is then sorted by score using the sortScores function.
      Output: If the file does not exist, "Player" with a score of 0 is written
          into the file 10 times. If the user has earned a high score, a
          congratulatory message is displayed, and the user is prompted to enter
          his or her name. After the HiScore array is sorted, the names and scores
          are re-written into the original high score file (in binary form to
          prevent the file from being easily changed). If the user has not earned
          a high score, "Sorry," is printed, and the user is told to press enter
          to continue.
      Assumptions: The file contains the correct information. Also, the user
          inputs a valid character string for his or her name. */
    void checkForHiScores (int score);

    /*This sorts the Hiscore array by score.
      Data Abstraction: 1 Hiscore struct to temporarily hold the contents of
          another Hiscore struct.
      Input: Function is passed a Hiscore array and the size of the array.
      Process/Implementation: A bubble sort is used through nested for loops.
          If the score of the Hiscore struct in one element is greater than the
          score of the Hiscore struct in the other, the Hiscore structs switch
          places in the array. This continues until all elements have been
          sorted.
      Assumptions: The correct data types are passed. */
    void sortScores (HiScore array[], int size);

	/*Description:This sorts the Hiscore array by score.
      Assumptions: The correct data types are passed.
      Post Condition: The structs in the array have been sorted by score
      Return: Void
    */
    void newHighScoreFile();

	/*Description: Creates a new high score file
      Assumptions: The Tetris game exists. 
      Post Condition: A file with dummy scores has been created
      Return: Void
    */
    void highScoreScreen();
};


#endif