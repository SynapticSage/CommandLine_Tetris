/*  Created: April 14, 2007
    Due: April 24, 2007
    Last Modified: April 14, 2007 by Jennifer
    What was changed: Created.
*/

#ifndef _FUNCTION_PROTOTYPES_
#define _FUNCTION_PROTOTYPES_

using namespace std;


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


void newHighScoreFile();
void highScoreScreen();

#endif // _FUNCTION_PROTOTYPES_
