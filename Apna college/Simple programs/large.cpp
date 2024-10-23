#include<iostream>
using namespace std;
int main()
{
   int a,b,c;
   cin>>a>>b>>c;
   if(a==b&&b==c)
   {
    cout<<"All the three numbers are equal";
   }
   else if(a>b)
   {
    if(a>c)
    {
        cout<<a<<" is largest";
    }
    else
    {
        cout<<c<<" is largest";
    }
   }
   else if(b>c)
   {
    cout<<b<<" is largest";
   }
   else
   {
    cout<<c<<" is largest";
   }
}