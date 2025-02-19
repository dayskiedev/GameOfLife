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


// TODO make these requirements in the file so they can be custom for each
int WIDTH;
int HEIGHT;
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

int main()
{
    // endgoal: implement hashlife?


    // open file now 
    std::ifstream spawnFile ("./spawns/spawn1234.txt");
    if (spawnFile.is_open()) {
        std::cout << "opened!" << std::endl;
    }
    else {
        std::cout << "ERROR: Unable to open file." << std::endl;
        return -1;
    }

    // get width and height of area


    // first  way to auto width and height, requires extra numbers in file, cant copy existing ideas without checking W H
    std::string line{};
    
    // width = read length of first line, height count the number of lines
    int count{ 0 };
    std::getline(spawnFile, line);
    if (line.length() <= 0) {
        std::cout << "Error, unable to determine width!\n";
        return -1;
    }
    WIDTH = line.length();
    count++; // increase count as the first getline is the first line 
             // now we have to loop through the lines
    while (!spawnFile.eof()) {
        std::getline(spawnFile, line);
        count++;
    }
    HEIGHT = count;
    std::cout << "Width: " << WIDTH << " Height: " << HEIGHT << std::endl;
    
    spawnFile.clear(); // removes eof flag
    spawnFile.seekg(0); // brings it back to the start of the file

    //create board alognside copyboard
    char** BOARD = new char* [HEIGHT];
    char** copyBoard = new char* [HEIGHT];

    for (int i = 0; i < HEIGHT; ++i) {
        BOARD[i] = new char[WIDTH];
        copyBoard[i] = new char[WIDTH];
    }


    count = 0;
    while (std::getline(spawnFile, line)) {
        for (int i = 0; i < line.length(); ++i) {
            BOARD[count][i] = line[i];
        }
        count++;
    }
    spawnFile.close();

    //initial state, add options before start?
    PrintBoard(BOARD);

    // wierd pointer stuff
    //std::copy(&BOARD[0][0], &BOARD[0][0]+HEIGHT*WIDTH, &copyBoard[0][0]);

    while (true) {
        // copy contents of board to the copy
        for (int y = 0; y < HEIGHT; ++y) { std::copy(BOARD[y],BOARD[y] + WIDTH, copyBoard[y]); }

        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                // count cells around current cell position
                int c = cellCount(BOARD, i, j);
                if (c < 2 || c > 3) { copyBoard[i][j] = DEAD; }
                else if (c == 3 && copyBoard[i][j] == DEAD) { copyBoard[i][j] = ALIVE; }
            }
        }

        // change these
        for (int y = 0; y < HEIGHT; ++y) { std::copy(copyBoard[y], copyBoard[y] + WIDTH, BOARD[y]); }

        PrintBoard(BOARD);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system("cls");
    }
}
