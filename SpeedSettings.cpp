//Defines the functions layed out in the Speed Settings struct in the HeaderStuff.h

#include "headerstuff.h" 

/*

THE IMPLEMENTATIONS FOR THE STRUCT SPEEDSETTINGS

*/

/*
Description:	PieceSetting Constructor
Assumption	:	nada
Postcondition:	Sets basic movement speed
				values that correspond with
				keys
*/
SpeedSettings::SpeedSettings()
{
	forced_drop_pause_ = .50;
	move_horizontal_speed_ = .1;
	move_vertical_speed_ = .010;
	flip_speed_ = .25;
}

/*
Description:	passes a value and resets the
				forced drop value time
Assumption	:	nada
Postcondition:	value is set accordingly with
				its internal switch statement
*/
void SpeedSettings::handleSpeedSettings(const int& speedLevel)
{
	forced_drop_pause_ = .50;
	move_horizontal_speed_ = .1;
	move_vertical_speed_ = .010;
	flip_speed_ = .25;
	
	//The higher the number picked, the more speed up it calls to
	//preset the speed
	switch(speedLevel)
	{
	default:
		speedUp();
	case 8:
		speedUp();
	case 7:
		speedUp();
	case 6:
		speedUp();
	case 5:
		speedUp();
	case 4:
		speedUp();
	case 3:
		speedUp();
	case 2:
		speedUp();
	case 1:
		speedUp();
	case 0:
		break;
	}
	//I dont want breaks
}

/*
Description:	A method used to speed up the speed variables
Implementation: multiplying each member variable of speed settings
				by a multiplier
Purpose:		A robust way to edit the multiplier
*/
void SpeedSettings::speedUp()
{
	forced_drop_pause_ *= .8;
	move_horizontal_speed_ *= .9;
	move_vertical_speed_ *= .85;
	flip_speed_ *= .95;
}