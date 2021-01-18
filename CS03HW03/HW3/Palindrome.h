// Sameer Zaher ID 206015125

// Najeeb Jabareen ID 318565470  
#pragma once
#include <iostream>
using namespace std;
class Palindrome
{
private:
	int m_size;
	
	char* m_pal;

public:
	Palindrome():m_size(0),m_pal(NULL){};
	Palindrome(int size,char* pal);
	Palindrome(const Palindrome& newPal);
	const Palindrome& operator += (const Palindrome& pal1);
	const Palindrome& operator += (const char ch);
	const Palindrome& operator -= (const Palindrome& pal1);
	const Palindrome& operator + (const Palindrome& pal1);
	Palindrome& operator ++(int);
	bool operator == (const Palindrome& pal1) const;
	const Palindrome& operator!();
	int operator[] (int index);
	char* Palindrome::operator() (const Palindrome& pal1);
	bool operator<(const Palindrome& pal1);
	Palindrome& operator=(const Palindrome& newPal);
	~Palindrome() { delete[] m_pal; }
};
ostream& operator<<(std::ostream& out, const char*& str);
istream& operator>>(istream& in, Palindrome& pal1);



