#include <iostream>

using namespace std;

void fun(int a)
{
	cout << a << endl;
	a++;
	cout << a << endl;
}

int main()
{
	int y = 10;
	fun(y);
	return 0;
}



