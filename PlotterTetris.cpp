#include "PlotterTetris.h"
#define _WIN32_WINNT 0x0501

void PlotterTetris::plot(char object)
{
	   cout  << object;
	   cout.flush();
}

void PlotterTetris::move(int x, int y)
{
       coordScreen.X = x;
       coordScreen.Y = y;
       SetConsoleTextAttribute(hConsoleOutput, color);
	   SetConsoleCursorPosition( hConsoleOutput, coordScreen );
}

void PlotterTetris::clear()
{
  cls( hConsoleOutput );
}

void PlotterTetris::setColor(ink i)
{
	color = i;
	SetConsoleTextAttribute(hConsoleOutput, color);
}

PlotterTetris::PlotterTetris()
{
	//Sets struct that deals with cursor on screen to zero and base color white
	color  = white;
	coordScreen.X = 0;
	coordScreen.Y = 0;

	//Set screen dimensions
	lpConsoleWindow = new SMALL_RECT;
	/*lpConsoleWindow->Bottom = 0;
	lpConsoleWindow->Left = 0;
	lpConsoleWindow->Right = 0;
	lpConsoleWindow->Top = 0;*/

	cout << "lpConsoleWindow->Top = " << lpConsoleWindow->Top<< endl;

	cout << "THE ADRESS OF lpConsoleWindow: " <<hex << lpConsoleWindow << endl;
	lpConsoleWindow->Right = 60;
	lpConsoleWindow->Top = 10;

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleOutput, color);
	if(!SetConsoleWindowInfo(hConsoleOutput,false,lpConsoleWindow))
		cout <<  "ERROR";

	//SEtup font
//	SetCurrentConsoleFontEx(hConsoleOutput, TRUE, FF_DECORATIVE);
	
	system("pause");
}

void PlotterTetris::cls( HANDLE hConsole )
{
  COORD coordScreen = { 0, 0 };


  DWORD cCharsWritten;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD dwConSize;

  GetConsoleScreenBufferInfo( hConsole, &csbi );
  dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
  FillConsoleOutputCharacter( hConsole, (TCHAR) ' ', dwConSize, coordScreen, &cCharsWritten );
  GetConsoleScreenBufferInfo( hConsole, &csbi );
  FillConsoleOutputAttribute( hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten );
  SetConsoleCursorPosition( hConsole, coordScreen );

  return;
}