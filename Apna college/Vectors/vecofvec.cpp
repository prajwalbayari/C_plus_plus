#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
using namespace std;


// int main()
// {
//     int num;
//     cout<<"Enter a number:\n";
//     cin>>num;
//     if(num==1)
//     {
//         cout<<"Hello\n";
//     }
//     else
//     {
//         cout<<"hi\n";
//     }
// }

// int main()
// {
//     int m,n;
//     vector<vector<int>> vec;
//     cout<<"Enter two numbers\n";
//     for(int i=0;i<2;i++)
//     {
//         for(int j=0;j<2;j++)
//         {
//             cin>>vec[i][j];
//         }
//     }

//     for(int i=0;i<2;i++)
//     {
//         for(int j=0;j<2;j++)
//         {
//             cout<<vec[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

int main()
{
    vector<vector<int>> v(10,vector<int> (20,0));
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<20;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}