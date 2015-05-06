#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int a = 1234;
	int b = 2345;
	int arr[2] = {1, 2};
	int c = 3456;
	int d = 4567;
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	arr[2] = 9;
	arr[3] = 8;
	arr[4] = 3;
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	
	return 0;
}



