/*

IMPLEMENTATIONS FOR OBJECT STRUCT

*/

#include "headerstuff.h"

Options::Options(int numLinesSpeedUp, bool colorChangeOnDelete)
{
	speedLevel_ = 0;
	numLinesSpeedUp_ = numLinesSpeedUp;
	colorChangeOnDelete_ = colorChangeOnDelete;
	disco_mode_ = false;
}