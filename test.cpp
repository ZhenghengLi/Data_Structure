#include <iostream>

using namespace std;

class A
{
public:
	A(int, int);
	int plus(int);
	int times();
private:
	int x;
	int y;
};

A::A(int a, int b)
{
	x = a;
	y = b;
}

int A::plus(int xx)
{
	int x = 13;
	return x + y;
}

int A::times()
{
	return x * y;
}

class B: public A
{
public:
	B(int, int, int);
	int funB();
	int bb;
private:
	int c;
};

B::B(int aa, int bb, int cc): A(aa, bb)
{
	c = cc;
}

int B::funB()
{
	return times() + c;
}

int main()
{
	B b(3, 4, 5);
	b.bb = 100;
	A *a;
	cout << "sizeof(a): " << sizeof(a) << endl;
	a = &b;
	cout << "sizeof(a): " << sizeof(a) << endl;
	cout << b.bb << endl;
	cout << a->plus(15) << endl;
	cout << b.plus(15) << endl;
//	cout << a.funB() << endl;
	
	return 0;
}
