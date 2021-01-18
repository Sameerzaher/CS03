// Sameer Zaher ID 206015125

// Najeeb Jabareen ID 318565470 
#include "Palindrome.h"
Palindrome::Palindrome(int size,char* pal)
{
	size = m_size;
	strcpy(pal,m_pal);
}
Palindrome::Palindrome(const Palindrome& newPal)
{
	*this = newPal;
}
Palindrome& Palindrome::operator=(const Palindrome& newPal)
{
	if (this != &newPal)
	{
		m_size = newPal.m_size;
		delete[]m_pal;
		m_pal = strdup(newPal.m_pal);
	}
	return *this;
}
const Palindrome& Palindrome::operator += (const Palindrome& pal1)
{

	for (int i = 0; i < pal1.m_size; i++)
	{
		m_pal += pal1.m_pal[i];
	}
	return *this ;
}
const Palindrome& Palindrome::operator += (const char ch)
{
	char* temp;
	temp[0]=ch;
	for(int i=1;i<m_size;i++)
	{
		temp[i]=m_pal[i];
	}
	int len=strlen(temp);
	temp[len+1]=ch;
}
const Palindrome& Palindrome::operator -= (const Palindrome& pal1)
{
	for(int i=0;i<m_size;i++)
	{
		for(int j=0;j<pal1.m_size;j++)
		{
			if(m_pal[i] == pal1.m_pal[j])
			{
				m_pal[i]-=m_pal[i];
			}
		}
	}
	m_size-=pal1.m_size;
	for(int i=0;i<m_size;i++)
	{
		m_pal[i]-=pal1.m_pal[i];
	}
}
const Palindrome& Palindrome::operator + (const Palindrome& pal1)
{
	Palindrome tempPal = *this;
	for (int i = 0; i < pal1.m_size; i++)
	{
		tempPal += pal1.m_pal[i];
	}
	return *this = tempPal;
}
Palindrome& Palindrome::operator ++(int)
{
	Palindrome temp(*this);
	m_pal[0]++;
	return temp;
}
bool Palindrome::operator == (const Palindrome& pal1) const 
{
	if ((m_size == pal1.m_size) && (m_pal == pal1.m_pal))
		return true;
	return false;

}
const Palindrome& Palindrome::operator!()
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_pal[i] >= 65 && m_pal[i] <= 90)
		{
			m_pal[i] = m_pal[i] + 32;
		}
	}
}
int Palindrome::operator[] (int index)
{
	return index != m_size ? m_pal[index] : '?';
}
char* Palindrome::operator() (const Palindrome& pal1)
{
	char* str = new char[pal1.m_size];
	if (pal1.m_size % 2 == 0 )
	{
		strncpy(str , pal1.m_pal,(pal1.m_size / 2 )+1);
		strncat(str,reverse(pal1.m_pal),pal1.m_size / 2);
	}
	else
	{
		strncpy(str, pal1.m_pal,(pal1.m_size / 2));
		str[(pal1.m_size / 2)= '\0'];
		strncat(str , reverse(pal1.m_pal),(pal1.m_size / 2)+1);
	}
	return str;
}
bool Palindrome::operator<(const Palindrome& pal1)
{
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < pal1.m_size; j++)
		{
			if (m_pal[i] < pal1.m_pal[j])
			{
				return true;
			}
			else
				return false;	
		}
	}
}
//global 
ostream& operator<<(std::ostream& out, const char*& str)
{
	for(int i=0;i<strlen(str);i++)
	{
		out<<str[i];
	}
	for(int i=strlen(str);i<0;i--)
	{
		out<<str[i];
	}
	return out;
}
istream& operator>>(istream& in, Palindrome& pal1)
{
	char* str;
	in >> str;
	int flag=0;
	int len = strlen(str);
	for(int i=0;i<len;i++)
	{
		if(str[i]!=str[len-i-1])
		{
			flag=1;
			break;

		}
	}
	if(flag)
	{
		Palindrome(len,str);
		return in;
	}
	else
	{
		char* st1;
		st1=="";
		Palindrome(0,st1);
		return in;
	}
}
