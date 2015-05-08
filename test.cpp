#include <iostream>
#include <cfloat>
#include <limits.h>

using namespace std;

int main()
{
	double a = DBL_MAX;
	double b = DBL_MAX;
	double c = a + 123.32;

	cout << "a = " << a << endl;
	cout << "c = " << c << endl;

	if (c < DBL_MAX)
		cout << "c < DBL_MAX" << endl;
	else if(c > DBL_MAX)
		cout << "c > DBL_MAX" << endl;
	else if(c == a)
		cout << "c == DBL_MAX" << endl;
	
	return 0;
}

