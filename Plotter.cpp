#include "Plotter.h"
#include <iostream>


using namespace std;

Plotter::Plotter(int x, int y)
{
       startX = x;
       startY = y;

       coordScreen.X = startX;
       coordScreen.Y = startY;

       hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
       SetConsoleTextAttribute(hConsoleOutput, green);

}

void Plotter::setStartPoint(int x,int y)
{
       startX = x;
       startY = y;
}

void Plotter::draw(const Matrix &n)
{
       coordScreen.X = startX;
       coordScreen.Y = startY;
       SetConsoleCursorPosition( hConsoleOutput, coordScreen );

   for(int c = 0 ; c < n.getColumns(); c++)
   {
     for(int r = 0; r < n.getRows(); r++)
     {
       coordScreen.X = c+startX;
       coordScreen.Y = r+startY;

	   SetConsoleTextAttribute(hConsoleOutput, n.getElement(r,c));
	   SetConsoleCursorPosition( hConsoleOutput, coordScreen );
	   cout << SQUARE << endl;
     }

     cout << endl;
   }
}




void Plotter::clear()
{
  cls( hConsoleOutput );
}





void Plotter::cls( HANDLE hConsole )
{
  COORD coordScreen = { startX, startY };    // here's where we'll home the cursor

  DWORD cCharsWritten;
  CONSOLE_SCREEN_BUFFER_INFO csbi; // to get buffer info
  DWORD dwConSize;                 // number of character cells in the current buffer


  // get the number of character cells in the current buffer


  GetConsoleScreenBufferInfo( hConsole, &csbi );
  dwConSize = csbi.dwSize.X * csbi.dwSize.Y;


  // fill the entire screen with blanks


  FillConsoleOutputCharacter( hConsole, (TCHAR) ' ', dwConSize, coordScreen, &cCharsWritten );


  // get the current text attribute


  GetConsoleScreenBufferInfo( hConsole, &csbi );


  // now set the buffer's attributes accordingly


  FillConsoleOutputAttribute( hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten );


  // put the cursor at (0, 0)


  SetConsoleCursorPosition( hConsole, coordScreen );

  return;


}
