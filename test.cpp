#include "sudoku.h"

using namespace std;

int main()
{
	sudoku su1;
	su1.initializeSudokuGrid();
	if (su1.solveSudoku())
	{
		cout << "Problem have been solved! The result is: " << endl;
		su1.printSudokuGrid();
	}
		
	return 0;
}
