#include <iostream>

using namespace std;

template<class T>
T power(T a)
{
	return a * a;
}

template <class A = int, A (*F)(A) = power<A> >
class AB
{
public:
	void fun1(A);
	A a;
};

template <class A, A (*F)(A)>
void AB<A, F>::fun1(A a)
{
	A r;
	r = F(a);
	cout << r << endl;
}


int main()
{
//	AB<double, int, 
	AB<> a;
	a.fun1(25.568);
	
	
	return 0;
}

