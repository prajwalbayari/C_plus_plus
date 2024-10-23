#include <iostream>
#include<conio.h>
#include<vector>
using namespace std;

//int main()
// {
//    cout<<"Size of short integer "<<sizeof(short int)<<"\n";
//    cout<<"Size of long integer "<<sizeof(long int)<<"\n";
//    cout<<"Size of signed integer "<<sizeof(signed int)<<"\n";
//    cout<<"Size of unsigned integer "<<sizeof(unsigned int)<<"\n";
//    return 0;
// }

// int fact(int n)
// {
//    int temp;
//    if(n==0)
//    {
//       return 1;
//    }
//    if(n==1)
//    {
//       return 1;
//    }
//    temp=n*fact(n-1);
//    return temp;
// }

// int main()
// {
//    int n;
//    cout<<"Enter the number:\n";
//    cin>>n;
//    cout<<"Factorial of given number is:\n";
//    cout<<fact(n)<<endl;
// }

// int main()
// {
//    int n,r,per,com;
//    cout<<"Enter the value of n and r:\n";
//    cin>>n>>r;
//    per=(fact(n)/fact(r));
//    cout<<"Permutation is: "<<per<<endl;
//    com=(fact(n)/fact(n-r));
//    cout<<"Combination is: "<<com<<endl;
// }

// int display(int a[])
// {
//    for(int i=0;i<10;i++)
//    {
//       if(a[i]>0)
//       {
//          cout<<i<<" is present "<<a[i]<<" times\n";
//       }
//    }
// }

// int count(int n,int a[])
// {
//    while(n/10!=0)
//    {
//       int temp=n%10;
//       a[temp]++;
//       n=n/10;
//    }
//    a[n]++;
//    display(a);
// }

// int main()
// {
//    int n,a[10]={0};
//    cout<<"Enter the number:\n";
//    cin>>n;
//    count(n,a);
// }

// int pow(int n,int r)
// {
//    int temp=0;
//    while(temp==0)
//    {
//       temp=n%r;
//       n=n/r;
//    }
//    if(n>0)
//    {
//       cout<<"False"<<endl;
//    }
//    else
//    {
//       cout<<"True"<<endl;
//    }
// }

// int main()
// {
//    int n,r;
//    cout<<"Enter the base:\n";
//    cin>>n;
//    cout<<"Enter the number:\n";
//    cin>>r;
//    pow(r,n);
// }

int main()
{
   vector<int> v={3,2,2,3};
   int a[100],j=0,val=3;
   for(int i=0;i<v.size();i++)
   {
      if(v[i]!=val)
      {
         cout<<v[i]<<" ";
         a[j]=v[i];
         j++;
      }
   }
   // for(int i=0;i<4;i++)
   // {
   //    cout<<a[i]<<" ";
   // }
   cout<<endl;
}