//Created: April 14, 2007
//Due: April 25, 2007
//Last Modified: April 24, 2007 by Jennifer
//What was changed:

/*Need: Include way to catch FILE_ERROR()
*/

#include <iostream>
#include "plotterTetris.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include "Tetris.h"

using namespace std;



void Tetris::checkForHiScores (int score)
{
    PlotterTetris plot;

    char name[30];
    int length;
    HiScore overall[10]; //Holds overall high score data

    ifstream inData;
    ofstream outData;

    //Opens the file in binary
    inData.open("GameData.dat", ios::binary);

    //If the file doesn't exist
    if (!inData)
    {
        inData.close();
        inData.clear();

        //Create a new high score file
        newHighScoreFile();

        //Open the new file
		inData.open("GameData.dat", ios::binary);

        //File still doesn't open
        if (!inData)
        {
            throw FILE_ERROR();
        }
    }

    //Read in names and scores from overall scores file
    for (int n=0; n<10; n++)
    {
        inData.read(reinterpret_cast<char*>(&overall[n].nameLength),
                    sizeof(overall[n].nameLength));
        inData.read(overall[n].name, overall[n].nameLength);
        inData.read(reinterpret_cast<char*>(&overall[n].score),
                    sizeof(overall[n].score));
    }

    inData.close();
    inData.clear();

    if (score > overall[9].score) //User's score > lowest overall high score
    {
        plot.clear();
        plot.move(16, 11);
        cout << "Congratulations! You have earned a high score."<< endl;
        plot.move(16,12);
        cout << "Please enter your name: ";

        cin.getline(name,30);

        //Score replaces lowest overall score
        overall[9].score = score;
        strcpy(overall[9].name,name);
        overall[9].nameLength = strlen(name);

        //Sort the scores
        sortScores (overall, 10);

        //Write the scores back into the file
        outData.open("GameData.dat", ios::binary);

        for (int r = 0; r<10; r++)
        {
            outData.write(reinterpret_cast<char*>(&overall[r].nameLength),
                          sizeof(overall[r].nameLength));
            outData.write(overall[r].name, overall[r].nameLength);
            outData.write(reinterpret_cast<char*>(&overall[r].score),
                          sizeof(overall[r].score));
        }

        outData.close();
        outData.clear();
    }
    else //User did not receive a high score
    {
        plot.clear();
        plot.move(13, 11);
        cout << "Sorry, you did not earn a high score. Please try again." << endl;
        plot.move(2, 23);
        cout << "Press ENTER to Continue." << endl;

        // The following char is created and entered to stop this function's
        //window from abruptly closing after the function is done
        char dummy;
        cin.get(dummy);
    }
}

void Tetris::sortScores (HiScore array[], int size)
{

    for (int n=0; n<size-1; n++)
    {
        for (int i=0;i<size-n-1; i++)
        {
            if (array[i].score < array[i+1].score)
            {
                swap(array[i],array[i+1]);
            }
        }
    }
}

void Tetris::newHighScoreFile()
{
    ofstream outData;
    HiScore newFile[10];

    //Create the file, opening it in binary form
	outData.open("GameData.dat", ios::binary);


    
    //Copy dummy data into the temp array
    for (int i = 0; i<10; i++)
    {
        strcpy(newFile[i].name,"Player");
        newFile[i].score = 0;
        newFile[i].nameLength = 6;
    }

    //Write data from array into the file
    for (int i = 0; i<10; i++)
    {
        outData.write(reinterpret_cast<char*>(&newFile[i].nameLength),
                      sizeof(newFile[i].nameLength));
        outData.write(newFile[i].name, newFile[i].nameLength);
        outData.write(reinterpret_cast<char*>(&newFile[i].score),
                      sizeof(newFile[i].score));
    }

    outData.close();
    outData.clear();

}

