#ifndef _PLOTTER
#define _PLOTTER

#include <windows.h>
#include "Matrix.h"

const char SQUARE = -79;

#ifndef _INK_COLOR_
#define _INK_COLOR_
enum ink
{
	        black   = 0x00, darkblue = 0x01, darkgreen  = 0x02, darkcyan  = 0x03,
            darkred = 0x04, purple   = 0x05, darkyellow = 0x06, lightgrey = 0x07,
		    grey    = 0x08, blue     = 0x09, green      = 0x0A, cyan      = 0x0B,
		    red     = 0x0C, magenta  = 0x0D, yellow     = 0x0E, white     = 0x0F
};
#endif

class Plotter
{
    protected:
       COORD  coordScreen;
       HANDLE hConsoleOutput;
       char   dummy;
       void cls( HANDLE hConsole );
       int startX;
       int startY;
    public:
       Plotter(int x = 0, int y = 0);
       void clear();
       void setStartPoint(int x,int y);
       void draw(const Matrix&);
};




#endif


