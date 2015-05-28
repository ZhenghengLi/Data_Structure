#include <iostream>

using namespace std;

class A;

class A
{
public:
	void print();
};

class A;

int main()
{
	A a;
	a.print();
	return 0;
}

void A::print()
{
	cout << "class A" << endl;
}


