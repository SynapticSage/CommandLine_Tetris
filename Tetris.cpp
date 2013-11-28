#include "Tetris.h"
#include "Manager.h"


void Tetris::playGame(int& score, int& speed)
{
		//Set up music
	    sndPlaySound("next.wav", NULL);
		if(manager_.options_.disco_mode_)
			PlaySound("bitdust2.wav", NULL, SND_FILENAME|SND_ASYNC|SND_NOSTOP|SND_LOOP);
		else
			PlaySound("music_game.wav", NULL, SND_FILENAME|SND_ASYNC|SND_NOSTOP|SND_LOOP);

		//Set up the screen
        manager_.setUpScreen();
		manager_.readySetGo();

		bool endGame = false;

		//Setup game
		setSpeedOption(speed);

		//Guts of Game
		while(!endGame)
		{
			endGame = manager_.step();
            manager_.draw();
		}
		
		//Store the score
        score = manager_.returnGameStat().score_;

	
		manager_.gameOver();

		//char dummy;
		//cin.get(dummy);
}

void Tetris::startTetris()
{

    char choice;
    bool play = true;
	bool titleScreenMusicPlaying = false;
    int speed = 0;
    while(play)
    {

		//SetUpMusic
		if(!titleScreenMusicPlaying)
		{
			PlaySound("music_title.wav", NULL,SND_FILENAME|SND_ASYNC);
			titleScreenMusicPlaying = true;
		}

        choice = welcomeScreen(); //User's choice entered in welcome screen
                                  //function is returned and stored in choice.

        if (choice == '1') //Play the game
        {
            int score = 0;
            
            playGame(score,speed);

            checkForHiScores(score);

            highScoreScreen(); // View overall high scores
			
			//Reset the title music to play after a round of game
			titleScreenMusicPlaying = false;
        }
        else if(choice == '2') //Options
        {
            OptionScreen(speed);
        }
        else if(choice == '3') //View Instructions ("How to Play")
        {
            instructionScreen();
        }
        else if (choice == '4') //View Overall High Scores
        {
            highScoreScreen();
        }
        else if (choice == '5') //About
        {
            aboutScreen();
        }
        else //if (choice == '6') - Exit
        {
            play = false;
			sndPlaySound("next.wav", NULL);
			PlaySound("cupOfTea.wav", NULL, SND_FILENAME|SND_ASYNC|SND_NOSTOP|SND_LOOP);
            aboutScreen();  // View the "about this program" screen
        }
    }

}
void Tetris::setSpeedOption(const int& speedLevel)
{
	manager_.setSpeed(speedLevel);
}