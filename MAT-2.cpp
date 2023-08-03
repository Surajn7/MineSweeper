#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

class Rules {
public:
  Rules() {
    cout << "Welcome to Mine Sweeper \n\n";
    cout << "Rules : "
         << "\n1.The board(9*9) is divided into cells, with mines randomly "
            "distributed \n";
    cout << "2.To win you need to open all the cells \n";
    cout << "3.The number on a cells determines the number of mines adjacent "
            "to it,\n  Using this information you can determine the numbers of "
            "cells that are safe, and cells that contain mine \n";
    cout << "4.Interact, Evolve and Enjoy \n\n\n";
    cout << "How to Play : "
         << "\n1.User will input X & Y (Co-ordinates where they want to "
            "click)\n";
    cout << "2.In each step check Win or Loose \n\n\n";
    cout << "+++++++ GAME STARTED +++++++\n\n\n";
  }
};

class skeleton {
  char board[9][9];
  int sides = 9, mines = 10;

public:
  void setBoard(char realBoard[][9], char myBoard[][9]) {
    srand(time(NULL));
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 10; j++) {
        myBoard[i][j] = realBoard[i][j] = '|';
      }
    }
    return;
  }

  bool isMine(int x, int y, char Board[][9]) {
    if (Board[x][y] == 'M') {
      return true;
    } else {
      return false;
    }
  }

  bool isValid(int row, int col) {
    return (row >= 0) && (row < sides) && (col >= 0) && (col < sides);
  }

  int countAdjacentMines(int row, int col, int mine[][2], char realBoard[][9]) {
    int i, count = 0;

    // North
    if (isValid(row - 1, col) == true) {
      if (isMine(row - 1, col, realBoard) == true)
        count++;
    }

    // South
    if (isValid(row + 1, col) == true) {
      if (isMine(row + 1, col, realBoard) == true)
        count++;
    }

    // East
    if (isValid(row, col + 1) == true) {
      if (isMine(row, col + 1, realBoard) == true)
        count++;
    }

    // West
    if (isValid(row, col - 1) == true) {
      if (isMine(row, col - 1, realBoard) == true)
        count++;
    }

    // North-East
    if (isValid(row + 1, col + 1) == true) {
      if (isMine(row + 1, col + 1, realBoard) == true)
        count++;
    }

    // South-West
    if (isValid(row + 1, col - 1) == true) {
      if (isMine(row + 1, col - 1, realBoard) == true)
        count++;
    }

    // North-West
    if (isValid(row - 1, col + 1) == true) {
      if (isMine(row - 1, col + 1, realBoard) == true)
        count++;
    }

    // North-East
    if (isValid(row - 1, col - 1) == true) {
      if (isMine(row - 1, col - 1, realBoard) == true)
        count++;
    }
    return count;
  }

  bool playGameUntil(char myBoard[][9], char realBoard[][9], int mine[][2],
                     int row, int col, int *movesLeft) {
    if (myBoard[row][col] != '|')
      return false;

    int i, j;

    if (realBoard[row][col] == 'M') {
      myBoard[row][col] = 'M';

      for (int i = 0; i < mines; i++)
        myBoard[mine[i][0]][mine[i][1]] = 'M';

      printBoard(myBoard);
      cout << "You Lost !!! \n";
      return true;
    } else {
      int count = countAdjacentMines(row, col, mine, realBoard);
      (*movesLeft)--;

      myBoard[row][col] = count + '0';

      if (!count) {

        // North
        if (isValid(row - 1, col) == true) {
          if (isMine(row - 1, col, realBoard) == false)
            playGameUntil(myBoard, realBoard, mine, row - 1, col, movesLeft);
        }

        // South
        if (isValid(row + 1, col) == true) {
          if (isMine(row + 1, col, realBoard) == false)
            playGameUntil(myBoard, realBoard, mine, row + 1, col, movesLeft);
        }

        // East
        if (isValid(row, col + 1) == true) {
          if (isMine(row, col + 1, realBoard) == false)
            playGameUntil(myBoard, realBoard, mine, row, col + 1, movesLeft);
        }

        // West
        if (isValid(row, col - 1) == true) {
          if (isMine(row, col - 1, realBoard) == false)
            playGameUntil(myBoard, realBoard, mine, row, col - 1, movesLeft);
        }

        // North-East
        if (isValid(row + 1, col + 1) == true) {
          if (isMine(row + 1, col + 1, realBoard) == false)
            playGameUntil(myBoard, realBoard, mine, row + 1, col + 1,
                          movesLeft);
        }

        // North-West
        if (isValid(row + 1, col - 1) == true) {
          if (isMine(row + 1, col - 1, realBoard) == false)
            playGameUntil(myBoard, realBoard, mine, row + 1, col - 1,
                          movesLeft);
        }

        // South-West
        if (isValid(row - 1, col + 1) == true) {
          if (isMine(row - 1, col + 1, realBoard) == false)
            playGameUntil(myBoard, realBoard, mine, row - 1, col + 1,
                          movesLeft);
        }

        // South-East
        if (isValid(row - 1, col - 1) == true) {
          if (isMine(row - 1, col - 1, realBoard) == false)
            playGameUntil(myBoard, realBoard, mine, row - 1, col - 1,
                          movesLeft);
        }
      }
      return false;
    }
  }

  void makeMove(int *x, int *y) {
    cout << "Enter X(row) and Y(column) ";
    cin >> *x;
    cin >> *y;
    return;
  }

  void cheatMinesweeper(char realBoard[][9]) {
    printf("The mines locations are-\n");
    printBoard(realBoard);
    return;
  }

  void replaceMine(int x, int y, char Board[][9]) {
    for (int i = 0; i < sides; i++) {
      for (int j = 0; j < sides; j++) {
        if (Board[i][j] != 'M') {
          Board[i][j] = 'M';
          Board[x][y] = '-';
          return;
        }
      }
    }
    return;
  }

  void placeMines(int mine[][2], char realBoard[][9]) {
    bool mark[sides * sides];
    memset(mark, false, sizeof(mark));

    for (int i = 0; i < mines;) {
      int random = rand() % (sides * sides);
      int x = random / sides;
      int y = random % sides;

      if (mark[random] == false) {
        mine[i][0] = x;
        mine[i][1] = y;
        realBoard[mine[i][0]][mine[i][1]] = 'M';
        mark[random] = true;
        i++;
      }
    }
    return;
  }

  void printBoard(char myBoard[][9]) {
    int i, j;

    for (int i = 0; i < sides; i++)
      cout << " " << i;

    cout << "\n --------------------" << endl;

    for (int i = 0; i < sides; i++) {
      cout << i;
      for (int j = 0; j < sides; j++) {
        cout << " " << myBoard[i][j];
      }
      cout << "\n --------------------" << endl;
    }
    return;
  }

  void PlayGame() {
    bool gameOver = false;

    char myBoard[9][9], realBoard[9][9];

    int movesLeft = sides * sides - mines, x, y;
    int mines[10][2];
    int moves[71][2];

    cheatMinesweeper(realBoard);

    setBoard(realBoard, myBoard);

    placeMines(mines, realBoard);

    int currentIndex = 0;

    cout << "GameOver " << gameOver << endl;

    while (gameOver == false) {
      cout << "Current Status of the board : " << endl;
      printBoard(myBoard);
      makeMove(&x, &y);

      if (currentIndex == 0) {
        cout << "Current Index " << currentIndex << endl;
        if (isMine(x, y, realBoard) == true)
          replaceMine(x, y, realBoard);
      }
      currentIndex++;

      gameOver = playGameUntil(myBoard, realBoard, mines, x, y, &movesLeft);

      if ((gameOver == false) && (movesLeft == 0)) {
        cout << "You Won ! \n";
        gameOver = true;
      }
    }
    return;
  }
};

int main() {
  Rules rules;
  skeleton sklt;
  sklt.PlayGame();
}