#include <iostream>

class Window {
	public:
		Window(int w, int h);

		void DisplayWindow();
		void TakeInput();

		void PlaceCell(int x, int y);

		bool Running() { return run; }

	private:
		int width;
		int height;
		bool run;

		char** Grid;
		char cell = 'C';
		char emptyCell = '.';
		int generation;
};