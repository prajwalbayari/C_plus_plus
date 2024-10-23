//Binary exponentiation

//Helpful in calculations like a^b%m with large value od a and b

#include<iostream>
using namespace std;

int MOD=1e5+9;

int powerIt(int a,int n)
{
    a%=MOD;
    int ans=1;
    while(n>0)
    {
        if(n&1)
            ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        n>>=1;
    }
    return ans;
}

int powerRec(int a,int n)
{
    if(n==0)
        return 1;
    int p=(powerRec(a,n/2)%MOD);
    if(n&1)
        return (((p*p)%MOD)*a)%MOD;
    return (p*p)%MOD;
}

int main()
{
    int a,n;
    cout<<"Enter the values of number and power: ";
    cin>>a>>n;
    cout<<"The modulo answer is: "<<powerRec(a,n)<<endl;
}