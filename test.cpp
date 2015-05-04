#include <iostream>

using namespace std;

void fun(const int &a, int &b, int x)
{
	cout << a << endl;
	b = x;
	cout << a << endl;
}

int main()
{
	int y = 10;
	fun(y, y, 100);
	cout << y << endl;
	return 0;
}



