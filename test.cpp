#include <iostream>

using namespace std;

int fplus(int, int);
int ftimes(int, int);
int changevalue(int&, int);
int usefun(int, int, int (&fun)(int, int));
int& leftchange(int &);

int main()
{
	int x = 20;
	int y = 34;
	cout << usefun(x, y, fplus) << endl;
	cout << usefun(x, y, ftimes) << endl;
	cout << "x = " << x << endl;
	changevalue(x, 123);
	cout << "x = " << x << endl;
	leftchange(x) = 345;
	cout << "x = " << x << endl;

	return 0;
}

int fplus(int a, int b)
{
	return a + b;
}

int ftimes(int a, int b)
{
	return a * b;
}

int changevalue(int &a, int b)
{
	a = b;
	return a;
}

int& leftchange(int &a)
{
	return a;
}

int usefun(int a, int b, int (&fun)(int, int))
{
	return fun(a, b);
}

