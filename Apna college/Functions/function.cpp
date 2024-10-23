#include<iostream>
#include<stdio.h>
using namespace std;

//Prime numbers in a range
// int isprime(int a);
// int main()
// {
//     int a,b,i;
//     cout<<"Enter the limit:\n";
//     cin>>a>>b;
//     cout<<"Prime numbers are:\n";
//        for(i=a+1;i<b;i++)
//        {
//         if(isprime(i)==0)
//         {
//             cout<<i<<endl;
//         }
//        }
// }
// int isprime(int a)
// {
//     int i,p=0;
//     for(i=2;i<a;i++)
//     {
//         if(a%i==0)
//         {
//             p=1;
//             break;
//         }
//     }
//     return p;
// }

//Fibonacci sequence
int fibonacci(int n);
int main()
{
    int n;
    cout<<"Enter the limit:\n";
    cin>>n;
    fibonacci(n);
}
int fibonacci(int n)
{
    int i,a=0,b=1,c;
    cout<<"Fibonacci sequence is:\n";
    for(i=1;i<=n;i++)
    {
        cout<<a<<" ";
        c=a+b;
        a=b;
        b=c;
    }
}


//Factorial
// int factorial(int n)
// {
//     int i,f=1;
//     for(i=1;i<=n;i++)
//     {
//         f=f*i;
//     }
//     return f;
// }
// int main()
// {
//     int n,m;
//     cout<<"Enter the number:\n";
//     cin>>n;
//     m=factorial(n);
//     cout<<"Factorial is: "<<m<<"\n";
// }


//Combination
// int factorial(int n)
// {
//     int i,f=1;
//     for(i=1;i<=n;i++)
//     {
//         f=f*i;
//     }
//     return f;
// }
// int main()
// {
//     int n,r;
//     float m,o,p,com;
//     cout<<"Enter the values of n and r:\n";
//     cin>>n>>r;
//     m=factorial(n);
//     o=factorial(n-r);
//     p=factorial(r);
//     com=(m)/(o*p);
//     cout<<"Value is: "<<com<<endl;
// }


// Pascal's triangle
// int fact(int n)
// {
//     int i,f=1;
//     for(i=1;i<=n;i++)
//     {
//         f=f*i;
//     }
//     return f;
// }
// int main()
// {
//     int n,i,j;
//     cout<<"Enter the number of rows:\n";
//     cin>>n;
//     for(i=0;i<n;i++)
//     {
//         for(j=0;j<=i;j++)
//         {
//             cout<<fact(i)/(fact(j)*fact(i-j))<<" ";
//         }
//         cout<<endl;
//     }
// }


// Sum of n numbers
// int sum(int n)
// {
//     int i,s=0;
//     for(i=0;i<=n;i++)
//     {
//         s+=i;
//     }
//     return s;
// }
// int main()
// {
//     int n,s;
//     cout<<"Enter the number: "<<endl;
//     cin>>n;
//     s=n*(n+1)/2;
//     cout<<"Sum using formula: "<<s<<endl;
//     cout<<"Sum using functions: "<<sum(n)<<endl;
// }


//Pythagorean triplets
// int max(int m,int n)
// {
//     if(m>n)
//     {
//         return m;
//     }
//     else
//     {
//         return n;
//     }
// }
// int pyth(int q,int w,int e)
// {
//     int x=max(q,max(w,e)),y,z;
//     if(x==q)
//     {
//         y=w,z=e;
//         if((x*x)==(y*y)+(z*z))
//         {
//             return 1;
//         }
//         else
//         {
//             return 0;
//         }
//     }
//     if(x==w)
//     {
//         y=q,z=e;
//         if((x*x)==(y*y)+(z*z))
//         {
//             return 1;
//         }
//         else
//         {
//             return 0;
//         }
//     }
//     if(x==e)
//     {
//         y=w,z=q;
//         if((x*x)==(y*y)+(z*z))
//         {
//             return 1;
//         }
//         else
//         {
//             return 0;
//         }
//     }
// }
// int main()
// {
//     int a,b,c;
//     cout<<"Enter the triplets: "<<endl;
//     cin>>a>>b>>c;
//     if(pyth(a,b,c)==1)
//     {
//         cout<<"These are pythagorean tiplets\n";
//     }
//     else
//     {
//         cout<<"These are not pythagorean triplets\n";
//     }
// }


// Binary addition
// int reverse(int z)
// {
//     int rev=0,n;
//     while(z>0)
//     {
//         n=z%10;
//         rev=rev*10+n;
//         z/=10;   
//     }
//     return rev;
// }
// int addBin(int x,int y)
// {
//     int s=0,carry=0;
//     while(x>0 && y>0)
//     {
//         if(x%2==0 && y%2==0)
//         {
//             s=s*10 +carry;
//         }
//         else if((x%2==0 && y%2==1)||(x%2==1 && y%2==0))
//         {
//             if(carry==1)
//             {
//                 s=s*10;
//                 carry=1;
//             }
//             else
//             {
//                 s=s*10+1;
//                 carry=0;
//             }
//         }
//         else
//         {
//             s=s*10 +carry;
//             carry=1;
//         }
//         x/=10,y/=10;
//     }
//     while(x>0)
//     {
//         if(carry==1)
//         {
//             if(x%2==1)
//             {
//                 s=s*10;
//                 carry=1;
//             }
//             else
//             {
//                 s=s*10+1;
//                 carry=0;
//             }
//         }
//         else
//         {
//             s=s*10 + (x%2);
//         }
//         x/=10;
//     }
//     while(y>0)
//     {
//         if(carry==1)
//         {
//             if(y%2==1)
//             {
//                 s=s*10;
//                 carry=1;
//             }
//             else
//             {
//                 s=s*10+1;
//                 carry=0;
//             }
//         }
//         else
//         {
//             s=s*10 + (y%2);
//         }
//         y/=10;
//     }
//     if(carry==1)
//     {
//         s=s*10+1;
//     }
//     return reverse(s);
// }
// int main()
// {
//     int a,b;
//     cout<<"Enter two numbers:\n";
//     cin>>a>>b;
//     cout<<"Sum is: \n";
//     cout<<addBin(a,b);
// }