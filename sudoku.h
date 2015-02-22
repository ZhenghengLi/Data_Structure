#include <iostream>
#include <stdlib.h>
using namespace std;

class sudoku
{
public:
	sudoku();
	sudoku(int g[][9]);
	void initializeSudokuGrid();
	void initializeSudokuGrid(int g[][9]);
	void printSudokuGrid();
	bool solveSudoku();
	bool findEmptyGridSlot(int &row, int &col);
	bool canPlaceNum(int row, int col, int num);
	bool numAlreadyInRow(int row, int num);
	bool numAlreadyInCol(int col, int num);
	bool numAlreadyInBox(int smallGridRow, int smallGridCol, int num);
private:
	int grid[9][9];
};

sudoku::sudoku()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			grid[i][j] = 0;
}

sudoku::sudoku(int g[][9])
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			grid[i][j] = g[i][j];
}

void sudoku::initializeSudokuGrid()
{
	int g[9][9];
	bool flag = true;
	char yn;
	while (flag)
	{
		for (int i = 0; i < 9; i++)
		{
			cout << "Please input the numbers of row " << i + 1 << " : ";
			for (int j = 0; j < 9; j++)
				cin >> g[i][j];
		}
		cout << "The SudokuGrid you input is:" << endl;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << g[i][j] << " ";
			cout << endl;
		}
		
		cout << "Dose it right? (y/n) ";
		cin >> yn;
		if (yn != 'n')
		{
			flag = false;
			for (int i = 0; i < 9; i++)
				for (int j = 0; j < 9; j++)
					grid[i][j] = g[i][j];
			cout << "Your SudokuGrid is stored successfully." << endl;
		}
	}
}

void sudoku::initializeSudokuGrid(int g[][9])
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			grid[i][j] = g[i][j];
	cout << "The SudokuGrid is initialized:" << endl;
	printSudokuGrid();
}

void sudoku::printSudokuGrid()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << grid[i][j] << " ";
		cout << endl;
	}
}	

bool sudoku::solveSudoku()
{
	int row, col;
	if (findEmptyGridSlot(row, col))
	{
		for (int num = 1; num <= 9; num++)
		{
			if (canPlaceNum(row, col, num))
			{
				grid[row][col] = num;
				if (solveSudoku())
					return true;
				grid[row][col] = 0;
			}
		}
		return false;
	}
	else
		return true;
}

bool sudoku::findEmptyGridSlot(int &row, int &col)
{
	for (row = 0; row < 9; row++)
		for (col = 0; col < 9; col++)
			if (grid[row][col] == 0)
				return true;
	return false;
}

bool sudoku::canPlaceNum(int row, int col,int num)
{
	return !(numAlreadyInRow(row, num) || numAlreadyInCol(col, num) || numAlreadyInBox(row / 3, col / 3, num));
}

bool sudoku::numAlreadyInRow(int row, int num)
{
	for (int j = 0; j < 9; j++)
		if (grid[row][j] == num)
			return true;
	return false;
}

bool sudoku::numAlreadyInCol(int col, int num)
{
	for (int i = 0; i < 9; i++)
		if (grid[i][col] == num)
			return true;
	return false;
}

bool sudoku::numAlreadyInBox(int smallGridRow, int smallGridCol, int num)
{
	int baserow = smallGridRow * 3;
	int basecol = smallGridCol * 3;
	for (int i = baserow; i < baserow + 3; i++)
		for (int j = basecol; j < basecol + 3; j++)
			if (grid[i][j] == num)
				return true;
	return false;
}

