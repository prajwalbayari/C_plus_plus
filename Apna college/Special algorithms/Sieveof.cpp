//SIEVE OF ERATOSTHENES
//Listing the prime numbers in a range
#include<iostream>
#include<conio.h>
#include<string.h>
#include<algorithm>
using namespace std;

// void sieve(int n)
// {
//     int prime[100]={0},i,j;
//     for(i=2;i<=n;i++)
//     {
//         if(prime[i]==0)
//         {
//             for(j=i*i;j<=n;j+=i)
//             {
//                 prime[j]=1;
//             }
//         }
//     }
//     for(i=0;i<n;i++)
//     {
//         if(prime[i]==0)
//         {
//             cout<<i<<" ";
//         }
//     }
//     cout<<endl;
// }
// int main()
// {
//     int n;
//     cout<<"Enter the limit:\n";
//     cin>>n;
//     cout<<"The prime numbers between the range is:\n";
//     sieve(n);
// }


//PRIME FACTOR
void primefactor(int n)
{
    int i,spf[100]={0},j;
    for(i=2;i<=n;i++)
    {
        spf[i]=i;
    }
    for(i=2;i<=n;i++)
    {
        if(spf[i]==i)
        {
            for(j=i*i;j<=n;j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j]=i;
                }
            }
        }
    }
    while(n!=1)
    {
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }
}    
int main()
{
    int n;
    cout<<"Enter the number:\n";
    cin>>n;
    primefactor(n);
    return 0;
}