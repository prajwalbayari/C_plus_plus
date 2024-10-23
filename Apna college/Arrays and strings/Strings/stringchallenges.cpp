#include <iostream>
#include<conio.h>
#include<string.h>
#include<algorithm>
using namespace std;


// Convert the whole string to upper case and lowercase
// int main() 
// {
//     string str="My name is Prajwal";
//     int i;
//     for(i=0;i<str.size();i++)                 //To uppercase
//     {
//         if(str[i]>='a'&& str[i]<='z')
//         {
//             str[i]-=32;
//         }
//     }
//     cout<<"String to uppercase is:\n"<<str<<endl;   //To lowercase
//     for(i=0;i<str.size();i++)
//     {
//         if(str[i]>='A'&&str[i]<='Z')
//         {
//             str[i]+=32;
//         }
//     }
//     cout<<"String to lowercase is:\n"<<str<<endl;
    
//     //trasnform (str.begin() ,str.end() ,str.begin() ,::toupper);   //using inbuilt function
// }


//Form the smallest and number
// int main()
// {
//     string str="1234556789043";
//     sort(str.begin(),str.end());
//     cout<<str<<endl;
//     sort(str.begin(),str.end(),greater<int>());
//     cout<<str<<endl;
// }


//Find the most frequently occuring alphabet
int main()
{
    string s="Shri Jayachamarajendra college of engineering";
    int fre[26],i,max=0;
    char ans='a';
    for(i=0;i<26;i++)
    {
        fre[i]=0;
    }
    for(i=0;i<s.size();i++)
    {
        fre[s[i]-'a']++;
    }
    for(i=0;i<26;i++)
    {
        if(fre[i]>max)
        {
            max=fre[i];
            ans='a'+i;
        }
    }
    cout<<max<<" "<<ans<<endl;
}