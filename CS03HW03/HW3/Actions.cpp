// Sameer Zaher ID 206015125

// Najeeb Jabareen ID 318565470 
#include"Actions.h"
Palindrome pal1;
Palindrome pal2;
Palindrome pal3;
void Actions::commandList()
{
    cout<<"Press 1 to Create a Palindrome"<<endl;
    cout<<"Press 2 to update the palindrome"<<endl;
    cout<<"Press 3 to concat the palindrome"<<endl;
    cout<<"Press 4 to subsrct the palindrome"<<endl;
    cout<<"Press 5 to add a char to the palindrome"<<endl;
    cout<<"Press 6 to equal the palindrome"<<endl;
    cout<<"Press 7 to promote the palindrome"<<endl;
    cout<<"Press 8 to access the palindrome"<<endl;
    cout<<"Press 9 to print the palindrome"<<endl;
    cout<<"Press 10 to exit"<<endl;
}
Palindrome Actions::Action_1_Create_A_Palindrome(int num,char* str)
{
    switch (num)
    {
         case 1:
         {
             Palindrome pal1(strlen(str),str);
            break;
         }
         case 2:
         {
             Palindrome pal2(strlen(str),str);
             break;
         }
        case 3:
        {
            Palindrome pal3(strlen(str),str);
            break;
        }
    default:
        break;
    }
}
Palindrome Actions::Action_2_Update_A_Palindrome(int num, char* str)
{
    switch(num)
    {
        case 1:
        {
            pal1.operator-=(pal1);
            pal1.operator+=(Palindrome(strlen(str),str));
            return pal1;
            break;
        }
        case 2:
        {
            pal2.operator-=(pal2);
            pal2.operator+=(Palindrome(strlen(str),str));  
            return pal2;
            break;     
        }
        case 3:
        {
            pal3.operator-=(pal3);
            pal3.operator+=(Palindrome(strlen(str),str));
            return pal3;
            break;
        }
    }
}
Palindrome Actions::Action_3_Concat_A_Palindrome(int num1,int num2,int num3)
{
    switch (num1)
    {
        case 1:
        {
            switch (num2)
            {
                case 2:
                {
                    pal1.operator+=(pal2);
                    switch (num3)
                    {
                        case 3:
                        {
                            pal1.operator+=(pal3);
                            return pal1;
                        }
                    }
                }
                case 3:
                {
                    pal1.operator+=(pal3);
                    switch (num3)
                    {
                        case 2:
                        {
                            pal1.operator+=(pal2);
                            return pal1;
                        }  
                    }
                }
                default:
                     break;
            }
        }
        case 2:
        {
            switch (num2)
            {
                case 1:
                {
                    pal2.operator+=(pal1);
                    switch (num3)
                    {
                        case 3:
                        {
                            pal2.operator+=(pal3);
                            return pal2;
                        }
                    }
                }
                case 3:
                {
                    pal2.operator+=(pal3);
                    switch (num3)
                    {
                        case 1:
                        {
                            pal2.operator+=(pal1);
                            return pal2;
                        }
                    }
                }
                default:
                     break;

            }
        }
        case 3:
        {
            switch (num2)
            {
                case 1:
                {
                    pal3.operator+=(pal1);
                    switch (num3)
                    {
                        case 2:
                        {
                            pal3.operator+=(pal2);
                            return pal3;
                        }
                        
                    }
                }
                case 2:
                {
                    pal3.operator+=(pal2);
                    switch (num3)
                    {
                        case 1:
                        {
                            pal3.operator+=(pal1);
                            return pal3;
                        }  
                    }
                }
                default:
                     break;
            }
        }
        default:
                     break;
    }
}
Palindrome Actions::Action_4_Sub_A_Palindrome(int num1,int num2)
{
    switch(num1)
            {
                case 1:
                {
                    switch(num2)
                    {
                        case 1:
                        {
                            pal1.operator-=(pal1);
                            return pal1;
                        }
                        case 2:
                        {
                             pal1.operator-=(pal2); 
                             return pal1; 
                        }
                        case 3:
                        {
                            pal1.operator-=(pal3);
                            return pal1;
                        }
                        default:
                     break;
                    }
                    break;
                }
                case 2:
                {
                    switch(num2)
                    {
                        case 1:
                        {
                            pal2.operator-=(pal1);
                            return pal2;
                        }
                        case 2:
                        {
                            pal2.operator-=(pal2);
                           return pal2;
                        }
                        case 3:
                        {
                            pal2.operator-=(pal3);
                            return pal2;
                        }
                        default:
                     break;
                    }
                    break; 
                }
                case 3:
                {
                    switch(num2)
                    {
                        case 1:
                        {
                            pal3.operator-=(pal1);
                            return pal3;
                        }
                        case 2:
                        {
                            pal3.operator-=(pal2);
                            return pal3;
                        }
                        case 3:
                        {
                            pal3.operator-=(pal3);
                            return pal3;
                        }
                        default:
                     break;
                    }
                    break;
                }
                default:
                     break;
    }
            
}
Palindrome Actions::Action_5_Add_A_char_To_Palindrome(int num,char ch)
{
    switch(num)
            {
                case 1:
                {
                    pal1.operator+=(ch);
                    return pal1;
                }
                case 2:
                {
                    pal2.operator+=(ch);
                    return pal2; 
                }
                case 3:
                {
                    pal3.operator+=(ch);
                    return pal3;
                }
                default:
                     break;
            }
}
Palindrome Actions::Action_6_equal_Palindromes(int num1,int num2)
{
    switch(num1)
    {
        case 1:
        {
            switch(num2)
            {
                case 1:
                {
                    pal1.operator<(pal1);
                    return pal1;
                }
                case 2:
                {
                    pal1.operator<(pal2);
                    return pal2;
                }
                case 3:
                {
                    pal1.operator<(pal3);
                    return pal3;
                }
                default:
                     break;
            }
        }
        case 2:
        {
            switch(num2)
            {
                case 1:
                {
                    pal2.operator<(pal1);
                    return pal1;
                }
                case 2:
                {
                    pal2.operator<(pal2);
                    return pal2;
                }
                case 3:
                {
                    pal2.operator<(pal3);
                    return pal3;
                }
                default:
                     break;
            }
        }
        case 3:
        {
            switch(num2)
            {
                case 1:
                {
                    pal3.operator<(pal1);
                    return pal1;
                }
                case 2:
                {
                    pal3.operator<(pal2);
                    return pal2;
                }
                case 3:
                {
                    pal3.operator<(pal3);
                    return pal3;
                }
                default:
                     break;
            }
        }
        default:
                     break;
    }
}
Palindrome Actions::Action_7_promote_a_palindrome(int num1)
{
    switch(num1)
            {
                case 1:
                {
                    pal1.operator++(1);
                    return pal1;
                }
                case 2:
                {
                    pal2.operator++(1);
                    return pal2;
                }
                case 3:
                {
                    pal3.operator++(1);
                    return pal3;
                }
                default:
                     break;
            }
}
Palindrome Actions::Action_8_access_Palindrome(int num1,int num2)
{
    switch (num1)
    {
    case 1:
        {
            pal1.operator[](num2);
            return pal1;
        }
    case 2:
        {
            pal2.operator[](num2);
            return pal2;
        }
    case 3:
        {
            pal3.operator[](num2);
            return pal3;
        }
    default:
        break;
    }
}
void Actions::Action_9_Print_palindrome(int num1)
{
    switch (num1)
    {
    case 1:
        {
            cout<< pal1[num1-1]<<endl;
            break;
        }
    case 2:
        {
            cout<< pal2[num1-1]<<endl;
            break;
        }
    case 3:
        {
            cout<< pal3[num1-1]<<endl;
            break;
        }
       
    
    default:
        break;
    }
}
void Actions::Action_10_exit()
{
    exit(0);
    return;
}
int Actions::ValidateInput(int num)
{
    cout<<"Please enter a number:"<<endl;
    while(num<0 || num>4)
    {
        cin>> num;
        cout<<" error try again not valid please enter a number between 1-3";
    }
    return num;
}
