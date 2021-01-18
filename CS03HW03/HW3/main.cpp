// Sameer Zaher ID 206015125

// Najeeb Jabareen ID 318565470 
#include"Palindrome.h"
#include"Actions.h"
int main()
{ 
    
    Palindrome palindrome1;
    Palindrome palindrome2;
    Palindrome palindrome3;
    int size;
    
    char* str;
    Actions action;
  
    action.commandList();
    while(1)
    {
        char ch;
        int PalNum,PalNum2,PalNum3;
        int cmdNum;
        cout<<"Choose command number: (1-10)";
        cin>>cmdNum;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        cout<<endl;
        switch (cmdNum)
        {
        case 1:
        {
            cout<<"Please choose a number between 1-3";
            cin>>PalNum;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            cout<<endl;
            action.ValidateInput(PalNum);
            action.Action_1_Create_A_Palindrome(PalNum,str);
        }
        case 2:
        {
            cout<<"Please choose a number between 1-3";
            cin>>PalNum;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            cout<<endl;
            action.Action_2_Update_A_Palindrome(PalNum,str);
        }   
        case 3:
        {
            cout<<"Please choose a number between 1-3";
            cin>>PalNum;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            cout<<endl;
           cout<<"Please choose a number between 1-3";
            cin>>PalNum2;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            cout<<endl;
            cout<<"Please choose a number between 1-3";
            cin>>PalNum3;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            cout<<endl;
            action.Action_3_Concat_A_Palindrome(PalNum,PalNum2,PalNum3);
        }
        case 4:
        {
            cout<<"Please choose a number between 1-3";
            cin>>PalNum;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            cout<<endl;
            cout<<"Please choose a number between 1-3";
            cin>>PalNum2;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            cout<<endl;
            action.Action_4_Sub_A_Palindrome(PalNum,PalNum2);
        }
        case 5:
        {
            cout<<"Please choose a number between 1-3";
            cin>>PalNum;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout<<"Error"<<endl;
                break;
            }
            cout<<endl;
            cout<<"Please enter a character";
            cin>>ch;
            cout<<endl;
            action.Action_5_Add_A_char_To_Palindrome(PalNum,ch);
        }
        case 6:
        {
            cout<<"Please choose a number between 1-3";
            cin>>PalNum;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout<<"Error"<<endl;
                break;
            }
            cout<<endl;
             cout<<"Please choose a number between 1-3";
            cin>>PalNum2;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout<<"Error"<<endl;
                break;
            }
            cout<<endl;
            action.Action_6_equal_Palindromes(PalNum,PalNum2);
            
        }
        case 7:
        {
            cout<<"Please choose a number between 1-3";
            cin>>PalNum;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout<<"Error"<<endl;
                break;
            }
            cout<<endl;
            action.Action_7_promote_a_palindrome(PalNum);
        }
        case 8:
        {
            cout<<"Please choose a number between 1-3";
            cin>>PalNum;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            cout<<endl;
            cout<<"Please choose a number between 1-3";
            cin>>PalNum2;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            cout<<endl;
            action.Action_8_access_Palindrome(PalNum,PalNum2);
        }
        case 9:
        {
            cout<<"Please choose a number between 1-3";
            cin>>PalNum;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            cout<<endl;
            action.Action_9_Print_palindrome(PalNum);
        }
        case 10:
        {
           action.Action_10_exit();
        }
        default:
        {
            break;
        }

    }


}


