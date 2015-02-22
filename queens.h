#include <iostream>
#include <stdlib.h>
using namespace std;

class nQueensPuzzle
{
public:
	nQueensPuzzle(int queens = 8);
	bool canPlaceQueen(int k, int i);
	void queensConfiguration(int k);
	void printConfiguration();
	int solutionsCount();
private:
	int noOfSolutions;
	int noOfQueens;
	int *queensInRow;
};

nQueensPuzzle::nQueensPuzzle(int queens)
{
	noOfQueens = queens;
	queensInRow = new int[noOfQueens];
	noOfSolutions = 0;
}

bool nQueensPuzzle::canPlaceQueen(int k, int i)
{
	for (int j = 0; j < k; j++)
		if ((queensInRow[j] == i) || (abs(queensInRow[j] - i) == abs(j - k)))
			return false;
	return true;
}

void nQueensPuzzle::queensConfiguration(int k)
{
	for (int i = 0; i < noOfQueens; i++)
	{
		if (canPlaceQueen(k, i))
		{
			queensInRow[k] = i;
			if (k == noOfQueens - 1)
				printConfiguration();
			else
				queensConfiguration(k + 1);
		}
	}
}

void nQueensPuzzle::printConfiguration()
{
	noOfSolutions++;
	cout << "(";
	for (int i = 0; i < noOfQueens - 1; i++)
		cout << queensInRow[i] << ", ";
	cout << queensInRow[noOfQueens - 1] << ")" << endl;
}

int nQueensPuzzle::solutionsCount()
{
	return noOfSolutions;
}
