# CommandLine Tetris

CommandLine Tetris is a console-based version of the classic Tetris game. This implementation includes various features such as different game speeds, high score tracking, and customizable game options.

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Contributing](#contributing)
- [License](#license)

## Features
- Play the classic Tetris game in your command line.
- Track high scores and save them to a file.
- Customize game speed and other options.
- Enjoy retro console graphics and sounds.

## Installation

Currently, this code requires Windows (calls `windows.h`).

To compile and run CommandLine Tetris, follow these steps:

1. Clone the repository:
    ```bash
    git clone https://github.com/ryoung/CommandLine_Tetris.git
    cd CommandLine_Tetris
    ```

2. Ensure you have a C++ compiler installed (such as g++ or clang).

3. Compile the project:
    ```bash
    g++ -o tetris main.cpp Tetris.cpp Manager.cpp hiscorestuff.cpp SpeedSettings.cpp Plotter.cpp
    ```

4. Run the game:
    ```bash
    ./tetris
    ```

## Usage
After running the game, you will be presented with a welcome screen. Use the following controls to play the game:

- **Arrow Keys**: Move the pieces left, right, or down.
- **Up Arrow**: Rotate the pieces.
- **Spacebar**: Instantly drop the piece.
- **Menu Options**:
  - **1**: Play Game
  - **2**: Options
  - **3**: Instructions
  - **4**: High Scores
  - **5**: About
  - **6**: Exit

## File Structure

- **main.cpp**: Entry point of the application.
- **Tetris.h / Tetris.cpp**: Main game logic and user interface management.
- **Manager.h / Manager.cpp**: Manages the game state and gameplay mechanics.
- **hiscorestuff.h / hiscorestuff.cpp**: Handles high score checking and file operations.
- **Plotter.h / Plotter.cpp**: Manages the console graphics and rendering.
- **PiecesContainer.h / Pieces.h / Pieces.cpp**: Manages the Tetris pieces and their behaviors.
- **SpeedSettings.h / SpeedSettings.cpp**: Manages game speed settings and adjustments.
- **HeaderStuff.h**: Contains various constants and struct definitions used throughout the game.

## Algorithm overview

```mermaid
graph TD
    A[Player Starts Game] --> B[Game Initialization]
    B --> C[Display Game Board]
    C --> D[Player Input]
    D --> E[Update Game State]
    E --> F{Check for Completed Lines}
    F -- Yes --> G[Clear Completed Lines]
    F -- No --> H[Check for Game Over]
    H -- No --> D
    H -- Yes --> I[End Game]
    G --> D
    I --> J[Display High Scores]
    J --> A
```

## Class Diagram

```mermaid
classDiagram
    class Tetris {
        -Manager manager_
        +void startTetris()
        +void playGame(int& score, int& speed)
        +char welcomeScreen()
        +void instructionScreen()
        +void aboutScreen()
        +void OptionScreen(int& speed)
        +void OptionsGameSpeed(int& speed)
        +void checkForHiScores(int score)
        +void sortScores(HiScore array[], int size)
        +void newHighScoreFile()
        +void highScoreScreen()
    }

    class Manager {
        -PlotterTetris plotHUD_
        -Plotter plotPlayField_
        -Plotter plotNext_
        -Matrix playField_
        -Matrix nextPiece_
        -PiecesContainer container_
        -Piece* pInAction_
        -Piece* pNextAction_
        -bool pieceHitRockBottom_
        -GameStat statistic_
        -Options options_
        +bool step()
        +void draw()
        +bool move(int keyLogged)
        +void setSpeed(const int& amount)
        +GameStat& returnGameStat()
        +void setUpScreen()
        +void readySetGo()
        +void justWait(double seconds)
        +void drawOutline(int xStart, int xEnd, int yStart, int yEnd)
        +void gameOver()
        +void updatePlayField(PiecesContainer* container)
        +void fillFieldWithEmpty()
        +void checkThatFieldEmpty()
        +void displayDeletionUpdatePlayField(PiecesContainer* container)
        +void destroyRowCompletions()
        +void movePiecesDown(PiecesContainer& container, const int rowToDelete)
        +void updateScore(int rowsDeletedAtOnce)
        +void drawNextPiece(Piece* next)
        +void colorChangeAllBlocks(int amount)
        +void wait(double seconds)
        +void checkKeyLog(int& keyLogged)
        +bool moveDown()
        +void flip()
        +void moveRight()
        +void moveLeft()
        +bool gravity()
        +bool isAPartOfActive(int row, int col)
        +bool moveActiveToPlayField(Piece& p)
    }

    class PlotterTetris {
        -COORD coordScreen
        -HANDLE hConsoleOutput
        -SMALL_RECT* lpConsoleWindow
        -COORD* lpNewScreenBufferDimensions
        -CONSOLE_CURSOR_INFO* lpConsoleCursorInfo
        -ink color
        +void clear()
        +void setColor(ink i)
        +void move(int x, int y)
        +void plot(char c)
        +void playMusic(string s)
    }

    class Plotter {
        -COORD coordScreen
        -HANDLE hConsoleOutput
        -char dummy
        -int startX
        -int startY
        +Plotter(int x = 0, int y = 0)
        +void clear()
        +void setStartPoint(int x, int y)
        +void draw(const Matrix& n)
    }

    class PiecesContainer {
        -Piece** container_
        -int capacity_
        -int numPieces_
        +PiecesContainer()
        +int getNumPieces()
        +void deleteContainer()
        +bool addPiece(Piece* p)
        +Piece& operator[](int num)
        +void setPointerAt(int num, Piece* p)
    }

    class Piece {
        -Bit bits_[4]
        -Bit direction_
        -char type_
        -int color_
        +Piece()
        +Piece(Bit direction, Bit startLocation)
        +Piece(const Piece& p)
        +Bit& operator[](int n)
        +Piece& operator=(const Piece& p)
        +char getType()
        +int getColor() const
        +void changeColor(const int amount)
        +bool deleteBit(int n = 0)
        +virtual void pieceBuilder(Bit direction, Bit startLocation)
    }

    Tetris --> Manager
    Manager --> PlotterTetris
    Manager --> Plotter
    Manager --> PiecesContainer
    PiecesContainer --> Piece
    PlotterTetris <|-- Plotter
```

## Contributing
Contributions are welcome! If you find a bug or have a feature request, please open an issue. Feel free to fork the repository and submit pull requests.

1. Fork the repository.
2. Create a new branch:
    ```bash
    git checkout -b feature-branch
    ```
3. Make your changes.
4. Commit your changes:
    ```bash
    git commit -m 'Add some feature'
    ```
5. Push to the branch:
    ```bash
    git push origin feature-branch
    ```
6. Open a pull request.


