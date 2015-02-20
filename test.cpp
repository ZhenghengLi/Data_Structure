#include <iostream>

using namespace std;

void decToBin(int num, int base);

int main(int argc, char** argv)
{
	int decimalNum;
	int base;
	base = 2;
	cout << "Enter number in decimal: ";
	cin >> decimalNum;
	cout << "Decimal " << decimalNum << " = ";
	decToBin(decimalNum, base);
	cout << " binary" << endl;
	return 0;
}

void decToBin(int num, int base)
{
	if (num > 0)
	{
		decToBin(num / base, base);
		cout << num % base;
	}
}
