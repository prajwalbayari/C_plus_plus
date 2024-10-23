//Boring factorials

//Given 2 integers n and p calculate (n!)%p
//Constraints -> 1<=n,p<=2*10^9 abs(n-p)<=1000

//Time complexity-> O((p-n)*Log(n))

#include<iostream>
using namespace std;

int power(int x,int y,int p)
{
    int res=1;
    x%=p;
    while(y>0)
    {
        if(y&1)
            res=(res*x)%p;
        y=y>>1;
        x=(x*x)%p;
    }
    return res;
}

int modInverse(int i,int p)
{
    return power(i,p-2,p);
}

int modFact(int n,int p)
{
    if(p<=n)
        return 0;
    int res=p-1;
    for(int i=n+1;i<p;i++)
        res=(res*modInverse(i,p))%p;
    return res;
}

int main()
{
    int n,p;
    cout<<"Enter the values of n and p respectively: ";
    cin>>n>>p;
    cout<<"Remainder of (n!)%p is: "<<modFact(n,p)<<endl;
}
