//FIbonacci number using dynamic programming

#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> v(1e5,-1);

int fib(int n)
{
    if(n==1 || n==2)
        return n-1;
    if(v[n]!=-1)
        return v[n];
    v[n]=fib(n-1)+fib(n-2);
    return v[n];
}

int main()
{
    int n;
    cout<<"Enter the number\n";
    cin>>n;
    cout<<"The fibonacci number is: "<<fib(n)<<endl;
}