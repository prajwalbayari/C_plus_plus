#include<iostream>
using namespace std;
int main()
{
    int q;
    cout<<"Enter a number\n";
    cin>>q;
    if(q==0)
    {
        cout<<"ZERO";
        exit(0);
    }
    else if(q%2==0)
    {
        cout<<"EVEN";
    }
    else 
    {
        cout<<"ODD";
    }
}

