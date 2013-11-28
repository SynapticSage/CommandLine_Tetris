#include <iostream>
#include <fstream>
using namespace std;
#include "PlotterTetris.h"
#include "headerstuff.h"
#include "Tetris.h"

// Prints the game's welcome screen and menu choices
char Tetris::welcomeScreen()
{
	SetConsoleTitle ( "Hola, me llama Tetris. Yo soy un juego." );

    PlotterTetris p;
    char menu = '0';

    p.clear();

    do
    {

        p.setColor(white);
        p.move(11,1);
        cout << "==============================================================="<<endl;
        p.move(11,23);
        cout << "==============================================================="<<endl;
        p.setColor(red);
        p.move(13,2);  cout << " ________"  <<endl;
        p.move(13,3);  cout << "|__|__|__|" <<endl;
        p.move(13,4);  cout << "   |__|   " <<endl;
        p.move(13,5);  cout << "   |__|   " <<endl;
        p.move(13,6);  cout << "   |__|   " <<endl;
        p.move(13,7);  cout << "   |__|   " <<endl;

        p.setColor(green);
        p.move(23,2); cout << " _______ " <<endl;
        p.move(23,3); cout << "|  |____|" <<endl;
        p.move(23,4); cout << "|__|___  " <<endl;
        p.move(23,5); cout << "|__|___| " <<endl;
        p.move(23,6); cout << "|  |____" <<endl;
        p.move(23,7); cout << "|__|____|"<<endl;


        p.setColor(blue);
        p.move(33,2);  cout << " ________"  <<endl;
        p.move(33,3);  cout << "|__|__|__|" <<endl;
        p.move(33,4);  cout << "   |__|   " <<endl;
        p.move(33,5);  cout << "   |__|   " <<endl;
        p.move(33,6);  cout << "   |__|   " <<endl;
        p.move(33,7);  cout << "   |__|   " <<endl;


       p.setColor(yellow);
       p.move(43,2);  cout << " ______ "   <<endl;
       p.move(43,3);  cout << "|_ ____|" <<endl;
       p.move(43,4);  cout << "|_|__|_|" <<endl;
       p.move(43,5);  cout << "|__ __ /"<<endl;
       p.move(43,6);  cout << "|__|\\__\\" <<endl;
       p.move(43,7);  cout << "|__| \\__|"<<endl;

       p.setColor(cyan);
       p.move(53,2); cout << " __ " <<endl;
       p.move(53,3); cout << "|__|" <<endl;
       p.move(53,4); cout << "|__|" <<endl;
       p.move(53,5); cout << "|__|" <<endl;
       p.move(53,6); cout << "|__|" <<endl;
       p.move(53,7); cout << "|__|" <<endl;

       p.setColor(magenta);
       p.move(59,2); cout <<" _______ " <<endl;
       p.move(59,3); cout <<"|__ _|__|" <<endl;
       p.move(59,4); cout <<"|__|____ " <<endl;
       p.move(59,5); cout <<"|_______|" <<endl;
       p.move(59,6); cout <<" ___|___|" <<endl;
       p.move(59,7); cout <<"|_____|_|" <<endl;
	   p.move(59,10); cout << "VERSION 2.0" <<endl;

       p.setColor(darkred);
       p.move(19,9);
       cout << "1. Play Game" <<endl;
       p.setColor(darkgreen);
       p.move(19,11);
       cout << "2. Options" <<endl;
       p.setColor(darkblue);
       p.move(19,13);
       cout << "3. Instructions" <<endl;
       p.setColor(darkyellow);
       p.move(19,15);
       cout << "4. High Scores" <<endl;
       p.setColor(blue);
       p.move(19,17);
       cout << "5. About" <<endl;
       p.setColor(darkcyan);
       p.move(19,19);
       cout << "6. Exit" <<endl;


       p.setColor(purple);
       p.move(33,21);
	   cout << "<<Enter Choice>>: ";
	   cin.clear();
       cin  >> menu;
	   if(cin.peek() != '\n')
		   menu = '7';
	   cin.ignore(INT_MAX, '\n');

        if (menu != '1' && menu != '2' && menu != '3' &&
            menu != '4' && menu != '5' && menu != '6' )
        {
            p.setColor(white);
            p.move(3,24);
            cout << "IVALID ENTRY! TRY AGAIN DUMMY." <<endl <<endl;
            p.move(3,26);
            system("PAUSE");
        }

        p.clear();

    } while (menu != '1' && menu != '2' && menu != '3' &&
             menu != '4' && menu != '5' && menu != '6' );

    return menu;
}

void Tetris::aboutScreen()
{
   PlotterTetris p;
   p.clear();
   p.setColor(white);
   p.move(13,2); cout << "====================================================="<<endl;
   p.move(13,11); cout << "====================================================="<<endl;

   p.setColor(cyan);
   p.move(15,4); cout << " ______  " << endl;
   p.move(15,5); cout << "|      | " << endl;
   p.move(15,6); cout << "|      | " << endl;
   p.move(15,7); cout << "|  __  | " << endl;
   p.move(15,8); cout << "| |  | | " << endl;
   p.move(15,9); cout << "|_|  |_| " << endl;

   p.setColor(red);
   p.move(25,4); cout << " ______  " << endl;
   p.move(25,5); cout << "|      | " << endl;
   p.move(25,6); cout << "|      | " << endl;
   p.move(25,7); cout << "|     <  " << endl;
   p.move(25,8); cout << "|      | " << endl;
   p.move(25,9); cout << "|______| " << endl;

   p.setColor(green);
   p.move(35,4); cout << " ______  " << endl;
   p.move(35,5); cout << "|      | " << endl;
   p.move(35,6); cout << "|      | " << endl;
   p.move(35,7); cout << "|      | " << endl;
   p.move(35,8); cout << "|      | " << endl;
   p.move(35,9); cout << "|______| " << endl;

   p.setColor(magenta);
   p.move(45,4); cout << " _    _  " << endl;
   p.move(45,5); cout << "| |  | | " << endl;
   p.move(45,6); cout << "| |  | | " << endl;
   p.move(45,7); cout << "| |  | | " << endl;
   p.move(45,8); cout << "| |__| | " << endl;
   p.move(45,9); cout << "|______| " << endl;

   p.setColor(yellow);
   p.move(55,4); cout << " _______  " << endl;
   p.move(55,5); cout << "|__   __| " << endl;
   p.move(55,6); cout << "   | |    " << endl;
   p.move(55,7); cout << "   | |    " << endl;
   p.move(55,8); cout << "   | |    " << endl;
   p.move(55,9); cout << "   |_|    " << endl;

   p.setColor(cyan);
   p.move(15,13); cout << "Tetris Project Created By... " << endl;
   p.setColor(red);
   p.move(15,14); cout << "Caleb Hidalgo   "  << endl;
   p.setColor(green);
   p.move(15,15); cout << "John Nichols    "  << endl;
   p.setColor(magenta);
   p.move(15,16); cout << "Jennifer Shimada"  << endl;
   p.setColor(yellow);
   p.move(15,17); cout << "Ryan Young      "  << endl;
   p.setColor(darkcyan);

   p.move(58,14); cout << "Booth " << endl;
   p.move(52,15); cout << "CSI 1440 01" << endl;
   p.move(54,16); cout << "4/25/2007" << endl;

   cout<<endl<<endl<<endl;

    p.move(5,22);
    system("PAUSE");

}

void Tetris::instructionScreen()
{
   PlotterTetris p;

   p.setColor(white);
   cout<<endl;
   cout << "============================================================"<<
          "======="<<endl<<endl;

   p.setColor(cyan);
   cout<< "Instructions:" <<endl<<endl;
   p.setColor(red);
   cout<<endl<< "Gameplay: "<<endl<<endl;  p.setColor(lightgrey);
         cout<< "   As tetronimoes of different permutations fall from the"    <<
         endl<<"the top of the screen into a playing area, the player must" <<
         endl<<"use three movements (left,right,rotate) to move the piece." <<
         endl<<"The object is to form a solid horizontal line by arranging" <<
         endl<<"the pieces. This will remove that line from screen allowing for" <<
         endl<<"space for more pieces to fall. The game is lost when there"  <<
         endl<<"more is no longer room for more pieces to fall"<<endl ;

   p.setColor(green);
   cout<<endl<< "Controls: "<<endl<<endl; p.setColor(lightgrey);
            cout<< "   Use the up arrow key to rotate the the tetris pieces." <<
            endl<< "Use the left and right arrow keys to move the piece side" <<
            endl<< "to side. Pressing the down arrow increases the speed that"<<
            endl<< "the peice moves down on the screen. Space bar will force "<<
			endl<< "your piece to instadrop to the bottom of the screen." ;

   cout << endl << endl; p.setColor(white);
   cout << "============================================================"<<
          "=======" <<endl<<endl;

    p.move(0,24);
    system("PAUSE");
}


void Tetris::highScoreScreen()
{
    PlotterTetris screen;
    ifstream inData;
    HiScore temp[10];

    screen.clear();


    //Print Screen Title
    screen.setColor(lightgrey);
    screen.move(30, 5);
    cout << "Overall High Scores:" <<endl;;

    //Open high scores file
	inData.open("GameData.dat", ios::binary);

    //If the file does not exist, create it
    if (!inData)
    {
        inData.close();
        inData.clear();
        
        newHighScoreFile();

        inData.open("GameData.dat", ios::binary);

        if (!inData) //File still doesn't open
        {
            throw FILE_ERROR();
        }
    }

    //Read in names and scores from overall scores file
    for (int n=0; n<10; n++)
    {
        inData.read(reinterpret_cast<char*>(&temp[n].nameLength),
                    sizeof(temp[n].nameLength));
        inData.read(temp[n].name, temp[n].nameLength);
        inData.read(reinterpret_cast<char*>(&temp[n].score),
                    sizeof(temp[n].score));
    }

    inData.close();
    inData.clear();

    //Display names and scores to screen
    for(int i = 0; i < 10; i++)
    {
        screen.setColor(lightgrey);
        screen.move(20,(7 + i));
        for (int n = 0; n<temp[i].nameLength; n++)
        {
            cout << temp[i].name[n];
        }

        cout << endl;
        screen.move(51,(7 + i));
        cout << temp[i].score <<endl;
    }

    screen.move(20, 21);
    system("PAUSE");

    inData.close();
}


void Tetris::OptionScreen(int& speed)
{
	static int numOfWrongAnswers = 0;

	 PlotterTetris p;
	 char choose;
     p.clear();
     p.setColor(white); 
     p.move(26,4);
     cout <<"==============================" <<endl;
     p.move(26,16);
     cout <<"==============================" <<endl;
     p.setColor(green);
     p.move(28,6);
	 cout << "Game Options (Hint: Dont Give me Wrong Numbers...)" << endl;
     p.move(28,9);
     p.setColor(cyan);
     cout << "1. Game Speed        " << endl;
     p.move(28,10);
     cout << "2. Disco Mode (ON/OFF)"  << endl;
	 p.move(28,11);
	 cout << "3. Turn (OFF/ON) Color Change" << endl;
	 p.move(28,12);
	 cout << "   On Speed Increase";
	 p.move(28,13);
	 cout << "4. Exit Options" << endl;
     p.move(28,15);
	 cout << "Enter Choice:  ";
     cin.clear();
	 cin >> choose;
     
     if(choose == '1')
     {
     	OptionsGameSpeed(speed);
     }
     else if(choose == '2')
     {
     	manager_.options_.disco_mode_ = !manager_.options_.disco_mode_;
     }
	 else if(choose == '3')
	 {
		 manager_.options_.colorChangeOnDelete_ = !manager_.options_.colorChangeOnDelete_;
	 }
	 else if(choose == '4')
	 {
		 welcomeScreen();
	 }
	 else
     {
		p.setColor(red);
     	p.move(30,14);
		if(numOfWrongAnswers < 3)
		{
     		cout << "INVALID INPUT!  TRY AGAIN DUMMY."  << endl;
		}
		else
			cout << "YOU'RE AN IDIOT. PLEASE. GO DIE.";

		numOfWrongAnswers++;
     	
		p.move(30,17);
     	system("pause");
     	
		OptionScreen(speed);
     }
     
}

void Tetris::OptionsGameSpeed(int& speed)
{
     PlotterTetris p;
	 p.clear();
     p.setColor(blue);
     p.move(30,5);
     p.move(30,6);
     cout << "Game Speed Value?  (0 - 9)";
	 cin.clear();
     cin  >> speed;
     if(speed >= 0 && speed <= 9)
     {
     	setSpeedOption(speed);
     	OptionScreen(speed);
     }
     else
     {
     	p.move(30,10);
     	cout << "Invalid Input!  Try again."  << endl;
     	p.move(30,11);
     	system("pause");
     	OptionsGameSpeed(speed);
     }
}

