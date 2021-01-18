#include <iostream>
using namespace std;

class String
{
public:
    String(const char* str = "");
    String(const String& str);
    ~String() { delete[] _p; }
  
public:
	String & operator = (const String& str);
	String& operator += (const String& str);
	String operator + (const String& str) const;
	const char& operator[] (int index) const;
	bool operator == (const String& str) const;
	bool operator >= (const String& str) const;
	bool operator <= (const String& str) const;
	bool operator > (const String& str) const;
	bool operator < (const String& str) const;
	bool operator != (const String& str) const;
    
private:
    char*	_p;
    int		_len;
};
