#include <iostream>
using namespace std;

class String
{
public:
    String(const char* str = "");
    String(const String& str);
    ~String() { delete[] _p; }
  

public:
	String& operator = (const String& str);
    String& operator += (const String& str);
    String operator + (const String& str) const;

    const char& operator[] (int index) const;
    //char& operator[] (int index);

    bool operator == (const String& str) const;
	bool operator >= (const String& str) const;

    bool operator <= (const String& str) const;
    bool operator > (const String& str) const;
    bool operator < (const String& str) const;
    bool operator != (const String& str) const;
    
    int len() const { return _len; }
    
    
private:
    char*	_p;
    int		_len;
};





//friend ostream& operator << (ostream& out, const String& str);
//ostream& operator << (ostream& out, const String& str);
//istream& operator >> (istream& in, String& str);