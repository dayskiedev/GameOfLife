#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

// My implementation of conweys game of life
// program is made up of cells
// rules for cells

// A live cell dies if it has fewer than 2 neighbours
// A live cells dies with more than 3 neighbours
// a cell is brought to life if it has exactly 3 neihbours

int WIDTH = 50;
int HEIGHT = 25;
char ALIVE = 'X';
char DEAD = ' ';

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

int main()
{
    // endgoal: implement hashlife?

    //create board alognside copyboard
    char** BOARD = new char* [HEIGHT];
    char** copyBoard = new char* [HEIGHT];

    for (int i = 0; i < HEIGHT; ++i) {
        BOARD[i] = new char[WIDTH];
        copyBoard[i] = new char[WIDTH];
    }

    //fill with dead cells

    // open file now 
    std::ifstream spawnFile ("./spawns/spawn0.txt");
    if (spawnFile.is_open()) {
        std::cout << "opened!" << std::endl;
    }

    std::string line;
    int count = 0;
    while (std::getline(spawnFile, line)) {
        for (int i = 0; i < line.length(); ++i) {
            BOARD[count][i] = line[i];
        }
        count++;
    }
    spawnFile.close();


    //for (int y = 0; y < HEIGHT; ++y) {
    //    for (int x = 0; x < WIDTH; ++x) {
    //        BOARD[y][x] = DEAD;
    //    }
    //}
    // we want this to be read from a file, 
    // so we need a way to read from a file that can get the length and width
    // possibly get width by taking length of first string line and height by
    // counting until we reach EOF
    // 
    // Add starting conditions, cell count/generation improve print speed of screen?
    // there has to be a better way than a bunch of for loops
    // 
    //set some random to 1
    //BOARD[14][20] = ALIVE;
    //BOARD[15][20] = ALIVE;
    //BOARD[15][19] = ALIVE;
    //BOARD[16][20] = ALIVE;
    //BOARD[18][20] = ALIVE;
    //BOARD[19][20] = ALIVE;
    //BOARD[16][21] = ALIVE;
    //BOARD[16][21] = ALIVE;
    
    // check on main board, apply changes to copy board.
    // once done set board to copyboard

    PrintBoard(BOARD);

    // wierd pointer stuff
    //std::copy(&BOARD[0][0], &BOARD[0][0]+HEIGHT*WIDTH, &copyBoard[0][0]);

    //while (true) {
    //    // copy contents of board to the copy
    //    for (int y = 0; y < HEIGHT; ++y) { std::copy(BOARD[y],BOARD[y] + WIDTH, copyBoard[y]); }

    //    for (int i = 0; i < HEIGHT; ++i) {
    //        for (int j = 0; j < WIDTH; ++j) {
    //            // count cells around current cell position
    //            int c = cellCount(BOARD, i, j);
    //            if (c < 2 || c > 3) { copyBoard[i][j] = DEAD; }
    //            else if (c == 3 && copyBoard[i][j] == DEAD) { copyBoard[i][j] = ALIVE; }
    //        }
    //    }

    //    // change these
    //    for (int y = 0; y < HEIGHT; ++y) { std::copy(copyBoard[y], copyBoard[y] + WIDTH, BOARD[y]); }

    //    PrintBoard(BOARD);
    //    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    //    system("cls");
    //}

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
