#include <iostream>
#include<conio.h>
#include<string.h>
#include<algorithm>
using namespace std;


// int main()
// {
//     char a[100];
//     int i,n,temp=1;
//     cout<<"Enter the number of letters in the word:\n";
//     cin>>n;
//     cout<<"Enter the word:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     for(i=0;i<n/2+1;i++)
//     {
//         if(a[i] != a[n-1-i])
//         {
//             temp=0;
//             break;
//         }
//     }
//     if(temp)
//     {
//         cout<<"Given word is a palindrome\n";
//     }
//     else
//     {
//         cout<<"Given word is not a palindrome\n";
//     }
// }


// STRING FUNCTIONS

// int main()
// {
//     int a;
//     string str,str1,str2,st,sr;
//     str1="Captain",str2=" Hook";
//     str=str1+str2;                                    //Appending without inbulit fumction
//     str1.append(str2);                                //For appending
//     cout<<str1<<endl<<str<<endl;
//     str2.clear();                                     //Clear the information in a string
//     a=str2.compare(str1);                             //Compare two strings
//     if(str2.empty())                                  //Checks if the given string is empty
//     {
//         cout<<"String is empty\n";
//     }
//     str1.erase(3,2);                                  //Erases certain characters from the given string
//     cout<<str1<<endl;
//     cout<<str1.find("tai")<<endl;                     //Finds specific substring in the given string and returns its index value
//     str2.insert(0,"SJCE");
//     cout<<str2<<endl;
//     cout<<str2.size()<<endl;                          //Finds the size of the given string
//     st=str1.substr(2,2);
//     cout<<st<<endl;    
//     sort(str1.begin(),str1.end());                    //Sort the elements using inbuilt function
//     cout<<str1<<endl;         
// }

int main()
{
    string str="(){}[]";
        for(int i=0;i<str.size();i+=2)
        {
            if(str[i]=='(' && str[i+1]==')')
            {
                continue;
            }
            else if(str[i]=='[' && str[i+1]==']')
            {
                continue;
            }
            else if(str[i]=='{' && str[i+1]=='}')
            {
                continue;
            }
            else
            {
                cout<<str[i]<<" "<<str[i+1];
                cout<<"FALSE"<<endl;
                exit;
            }
        }
        cout<<"TRUE"<<endl;
}