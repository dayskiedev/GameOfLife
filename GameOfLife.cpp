#include <iostream>
#include <chrono>
#include <thread>
#include "Window.h"

// My implementation of conweys game of life
// program is made up of cells
// rules for cells

// A live cell dies if it has fewer than 2 neighbours
// A live cells dies with more than 3 neighbours
// a cell is brought to life if it has exactly 3 neihbours

int WIDTH = 50;
int HEIGHT = 25;
char ALIVE = 'X';
char DEAD = '.';

void PrintBoard(char** board) {
    
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}

int cellCount(char** board, int r, int c) {
    int cellCount = 0;

    //not brackets

    for (int i = r - 1; i <= r + 1; i++) {
        for (int j = c - 1; j <= c + 1; j++) {
            if (i == r && j == c ||
                i < 0 || i >= HEIGHT ||
                j < 0 || j >= WIDTH) { continue; }

            if (board[i][j] == ALIVE) {
                cellCount++;
            }
        }
    }

    //cell counting may be wrong

    return cellCount;
}

void Mutate(char** board) {
    
}

int main()
{
    // endgoal: implement hashlife?

    //create board
    char** BOARD = new char* [HEIGHT];
    for (int i = 0; i < HEIGHT; ++i) {
        BOARD[i] = new char[WIDTH];
    }

    //set to 0
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            BOARD[y][x] = DEAD;
        }
    }

    char** copyBoard = new char* [HEIGHT];
    for (int i = 0; i < HEIGHT; ++i) {
        copyBoard[i] = new char[WIDTH];
    }

    //set some random to 1
    BOARD[14][20] = ALIVE;
    BOARD[15][20] = ALIVE;
    BOARD[15][19] = ALIVE;
    BOARD[16][20] = ALIVE;
    BOARD[16][21] = ALIVE;
    //BOARD[16][21] = ALIVE;
    
    // check on main board, apply changes to copy board.
    // once done set board to copyboard

    PrintBoard(BOARD);

    // wierd pointer stuff
    //std::copy(&BOARD[0][0], &BOARD[0][0]+HEIGHT*WIDTH, &copyBoard[0][0]);

    while (true) {
        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                copyBoard[y][x] = BOARD[y][x];
            }
        }

        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                // count cells around current cell position
                int c = cellCount(BOARD, i, j);
                if (c < 2 || c > 3) { copyBoard[i][j] = DEAD; }
                else if (c == 3 && copyBoard[i][j] == DEAD) { copyBoard[i][j] = ALIVE; }
            }
        }

        // change these
        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                BOARD[y][x] = copyBoard[y][x];
            }
        }

        PrintBoard(BOARD);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        system("cls");
    }

    //while (true) {

    //    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    //}


    // got it working.
    // now test with preade board
    // make it automated using a timer?

    //check top left
    

    // xxx
    // x.x
    // xxx 
    // cell needs to check all the x's for a potential dot
    // need a copy of the array to edit.
}
