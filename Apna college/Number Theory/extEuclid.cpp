// Extended euclid algorithm to solve non-linear equations

//ax+by=gcd(a,b)

#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;

struct triplet
{
    int x,y,gcd;
};

triplet extended(int a,int b)
{
    if(b==0)
    {
        triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }

    triplet smallAns=extended(b,a%b);
    triplet ans;
    ans.gcd=smallAns.gcd;
    ans.x=smallAns.y;
    ans.y=smallAns.x-(a/b)*smallAns.y;
    return ans;
}

int main()
{
    int a,b;
    cout<<"Enter the coefficients of equations(a,b in ax+by): ";
    cin>>a>>b;
    triplet ans=extended(a,b);
    cout<<"x= "<<ans.x<<" y= "<<ans.y<<" GCD= "<<ans.gcd<<endl;
}