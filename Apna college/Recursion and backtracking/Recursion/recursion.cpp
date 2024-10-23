#include<conio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

//Sum of first N natural number
// int sum(int n)
// {
//     if(n==0)
//     {
//         return 0;
//     }
//     int prevsum=sum(n-1);
//     return n+prevsum;
// }
// int main()
// {
//     int n;
//     cout<<"Enter the number:\n";
//     cin>>n;
//     cout<<"Sum is:\n";
//     cout<<sum(n);
// }

// Calculate 'n' raised to the power 'p'

// int power(int n,int p)
// {
//     if(p==0)
//     {
//         return 1;
//     }
//     int prevpow=power(n,p-1);
//     return n*prevpow;
// }
// int main()
// {
//     int n,p;
//     cout<<"Enter the number:\n";
//     cin>>n;
//     cout<<"Enter the power:\n";
//     cin>>p;
//     cout<<"Answer is:\n";
//     cout<<power(n,p);
// }


//Factorial
// int fact(int n)
// {
//     if(n==0)
//     {
//         return 1;
//     }
//     int prevfact=fact(n-1);
//     return n*prevfact;
// }
// int main()
// {
//     int n;
//     cout<<"Enter the number:\n";
//     cin>>n;
//     cout<<"Factorial of the number is:\n";
//     cout<<fact(n);
// }

//Fibonacci sequence
// int fibonacci(int n)
// {
//     if(n==0 || n==1)
//     {
//         return n;
//     }
//     return fibonacci(n-1)+fibonacci(n-2);
// }
// int main()
// {
//     int n;
//     cout<<"Enter the limit:\n";
//     cin>>n;
//     cout<<"Fibonacci sequence is:\n";
//     cout<<fibonacci(n)<<endl;
// }

//To print n numbers in decreasing order
// void order(int n)
// {
//     if(n==0)
//     {
//         return;
//     }
//     cout<<n<<" ";
//     return order(n-1);
// }
// int main()
// {
//     int n;
//     cout<<"Enter the limit:\n";
//     cin>>n;
//     cout<<"Numbers in decreasing order:\n";
//     order(n);
// }


//To print numbers in their increasing order
// void order(int n)
// {
//     if(n==0)
//     {
//         return;
//     }
//     order(n-1);
//     cout<<n<<" ";
// }
// int main()
// {
//     int n;
//     cout<<"Enter the limit:\n";
//     cin>>n;
//     cout<<"Numbers in increasing order:\n";
//     order(n);
// }


//To determine the first and last occurence of a number in an array
// int firstocc(int arr[10],int n,int i,int key)
// {
//     cout<<i<<" ";
//     if(i==n)
//     {
//         return -1;
//     }
//     if(arr[i]==key)
//     {
//         return i;
//     }
//     firstocc(arr,n,i+1,key);
// }
// int lastocc(int arr[10],int n,int i,int key)
// {
//     if(i==n)
//     {
//         return 0;
//     }
//     int restarr=lastocc(arr,n,i+1,key);
//     if(restarr!=-1)
//     {
//         return restarr;
//     }
//     if(arr[i]==key)
//     {
//         return i;
//     }
//     return -1;
// }
// int main()
// {
//     int arr[10],i,j=0,key,n;
//     cout<<"Enter the size of the array:\n";
//     cin>>n;
//     cout<<"Enter the array elements:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     cout<<"Enter the searching element:\n";
//     cin>>key;
//     cout<<firstocc(arr,n,j,key)<<endl;
//     cout<<lastocc(arr,n,i,key)<<endl;
// }