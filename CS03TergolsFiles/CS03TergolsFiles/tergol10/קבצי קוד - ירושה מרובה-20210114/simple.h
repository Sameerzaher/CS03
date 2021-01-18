#include<iostream> 
using namespace std;

class A
{
public:
	A() { cout << "A's constructor called" << endl; }

public:
	int m_test;
};


class B
{
public:
	B() { cout << "B's constructor called" << endl; }

public:
	int m_test;
};


class C : public B, public A  // Note the order 
{
public:
	C() { cout << "C's constructor called" << endl; }
};


