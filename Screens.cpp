#include "PlotterTetris.h"
#include "Matrix.h"
#include "Plotter.h"
#include "Manager.h"
#include "Pieces.h"
#include <ctime>

/*Description: Prints "Ready Set Go" to the screen 
  Assumptions: The Manager exists
  Post Condition: Ready Set Go has been printed in the middle of the playing field
  Return: Void
*/
void Manager::readySetGo()
{
    //Store the coordinates of the middle of the matrix
    int averageX = START_X+(END_X-START_X)/2,
        averageY = START_Y+(END_Y-START_Y)/2;

    //Print Ready Set Go in white, wait, then "erase" it
    plotHUD_.setColor(white);
    plotHUD_.move(averageX-2,averageY);
    cout << "READY" << endl;
    justWait(1);

    plotHUD_.setColor(black);
    plotHUD_.move(averageX-2,averageY);
    cout << "READY" << endl;

    plotHUD_.setColor(white);
    plotHUD_.move(averageX-1,averageY);
    cout << "SET" << endl;
    justWait(1);

    plotHUD_.setColor(black);
    plotHUD_.move(averageX-1,averageY);
    cout << "SET" << endl;

    plotHUD_.setColor(white);
    plotHUD_.move(averageX-1,averageY);
    cout << "GO!" << endl;
    justWait(1);

    plotHUD_.setColor(black);
    plotHUD_.move(averageX-1,averageY);
    cout << "GO!" << endl;
}

/*Description: Sets up the screen
  Assumptions: The Manager exists
  Post Condition: Prints the lines cleared, score, and the next piece box
  Return: Void
*/
void Manager::setUpScreen()
{

    //Print score, lines cleared, and the outline for the next piece box
    plotHUD_.setColor(green);
    int x = FIELD_SIZE_X + 40;
    int y = 7;
    plotHUD_.move(x,y);
    cout << "Score: 0" << endl;
    plotHUD_.move(x,y+1);
    cout << "Lines Cleared: 0" <<endl;;
	plotHUD_.move(x,y+2);
	cout<< "Level Of Play: " << options_.speedLevel_ << endl;

    int x2 = x;
    int y2 = y+3;
    plotHUD_.move(x2,y2);
    cout << "Next Piece:"  << endl;
    plotHUD_.move(x2+2,y2+1);
    cout << " _________"  << endl;
    plotHUD_.move(x2+2,y2+2);
    cout << "|         |"  << endl;
    plotHUD_.move(x2+2,y2+3);
    cout << "|         |"  << endl;
    plotHUD_.move(x2+2,y2+4);
    cout << "|         |"  << endl;
    plotHUD_.move(x2+2,y2+5);
    cout << "|         |"  << endl;
    plotHUD_.move(x2+2,y2+6);
    cout << "|         |"  << endl;
    plotHUD_.move(x2+2,y2+7);
    cout << "|_________|"  << endl;


    drawOutline(START_X-1,END_X,START_Y-1,END_Y);

    drawTetrisLarge(5, 0);
}

/*Description: Draws Tetris
  Assumptions: The Manager exists
  Post Condition: Tetris is drawn on the sides of the matrix
  Return: Void
*/
void Manager::drawTetrisLarge(int x, int y)
{

    //Draw "Tetris" on the side of the Game
    plotHUD_.setColor(yellow);
    int x3 = x;
    int y3 = y+1;
    plotHUD_.move(x3,y3);
    cout << " _____"  << endl;
    plotHUD_.move(x3,y3+1);
    cout << "|_|_|_|"  << endl;
    plotHUD_.move(x3,y3+2);
    cout << "  |_|"  << endl;
    plotHUD_.move(x3,y3+3);
    cout << "  |_|" << endl;
    plotHUD_.move(x3,y3+4);
    cout << "  |_|" << endl;

    int x4 = x3;
    int y4 = y3+7;
    plotHUD_.move(x4,y4);
    cout << " _____" << endl;
    plotHUD_.move(x4,y4+1);
    cout << "|_|_|_|" << endl;
    plotHUD_.move(x4,y4+2);
    cout << "|_|_" << endl;
    plotHUD_.move(x4,y4+3);
    cout << "|_|_|" << endl;
    plotHUD_.move(x4,y4+4);
    cout << "|_|_ _" << endl;
    plotHUD_.move(x4,y4+5);
    cout << "|_|_|_|" << endl;

    int x5 = x3;
    int y5 = y4+8;
    plotHUD_.move(x5,y5);
    cout << " _____" << endl;
    plotHUD_.move(x5,y5+1);
    cout << "|_|_|_|" << endl;
    plotHUD_.move(x5,y5+2);
    cout << "  |_|" << endl;
    plotHUD_.move(x5,y5+3);
    cout << "  |_|" << endl;
    plotHUD_.move(x5,y5+4);
    cout << "  |_|" << endl;

	//CHANGE MADE HERE TO ACCOMODATE A CHANGING FIELD SIZE!!!
    int x6 = x+42+ X_ADJUSTMENT_FACTOR;
    int y6 = y;
    plotHUD_.move(x6,y6);
    cout << " _ _ " << endl;
    plotHUD_.move(x6,y6+1);
    cout << "|_|_|_" << endl;
    plotHUD_.move(x6,y6+2);
    cout << "|_| |_|" << endl;
    plotHUD_.move(x6,y6+3);
    cout << "|_|_|_|" << endl;
    plotHUD_.move(x6,y6+4);
    cout << "|_|_|_" << endl;
    plotHUD_.move(x6,y6+5);
    cout << "|_| |_|" << endl;
    plotHUD_.move(x6,y6+6);
    cout << "|_| |_|" << endl;

    int x7 = x6;
    int y7 = y6+8;
    plotHUD_.move(x7,y7);
    cout << " _____" << endl;
    plotHUD_.move(x7,y7+1);
    cout << "|_|_|_|" << endl;
    plotHUD_.move(x7,y7+2);
    cout << "  |_|" << endl;
    plotHUD_.move(x7,y7+3);
    cout << "  |_|" << endl;
    plotHUD_.move(x7,y7+4);
    cout << " _|_|_" << endl;
    plotHUD_.move(x7,y7+5);
    cout << "|_|_|_|" << endl;

    int x8 = x6;
    int y8 = y7+7;
    plotHUD_.move(x8,y8);
    cout << " _ _ _" << endl;
    plotHUD_.move(x8,y8+1);
    cout << "|_|_|_|" << endl;
    plotHUD_.move(x8,y8+2);
    cout << "|_|" << endl;
    plotHUD_.move(x8,y8+3);
    cout << "|_|_ _" << endl;
    plotHUD_.move(x8,y8+4);
    cout << "|_|_|_|" << endl;
    plotHUD_.move(x8,y8+5);
    cout << "    |_|" << endl;
    plotHUD_.move(x8,y8+6);
    cout << " _ _|_|" << endl;
    plotHUD_.move(x8,y8+7);
    cout << "|_|_|_|" << endl;
}

/*Description: Draws the outline of the playing field
  Assumptions: The Manager exists
  Post Condition: Draws the outline of the playing field
  Return: Void
*/
void Manager::drawOutline (int xStart, int xEnd, int yStart, int yEnd)
{

    plotHUD_.setColor(blue);

    //Draw left outline
    for (int i = 0; i <= xEnd-xStart; i++)
    {
        plotHUD_.move(xStart+i,yStart);
        cout << BLOCK << endl;
    }

    //Draw top outline
    for (int i = 0; i <= yEnd-yStart; i++)
    {
        plotHUD_.move(xStart,yStart+i);
        cout << BLOCK << endl;
    }

    //Draw bottom outline
    for (int i = 0; i <= yEnd-yStart; i++)
    {
        plotHUD_.move(xEnd,yStart+i);
        cout << BLOCK << endl;
    }

    //Draw right outline
    for (int i = 0; i <= xEnd-xStart; i++)
    {
        plotHUD_.move(xStart+i,yEnd);
        cout << BLOCK << endl;
    }
}

/*Description: Waits for a certain amount of time
  Assumptions: The Manager exists
  Post Condition: A certain amount of time has passed
  Return: Void
*/
void Manager::justWait(double seconds)
{
    clock_t endwait;
    endwait = clock () + seconds * CLK_TCK ;
    while (clock() < endwait){}
}
