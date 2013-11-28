#ifndef PLOOTER_Tetris_H_
#define PLOOTER_Tetris_H_
#define _WIN32_WINNT 0x0501


#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

const double ROUND_FACTOR = 0.05;

#ifndef _INK_COLOR_
#define _INK_COLOR_
enum ink
{
	        black   = 0x00, darkblue = 0x01, darkgreen  = 0x02, darkcyan  = 0x03,
            darkred = 0x04, purple   = 0x05, darkyellow = 0x06, lightgrey = 0x07,
		    grey    = 0x08, blue     = 0x09, green      = 0x0A, cyan      = 0x0B,
		    red     = 0x0C, magenta  = 0x0D, yellow     = 0x0E, white     = 0x0F
};
#endif //_INK_COLOR_


class PlotterTetris
{
    protected:
       COORD                coordScreen;
       HANDLE               hConsoleOutput;
	   SMALL_RECT*          lpConsoleWindow;
       COORD*               lpNewScreenBufferDimensions;
       CONSOLE_CURSOR_INFO* lpConsoleCursorInfo;
       ink                  color;

       void cls( HANDLE hConsole );

    public:
       PlotterTetris();
       void clear();
       void setColor(ink i);
       void move(int,int);
	   void plot(char);
	   void playMusic(string s){PlaySound(s.c_str(),NULL,SND_FILENAME|SND_ASYNC);}
};



#endif /*PLOOTER_Tetris_H_*/
