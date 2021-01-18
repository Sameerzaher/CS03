#include <iostream>
#include "String.h"

using namespace std;

int main (void)
{
    String s1 = "Hope for "; // Calls the String(const char*) constructor
    String s2 = "the best";
  
    s1 += s2 ; // calls operator +=
    
    if (s1 == s2)
        cout<<"s1 and s2 are lexicographically equal!"<<endl;
    
    return 0;
}