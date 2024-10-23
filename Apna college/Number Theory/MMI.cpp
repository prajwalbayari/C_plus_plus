//Multiplicative Modulo Inverse

//Find a 'B' such that (A*B)%m=1 given m and 'A'
//Similar to extended euclid's algorithm the GCD value is fixed as 1 the quadratic equation we get is
// A*B-m*q=1 where q is quotient

#include<iostream>
using namespace std;

struct triplet
{
    int x,y,gcd;
};

triplet extendedEuclid(int a,int b)
{
    if(b==0)
    {
        triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    triplet smallAns=extendedEuclid(b,a%b);
    triplet ans;
    ans.gcd=smallAns.gcd;
    ans.x=smallAns.y;
    ans.y=smallAns.x-(a/b)*smallAns.y;
    return ans;
}

int MMI(int a,int m)
{
    triplet ans=extendedEuclid(a,m);
    return ans.x;
}

int main()
{
    int m,a;
    cout<<"Enter the values A and m respectively: ";
    cin>>a>>m;
    cout<<"The possible value of B is: "<<MMI(a,m)<<endl;
    //if ans is negative then the answer can be obtained by ((A*B)%m+m)%m
}