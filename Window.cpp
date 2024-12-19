#include <iostream>

#include "Window.h"
#include "Cells.h"

Window::Window(int w, int h) {
	width = w;
	height = h;
	generation = 0;
	run = true;

	Grid = new char*[height];
	for (int i = 0; i < height; ++i) {	Grid[i] = new char[width]; }

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			Grid[i][j] = emptyCell;
		}
	}
}

void Window::DisplayWindow(char* Array) {
	std::cout << "Generation: " << generation << std::endl;
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			std::cout << Array[i][j];
		}
		std::cout << std::endl;
	}

	TakeInput();
}

void Window::TakeInput() {
	std::string input;
	std::cin >> input;

	if (input == "e") {
		std::cout << "Ending simulation..." << std::endl;
		run = false;
	}

	if (input == "s") {
		generation++;
		// go to next generation
	}

	if (input == "p") {
		std::cout << "Enter the x and why position for the cell" << std::endl;
		int x, y;
		std::cin >> x;
		std::cin >> y;

		PlaceCell(x, y);
	}

}

void Window::PlaceCell(int x, int y) {
	Grid[y][x] = cell;
}