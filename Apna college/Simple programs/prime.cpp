#include <iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n,t=0,i;
    cout<<"Enter a number\n";
    cin>>n;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            t=1;
            break;
        }
    }
    if(t==1)
    {
        cout<<"Not a prime number\n";
    }
    else
    {
        cout<<"Prime number\n";
    }
}   