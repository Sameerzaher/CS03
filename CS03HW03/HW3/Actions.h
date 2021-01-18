// Sameer Zaher ID 206015125

// Najeeb Jabareen ID 318565470 
#include"Palindrome.h"
#pragma once
class Actions
{
public:
    void commandList();
    Palindrome Action_1_Create_A_Palindrome(int num,char* str);
    Palindrome Action_2_Update_A_Palindrome(int num, char* str);
    Palindrome Action_3_Concat_A_Palindrome(int num1,int num2,int num3);
    Palindrome Action_4_Sub_A_Palindrome(int num1,int num2);
    Palindrome Action_5_Add_A_char_To_Palindrome(int num,char ch);
    Palindrome Action_6_equal_Palindromes(int num1,int num2);
    Palindrome Action_7_promote_a_palindrome(int num1);
    Palindrome Action_8_access_Palindrome(int num1,int num2);
    void Action_9_Print_palindrome(int num1);
    void Action_10_exit();
    int ValidateInput(int num);
   

};